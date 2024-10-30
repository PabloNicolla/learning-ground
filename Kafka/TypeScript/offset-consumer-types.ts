import { Kafka } from "kafkajs";
import type { Consumer, EachMessagePayload } from "kafkajs";

const kafka = new Kafka({
  clientId: "offset-demo-app",
  brokers: ["localhost:9092"],
});

class KafkaConsumerWithOffsets {
  private consumer: Consumer;

  constructor(groupId: string) {
    // Configure consumer with specific auto-commit settings
    this.consumer = kafka.consumer({
      groupId,
    });
  }

  // 1. Auto-commit example
  async consumeWithAutoCommit(): Promise<void> {
    await this.consumer.connect();
    await this.consumer.subscribe({ topic: "my-topic" });

    await this.consumer.run({
      autoCommit: true,
      eachMessage: async ({ topic, partition, message }: EachMessagePayload) => {
        try {
          console.log(`Processing message ${message.offset} from partition ${partition}`);
          // Process your message here
          await this.processMessage(message);
          // No need to commit manually - Kafka will auto-commit based on interval/threshold
        } catch (error) {
          console.error("Error processing message:", error);
          // Handle error (might want to stop processing or implement retry logic)
        }
      },
    });
  }

  // 2. Manual commit example
  async consumeWithManualCommit(): Promise<void> {
    await this.consumer.connect();
    await this.consumer.subscribe({ topic: "my-topic" });

    await this.consumer.run({
      autoCommit: false,
      eachMessage: async ({ topic, partition, message }: EachMessagePayload) => {
        try {
          console.log(`Processing message ${message.offset} from partition ${partition}`);

          // Process your message
          await this.processMessage(message);

          // Manually commit the offset after successful processing
          await this.consumer.commitOffsets([
            {
              topic,
              partition,
              offset: (Number(message.offset) + 1).toString(),
            },
          ]);
          console.log(`Committed offset ${message.offset} for partition ${partition}`);
        } catch (error) {
          console.error("Error processing message:", error);
          // In case of error, don't commit the offset
          // The message will be reprocessed after consumer restart
        }
      },
    });
  }

  // 3. Batch commit example
  async consumeWithBatchCommit(): Promise<void> {
    await this.consumer.connect();
    await this.consumer.subscribe({ topic: "my-topic" });

    const BATCH_SIZE = 100;
    let messageCount = 0;
    let lastOffsets: Record<number, string> = {};

    await this.consumer.run({
      autoCommit: false,
      eachMessage: async ({ topic, partition, message }: EachMessagePayload) => {
        try {
          await this.processMessage(message);

          // Keep track of latest offset for each partition
          lastOffsets[partition] = message.offset;
          messageCount++;

          // Commit offsets after processing BATCH_SIZE messages
          if (messageCount >= BATCH_SIZE) {
            const offsetsToCommit = Object.entries(lastOffsets).map(([partition, offset]) => ({
              topic,
              partition: Number(partition),
              offset: (Number(offset) + 1).toString(),
            }));

            await this.consumer.commitOffsets(offsetsToCommit);
            console.log("Committed batch of offsets:", offsetsToCommit);

            // Reset counters
            messageCount = 0;
            lastOffsets = {};
          }
        } catch (error) {
          console.error("Error processing message:", error);
          // Handle error (might want to stop processing or implement retry logic)
        }
      },
    });
  }

  private async processMessage(message: any): Promise<void> {
    // Simulate message processing
    await new Promise((resolve) => setTimeout(resolve, 100));
  }

  async disconnect(): Promise<void> {
    await this.consumer.disconnect();
  }
}

// Example usage
async function main() {
  // Example with manual commit
  const consumer = new KafkaConsumerWithOffsets("my-group");

  try {
    // Choose one of these consumption patterns:
    // await consumer.consumeWithAutoCommit();
    // await consumer.consumeWithManualCommit();
    await consumer.consumeWithBatchCommit();
  } catch (error) {
    console.error("Error in consumer:", error);
  }
}

// Handle graceful shutdown
process.on("SIGTERM", async () => {
  console.log("Shutting down...");
  // Implement cleanup logic here
  process.exit(0);
});

main().catch(console.error);
