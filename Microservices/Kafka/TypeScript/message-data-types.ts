import { Kafka } from "kafkajs";
import avro from "avsc";
import protobuf from "protobufjs";

// Sample user event data structure
interface UserEvent {
  userId: string;
  eventType: string;
  timestamp: number;
  data: {
    name?: string;
    email?: string;
    action?: string;
  };
}

// 1. JSON Implementation
class JsonMessageHandler {
  async serialize(event: UserEvent): Promise<Buffer> {
    return Buffer.from(JSON.stringify(event));
  }

  async deserialize(buffer: Buffer): Promise<UserEvent> {
    return JSON.parse(buffer.toString());
  }
}

// 2. Avro Implementation
class AvroMessageHandler {
  private type = avro.Type.forSchema({
    type: "record",
    name: "UserEvent",
    fields: [
      { name: "userId", type: "string" },
      { name: "eventType", type: "string" },
      { name: "timestamp", type: "long" },
      {
        name: "data",
        type: {
          type: "record",
          name: "EventData",
          fields: [
            { name: "name", type: ["null", "string"], default: null },
            { name: "email", type: ["null", "string"], default: null },
            { name: "action", type: ["null", "string"], default: null },
          ],
        },
      },
    ],
  });

  async serialize(event: UserEvent): Promise<Buffer> {
    return Buffer.from(this.type.toBuffer(event));
  }

  async deserialize(buffer: Buffer): Promise<UserEvent> {
    return this.type.fromBuffer(buffer);
  }
}

// 3. Protobuf Implementation
class ProtobufMessageHandler {
  private UserEvent: protobuf.Type;

  constructor() {
    // Create the root and define message types directly instead of loading from file
    const root = protobuf.Root.fromJSON({
      nested: {
        EventData: {
          fields: {
            name: { type: "string", id: 1 },
            email: { type: "string", id: 2 },
            action: { type: "string", id: 3 },
          },
        },
        UserEvent: {
          fields: {
            userId: { type: "string", id: 1 },
            eventType: { type: "string", id: 2 },
            timestamp: { type: "int64", id: 3 },
            data: { type: "EventData", id: 4 },
          },
        },
      },
    });

    this.UserEvent = root.lookupType("UserEvent");
  }

  async serialize(event: UserEvent): Promise<Buffer> {
    const message = this.UserEvent.create(event);
    return Buffer.from(this.UserEvent.encode(message).finish());
  }

  async deserialize(buffer: Buffer): Promise<UserEvent> {
    const uint8Array = new Uint8Array(buffer);
    const message = this.UserEvent.decode(uint8Array);
    return this.UserEvent.toObject(message) as UserEvent;
  }
}

// Example usage with error handling and performance monitoring
class MessageFormatExample {
  private jsonHandler: JsonMessageHandler;
  private avroHandler: AvroMessageHandler;
  private protobufHandler: ProtobufMessageHandler;

  constructor() {
    this.jsonHandler = new JsonMessageHandler();
    this.avroHandler = new AvroMessageHandler();
    this.protobufHandler = new ProtobufMessageHandler();
  }

  async compareFormats() {
    const testEvent: UserEvent = {
      userId: "123",
      eventType: "USER_CREATED",
      timestamp: Date.now(),
      data: {
        name: "John Doe",
        email: "john@example.com",
        action: "signup",
      },
    };

    // Measure size and performance for each format
    console.log("Comparing message formats:");

    // JSON
    const jsonStart = process.hrtime();
    const jsonBuffer = await this.jsonHandler.serialize(testEvent);
    const jsonDeser = await this.jsonHandler.deserialize(jsonBuffer);
    const jsonDuration = process.hrtime(jsonStart);

    // Avro
    const avroStart = process.hrtime();
    const avroBuffer = await this.avroHandler.serialize(testEvent);
    const avroDeser = await this.avroHandler.deserialize(avroBuffer);
    const avroDuration = process.hrtime(avroStart);

    // Protobuf
    const protobufStart = process.hrtime();
    const protobufBuffer = await this.protobufHandler.serialize(testEvent);
    const protobufDeser = await this.protobufHandler.deserialize(protobufBuffer);
    const protobufDuration = process.hrtime(protobufStart);

    console.log({
      json: {
        size: jsonBuffer.length,
        duration: `${jsonDuration[0]}s ${jsonDuration[1] / 1000000}ms`,
      },
      avro: {
        size: avroBuffer.length,
        duration: `${avroDuration[0]}s ${avroDuration[1] / 1000000}ms`,
      },
      protobuf: {
        size: protobufBuffer.length,
        duration: `${protobufDuration[0]}s ${protobufDuration[1] / 1000000}ms`,
      },
    });
  }
}

// Usage
const example = new MessageFormatExample();
example.compareFormats().catch(console.error);
