import amqp from "amqplib";

async function publishMessage() {
  try {
    // Connect to RabbitMQ
    const connection = await amqp.connect("amqp://guest:guest@localhost:5672");
    const channel = await connection.createChannel();

    // Queue declaration
    const queue = "test_queue";
    await channel.assertQueue(queue, {
      durable: false,
    });

    // Message to send
    const message = {
      text: "Hello from publisher!",
      timestamp: new Date().toISOString(),
    };

    // Send message
    channel.sendToQueue(queue, Buffer.from(JSON.stringify(message)));
    console.log(" [x] Sent message:", message);

    // Close connection after 1 second
    setTimeout(() => {
      connection.close();
      process.exit(0);
    }, 1000);
  } catch (error) {
    console.error("Error:", error);
  }
}

publishMessage();
