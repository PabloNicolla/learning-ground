import { Kafka } from "kafkajs";
import type { Producer, Consumer, EachMessagePayload } from "kafkajs"; // Use type-only import for Consumer
import { v4 as uuidv4 } from "uuid";

// Kafka client configuration
const kafka = new Kafka({
  clientId: "my-app",
  brokers: ["localhost:9092"], // Update with your Kafka broker addresses
  ssl: false, // Set to true if using SSL
});

// Producer class to handle message publishing
class KafkaProducer {
  private producer: Producer;

  constructor() {
    this.producer = kafka.producer();
  }

  async connect(): Promise<void> {
    try {
      await this.producer.connect();
      console.log("Producer connected successfully");
    } catch (error) {
      console.error("Failed to connect producer:", error);
      throw error;
    }
  }

  async sendMessage(topic: string, message: any): Promise<void> {
    try {
      await this.producer.send({
        topic,
        messages: [
          {
            key: uuidv4(),
            value: JSON.stringify(message),
          },
        ],
      });
      console.log("Message sent successfully");
    } catch (error) {
      console.error("Failed to send message:", error);
      throw error;
    }
  }

  async disconnect(): Promise<void> {
    await this.producer.disconnect();
  }
}

// Consumer class to handle message consumption
class KafkaConsumer {
  private consumer: Consumer;
  private readonly groupId: string;

  constructor(groupId: string) {
    this.groupId = groupId;
    this.consumer = kafka.consumer({ groupId });
  }

  async connect(): Promise<void> {
    try {
      await this.consumer.connect();
      console.log("Consumer connected successfully");
    } catch (error) {
      console.error("Failed to connect consumer:", error);
      throw error;
    }
  }

  async subscribe(topics: string[]): Promise<void> {
    try {
      for (const topic of topics) {
        await this.consumer.subscribe({ topic, fromBeginning: true });
      }
      console.log("Subscribed to topics:", topics);
    } catch (error) {
      console.error("Failed to subscribe to topics:", error);
      throw error;
    }
  }

  async consume(messageHandler: (message: any) => Promise<void>): Promise<void> {
    try {
      await this.consumer.run({
        eachMessage: async ({ topic, partition, message }: EachMessagePayload) => {
          console.log({
            topic,
            partition,
            offset: message.offset,
            timestamp: message.timestamp,
          });

          const messageValue = message.value?.toString();
          if (messageValue) {
            const parsedMessage = JSON.parse(messageValue);
            await messageHandler(parsedMessage);
          }
        },
      });
    } catch (error) {
      console.error("Error in message consumption:", error);
      throw error;
    }
  }

  async disconnect(): Promise<void> {
    await this.consumer.disconnect();
  }
}

// Example usage
async function main() {
  // Producer example
  const producer = new KafkaProducer();
  await producer.connect();

  // Consumer example
  const consumer = new KafkaConsumer("my-consumer-group");
  await consumer.connect();
  await consumer.subscribe(["my-topic"]);

  // Send a message
  const message = {
    id: 1,
    text: "Hello Kafka!",
    timestamp: new Date().toISOString(),
  };

  await producer.sendMessage("my-topic", message);

  // Consume messages
  await consumer.consume(async (message) => {
    console.log("Received message:", message);
    // Add your message processing logic here
  });

  // Cleanup (call these when shutting down your application)
  // await producer.disconnect();
  // await consumer.disconnect();
}

// Error handling
process.on("SIGTERM", async () => {
  console.log("Termination signal received. Cleaning up...");
  process.exit(0);
});

main().catch(console.error);
