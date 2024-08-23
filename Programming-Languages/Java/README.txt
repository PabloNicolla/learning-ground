package packageName;
import java.util.*;

public class ClassName {}
public static void main(String[] args) {}   - Start of the program
                                            - args: Array of program inputs     - e.g. File Names
                                            - args.length: Number of inputs

//          - Comment line
/* */       - Comment lines
/** */      - Java Doc

# <<< Output, Input >>> #

    System.out.print();     - Print
    System.out.println();   - Print + \n
    System.out.printf();    - Print with insertions
                            - %d %f %s %c %b

    Scanner(System.in);     - Get user input

# <<< Types >>> #

    Primitive   - int, char, double, boolean
                - short, long, float(f)
    Objects     - Integer, Character, Double, Boolean, String

    var         - The compiler deduces the type(Primitive or Object)

    var x = (int) (char)... - Core conversions
    Integer.parseInt()      - String -> int
    Double.parseDouble()    - String -> double
    Boolean.parseBoolean()  - String -> boolean
    String.valueOf()        - num -> String

# <<< Operators >>> #

    Math Operators          - (+, -, *, /, %)
    Increment Operators     - (++, --, +=, -=, *=, /=, %=)
    Logical Operators       - (||, &&, !)
    Relational Operators    - (==, !=, >, >=, <, <=)
    Comparison              - SomeObject.equals(OtherObject);
                            - Objects.equals(Object1, Object2);

# <<< Arrays >>> #

    Array               - type[] name = new type[...];
    2D-Array            - type[][] name = new type[...][...];


# <<< Mutable Strings >>> #

    StringBuffer        - A string buffer is like a String, but can be modified.
    StringBuilder       - Compatible with StringBuffer.
                        - No guarantee of synchronization.
                        - Faster than StringBuffer.

# <<< If statement >>> #

    if                  - if(bool);
                        - if(bool), else;
                        - if(bool), else if(bool), else;

    ternary operator    - result = (condition) ? option1 : option2;

# <<< For statement >>> #

    for             - for (int i = 0; i < x; i++);
    for each        - for (Object o : Array/List/Set);

    Char Iteration  - for (int i = (int)'a'; i <= (int)'z'; i++)    - [a to z]

# <<< While statement >>> #

    do
    while

# <<< Switch statement >>> #

    switch (var)    - case A: case B: {} break;
                    - default: {}
                    - case C, D: -> {}
                    - default -> {}

# <<< Functions >>> #

    Functions declaration       - returnType functionName(pType p, ...) { return; }
    Overloading                 - Same method name, but different parameters.

# <<< Try statement >>> #

    try
    catch           - (Exception e) { e. ... };         - (Error e) { e. ... };
    finally

# <<< Handling Data >>> #

    CSV
    JSON
    XML
    TSV

    Files
    FileWriter      - FileWriter writer = new FileWriter("FILENAME.txt");
                    - writer.write("Hello\n");
                    - writer.append("World\n");
                    - writer.close();
                    - try {} catch(IOException e) {}
    FileReader      - FileReader reader = new FileReader("FILENAME.txt");
                    - int data = reader.read();
                    - while (!Objects.equals(data, -1)) {
                    -       System.out.print((char) data);
                    -       data = reader.read();
                    - }
                    - try {} catch(IOException e) {}

URLs

BufferedReader  -

# <<< Data Structures >>> #

    DataStructure<DataType,...> name = new DataStructure<DataType,...>();

    # <<< ArrayList >>> #

        ArrayList<TYPE> myArr = new ArrayList<TYPE>();

    # <<< LinkedList >>> #

        Can be used as a queue

        LinkedList<TYPE> myList = new LinkedList<TYPE>();

    # <<< HashTable >>> #

        Key -> Value

        HashTable<key_TYPE, value_TYPE> myTable = new HashTable<key_TYPE, value_TYPE>();

    # <<< HashMap >>> #

        Same as HasTable but it is un-synchronized(faster) and permits nulls.
        !!!
            The synchronization is on the accessor/mutator methods,
            and it will stop two threads adding or removing from the map concurrently,
            but in the real world, you will often need additional synchronization.
        !!!

        HashMap<key_TYPE, value_TYPE> myMap = new HashMap<key_TYPE, value_TYPE>();

    # <<< LinkedHashMap >>> #

        It keeps the insertion order of keys in a doubly-linked list

    # <<< HashSet >>> #

        Unique Values

        HashSet<TYPE> mySet = new HashSet<TYPE>();

    # <<< LinkedHashSet >>> #

        It keeps the insertion order of values in a doubly-linked list

    # <<< TreeSet >>> #

        Binary Search Tree

    # <<< TreeMap >>> #

        Trie

    # <<< PriorityQueue >>> #

        Java automatic queue
        All objects in the queue are compared using compareTo from Comparable
        It keeps the "list" "sorted" after new items are added
        It sorts the items every time the method poll is called

        PriorityQueue<TYPE> myPQ = new PriorityQueue<TYPE>( INITIAL_SIZE );

        PriorityQueue<TYPE> reversePQ = new PriorityQueue<TYPE>( INITIAL_SIZE, Collections.reverseOrder() );

# <<< Data Structures casts >>> #

    # <<< coping to List from >>> #

        List        -/ ArrayList<Object> copy = new ArrayList<Object>(OtherArrayList);
        Set         -| ArrayList<Object> copy = new ArrayList<Object>(HashSet);
        Collection  -\ ArrayList<Object> copy = new ArrayList<Object>(Collection);
        Array       - ArrayList<Object> copy = new ArrayList<Object>(List.of(Array));   - Array cannot be primitive

    # <<< coping to Set from >>> #

        List        -/ HashSet<Object> copy = new HashSet<Object>(ArrayList);
        Set         -| HashSet<Object> copy = new HashSet<Object>(OtherHashSet);
        Collection  -\ HashSet<Object> copy = new HashSet<Object>(Collection);
        Array       - HashSet<Object> copy = new HashSet<Object>(Set.of(Array));        - Array cannot be primitive, Array must have unique values
        Array       - HashSet<Object> copy = new HashSet<Object>(List.of(Array));       - Array cannot be primitive

    # <<< coping to Array >>> #

        - Airport[] arr = airports.toArray(new Airport[0]);                 - Array cannot be primitive
        - Airport[] arr = new Airport[0];   - airports.toArray(arr);


# <<< Multiple Packages Program >>> #

    new package Main    - Main program
    new package Math    - Functions + Classes

    inside main:
        - import Math.*;
        - methodName. ... ;                     - non-static methods
        or
        - className cn = new className();       - No import
        - cn. ... ;                             - static methods
        or
        - Math.className. ...;                  - No import
                                                - non-static methods

# <<< Java Class >>> #

    Class               - public class ClassName {}
    Constructor         - public ClassName() {}
    this.var            - This == ClassName    so    this.var1 == ClassName.var1
    getter/setters      - For private vars
    @Override           - "Re-write" functions for this class
    toString()          - Print return


    Inheritance         - public class Human {...}                      (All classes extend Object)
                        - public class Hero extends Human {...}
                        - public class Villain extends Human {...}
    super(...);         - Send parameters to the parent class constructor
    super.func();       - In order to use parent functions


    static              - The function or variable belongs to the class and not to objects
    e.g.                - Human.func();        instead of         myHuman.func();


    final               - Block modifications after declaration (const)
    e.g.                - final NAME

# <<< Abstract >>> #

    Several methods and instances that many classes will implement

    Transforms the class into an abstract model for children to extend
    Cannot be instanced

    e.g.
        - public abstract class NAME() {}
        - public abstract void NAME();

    sealed
        - Use after abstract
        - It makes that only cited classes can inherit from sealed
        - Classes that inherit from sealed must be: final, non-sealed or sealed

    e.g.
        -

# <<< Interfaces >>> #

    Several methods that many classes will implement

    public interface IInterfaceName() {}
    After implementing ISomeInterface to Human
    If Villain and Hero extend Human:

    Dynamic dispatch
            - ISomeInterface SI1 = humanObject;     - ISomeInterface SI2 = HeroObject;
            - Human h = (Human) SI1;                - Hero hr = (Hero) SI2;
            - Name of interfaces starts with "I"

# <<< Encapsulation >>> #

    Data hiding

    public          - All scope
    protected       - Same Package scope + "direct access" when extended
    default         - Same Package scope
    private         - Same Class scope

# <<< Polymorphism >>> #

    If Villain and Hero extend Human:
    Villain and Hero can be Human, but, Human can only be Human
    ArrayList<Human> can store objects from all 3 classes

    if ( humanObject instanceof Villain )
    ((Hero) humanObject).doSomething();

# <<< Record >>> #

    Automatically creates: var fields, constructor, getters, toString, hashCode, and equals

    public record RecordName (String name, int id) {}

# <<< Enum >>> #

    Give a name to integers
    "List of" public static final int

    public enum EnumName { NUM1, NUM2, ...;}

# <<< Annotation >>> #

    - ...

# <<< Sorting and Searching >>> #

    # <<< Sorting Array >>> #

        Arrays.sort(arr, );

    # <<< Linear Search >>> #

        Iterate over all values until find target

    # <<< Binary Search >>> #

        low=0, high=size-1, while(low <= high), mid=(low+high) / 2

    # <<< Selection Sort >>> #

        Find the smallest value and swap

    # <<< Insertion Sort >>> #

        Insert value and swap until the correct place

    # <<< Merge Sort >>> #

        MergeSort(arr[], l,  r);      if l<r;     merge(arr[], l, m, r);
        Break everything, then merge sorting at the same time

    # <<< Quick Sort >>> # 111

        QuickSort(arr[], l,  r);      if l<r;     partition(arr[], l, r) {returns r's new index};
        Break moving all numbers less than r to r's left and the rest to r's right, but only r is 100% at the correct place
        Because r is already sorted after partition, QS(arr, l, r-1) || QS(arr, l ,r+1)

    # <<< HeapSort >>> #

        "Heapify" Array, then Transform it into a Max Heap.
        Max Heap: The parent node must always be greater than or equal to the child nodes.
        Swap root node with the last node, and delete the last node from the heap.
        Process visualization ~= "REVERSE SELECTION SORT".
        If the parent node is stored at index I, the left child can be calculated by 2 * I + 1,
        and the right child by 2 * I + 2 (assuming the indexing starts at 0).

    # <<< BubbleSort >>> #

        Iterate swapping couples until NO SWAPS/SORTED, each Iteration the last index will be sorted.
        [3,2,1] ->      [2,1,3]        -> [1,2,3]  -> [1,2,3] -> [1,2,3]
        Start   | swap(3,2), swap(3,1) | swap(2,1) | NO SWAPS  | End

# <<< Comparing >>> #

    Collections.sort();             - Works with objects which implement Comparable or Comparator interfaces
    Reverse sort                    - Collections.sort( list, Collections.reverseOrder() );
    Reverse order                   - Collections.reverse( list );
    shuffle                         - Random order
    implements Comparable<...>      - public int compareTo ( SomeObject other )
                     <SomeObject>   - { this."".get""()    compared to    other."".get""() }
                                    - Use this inside the SomeObject class
                                    - Collections.sort( List<SomeObject> );

    implements Comparator<...>      - public int compare ( SomeObject so1, SomeObject so2 )
                     <SomeObject>   - { so1."".get""()    compared to    so2."".get""() }
                                    - Use this inside an instance comparator class e.g.
                                    - NameComparator, AgeComparator, PowerComparator, ...
                                    - Collections.sort( List<SomeObject>, new NameComparator() );

# <<< Generic >>> #

    class ClassName<E>          - E is generic
                                - It can be Integer, String, Boolean, ...
    class ClassName<E1, E2>     - Like map<String, Integer>
    e.g.                        - ClassName<Integer> cnInt = new ClassName<Integer>();

# <<< Throw >>> #

    Throw Exceptions    - throw new Exception("...String...");
                        - Some Exceptions need      - public void myMethod() throws ExceptionName {}
                        - You also may need to create a custom exception to throw.

    Throw Errors        - throw new Error("...String...");

# <<< Testing >>> #

    Unit Testing
    JUnit
    Black Box Testing       - User, who doesn't know how to use the program.
    Clear Box Testing       - You the programmer, who knows how to use the program.

# <<< DataStructures+ >>> #

    # <<< LinkedList >>> #

        Divided in nodes(NodeClass)
        Singly Linked: head -> data-next -> ... -> data-next
        Doubly Linked: head -> prev-data-next <-> ... <-> prev-data-next <- tail
        Head and Tail are created in the LinkedListClass and only have next and prev val.

    # <<< Trees >>> #

        Trees           - x Parents -> y Children

        Binary Tree     - 1 Parent -> 2 Children

                                       A
                                   B       C
                                D     E F     G

        Tree Searches
        Traversals:
            - Pre-Order, Post-Order, In-Order,  Level-Order(First in, First out)(Breadth-first search)
            - (ABDECFG)  (DEBFGCA)   (DBEAFCG)  (ABCDEFG)
            - [You        Left        Left ]    List.add(A) -> List.remove(A) -> List.add(B), List.add(C)
            - [Left       Right       You  ]    List.remove(B) -> List.add(D), List.add(E)
            - [Right      You         Right]    List.remove(C) -> List.add(F), List.add(G)
            - Visit order recursion             List.remove(D) ...(E) ...(F) ...(G)

        Binary Search Tree      - public class BST<E extends Comparable<? super E>>
                                - ^ With this you can use "E value".compareTo
                                - Saves your time avoiding ((String/Integer) value).compareTo(...)

                                       D
                                   B       F
                                A     C E     G

        Important operations    - Search, Add, Remove


        Tries           - Tree of HashMaps          - Object/data e.g. \/
        First level     - String word = '', isWord = false, HashMap = {a-z}
        Second level    - String word = 'a', isWord = true, HashMap = {a-z}
        ...
        Important operations    - Search, Add, Remove   - Auto Complete uses Level-Order traversals

    # <<< Tables >>> #

        HashTables
            - key -> hashFunction -> hashCode   - hashCode == index -> data
            - Common function: mod n    - mod = %, it returns the remainder
            - Resize when the table is 70% full. New table, new hashFunction, insert old keys/values

            Collisions:
                - data can be a list containing all values from different keys which generated the same hashCode (Separate chaining)

        HashMap<SomeObject, ...>
            - When utilizing a custom object as key of hashMap, some changes are important
            - Write the method:     - public int hashCode() { return hashCode }
            - Write the method:     - public boolean equals(Object o) {}
            - If you do not create this method, the HashMap will use the object's memory pointer
            - Need to be creative with the hashCode solution
            - return Objects.hash(name, age);   - age and name are final

    # <<< Graph >>> #

        Graph       -
        Vertex:     - node / object             - V
        Edge:       - link between vertices     - E
                    - Undirected                - V <-E-> V
                    - Directed                  - V --E-> V
                    - Edges can have/carry more info            - e.g. cost of traversing it

        Basic operations    - Add vertex, add edge, get neighbors, display vertex.

        Matrix vs List
        Matrix:
            - Fast to add, remove and test edges
            - Slow to add and remove vertex             - Requires a lot of memory
            - Size = V²
        List:
            - Easy to add, remove edges and vertex      - Uses less memory than matrix
            - Size = V + E


        Using matrix:
            - int[v][v] adjMatrix;
            - The keys for columns and lines represent the vertex
            - The value, 0 or 1, represents if there is an edge from a to b, considering adjMatrix[a][b]
        Adding vertex:
            - if (v >= adjMatrix.length)        - Copy current matrix into a bigger one
            - int[][] newAdjMatrix = new int[v*2][v*2];


        Using list:
            - Map<Integer, ArrayList<Integer>> adjListsMap;
            -                   or
            - Map<Location/Id, VertexClass> adjListsMap;


        Depth-first Search:
            - Stack (LIFO)              - HashSet           - HashMap       - Can use Recursion
            - Where to search next      - Visited nodes     - Path walked   - DSF(S, G, visited, parents)
        Breath-first Search:
            - Queue (FIFO)              - HashSet           - HashMap
            - Where to search next      - Visited nodes     - Path walked
        Dijkstra's Algorithm:
            - Heaps (Priority Queue)    - HashSet           - HashMap       - Current cost/priority
            - Where to search next      - Visited nodes     - Path walked   - Current biggest priority
        A* search:
            - Same as Dijkstra, however, while Dijkstra's priority = distance from start to curr
            - A*'s priority = distance from start to curr +++ distance from curr to end


        unweighted graph        - Edges have no cost        - Good with Breath-first Search
        weighted graph          - Edges have cost           - Works with Dijkstra       - Good with A*
        Priority Queue          - {element, priority}


        Traveling Salesperson Problem (TSP):
            - Visit all nodes from Start to Start choosing the shortest path/cost
        2-Opt Heuristic:
            - Make small random changes (swap 2 edges, making a new route) -> Check if it is better (save or discard) -> repeat process in saved route as necessary.
        Hamiltonian Graph:
            - When it is possible to visit all the vertex in the graph exactly once from Start to End
        Eulerian Graph:
            - When it is possible to visit all the edges in the graph exactly once from Start to End, vertex can be repeated
            - For a graph to be Eulerian, no more than two vertex can have odd num of edges


        Strongly connected components (SCC)?
            - Basically a list of circuits/circles
            - BFS, invert edges, BFS


        Graph Bonus
        # In-degree:    num of edges ending here
        # Out-degree:   num of edges starting here
        # Degree:       sum of in and out degrees
        # n(n-1), (n(n-1))/2
        # P -> NP -> NP-Complete -> NP-Hard
        # Suggested structure:      adjList -> VertexClass -> EdgeClass -> LocationClass        - MapValue for A*


# <<< Serialization >>> #

    It is the process of converting an object into a byte stream.
    Persists (saves the state) the object after the program exits.
    This byte stream can be saved as a file or sent over a network. Can be sent to a different machine.
    The byte stream can be saved as a file (.ser) which is platform-independent.

    import java.io.Serializable;

    public class Human implements Serializable {
        ...
        private static final long serialVersionUID = ...;
        ...
    }

    import java.io.*;

    public static void main(String[] args) {
        ...
        Human myHuman = new Human(...);
        ...
        FileOutputStream fileOut = new FileOutputStream( "my_file_path.ser" );
        ObjectOutputStream out = new ObjectOutputStream( fileOut );
        out.writeObject( myHuman );
        out.close();
        fileOut.close();
    }

    !!!
        1. child classes of a parent class that implements Serializable will do so as well
        2. static fields are not serialized (they belong to the class, not to the object)
        3. the class's definition (Java Class File) itself is not recorded
            - You need the implementation of Human in both programs
        4. fields declared as transient are not serialized, e.g.
            - private transient String name;                                    - Will be ignored
        5. serialVersionUID is a unique version ID for a class that is serializable
            - Prevents casts to wrong or outdated objects
    !!!

# <<< Deserialization >>> #

    It is the process of converting a byte stream to an object

    import java.io.Serializable;

    public class Human implements Serializable {
        ...
        private static final long serialVersionUID = ...;
        ...
    }

    import java.io.*;

    public static void main(String[] args) {
        ...
        Human myHuman = null;
        ...
        FileInputStream fileIn = new FileInputStream( "my_file_path.ser" );
        ObjectInputStream in = new ObjectInputStream( fileIn );
        myHuman = (Human) in.readObject();
        in.close();
        fileIn.close();
    }

# <<< Thread >>> #

    Each thread can execute parts of your code in parallel with the main thread.
    Each thread has its own priority,
    threads with higher priority are executed in preference compared to threads with lower priority.

    The Java Virtual Machine continues to execute threads until either of the following occurs:
        1. The exit method of class Runtime has been called
        2. All user threads have died

    When the JVM starts up there is a thread that calls the main method.
    This thread is called "main".

    Daemon thread is a low-priority thread that runs in the background,
    to perform tasks such as garbage collection.
    JVM terminates itself when all user thread (non-daemon thread) finish their execution,
    ignoring daemon threads that are still running.

    Thread.activeCount()                    - How many threads are currently running
    Thread.currentThread()                  -
    Thread.currentThread().getName()        - This thread name
    Thread.currentThread().setName("...")   -
    Thread.currentThread().getPriority()    - The higher the number the higher the priority is
    Thread.currentThread().serPriority(x)   - x can be any integer from 1 to 10
    Thread.currentThread().isAlive()        -

    Thread.sleep(x)                         - x is in milliseconds


    public class MyThread extends Thread {
        @Override
        public void run() {
            ...
        }
    }

    public static void main(String[] args) {
        ...
        MyThread thread2 = new MyThread();

        thread2.setDaemon(true);            - Make thread daemon
        thread2.isDaemon();                 - check if daemon

        thread2.start();                    - Executes run() + starts thread
    }

# <<< Multithreading >>> #

    Threads are independent, they do not affect the execution of other threads.
    An exception in one thread will not interrupt other threads.
    Useful for serving multiple clients, multiplayer games, or other mutually independent tasks.

    public class MyThread extends Thread {
        @Override
        public void run() {
            ...
        }
    }

    --- or ---

    public class MyRunnable implements Runnable {           - Used more than "extends Thread"
        @Override                                           - Because it can inherit another class
        public void run() {
            ...
        }
    }

    --- ---

    public static void main(String[] args) {
        ...
        MyThread thread1 = new MyThread();

        MyRunnable runnable1 = new MyRunnable();
        Thread thread2 = new Thread(runnable1);

        thread1.start();
        thread2.start();

        thread1.join();
        thread2.join();
    }

# <<< Run Java With Command Prompt >>> #

    1. Java JDK installed
    2. Save the program as .java
    3. Open Command Prompt
  ? 4. set path=C:\...\jdk-...\bin ?
    5. cd to the .java file's directory
    6. javac MyProgramName.java                 - Creates a .class file
    7. java MyProgramName                       - Executes .class file

# <<< Create an executable jar >>> #

    # <<< Eclipse IDE >>> #

        1. Right-click the project folder inside Eclipse IDE
        2. Export
        3. >Java
        4. >Runnable JAR file
        5. Launch Configuration: Make sure that this is set to the main class of your program
        6. Export Destination: Choose the destination folder
        7. Finish

    # <<< IntelliJ >>> #

        1. File
        2. Project Settings
        3. Artifacts
        4. >+ (click on the plus button)
        5. >JAR
        6. >From modules with dependencies...
        7. Find main class
        8. OK
        9. (OPTIONAL) OutPut directory: Choose the destination folder
       10. Apply
       11. OK
       12. Build
       13. >Build Artifacts
       14. >ProjectName
       15. >Build

# <<< Others >>> #

    System.exit(num)    - num == 0 for success      - num > 0 for failure

    System.nanoTime()   - (endTime - startTime);  //divide by 1000000 to get milliseconds.










# <<< Java Bonus >>> #

    i = i++               - Doesn't work
    catch(Exception e)    - Doesn't catch Errors, only exceptions
    Scanner               - Remember scanner.close();

# <<< Programing Bonus >>> #

    Queue                 - First in, First out
    Stack                 - Last in, First out
    Heap                  - Priority Queue            - {element, priority}
    If you cannot solve a problem with small combinations of data structures(one or two nested) such as list, set, map, and array or map of lists. Create a new object!
    mid = (low+high) / 2;          SAME AS          mid = low + (high - low) / 2;

# <<< Java Dic >>> #

    Method            -
    Field             -
    Instance          -

# <<< Important Libraries >>> #

    Util            - Core data structures
    IO              - File handling
    Math            - Math handling
    Scanner         - Input handling
    Random          - Random                    - https://docs.oracle.com/javase/8/docs/api/java/util/Random.html
    Random          - Secure Random             - https://docs.oracle.com/javase/8/docs/api/java/security/SecureRandom.html
    Collections     -
    Objects         -

# <<< Books >>> #

    Computers and Intractability
