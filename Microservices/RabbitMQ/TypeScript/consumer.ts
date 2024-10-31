import amqp from "amqplib";

async function consumeMessages() {
  try {
    // Connect to RabbitMQ
    const connection = await amqp.connect("amqp://guest:guest@localhost:5672");
    const channel = await connection.createChannel();

    // Queue declaration
    const queue = "test_queue";
    await channel.assertQueue(queue, {
      durable: false,
    });

    console.log(" [*] Waiting for messages in %s. To exit press CTRL+C", queue);

    // Consume messages
    channel.consume(queue, (msg) => {
      if (msg !== null) {
        const content = JSON.parse(msg.content.toString());
        console.log(" [x] Received:", content);
        channel.ack(msg);
      }
    });
  } catch (error) {
    console.error("Error:", error);
  }
}

consumeMessages();
