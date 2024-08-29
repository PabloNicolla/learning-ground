# Lambda

## Types

- `Consumer<T>`: Represents an operation that takes a single input argument and returns no result.
- `Function<T, R>`: Represents a function that takes one argument and produces a result.
- `BiFunction<T, U, R>`: Represents a function that takes two arguments and produces a result.
- `Supplier<T>`: Represents a supplier of results (takes no parameters and returns a result).
- `Predicate<T>`: Represents a predicate (boolean-valued function) of one argument.

## Examples

### Simple in-line

```java
public class LambdaExample {
  public static void main(String[] args) {
    String prefix = "Hello, ";

    // Lambda expression that captures the local variable 'prefix'
    Greeting greeting = name -> System.out.println(prefix + name);

    // Use the lambda expression
    greeting.sayHello("John"); // Output: Hello, John
  }
}

@FunctionalInterface
interface Greeting {
    void sayHello(String name);
}
```

### Simple Enclosed

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

### Parameter In Line

```java
import java.util.function.Consumer;

public class LambdaExample {
    public static void main(String[] args) {
        // Lambda with a single parameter
        Consumer<String> greeter = name -> System.out.println("Hello, " + name);

        greeter.accept("John");  // Output: Hello, John
    }
}
```

### Parameter Enclosed

```java
import java.util.function.BiFunction;

public class LambdaExample {
    public static void main(String[] args) {
        // Lambda with two parameters
        BiFunction<Integer, Integer, Integer> add = (a, b) -> a + b;

        int result = add.apply(5, 3);  // Output: 8
        System.out.println(result);
    }
}
```
