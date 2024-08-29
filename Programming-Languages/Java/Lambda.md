# Lambda

## Examples

### Example 1

```java
public class LambdaExample {
  public static void main(String[] args) {
    String prefix = "Hello, ";

    // Lambda expression that captures the local variable 'prefix'
    Greeting greeting = name -> System.out.println(prefix + name);

    // Use the lambda expression
    greeting.sayHello("John");
  }
}

@FunctionalInterface
interface Greeting {
    void sayHello(String name);
}
```

### Example 2

```java
public class LambdaExample {
  public static void main(String[] args) {
    int[] counter = {0};  // Using an array to hold a mutable integer

    Runnable runnable = () -> {
      counter[0]++;
      System.out.println("Counter: " + counter[0]);
    };

    runnable.run();  // Output: Counter: 1
    runnable.run();  // Output: Counter: 2
  }
}
```
