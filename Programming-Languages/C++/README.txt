# <<< C++ CORE >>> #

    #include <...>                              - Important library or header
    #include <iostream>
    using namespace std;                        - Avoid typing std:: for everything
    using std::string, std::cout, ...;          - Avoid typing std:: for some

    int main(int argc, char** argv) {}
    int main(int argc, char*  argv[]) {}        - Program start
                                                - argc: Number of inputs + 1 (program name)
                                                - argv: Array of programs inputs        - e.g. File names

    # <<< C++ INPUT / OUTPUT >>> #

        std     - Standard
        cout    - Output
        <<      - Insertion Operator (Passes data to || Concatenate(+) )

        cin     - Input
        >>      - Extraction Operator

        std::cout << "Hello " << "World";           - Print
        std::cout << "Hello World\n";               - Print + \n
        std::cout << "Hello World" << std::endl;    - Print + \n + flushes the output buffer
                                                    - Use endl only of terminal output; Never for files.

        std::cin >> declaredVariable;               - Considers any white spaces as terminating characters
        std::cin >> dV1 >> dV2 >> ...;              - Get more than one input;  - Each separated by a white space in the same line

        # <<< GET LINE >>> #

            cin.getline(str, n);
            
            OR
            
            #include <string>
            <>  std::getline(std::cin, declaredString);     - Does not stop at white spaces
                                                            - Only works with string

        # <<< !! cin SECURE UTILIZATION !! >>> #

            ! cin is can fail, so it is important to check if it is still working after calling it !

            if (cin.fail()) {
                cin.clear();
                cin.ignore(10000, '\n');
            }

        # <<< C INPUT / OUTPUT / %... >>> #

            !! THIS IS FROM C FORMATTED !!

            # <<< !! COERCION !! >>> #

                The compiler does not coerce the value,
                therefore a wrong conversion specifier will not work properly.

            #include <stdio.h>                  - Standard input and output

            # <<< OUTPUT printf() >>> #

                printf() - formatted

                printf(format, expression);

                printf("...");                  - Output text
                printf("...", ..., ...);        - Output text + variable value
                                                - Use conversion specifiers
                                                - Return number of chars printed

                # <<< CONVERSION CONTROL >>> #

                    The general form of a conversion specification is:

                    % [flags] [width] [. precision size] conversion_character

                    printf("%-20.10s", str);    - left align + 20 spaces + only 10 chars
                    printf("%020.10s", str);    - right align + fill with 0 + 20 spaces + only 10 chars


                    The five control characters are:

                    - flags
                        Prescribes left justification of the converted value in its field
                        0 pads the field width with leading zeros

                    - width 
                        sets the minimum field width within which to format the value
                        (overriding with a wider field only if necessary).
                        Pads the converted value on the left (or right, for left alignment).
                        The padding character is space or 0 if the padding flag is on

                    - .
                        separates the field's width from the field's precision

                    - precision
                        sets the number of digits to be printed after the decimal point for f
                        conversions and the minimum number of digits to be printed for an integer
                        (adding leading zeros if necessary). A value of 0 suppresses the printing
                        of the decimal point in an f conversion

                    - size
                        identifies the size of the type being output

                    For integer values:

                        Size Specifier | Convert to Type
                        ---------------|------------------
                            -none-	   |     int
                            hh	       |     char
                            h	       |     short
                            l	       |     long
                            ll	       |     long long

                    For floating-point values:

                        Size Specifier | Convert to Type
                        ---------------|------------------
                            -none-	   |     float
                            l	       |     double
                            L	       |     long double

                # <<< SPECIAL CHAR >>> #

                    printf("\\ \' \" %%\n");        - Output:       \ ' " %

            # <<< OUTPUT putchar() >>> #

                putchar() - unformatted

                putchar(char)           - Sends a single char to the output buffer
                                        - Return character sent
                                        - Or EOF if an error occurs

            # <<< INPUT scanf() >>> #
            
                scanf() - formatted input

                scanf(format, address);

                scanf("...", &..., &...);       - Input capture
                                                - Unsafe method
                                                - Input capture is separated by whitespace
                                                - #define _CRT_SECURE_NO_WARNINGS

                # <<< CONVERSION CONTROL >>> #

                    We may insert control characters between the % and the conversion character.
                    The general form of a conversion specification is

                    % [*] [width] [size] conversion_character

                    The three control characters are:

                    *       - suppresses storage of the converted data (discards it without storing it)
                    width   - specifies the maximum number of characters to be interpreted
                    size    - specifies the size of the storage type


                    For integer values:

                        Size Specifier | Convert to Type
                        ---------------|------------------
                            -none-	   |     int
                            hh	       |     char
                            h	       |     short
                            l	       |     long
                            ll	       |     long long

                    For floating-point values:

                        Size Specifier | Convert to Type
                        ---------------|------------------
                            -none-	   |     float
                            l	       |     double
                            L	       |     long double

                    A conversion specifier that includes an * does not have a corresponding address
                    in the argument list. This is an exception to the matching
                    conversion-specifier/argument rule.

                # <<< RETURN VALUE >>> #
                
                    scanf() returns either the number of addresses successfully filled or EOF.
                    A return value of:

                        - 0 indicates that scanf() did not fill any address
                        - 1 indicates that scanf() filled the first address successfully
                        - 2 indicates that scanf() filled the first and second addresses successfully
                        - EOF indicates that scanf() did not fill any address AND encountered an end of data character
                    
                    The return code from scanf() does not reflect success of %* conversions or
                    any successful reading of plain characters in the format string.

                    For more info read "PLAIN CHAR" in "THEORY".

                # <<< !!! VALIDATION !!! >>> #

                    Check "VALIDATION" in "THEORY" for more info.

                    # <<< PRE MADE >>> #

                        /* Robust Input Validation
                        *  getInt.c
                        */

                        #include <stdio.h>
                        #define MIN 3
                        #define MAX 15

                        int getInt(int min, int max);
                        void clear(void);

                        int main(void)
                        {
                            int input;

                            input = getInt(MIN, MAX);
                            printf("\nProgram accepted %d\n", input);

                            return 0;
                        }

                        // getInt accepts an int between min and max
                        // inclusive, returns the value of the int accepted
                        //
                        int getInt(int min, int max)
                        {
                            int value, keepTrying = 1, rc;
                            char after;

                            do {
                                printf("Enter an integer in range [%d,%d] : ", min, max);
                                rc = scanf("%d%c", &value, &after);

                                if (rc == 0)
                                {
                                    printf("**Bad char(s)!**\n");
                                    clear();
                                }
                                else if (after != '\n')
                                {
                                    printf("**Trail char(s)!**\n");
                                    clear();
                                }
                                else if (value < min || value > max)
                                {
                                    printf("**Out of range!**\n");
                                }
                                else
                                {
                                    keepTrying = 0;
                                }
                            } while (keepTrying == 1);

                            return value;
                        }

                        // clear empties the input buffer
                        //
                        void clear(void)
                        {
                            while (getchar() != '\n')
                            {
                                ;  // empty statement intentional
                            }
                        }

                # <<< PROBLEMS WITH %c >>> # 

                    !!! We use " %c" with a extra space so it flushes the buffer. !!!
                    !!! Use the getchar() loop to clear the buffer after scanf(). !!!

                # <<< ADVANCED >>> #

                    !!! %[...] != %[^...] !!!

                    %s  - whitespace delimited set
                    %[] - rule delimited set

                    scanf("%s", str);               - until whitespace
                    scanf("%10s", str);             - no more than 10 chars + until whitespace
                    scanf("%[^\n]", str);           - until new line
                    scanf("%10[^\n]", str);         - until new line + no more than 10 chars

                    # <<< %s >>> #

                        The corresponding argument for these specifiers is the address of
                        the string to be populated from the input stream.

                        - reads all characters until the first whitespace character
                        - stores the characters read in the char array identified by the corresponding argument
                        - stores the null terminator in the char array after accepting the last character
                        - leaves the delimiting whitespace character and any subsequent characters in the input buffer

                    # <<< %[] >>> #

                        The %[] conversion specifier accepts input consisting only of a set of
                        pre-selected characters. The brackets contain the admissible and/or
                        inadmissible characters. The symbol ^ prefaces the list of inadmissible
                        characters. The symbol - identifies a range of characters in an inclusive set.

                        - reads all characters until the newline ('\n')
                        - stores the characters read in the char array identified by the corresponding argument
                        - stores the null terminator in the char array after accepting the last character
                        - leaves the delimiting character ('\n') in the input buffer

            # <<< INPUT getchar() >>> #

                getchar() - unformatted input
            
                # <<< CLEARING BUFFER >>> #

                    // Empties the input buffer
                    //
                    void clear(void)
                    {
                        while (getchar() != '\n')
                        {
                            ;  // empty statement intentional
                        }
                    }

                # <<< PAUSE EXECUTION >>> #

                    // pause execution
                    //
                    void pause_(void)
                    {
                        printf("Press enter to continue ...");
                        while (getchar() != '\n')
                        {
                            ;  // empty statement intentional
                        }
                    }

                char c = getchar()          - getchar retrieves the next unread character
                                            - from the input buffer.
                                            - !! RETURNS char OR EOF (-1) !!
                                            - !! EOF is when user KILLS the process !!
                                            - Works better in a loop with (c != '\n') as flag.
                
                while ((c = getchar()) != '\n') {...}

                # <<< !!! VALIDATION !!! >>> #

                    Check "VALIDATION" in "THEORY" for more info.

            # <<< CONVERSION SPECIFIER >>> #

                %d          |   Integer                 |   char, int, short, long, long long
                %c          |   Char                    |   char
                            |                           |
                %f          |   Float                   |   float, double, long double
                %lf         |   Double                  |   float, double, long double
                            |                           |
                %s          |   String                  |   char string
                %x          |   Address/hexadecimal     |   char, int, short, long, long long
                %o	        |   Octal                   |   char, int, short, long, long long
                            |                           |
                %g	        |   general                 |   float, double, long double
                %e	        |   exponential             |   float, double, long double

            # <<< ADVANCED >>> #

                # <<< OUTPUT fprintf() >>> #

                    Same as printf, but it allows to choose the destination

                    int fprintf(stdout, format, ...);
                    int fprintf(FILE*, format, ...);

                    returns number of characters written.

                # <<< OUTPUT puts() >>> #

                    Writes a string to stdout up to but not including the null character.

                    int puts(const char *str)

                # <<< OUTPUT fputs() >>> #

                    Same as puts, but it allows to choose the destination

                    int fputs(str, stdout);
                    int fputs(str, FILE*);

                # <<< INPUT fscanf() >>> #

                    Same as scanf, but it allows to choose the source

                    int fscanf(stdin, format, address);
                    int fscanf(FILE*, format, address);

                    returns the number of successful conversions.

                # <<< INPUT gets() >>> #

                    Reads a line from stdin and stores it into the string pointed to by str
                    until newline or EOF is reached.

                    char *gets(char *str)

                # <<< INPUT fgets() >>> #

                    Same as gets, but it allows to choose the source

                    char *gets(stdin, char *str);
                    char *gets(FILE*, char *str);

            # <<< OLD EXAMPLES >>> #

                # <<< input PRE-BUILT, getchar() >>> #

                    int input(char str[], int size) {
                        int c, i{0};
                        while ((c = getchar()) != '\n') {       - getchar()
                            if (i < size) {                         - asks:    User line input
                                str[i++] = c;                       - returns: Each char ASCII value
                            }                                       -          Each iteration
                        }
                        str[i] = '\0';
                        return i;
                    }

                # <<< putchar() >>> #

                    for (size_t i = 'a'; i <= 'z'; i++) {       - putchar()
                        putchar(i);                                 - Transforms int into char and prints it
                    }

    //          - Comment line
    /* */       - Comment lines
    /** */      - C++ Doc

    # <<< C++ TYPES >>> #

        CORE C++ TYPE       |           MEANING         |           MINIMUM SIZE                |       Precision
        bool                |           boolean         |           8  bits     (1 byte)        |       100%
        --------------------|---------------------------|---------------------------------------|-----------------------------
        char                |           character       |           8  bits     (1 byte)        |       100%
        wchar_t             |      wide character       |           16 bits     (2 bytes)       |       100%
        char16_t            |   Unicode character       |           16 bits     (2 bytes)       |       100%
        char32_t            |   Unicode character       |           32 bits     (4 bytes)       |       100%
        --------------------|---------------------------|---------------------------------------|-----------------------------
        short               |     short integer         |           16 bits     (2 bytes)       |       100%
        int                 |           integer         |           32 bits     (4 bytes)       |       100%
        long                |      long integer         |           32 bits     (4 bytes)       |       100%
        long long           |      long integer         |           64 bits     (8 bytes)       |       100%
        --------------------|---------------------------|---------------------------------------|-----------------------------
        float         (f)   |   single-precision float  |           32 bits     (4 bytes)       |   6  significant digits
        double              |   double-precision float  |           64 bits     (8 bytes)       |   10 significant digits
        long double   (L)   | extended-precision float  |           128 bits    (16 bytes)      |   10 significant digits
        
        Floats              - NaN, (+/-)infinity

        -------------------------------------------------------------------------------------
        LIB C++ TYPE        |           MEANING         |       MINIMUM SIZE
        std::string         |           string          |           ?

    # <<< C++ INITIALIZATION >>> #

        int x = 2;  // A        - Copy initialization
        int y (2);  // B        - Direct initialization
        int y {2};  // C        - Direct List initialization

        A and B allow initializing with a narrowing conversion
        C allows only non-narrowing conversion (Can detect unintentional narrowing)

        int y = 0, z = 4;       - Multiple initialization

    unsigned int    - Only positive numbers             - Can store bigger numbers than signed
    signed int      - Positive and negative numbers     - Can store numbers half the size of unsigned
                    - Works with Integer core family

    auto            - The compiler deduces the type/Object      - Can use suffixes  e.g.  132ul

    # <<< C++ LITERAL SUFFIXES >>> #

        INTEGER     |
        ------------------------------------
        'c'         |   char
        l/L         |   long
        ll/LL       |   long long
        u           |   unsigned
        ul          |   unsigned long
        ull         |   unsigned long long


        float       |
        ------------------------------------
        f           |   float
        L           |   long double

    # <<< C++ decltype, typeid >>> #
    
        decltype                            - The compiler deduces the type/Object, 
                                            - but not initialize it

        decltype( myFunc() ) NAME = x;      - Compiler does not call myFunc()
                                            - It uses the type that myFunc would return and,
                                            - gives NAME the same type

        decltype( myVar ) NAME = x;         - Gives NAME myVar's type


        typeid(11).name();      - returns i
        typeid(11.22).name();   - returns d
        typeid('a').name();     - returns c
        typeid("aaa").name();   - returns A4_c

    # <<< C++ CONVERSIONS / CASTING >>> $

        int x = static_cast<int>(c)     - Core conversions
        auto x = (int) (char) ...       - Core conversions
        int x = std::stoi(str);         - std::string -> int
        float f = std::stof(str);       - std::string -> float
        double d = std::stod(str);      - std::string -> double
        string s = std::to_string(num); - int/double -> string

        # <<< C++ ..._cast >>> #

            # <<< static_cast >>> #

                This takes the pointer in ptr and tries to safely cast it to a pointer of type Type*.
                This cast is done at compile time.
                It will only perform the cast if the types are related.
                If the types are not related, you will get a compiler error.

                static_casting a pointer to and from void* preserves the address.
                That is, in the following, a, b and c all point to the same address:

                int* a = new int();
                void* b = static_cast<void*>(a);
                int* c = static_cast<int*>(b);

            # <<< reinterpret_cast >>> #

                reinterpret_cast only guarantees that if you cast a pointer to a different type,
                and then reinterpret_cast it back to the original type, you get the original value.
                So in the following:

                int* a = new int();
                void* b = reinterpret_cast<void*>(a);
                int* c = reinterpret_cast<int*>(b);

                a and c contain the same value, but the value of b is unspecified.
                (in practice it will typically contain the same address as a and c,
                but that's not specified in the standard,
                and it may not be true on machines with more complex memory systems.)

                For casting to and from void*, static_cast should be preferred.

            # <<< dynamic_cast >>> #

                This tries to take the pointer in ptr and safely cast it to a pointer of type Type*.
                But this cast is executed at runtime, not compile time. Because this is a run-time cast,
                it is useful especially when combined with polymorphic classes.
                In fact, in certain cases the classes must be polymorphic in order for the cast to be legal.

                Casts can go in one of two directions:
                from base to derived = (B2D)
                from derived to base = (D2B)

        #include <sstream>
        <>  string -> bool                  - std::istringstream("1") >> bool;
        <>  string -> bool                  - std::istringstream("true") >> std::boolalpha >> bool;

    # <<< C++ OPERATORS >>> #

        Math Operators                  - (+, -, *, /, %)
        Increment Operators             - (++, --, +=, -=, *=, /=, %=)
        Relational Operators            - (==, !=, >, >=, <, <=)
        Logical Operators               - (||, &&, !)                       - (false && ... anything after is not evaluated)
                                                                            - (true  || ... anything after is not evaluated)

    # <<< C++ ARRAYS >>> #

        Array               - type name[SIZE] {...};                        - SIZE must be const
        2D-Array            - type name[SIZE][SIZE];
        size                - std::size(array);
        old size            - ( sizeof(array) / sizeof(array[0]) );

        Array of Pointers   - type* name[SIZE];                             - & pointing to type

        # <<< MULTIDIMENSIONAL ARRAYS >>> #

            Array           - {1, 2, 3, 4, 5}                   ( [...] )

            2D-Array        - {
                            -     {1, 2, 3, 4, 5},              ( [0][...] )
                            -     {1, 2, 3, 4, 5},              ( [1][...] )
                            -     {1, 2, 3, 4, 5}               ( [2][...] )
                            - }

            3D-Array        - {
                            -     {
                            -         {1, 2, 3, 4, 5},          ( [0][0][...] )
                            -         {1, 2, 3, 4, 5},          ( [0][1][...] )
                            -         {1, 2, 3, 4, 5}           ( [0][2][...] )
                            -     },
                            -     {
                            -         {1, 2, 3, 4, 5},          ( [1][0][...] )
                            -         {1, 2, 3, 4, 5},          ( [1][1][...] )
                            -         {1, 2, 3, 4, 5}           ( [1][2][...] )
                            -     },
                            -     {
                            -         {1, 2, 3, 4, 5},          ( [2][0][...] )
                            -         {1, 2, 3, 4, 5},          ( [2][1][...] )
                            -         {1, 2, 3, 4, 5}           ( [2][2][...] )
                            -     }
                            - }

            # <<< MATRIX MULTIPLICATION >>> #

                int 2D_A[2][3];     { {0,1,2}, {3,4,5} }
                int 2D_B[3][2];     { {6,7}, {8,9}, {10,11} }

                2D_A [SIZE][] == 2D_B [][SIZE]          - Required
                2D_A [][SIZE] == 2D_B [SIZE][]          - Required

                2D_A * 2D_B   ==    2D_RES[2][2]    { {, }, {, } }
                                    - {
                                    -     {
                                    -         [0][0] == 0*6 + 1*8 + 2*10
                                    -         [0][1] == 0*7 + 1*9 + 2*11
                                    -     },
                                    -     {
                                    -         [1][0] == 3*6 + 4*8 + 5*10
                                    -         [1][1] == 3*7 + 4*9 + 5*11
                                    -     }
                                    - }

    # <<< C++ IF >>> #

        if                  - if(bool);
                            - if(bool), else;
                            - if(bool), else if(bool), else;
        ternary operator    - result = (condition) ? option1 : option2;

    # <<< C++ ITERATORS, FOR, FOR EACH >>> #

        Iterate over any data structure

        std::vector<int> vec = {1, 2, 3, 4, 5};
        using ScoreMap =                                        - Makes code more readable
            std::unordered_map<std::string, int>;
        ScoreMap map;
        ...

        for (size_t i = 0; i < vec.size(); i++)                 - For loop
                                                                - size_t == unsigned int

        for (const int& num : vec)                              - For each
        for (const auto& num : vec)                             - For each
        &                                   - use & to get the value instead of a pointer to the value

        for (auto kv : map)                                     - For each (return std::pair)
        {                                                       - Maps
            auto& key   = it.first;
            auto& value = it.second;
        }

        for (auto [key, value] : map)                           - Structure Binding
        {
            auto& key   = key;
            auto& value = value;
        }

        for (std::vector<int>::iterator it = vec.begin();       - Iterator operator
            it != vec.end(); it++)                              - Useful for some data structures
        {
            int currIteration = *it;
        }

        for (ScoreMap::iterator it = map.begin();               - Cleaner Iteration (using ScoreMap...)
            it != map.end(); it++)
        {
            auto& key   = it->first;
            auto& value = it->second;
        }

        # <<< Loop Bonus >>> #

            Char Iteration      - for (size_t i = (int)'a'; i <= (int)'z'; i++)    - [a to z]

            String to Char      - for (char c : my_text)

    # <<< C++ WHILE >>> #

        while           - Run only if
        do while        - Run at least once

    # <<< C++ SWITCH >>> #
    
        switch (var)    - case A: case B: {} break;
                        - case C ... D: {} break;
                        - default {}

    # <<< C++ FUNCTIONS >>> #

        Functions declaration       - returnType functionName(pType p, ...);
                                    - 
                                    - (use before main and implement after)
                                    -
        Functions definition        - returnType functionName(pType p, ...) { return; }
        or implementation


        Function parameters         - use(* or &)
        const int* ...              - avoid copying values
        const int& ...              - Use const for parameters that will not be modified
                                    - 
        int* ...                    - Modify parameters instead of returning them
        int& ...                    - 


        Overloading                 - Same method name, but different parameters


        Function return+            - return a struct
                                    - In order to return multiple values
                                    - (Less efficient than & or *)


        function return & or *      - !! Never return a * or & of a local stack variable !!
                                    - !! Because the memory address is delete at the end of the scope !!
            # <<< e.g. >>> #
                int* func() {
                    int num = 10;
                    return &num;
                }

                int main() {
                    int* x;

                    x = func();

                    // x == dangling pointer
                }
            #
                                    - Returns the object/variable itself, not a copy.
                                    - Useful for returning data from Data Structures,
                                    - which are declared outside this function,
                                    - and were passed as parameters.
                                    - e.g. Search Algorithm return

    continue        - Go to the next iteration of this loop, if there is one.
    break           - End the loop.
    return          - Exit the function + (Optional) return something.

    using MY_NAME = const int;          - Makes code more readable
    typedef unsigned int MY_NAME;       - MY_NAME var = 111;
                                        - 
    #define Test std::vector<int>       - Also works with Macros

# <<< C++ POINTER >>> #

    Direct   Addressing     - int x = 22;
                            - x is &x and stores 22
    Indirect Addressing     - int* a = &x;
                            - a is &a and stores &x which stores 22


    &       - Memory address
    *       - Pointer                           - int* a = &x           - a == &x; *a == x;
    **      - Pointer to a pointer              - int** aa = &a         - aa == &a; *aa == &x; **aa == x;
    ***     - ...
    int**   ->   int* address   ->   int address   ->   value


    nullptr == std::nullptr_t       - Implicitly convertible to any pointer type
                                    - Not convertible to int
                                    - 
    NULL == 0                       - Can cause ambiguity with int

    dangling / wild pointers        - Is a pointer which points to some non-existing memory location

        int* func() {
            int num = 10;
            return &num;
        }

        int main() {
            int* x;
            int* y;
            int* z = new int(55);

            x = func();
            delete z;

            // x == dangling pointer
            // y == dangling pointer
            // z == dangling pointer
        }


    # <<< C++ POINTER USES >>> #

        Dynamic memory      - In order to have full control of the memory lifetime use heap memory instead of stack memory
                            - Stack is faster than Heap, However Heap can ask the OS for more(Bigger) memory (May sign Bad code)
                            - int x {2}; is deleted in its scope end "}"
                            - int* x = new int {value}; is only deleted when the dev wants
        NULL                - TYPE* NAME {nullptr};
        Allocate            - NAME = new TYPE;
        Assign              - *NAME = value;
        Delete              - delete NAME;
        NULL                - NAME = nullptr;

        Pointer conversions - TYPE NAME = *NAME;
                            - TYPE* NAME = ((TYPE*) NAME);

        const int*          - Pointer cannot change its value, but can point to another memory address
        const int* const    - Pointer cannot change its value or point to another memory address
        int* const          - Pointer can change its value, but cannot point to another memory address

        sizeof              - Warning: sizeof is going to return the size of the pointer not the value

        void pointer        - void functionName(void* NAME, char NAME) {}
                            - void*: can point to any type
                            - char:  represents the type which void* is
                            - Cannot be dereferenced until casted
                            - Used for allocating memory (malloc and calloc)

        function return+    - Modifying functions parameter inside the function and returning the modified version
        using *             - void funcName(...Parameters..., TYPE* return1, TYPE* return2, ...) {}
        stack call          - funcName(..., &pp1, pp2, ...);     (int)         (int[])
        heap call           - funcName(..., pp1, pp2, ...);      (int*)        (int*[])
                            - (*return1) = x;
                            - ((*return2)[0]) = y;

        using &             - void funcName(...Parameters..., TYPE& return1, TYPE return2[], ...) {}
        stack call          - funcName(..., pp1, pp2, ...);      (int)        (int[])
        heap call           - funcName(..., *pp1, pp2, ...);     (int*)       (int*[])
                            - return1 = x;
                            - return2[0] = y;

        function pointers   - Stores the address of a function instead of a variable
        original func ex:   - int sum(int x, int y) {...}
        func pointer ex:    - int(*sumFuncPointer)(int, int) = sum;         - res = sumFuncPointer(2,2);
                            - Type - Pointer Name - Parameters - OFunc
        uses                - To pass a function as a parameter to another function
        e.g.                - customSort(vector<int>$ numVector, bool(*compareFuncPointer)(int, int)) {Linear Search}
                            - customSort(intVector, funcPointer)
                            - ascending and descending Linear Search in the same function
                            - 
        func ptr Array      - int (*operations[4])(int,int) = {sum, sub, div, mult};
        uses                - operations[choice](123,456);

        class pointers      - MOVE TO C++ CLASS SECTION

        ! Memory Leak !     - For every "new SOMETHING" there must be a "delete SOMETHING"

    # <<< C++ DYNAMIC ARRAYS >>> #

        Dynamic array       - Create/Change arrays during runtime
                            - Incompatible with for each and std::size()
        Get                 - array[x];                 - *(array + x);

        Creating            - TYPE* NAME = new int[SIZE] {...};
        Deleting            - delete[] NAME;
                            - NAME = nullptr;

        2D Dynamic array    - TYPE** arr2D = new TYPE*[SIZE];
        Creating            - arr2D[i] = new TYPE[SIZE];
                            - arr2D[i][k] = x;
        Deleting            - delete[] arr2D[i];
                            - delete[] arr2D;           - arr2D = nullptr;

        ! Memory Leak !     - For every "new SOMETHING" there must be a "delete SOMETHING"

    # <<< C++ SMART POINTERS >>> #

        #include<memory>
        <>  smart pointers  - Deallocates memory automatically
        <>                  - 
        <>  unique          - Deleted at the end of the scope                       - Cannot be shared
        <>  <> Make         - std::unique_ptr<TYPE> NAME = std::make_unique<TYPE>();
        <>  <> Move         - std::unique_ptr<TYPE> NAME2 = std::move(NAME);
        <>  <>                  - NAME == nullptr;
        <>  <>                  - NAME2 == NAME;
        <>  <> Swap         - NAME.swap(NAME2);
        <>  <>                  - NAME = NAME2;
        <>  <>                  - NAME2 = NAME;
        <>  <> Reset        - NAME.reset(new int {123});
        <>  <>                  - Call deleter;
        <>  <>                  - allocate a new int {123};
        <>  <>                  - NAME points to 123 memory address;
        <>  <> Reset        - NAME.reset(nullptr);
        <>  <>                  - Release and delete value;
        <>  <> Release      - NAME.release()
        <>  <>                  - CAN CAUSE MEMORY LEAK. --return must be deleted--
        <>  <>                  - return     == (Pointer / nullptr)
        <>  <>                  - NAME.get() == nullptr
        <>  <>                  - NAME       == nullptr
        <>                  - 
        <>  shared          - Deleted when the reference count(copies) hit 0        - Can be shared
        <>  <> Make         - std::shared_ptr<TYPE> NAME = std::make_shared<TYPE>();
        <>  <> Share        - std::shared_ptr<TYPE> NAME2 = NAME;
        <>  <> Copies       - NAME.use_count();
        <>  <> Is Unique    - NAME.unique();
        <>  <>                  - true if only one copy, else false;
        <>  <> Reset        - NAME.reset();
        <>  <>                  - Release
        <>                  - 
        <>  weak            - Does not increase the shared reference count
        <>  <> Make         - std::weak_ptr<TYPE> NAME = sharedNAME;
        <>  <> Expired      - NAME.expired();
        <>  <>                  - true if shared has not been deleted, else false;

# <<< C++ REFERENCE >>> #

    References(&)       - Same memory address, same value
                        - Useful in functions parameters and for each loops
    Original            - int x = 2;
    Reference           - int& reference_to_x = x;

    References vs Pointers
    References          - Don't use dereferencing for reading and writing
                        - Can't be changed to reference something else
                        - Must be initialized at declaration

    Pointers            - Must go through dereference operator to read and write
                        - Can be changed to point somewhere else
                        - Can be declared un-initialized

# <<< C++ CHAR, CHAR*, CHAR[] >>> #

    mutable                 - char message[] {'h', 'e', 'l', 'l', 'o', '\0'};
                            - char message[] {"hello"};
    immutable               - const char* message {"hello"};

    C Character Manipulation
    #include <cctype>
    char                - std::toupper(''); std::isalpha(''); std::isblank(''); ...
                        - cctype reference for more

    C String Manipulation
    #include <cstring>
    char[] and char*    - std::strlen(str1)             - Uninitialized size
                        - sizeof(str1)                  - Total size
                        - std::strcmp(str1, str2)       - compare 2 string      returns(1, 0, -1)
                        - std::strcpy(str1, str2)       - Copy
                        - std::strchr(str, target)      - find first            returns(pointer or nullptr)
                        - std::strrchr(str, target)     - find last             returns(pointer or nullptr)
                        - ++char*                       - moves one index
                        - cstring reference for more

# <<< C++ STRING >>> #

    <string>
    <>  std::string         - Have many C String functionalities + Easier to work with
    <>                      - string reference for more

    using namespace std::string_literals;
    <>
    <>  String Literals is const char*
    <>
    <>  std::string str = "Hello "s + "World";

    #include <string_view>
    <>  std::string_view    - When you only need to "look at the String" {char* + size}
                            - Pros: Memory efficient
    use 1                   - const char* name = "first last";
                            - std::string_view first_name(name, 5);
                            - std::string_view last_name(name + 6, 4);
    use 2                   - void func(std::string_view sv) {...}
    use 3                   - ClassName(std::string_view param, ...) {}
    # Using it for a function parameter or a local variable is normally fine.
    # But use extreme caution if you're using it as a data member or returning it from a function.

    # <<< C++ SMALL STRINGS >>> #

        main idea       - String are allocated in the heap, However,
                        - Strings that are not long does not need to be heap allocated
                        - std::string;

# <<< C++ LAMBDA >>> #

    lambda function
    lambda function signature = [capture list] (parameters) -> return type {
                                    //function body
                                }

    Without name / one use      - []() { std::cout << "Hello world" << "\n"; }();
    With parameters             - [](int x, int y) { std::cout << (x + y) << "\n"; }(2,2);
    With name / many uses       - auto func = []() -> void { std::cout << "Hello world" << "\n"; };
                                - func();
    With return                 - auto func = [](int x, int y) { return x + y; };
                                - int x = func(2,2);
    With Capture List           - double x = 2.2;
                                - int num = [x](double y) -> int { return x + y; }(3.1);
        # Using [x] creates a copy, while [&x] creates a reference.
        # X can be modified inside lambda using &
    Capture all variables by copy           - [=](...) -> void {...}(...);
    Capture all variables by reference      - [&](...) -> void {...}(...);

# <<< C++ TEMPLATE, GENERIC, BLUEPRINT, CONCEPTS >>> #

    Create Function or Class blueprint (~=GENERIC)

    # <<< C++ CLASS BLUEPRINT >>> #

            Go to    Creating Data Structures    SECTION

    # <<< C++ FUNCTION BLUEPRINT >>> #

    copy parameters             - template <typename T> T max(T a, T b) {
                                -     return (a > b) ? a : b;
                                - }
    reference Parameters        - template <typename T> const T& max(const T& a, const T& b) {
                                -     return (a > b) ? a : b;
                                - }

    Implicit (only one type)    - max(2,4);        max(1.11,3.33);        max("aa", "cc");
    Explicit (different types)  - max<double>(1.11, 4);        max<double>(2, 1.11);

    # <<< C++ TEMPLATE SPECIALIZATION >>> #

        Default / Generic       - template <typename T> T max(T a, T b);

        Specific                - template <> const char* max<const char*> (const char* a, const char* b);

    Core C++ Concepts       - A mechanism to place constraints on template type parameters
    Standard concepts       - https://en.cppreference.com/w/cpp/concepts
                            - https://en.cppreference.com/w/cpp/language/constraints
    #include <concepts>
    <>  Syntax 1            - template <typename T>
    <>                      - requires std::integral<T>
    <>                      - T max(T a, T b) {
    <>                      -     return (a > b) ? a : b;
    <>                      - }
    <>  Syntax 2            - template <std::integral T>
    <>                      - T max(T a, T b) {
    <>                      -     return (a > b) ? a : b;
    <>                      - }
    <>  Syntax 3            - auto max (std::integral auto a, std::integral auto b) {
    <>                      -     return (a > b) ? a : b;
    <>                      - }
    <>  Syntax 4            - template <typename T>
    <>                      - T max(T a, T b) requires std::integral<T>{
    <>                      -     return (a > b) ? a : b;
    <>                      - }
    COMBINING CONCEPTS
    <>  Syntax 1            - template <typename T>
    <>  (BAD)               - requires std::integral<T> (&& or ||)
    <>                      - requires (T a, T b) {
    <>                      -     requires sizeof(T) <= 4;
    <>                      - }
    <>                      - T max(T a, T b) {
    <>                      -     return (a > b) ? a : b;
    <>                      - }
    <>  Syntax 2            - template <typename T>
    <>  (GOOD)              - requires std::integral<T> (&& or ||)
    <>                      - TinyType<T>
    <>                      - T max(T a, T b) {
    <>                      -     return (a > b) ? a : b;
    <>                      - }
    MULTIPLE TYPES
    <>  Syntax 2.2          - template <typename T1, typename T2>
    <>                      - requires MyTest<T1, T2>
    <>                      - auto max(T1 a, T2 b) {
    <>                      -     return (a > b) ? a : b;
    <>                      - }

    Custom concepts         - Build your own concepts
    #include <concepts>
    SIMPLE REQUIREMENT      - ONLY checks that the syntax is correct (~No compiler error)
    <>  if both support *   - template <typename T>
    <>                      - concept Multipliable = requires(T a, T b) {
    <>                      -     a * b;  //  Just make sure the syntax is valid
    <>                      - };
    <>  Multiple tests      - template <typename T>
    <>                      - concept Incrementable = requires(T a) {
    <>                      -     a+=1;
    <>                      -     a++;
    <>                      -     ++a;
    <>                      - };
    NESTED REQUIREMENT      - Checks if the expression is true
    <>  std::integral ==    - template <typename T>
    <>                      - concept MyIntegral = std::is_integral_v<T>;
    <>                      - 
    <>  sizeof(T) <= 4      - template <typename T>
    <>                      - concept TinyType = requires(T) {
    <>                      -     sizeof(T) <=4;  //  Simple requirement : Only checks syntax
    <>                      -     requires sizeof(T) <= 4;  //  Nested requirement : checks if expression is true
    <>                      - };
    COMPOUND REQUIREMENT    - Checks if syntax is correct
                            - (Optional) If it does not throw exceptions
                            - (Optional) If the result is convertible to int
    <>  a + b               - template <typename T>
    <>                      - concept Addable = requires(T a, T b) {
    <>                      -     {a + b} noexcept -> std::convertible_to<int>;  //  Compound requirement
    <>                      - };

    Application         - Choose Syntax (1, 2, 3 or 4) and replace std::integral with MyIntegral
                        - Syntax 3 can be a more optimal choice.

    MULTIPLE TYPES          - 
    <>  T1 == int &&        - template <typename T1, T2>
    <>  T2 == float         - concept MyTest = requires(T1, T2) {
    <>                      -     requires std::is_integral_v<T1>;
    <>                      -     requires std::is_floating_point_v<T2>;
    <>                      - };
    Application             - Use Syntax (2.2)

    CONCEPTS FOR VARIABLES
    <>                      - std::integral auto x = func(...);

# <<< C++ TRY, ASSERT, EXCEPTION >>> #

    static_assert   - static_assert(boolean, message);

    try
    catch           - (std::exception &e) {e.what()}
    finally

    std::cerr       - Print errors to the console
    std::clog       - Print log messages to the console

    #include <stdexcept>
    <>
    <>  https://en.cppreference.com/w/cpp/error/exception
    <>
    <>  throw std::invalid_argument( "received negative value" );

# <<< C++ FILE MANIPULATION >>> #

    #include <fstream>
    <>  std::fstream myFile;
    <>  myFile.open("FILENAME.txt", std::ios::out);             - Write mode
    <>  myFile.open("FILENAME.txt", std::ios::app);             - Append mode
    <>  if (myFile.is_open()) {
    <>      myFile << "Hello\n";
    <>      myFile << "World\n";
    <>      myFile.close();
    <>  }
    <>  myFile.open("FILENAME.txt", std::ios::in);              - Read mode
    <>  if (myFile.is_open()) {
    <>      std::string line;
    <>      while (std::getline(myFile, line)) {
    <>          cout << line << endl;
    <>      }
    <>      myFile.close();
    <>   }

# <<< C++ CONTAINERS >>> #

    # <<< C++ ARRAY >>> #

        #include <array>            - "Safer array" Array
        Pros:                       - Stack Allocated
                                    - Contiguous memory
                                    - Useful methods such as .size()

        Cons:                       - Fix Size
                                    - Size defined at Compile Time

        # <<< INFO >>> #

            Type needs default constructor

            Insert at end           - O(1)
            Insert at begin         - O(n)      !!! MANUALLY !!!
            Access any              - O(1)
            Resize                  - O(n)      !!! MANUALLY !!!

        <>  Declaration             - std::array<TYPE, SIZE> NAME;
        <>  Init List               - NAME = {1, 2, 3, 4, 5, 6, ...};
        <>  Iterator                - for (std::array<int, 10>::iterator i = NAME.begin(); i != NAME.end(); ++i) { *i = something; }
        <>  Iterator + auto         - for (auto i = NAME.begin(); i != NAME.end(); ++i) { *i = something; }
        <>  Iterator for each       - for (auto& i : NAME) { i = something; }
        <>  #include <algorithm>
        <>  <>                      - std::fill(NAME.begin(), NAME.end(), something);

        <>  std::array as func parameter
        <>                          - template<std::size_t SIZE>
        <>                          - void printArray(std::array<int, SIZE>& arr) {
        <>                          -     for(const auto& num : arr) {
        <>                          -         std::cout << num << "\n";
        <>                          -     }
        <>                          - }
        <>  Call template           - printArray< array.size() >(array);

    # <<< C++ VECTOR >>> #

        #include <vector>           - ArrayList
        Pros:                       - Can grow in size
                                    - Contiguous memory

        Cons:                       - Heap Allocated

        # <<< INFO >>> #

            !!! Avoid pointing to a vector value (The memory address changes during resize) !!!

            Insert at end           - O(1)
            Insert at begin         - O(n)      !!! MANUALLY !!!
            Access any              - O(1)
            Resize                  - O(n) + Heap request

        <>  Declaration             - std::vector<TYPE> NAME;

        <>  Add                     - NAME.push_back(...);

        <>  Get                     - NAME[ INDEX ];
        <>                          - NAME.at( INDEX );
        <>  IMPORTANT (get)         - TYPE& aa = NAME[ INDEX ];
        <>                              - Use & to get the var instead of a copy

        <>  Size                    - NAME.size();
        <>  Remove                  - NAME.erase(  NAME.begin()  +  INDEX  );
        <>  Clear                   - NAME.clear();
        <>  Allocate space          - NAME.reserve( SIZE );
        <>  Make inside vector      - NAME.emplace_back( Parameters for the constructor of TYPE );
        <>                          - Instead of making outside and then copying into the vector(Add), just make inside(Make)


        <> Objects vs *             - Storing * make it faster to reallocate memory when vector grows in size
        <>                          - Storing Objects is faster to use + ? saves memory ?

    # <<< C++ LIST >>> #

        #include <list>             - Double Linked List
        Pros:                       - Value memory address does not change + .insert() == O(1)

        Cons:                       - Non contiguous memory
                                    - does not have [] .get() == O(n)
                                    - Heap allocated

        # <<< INFO >>> #

            Insert at end           - O(1)
            Insert at begin         - O(1)
            Access any              - O(n)
            Resize                  - O(1)

        <>  Declaration             - std::list<TYPE> NAME;

    # <<< C++ DEQUE >>> #

        #include <deque>            - Linked List of arrays
                                    - Instead of inserting individual data NODES
                                    - NODES are small arrays containing a few indexes

        Pros:                       - Almost array get, Almost list insert

        Cons:                       - Indexing cost is twice of an vector

        # <<< INFO >>> #

            Insert at end           - O(~1)
            Insert at begin         - O(~1)
            Access any              - O(~1)
            Resize                  - O(~1)

        <>  Declaration             - std::deque<TYPE> NAME;

    # <<< C++ TUPLE >>> #

        #include <tuple>            - Contains x amount of variables and does not care about the type
                                    - Useful for returning multiple values from a function
                                    - 
        <>  Declaration             - std::tuple< var1TYPE, var2TYPE, ... > NAME;
        <>  Get                     - std::get< INDEX >(NAME);
        <>  Structure Binding       - auto[name, age power] = NAME;

    # <<< C++ PAIR >>> #

        #include <pair>             - Same as tuple, However, it will always contain 2 variable
                                    - Useful for returning two values from a function
                                    - 
        <>  Declaration             - std::pair< var1TYPE, var2TYPE> NAME;
        <>  Get                     - NAME.first;
        <>                          - NAME.second;
        <>  Structure Binding       - auto[name, age] = NAME;

    # <<< C++ SET >>> #

        #include <set>              - Unique values + Sorted values
                                    - !!! Requires operator< !!!

        # <<< INFO >>> #

            Insert                  - O(1) + sorting
            Access any              - O(1)
            Contains                - O(log(n))
            Resize                  - O(1)

        <>  Declaration             - std::set<TYPE> NAME;

    # <<< C++ UNORDERED SET >>> #

        #include <unordered_set>    - Unique values + unordered + faster than set

        # <<< INFO >>> #

            Insert                  - O(1)
            Access any              - O(1)
            Contains                - O(n)
            Resize                  - O(1)

        <>  Declaration             - std::unordered_set<TYPE> NAME;
        <>  Insert                  - NAME.emplace(VALUE);
        <>  Insert at               - NAME.emplace_hint(ITERATOR_POS, VALUE)

    # <<< C++ MAP >>> #

        #include <map>              - Sorted by keys
                                    - Stored in a "Binary Search Tree"
                                    - !!! Key's Type requires operator< !!!

        # <<< INFO >>> #

            Insert                  - O(1)
            Access any              - O(1)
            Contains                - O(1)
            Resize                  - O(n)

        <>  Declaration             - std::map<KeyTYPE, ValueTYPE> NAME;

        <>  Add                     - NAME[ "my_key" ] = value;

        <>  Get                     - NAME.at( "my_key" );
        <>                          - NAME[ "my_key" ];
        <>  IMPORTANT (get)         - TYPE& aa = NAME[ "my_key" ];
        <>                              - Use & to get the var instead of a copy

        <>  Contains                - NAME.contains( "my_key" );
        <>                          - if ( NAME.find( "my_key" ) != my_map.end() );

        <>  Remove                  - NAME.erase( "my_key" );
        <>  Clear                   - NAME.clear();
        <>  Make inside map         - NAME.emplace( Parameters for the constructor of TYPE );
        <>                          - NAME[ "my_key" ] = TYPE { Parameters for the constructor };

    # <<< C++ UNORDERED MAP >>> #

        #include <unordered_map>    - unordered + faster than map       (Preferred)
                                    - Stored in a "Hash Table"          (key -> hashFunc() = index, index -> DataStruct = value)
                                    - !!! Key's Type requires Hashable !!!

        # <<< INFO >>> #

            Insert                  - O(1)
            Access any              - O(1)
            Contains                - O(1)
            Resize                  - O(n)

        <>  Declaration             - std::unordered_map<KeyTYPE, ValueTYPE> NAME;

    # <<< C++ MAP BONUS >>> #

        Hashable pointers           - if my_class does not implement hash           (is not hashable)
                                    - std::unordered_map< my_class,  int> my_map;   (Will not work)
                                    - std::unordered_map< my_class*, int> my_map;   (Will work)
                                    -                                               (pointers are hashable)
                                    - 
        auto [] insert              - if ! my_map.contains("ss1")
                                    - TYPE& aa = my_map["ss1"];         (ss1 is inserted/created in the map)
                                    - 
        const std::map              - Map cannot be modified, so operator[] will not work
                                    - Use map.at();
                                    - While map[] can modify map, map.at() cannot.      (insert/create)

    # <<< C++ PRIORITYQUEUE >>> #

        #include <queue>            - Sorted values
                                    - !!! Requires operator< !!!

        # <<< INFO >>> #

            Insert                  - O(log n)
            Pop                     - O(log n)
            Peek                    - O(1)
            Resize                  - O(?)

        <>  Declaration - -> +          - std::priority_queue< TYPE > pq;

        #include <functional>
        #include <vector>
        <>  <>  Declaration + -> -      - std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

        <>  Add                         - pq.push(VALUE);
        <>  Make                        - pq.emplace( constructorParameters );

        <>  Pop                         - pq.pop();
                                            - removes the top element

        <>  Peek                        - pq.top();
                                            - accesses the top element

# <<< C++ std::hash, HASHABLE >>> #

    Make an object hashable

    namespace std {

        template <>
        struct hash<Key>
        {
            std::size_t operator()(const Key& k) const
            {
            using std::size_t;
            using std::hash;
            using std::string;

            // Compute individual hash values for first,
            // second and third and combine them using XOR
            // and bit shifting:

            return ((hash<string>()(k.first)                        - Meaning of:
                    ^ (hash<string>()(k.second) << 1)) >> 1)        - std::hash<std::string>()...;
                    ^ (hash<int>()(k.third) << 1);                      - Instantiates one struct of std::hash
            }                                                       - ...(airport.getName());
        };                                                              - Calls operator() of std::hash
    }

    # <<< If you don't want to specialize template inside the std namespace >>> #

        struct KeyHasher
        {
            std::size_t operator()(const Key& k) const
            {
                using std::size_t;
                using std::hash;
                using std::string;

                return ((hash<string>()(k.first)
                        ^ (hash<string>()(k.second) << 1)) >> 1)
                        ^ (hash<int>()(k.third) << 1);
            }
        };

        int main()
        {
            std::unordered_map<Key, std::string, KeyHasher> map = {
                { {"John", "Doe", 12}, "example"},
                { {"Mary", "Sue", 21}, "another"}
            };
        }

# <<< C++ std::copy >>> # <<< C++ CONTAINERS TRANSFORMATION >>> #

    std::vector<int> vec {1,2,3,4,5};
    int array[vec.size()];

    std::copy(vec.begin(), vec.end(), array);

    std::set<std::string> s(vec.begin(), vec.end());    - For other types, you must have 'operator<' defined.

# <<< C++ MULTIPLE FILES PROGRAM, GLOBAL VARIABLES >>> #

    # <<< GUIDE LINES >>> #

        Guideline for creating modules
        #includes

        Avoid unnecessary random includes and only include a header file in a cpp file in which the header file functions are called or the header file definitions are used.
        Do not include a header file inside another header file unless it is absolutely necessary.
        Global variables (file scope variables)

        Global variable declarations must be in the CPP files to be kept invisible to other modules
        Structure definitions

        Structure definitions must be kept in the header file to be visible to all the modules using it.
        Constant value declarations

        The Constant value declarations are to be added to the file they are used in; if they are used in a header file, they must be added to the header file otherwise they must be added to the CPP file they are used in.
        Namespace

        All your code (in header files and CPP files) must be surrounded by the sdds namespace except in the module holding the main function.
        The main module should use the sdds namespace (using namespace sdds;).

        important: Never use the using statement in a header file.

        https://www.youtube.com/watch?v=EGak2R7QdHo

        You SHOULD NOT place #include directives inside your own namespace.

    new file main.cpp           - Main program
    new file math.cpp           - math functions implementation
    new file math.h             - math functions declaration (header)
    e.g.
    inside math.cpp:            - #include <iostream>
                                - int sum(int x, int y) { return x + y; }
    inside math.h:
                                - int sum(int x, int y);
    inside main.cpp:
                                - #include "math.h"
    Running options:
    terminal                    - g++ -o main.exe main.cpp math.cpp
    terminal                    - g++ -o main.exe main.cpp *.cpp            - main cannot be "read" twice
    VSCode                      - tasks.json { "tasks": [ { "args": [ "${workspaceFolder}\\*.cpp",

    # <<< GLOBAL VARIABLES >>> #

        new file GlobalHeader.h     - Contains all global variables definitions
                                    - 
                                    - #pragma once
                                    - 
                                    - extern int g_MyGlobalVar;       // Old C++
                                    -                                 // Requires Inside main.cpp
                                    -                                 // int g_MyGlobalVar = 999;
                                    -
                                    - inline int g_MyGlobalVar = 999; // Modern C++
                                    -                                 //
                                    - 
                                    - Just #include "GlobalHeader.h" in all program files

        extern int NAME;            - "Go outside my scope/file and you will find my definition"
                                    - Only works with Global Variables
                                    - Does not work with static Global Variables

        inline int NAME = value;    - Dealing with global variables with multiple files

# <<< C++ CLASSES AND STRUCT >>> #

    struct StructName {};           - Same as class, but Members are public by default
                                    - More uses at Type Punning and Union

    class ClassName {               - Members are private by default
        private: {
            std::string name;
            int age;
            int* height = new int;                      - Use Destructor to liberate memory
        }
        public: {
            ClassName() {                               - Default constructor
                name = "test";
                age = 0;
            }
            ClassName(std::string _name, int age) {     - Constructor call
                this->name = _name;  //  *
                (*this).age = age;   //  &
            }
            virtual ~ClassName() {                      - Destructor (Called when the object dies)
                delete height;
            }
            void method(...) {...}                      - Functions
        }
    };

    ~DESTRUCTOR
    #There is no need to use a virtual destructor when any of the below is true:
    #   No inheritance
    #   No instantiation on the heap
    #   No intention to store with access via a pointer to a superclass
    Use virtual to avoid memory leaks:
    (Human* h = new Hero();     delete h;)      only calls Human destructor if not virtual

    CLASS Initialization
    ClassName cn1("name", 20);          - Constructor call
    ClassName cn2;                      - Default constructor


    # <<< C++ CLASSES GOOD PRACTICE >>> #

        file name                   - constants.h
        Move all constants to here.

        file name                   - className.h
            Build ClassName.
        OR
            ClassName [PREVIEW].
            +
            file name               - className.cpp
            Build ClassName.

        USING THE CLASS             - main.cpp
        #include "constants"
        #include "ClassName.h"

    # <<< C++ AVOIDING DUPLICATES VARIABLES AND CLASSES >>> #

        #pragma once                - Include this header only once (per .cpp file), prevent duplicates.

        same as:

        #ifndef CLASSNAME_H         - Checks if ClassName is not defined
        #define CLASSNAME_H         - Defines ClassName

        #include <iostream>
        #include "constants.h"
        Create Class...

        #endif                      - End of if body

    # <<< C++ IMPLEMENTATION OF CLASSES DIVIDED IN TWO FILES >>> #

        file name                   - className.h
            class ClassName {
                private : {...}
                public : {
                    ClassName(int age, std::string name);
                    virtual ~ClassName();
                    int get_age();
                    std::string get_name();
                    ...
                }
            };
        file name                   - className.cpp
            ClassName::ClassName(int age, std::string name) {
                this->age = age;
                this->name = name;
            }
            ClassName::~ClassName() {
                delete height;
            }
            int ClassName::get_age() {
                return age;
            }
            std::string ClassName::get_name() {
                return name;
            }

    CLASS ON HEAP MEMORY
    Pointing                - ClassName* p_cn = &cn;
    Initialization          - ClassName cn1 = new ClassName(55, "name")
    Using Functions         - *cn1.func();
                            - cn1->func();
    Deleting                - delete cn1;

    # <<< C++ SIZE OF AN OBJECT, STRUCTURE PADDING >>> #

        sizeof(ClassName)       - size == The sum of all var members sizes inside the Class,
                                - size += Structure Padding  and  (functions does not count)
                                - 
        Structure Padding       - Empty memory created in order to make the CPU reading more efficient
                                - CPU (32 bit architecture) reads 4 Bytes
                                - CPU (64 bit architecture) reads 8 Bytes
                                - 
        e.g.                    - char a, char b, int x;                    (32 bit)
        Expected memory         - |a|b|x|x| \/ |x|x|0|0| \/ ...             size == 6 Bytes
        Real memory             - |a|b|0|0| \/ |x|x|x|x| \/ ...             size == 8 Bytes
                                - The program automatically add Padding( 0/Empty memory )
                                - Helping the CPU 4Bytes reader, thus, increasing memory use
                                - 
                                - char a, char b, char c, char d, int x;    size == 8 Bytes
                                - char a, char b, int x;                    size == 8 Bytes

    # <<< C++ STRUCTURE PACKING, #pragma >>> #

        #pragma                 - Is used to turn on or off certain features

        #pragma pack(1)         - Force no Padding      (Less memory use) + (Slower to read)

        class ClassName {...};

# <<< C++ ENCAPSULATION >>> #

    Encapsulation       - Data hiding
    public              - All
    protected           - By inherited classes
    private             - Same class

# <<< C++ CONST >>> #

    const               - Block modifications after declaration (final)
    e.g.                - const NAME;

    Inside Human        - Use TYPE hFunc(...) const {...};              - (const Circle* this, ...)
                        - It means that hFunc will not modify Human
    Uses                - 
    Outside Human       - TYPE Func(const Human& human) {...};
                        - Only Human const functions can be called      - (Keeping human const)
                        - 
    Inside Human        - Use const TYPE hFunc(...) {...};
                        - It return a const TYPE

# <<< C++ INHERITANCE, COPY CONSTRUCTOR >>> #

    Inheritance
                        - class Human {#ifndef ...};
                        - class Hero : public Human {#ifndef ... #include "human.h" ...};
                        - class Villain : protected Human {#ifndef ... #include "human.h" ...};
                        - class Civilian : private Human {#ifndef ... #include "human.h" ...};
    base class          - Before :   public x1, protected y2, private z3
    public inhit        - After :    public x1, protected y2, private z3
    protected inhit     - After : protected x1, protected y2, private z3
    private inhit       - After :   private x1, private   y2, private z3        (Civilian now owns x1, x2 but as private)
    Resurrecting
                        - using Human::get_name;            // After private inhit || (BAD CODE)
                        - using Human::Human;               // Use base class constructor in inhit
    Constructor
    inhit to base       - Hero(int age, std::string name) : Human(age) {...}
    :                   - Initializer list (: ..., ...)

    ~super              - Human::...;

    # <<< C++ COPYING CLASS OBJECTS >>> #

        without copy        - func(ClassName cn) {} 
                            - can break you program because cn will be a copy

        Copy constructor    - Human myHuman2(myHuman1);
        Only Stack memory   - Works by default
        With heap memory    - Does not work by default
        Base class          - Human(const Human& source) {
                            -     name = source.get_name();
                            -     age = source.get_age();
                            - }
        Inhit class         - Hero(const Hero& source) : Human(source) {
                            -     power = source.get_power();
                            - }

# <<< C++ STATIC >>> #

    static              - "Ownership" change            - Remains in memory after scope end
    Class Variable      - The Class owns the variable. The Class's object not anymore

                        - private: 
                        -     static int total;
                        - public:  
                        -     static int get_total() {
                        -         return total;
                        -     }
                        -     static void set_total(int total) {
                        -         Human::total = total;
                        -     }
    Init                - };  int Human::total{0};
                        -
    Call                - Human::get_total();
    Call                - myHuman.get_total();

    Global Variable             - This Program owns the global variable. The file not anymore

    int aa = 55;                - File Global Variable
    static int bb = 88;         - Program Global Variable

    Local Variable              - This function owns the variable. The local scope not anymore
    int summ() {
        static int x = 0;       - Each call x is incremented and is not set to 0
        return x++;
    }

    !! IMPORTANT BE AWARE OF !!     - 1. (HOW/THE ORDER) THAT YOUR PROGRAM INITIALIZE
                                    -                   STATIC FUNCTIONS AND VARIABLES
                                    - 2. (WHERE) YOU ARE USING THEM, BECAUSE,
                                    -           SOMETIMES IT MAY NOT WORK AS INTENDED

# <<< C++ FRIEND, "TO_STRING" >>> #

    friend keyword      - Used to access private or protected members of a class without the objects
                        - Avoid the "must be a member of both classes to access them"
                        - Used to perform operator overloading
    friend func e.g.
    Inside class        - friend int friend_get_human_age (Human& human) { return human.age; }
    Call outside        - friend_get_human_age(myHuman);

    ~toString
    Base class          - friend std::ostream& operator<<(std::ostream& out, const Human& human);
                        - std::ostream& operator<<(std::ostream& out, const Human& human) {
                        -     out << "Human name: " << human.name << " age: " << human.age;
                        -     return out;
                        - }
    Inhit class         - friend std::ostream& operator<<(std::ostream& out, const Hero& hero);
                        - std::ostream& operator<<(std::ostream& out, const Hero& hero) {
                        -     out << "Hero name: " << hero.get_name() << " age: " <<
                        -           hero.get_age() << " power: " << hero.power;
                        -     return out;
                        - }
                        - WARNING !! Using ((Human) hero) WILL create a COPY !! WARNING
    friend class e.g.
                        - class Dog;
                        - class Cat {
                            //code;
                            friend class dog;
                        - }
                        - class Dog {
                            Cat objc;
                            std::cout << objc.non-public_var ;
                        - }

# <<< C++ POLYMORPHISM, VIRTUAL, SLICING, STATIC vs DYNAMIC, FINAL, ABSTRACT, INTERFACE >>> #

    ~=instanceof        - if (dynamic_cast<Villain*>(h) != nullptr) {...}

    # <<< C++ POLYMORPHISM >>> #

        - Hero and Villain can be Human but Human cannot be Hero or Villain.
        - Human* myHero = new Hero;
        - Human& myHeroR = &myHero;
        - ((Hero*) myHero).func()
        - ((Hero&) myHeroR).func();
        - Both works in functions and data structures

    # <<< C++ STATIC vs DYNAMIC >>> #

        static binding
            - 
            - (Default behavior) + uses less memory than dynamic binding
            - Human* myHero = new Hero(...);
            - myHero.func() Instead of using Hero's func it will use Human's func

        Solution:

        virtual keyword / dynamic binding
            - 
            - Uses more memory than static binding
            - virtual void func() {...}
            - By adding virtual before the function inside (Human), Polymorphism will work as intended
            - myHero.func() will call Hero's func

    # <<< C++ SLICING >>> #

        Warning:
            - Although dynamic binding works with pointers and references
            - IT WILL WORK WITH            Human* array[] {&myHero, &myVillain, ...}
            - IT WILL WORK WITH            std::shared_ptr<Human> array[] {std::make_shared<Hero>(...), ...}
            - IT WILL NOT WORK WITH        Human temp = myHero;
            - IT WILL NOT WORK WITH        Human array[] {myHero, myVillain, ...}
            - C++ compiler will slice(delete) all non-Human information
            - And ignoring all virtual functions

    # <<< C++ Override >>> #

        - virtual void func() override {}
        - Avoid mistakes with dynamic polymorphism
        - Works only in inhit classes

    # <<< C++ FINAL >>> #

        - Restrict override methods in child classes         (Impossible to override)
        e.g.
        - void func() const override final {}               (Must be virtual in base class)


        - Restrict inheritance                               (Impossible to inhit)
        e.g.
        - class Hero final : public Human {...};

    # <<< C++ DEFAULT PARAMETERS >>> #

        Default parameters  - If no param given use default
                            - int add(int x = 5, int y = 5) {...}
        
        Warning:            - If used with virtual, during polymorphism:    (Bad code)
                            - Default parameters  =  from base class
                            - function body       =  from inhit class

    # <<< C++ DYNAMIC CAST >>> #

                        - Dynamic_cast<TYPE>()                                  (Don't Overuse it.)
        Base to Inhit   - 
                        - Human* myHuman = new Hero();
        * -> *          - Hero* myHero = Dynamic_cast<Hero*>(myHuman);          (Fail == nullptr)
        & -> *          - Hero* myHero = Dynamic_cast<Hero*>(&human_ref);       (Fail == nullptr)
        & -> &          - Hero& myHero = Dynamic_cast<Hero&>(human_ref);        (Fail == crash)

    # <<< C++ ABSTRACT CLASS >>> #

                - Whenever =0 is added to the end of a virtual function,
                - the class becomes abstract. (Cannot be instantiated)
                - 
        =0;     - Pure virtual functions
        e.g.    - virtual void print_info() = 0;
                - 
                - enforce override implementation in Inhit classes

    # <<< C++ INTERFACE >>> #
        
        - Abstract class + No member variables (Only pure virtual functions)
        - class Human : public SomeInterface {...};

# <<< C++ ENUM >>> #

    ENUM            - Enumerate a sequence of integers with names
                    - Making the code easier to understand and cleaner
                    - Instead of
                    - A {0}; B {1}; C {2}; D {3}; E {4}; F {5}; G {6};
                    - Use
                    - enum WeekDays : unsigned char {
                    -     Monday = 0, Tuesday, Wednesday = 2, Thursday, Friday, Saturday, Sunday
                    - };
                    - WeekDays::Friday;

# <<< C++ MUTABLE >>> #

    Mutable keyword     - It basically let you modify the object inside a func() const {};

    Inside Class        - mutable int debugCount = 0;
                        - void func() const {
                        -     debugCount++;
                        -     ...
                        - }

    lambda + mutable    - [=]() mutable {...;}();     Now vars copy can be modified

# <<< C++ MACROS, DEFINE, #Pre-Process >>> #

    Text E          - Pre-process stage controls what code is passed to the compiler
    #               - Everything that starts with # is evaluated at pre-process time
                    - 
    Declaration V   - #define NAME value                                (Same as const)
    Call            - std::cout << NAME << "\n";
                    - 
    Declaration F   - #define MAIN int main(...)\                       (Can be anywhere in the code)
                    - {\                                                (\ == "new line")
                    -     std::cout << "Hello" << "\n";\
                    - }
    Call            - MAIN
                    - 
    DEBUG MACRO     - Print logs only when program is in debug mode and when it is not the code will not crash
    (Advanced)      - #define DEBUG 1
                    - 
                    - #if DEBUG == 1
                    - #define LOG(x) std::cout << x << std::endl        (If ; here Call doesn't need ;)
                    - #else
                    - #define LOG(x)
                    - #endif

    IMPORTANT       - MACRO PARAMETERS e.g. x in LOG(x)
                    - x is just a copy and paste which only after pasted is going to be evaluated
                    - IF YOU PASS A FUNCTION IT MAY NOT WORK PROPERLY

    Predefined Macros
    __TIME__        - Current time (14:45:08)
    __DATE__        - Current date (Jun  5 2022)

# <<< C++ NAMESPACE >>> #

    namespace       - Creating a library of functions
                    - full static class that does not need instantiation
    Declaration     - namespace test {
                    -     static void print() { std::cout << "Hello World" << "\n"; }
                    - }
    Call            - test::print();

# <<< C++ SINGLETONS >>> #

    SINGLETONS      - Full static class that does not need instantiation

    Why             - why return an instance and not make all functions static:
                    - If any static function depends on another code to be loaded first,
                    - it can crash the program. Plus more problems such (exception handlers, ...)
                    - However you can use static when:
                    - You are entirely sure you aren't depending on any static variables,
                    - outside your own translation unit and aware of the initialization order,
                    - within your own translation unit.

    class Singleton {
        private:
            Singleton() {};                         - Private constructor (block Initializations)
            // Singleton() = default;               - Alternative to Singleton() {};
            static Singleton s_Instance;
        public:
            Singleton(const Singleton&) = delete;   - Delete copy constructor (block copies)

            static Singleton& Get() {
                return s_Instance;
            }
            // ----Code----
            void Func() {...}
    }
    Singleton Singleton::s_Instance;

    int main() {
        Singleton::Get().Func();                    - Uses
    }

# <<< C++ MULTITHREADING >>> # <<< C++ CHRONO >>> #

    #include <thread>
    <> Run                  - std::thread worker(funcName);
    <> Wait                 - worker.join();                        (Main wait until worker finish)
    <>                      -
    <> using namespace std::literals::chrono_literals;
    <> <> Sleep             - std::this_thread::sleep_for(1s);      (Sleep for 1s)
    <> <> ID                - std::this_thread::get_id();
    <>                      - 
    <>                      - 

    #include <chrono>
    <> Timer                - auto start = std::chrono::high_resolution_clock::now();
    <>                      - auto end = std::chrono::high_resolution_clock::now();
    <>                      - std::chrono::duration<float> duration = end - start;
    <>                      - std::cout << duration.count() << "s " << "\n";

    #include <chrono>
    #include <thread>
    using namespace std::literals::chrono_literals;
    <> Sleep                - std::this_thread::sleep_for(std::chrono::milliseconds(x));

# <<< C++ TIMER PRE-BUILD >>> #

    Copy and paste

# <<< C++ std::async >>> # <<< C++ LOCK  >>> #

    std::async                   - Automatic Multithreading

    #include <future>

    std::vector<std::future<void>> m_Futures;

    static std::mutex s_MeshesMutex;

    static void LoadMeshe (std::vector<Ref<Mesh>>* meshes, std::string filepath)
    {
        auto mesh = Mesh::Load(filepath);

        std::Lock_guard<std::mutex> lock(s_MeshesMutex);                - thread1 enters this func Lock_guard blocks any other threads from modifying until function end
        meshes->push_back(mesh);
    }

    void editorLayer::LoadMeshes() {

        std::vector<std::string> meshFilepaths = """ Read from file """;

        for (const auto& file : meshFilepaths)
        {
            m_Futures.push_back(  std::async(  std::launch::async, LoadMesh, &m_Meshes, file  )  );
        }
    }

# <<< C++ SWAP >>> #

    !!! Requires operator= !!!

    void swap(int* a, int* b) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }

    void swap(Airport& a, Airport& b) {
        Airport temp = std::move(a);
        a = b;
        b = temp;
    }

    # <<< C++ std::swap >>> #
        
        #include <utility>      - 
        #include <algorithm>    - https://en.cppreference.com/w/cpp/algorithm/swap
                                - 
        <>  use                 - std::swap(vector[index1], vector[index2]);

    # <<< C++ std::iter_swap >>> #

        std::iter_swap          - std::swap(*a, *b);
                                - The dereferenced values *a and *b must be "swappable"

        #include <utility>      - 
        #include <algorithm>    - https://en.cppreference.com/w/cpp/algorithm/iter_swap
                                - 
        <>  use                 - std::iter_swap(vector.begin() + index1 , vector.begin() + index2);

# <<< C++ SORTING AND SEARCHING >>> #

    #include <algorithm>
    <>  sort using <        - std::sort(myVector.begin(), myVector.end());
    <>  sort by lambda      - std::sort(myVector.begin(), myVector.end(), [](int a, int b) {
    <>                      -     return a < b;
    <>                      - });
    <>  #include <functional>
    <>  <>  sort by func    - std::sort(myVector.begin(), myVector.end(), std::greater<int>);

    # <<< C++ SORTING >>> #

        # <<< C++ BUBBLE >>> #

            - Iterate swapping couples until NO SWAPS/SORTED,
            - Each Iteration the last index will be sorted.
        
            # <<< INFO >>> #

                - The larger elements bubble to the top of the list.
                - It works by stepping through the list repeatedly,
                - comparing adjacent elements and swapping them if they are out of order.

                - AVG. PERFORMANCE:         O(N^2)          - N^2 Comparisons && N^2 Swaps
                - SPACE COMPLEXITY:         O(1)            - Sort is done in place
                - STABLE                                    - Does not alter the order of equivalent elements

            void bubbleSort(std::vector<Airport>& arr) {
                for (size_t i = 0; i < arr.size(); i++) {
                    bool swapped = false;
                    for (size_t k = 1; k < arr.size()-i; k++) {
                        if (arr[k-1] > arr[k]) {
                            swap(arr[k-1], arr[k]);
                            swapped = true;
                        }
                    }
                    if (swapped == false) {
                        return;
                    }
                }
            }

        # <<< C++ SELECTION >>> #

            # <<< INFO >>> #

                - It Divides the input list into two parts: sorted and unsorted.
                - The sorted section starts empty and the unsorted section is the entire list,
                - then it finds the smallest element in the unsorted section and,
                - swaps it with the leftmost element of the sorted section.
                - Increasing the size of the sorted section one by one.
                - It repeats this process until the sorted section is the size of the entire list.

                - AVG. PERFORMANCE:         O(N^2)          - N^2 Comparisons &&
                                                            - N Swaps (# Because it wait until it has found the smallest unsorted element)
                - SPACE COMPLEXITY:         O(1)            - Sort is done in place
                - NOT STABLE                                - Does alter the order of equivalent elements

                - Faster than bubbleSort

            void selectionSort(std::vector<Airport>& arr) {
                for (size_t i {0}; i < arr.size(); i++) {
                    int minIndex (i);
                    for (size_t k {1+i}; k< arr.size(); k++) {
                        if (arr[minIndex] > arr[k]) {
                            minIndex = k;
                        }
                    }
                    swap(arr[i], arr[minIndex]);
                }
            }

        # <<< C++ INSERTION >>> #

            # <<< INFO >>> #

                - Iterates through the input list one element at a time and,
                - inserts the current element into the location it belongs to in the sorted section,
                - once there are no more input elements, the list is sorted.

                - AVG. PERFORMANCE:         O(N^2)          - N^2 Comparisons && N^2 Swaps
                - SPACE COMPLEXITY:         O(1)            - Sort is done in place
                - STABLE                                    - Does not alter the order of equivalent elements
                - QUICK FOR SMALL LISTS
                - QUICK FOR MOSTLY SORTED LISTS
                - ONLINE                                    - Can accommodate more items as it receives them

                - Faster than bubbleSort and selectionSort in practice

            void insertionSort(std::vector<Airport>& arr) {
                for (size_t i {0}; i < arr.size(); i++) {
                    int currIndex (i);
                    while (currIndex > 0 && arr[currIndex-1] > arr[currIndex]) {
                        swap(arr[currIndex-1], arr[currIndex]);
                        currIndex--;
                    }
                }
            }

        # <<< C++ MERGE >>> #

            # <<< INFO >>> #

                - It takes an input list and divides it in half over and over until,
                - we are left with a bunch of sub-lists of size 1 that are trivially sorted.
                - Then the merging process begins.
                - Merge sort sequentially compares the elements of two sub lists together,
                - to form sorted sub-lists of size 2, 4, 8 and so on,
                - until it has just one sorted sub-list the same size as the input list.

                - AVG. PERFORMANCE:         O(N log(N))     - log(N) To divide the input list
                                                            - && N Operations to merge the sublist back together
                - SPACE COMPLEXITY:         O(N)            - Auxiliary space is required
                - STABLE                                    - Does not alter the order of equivalent elements

                - Can be optimized by merging sub-lists in parallel with one another

            void mergeSort(std::vector<Airport>& arr, const int& low, const int& high) {
                if (low < high) {
                    int mid (low + (high - low) / 2);

                    mergeSort(arr, low, mid);
                    mergeSort(arr, mid+1, high);
                    merge(arr, low, mid, high);
                }
            }

            void merge(std::vector<Airport>& arr, const int& low, const int& mid, const int& high) {
                int nL (mid - low + 1);
                int nH (high - mid);

                Airport arrL[nL];
                Airport arrH[nH];

                for (size_t i {0}; i < nL; i++) {
                    arrL[i] = arr[low + i];
                }
                for (size_t i {0}; i < nH; i++) {
                    arrH[i] = arr[mid + 1 + i];
                }

                int indexL {0};
                int indexH {0};
                int indexK {low};

                while (indexH < nH && indexL < nL) {
                    if (arrH[indexH] > arrL[indexL]) {
                        arr[indexK] = arrL[indexL];
                        indexL++;
                    }
                    else {
                        arr[indexK] = arrH[indexH];
                        indexH++;
                    }
                    indexK++;
                }

                while (indexH < nH) {
                    arr[indexK] = arrH[indexH];
                    indexH++;
                    indexK++;
                }
                while (indexL < nL) {
                    arr[indexK] = arrL[indexL];
                    indexL++;
                    indexK++;
                }
            }

        # <<< C++ QUICK >>> #

            # <<< INFO >>> #

                - It first picks an element from the input list called the pivot then,
                - all elements less than the pivot are placed before it and,
                - all elements greater than the pivot are placed after it.
                - Once this process is completed the pivot is in its final position and,
                - the input list has been partitioned into two sub lists (Elements less than the pivot and Elements greater than the pivot).
                - Then recursively applies the same steps to each sub-list,
                - until it has sub-list of at most one element which is trivially sorted.
                - When the recursion is finished, the list is sorted.

                - AVG. PERFORMANCE:         O(N log(N))     - # On average as long as the chosen pivot divides the input list into two reasonably sized pieces
                - (Generally considered as worst case)      - log(N) recursive calls to reach a list of size one
                                                            - && N Operations for each recursive calls to place other elements on the current side of the pivot
                                                            - 
                - Worst-Case:               O(N^2)          - # When the chosen pivots are always a minimum or maximum and they do not partition the list.
                - (Real worst case, but uncommon)           - # Can happen when a bad partition is used on almost sorted data
                                                            - 
                - SPACE COMPLEXITY:         O(log(N))       - Recursively partitioning the input list
                - NOT STABLE                                - Usually not implemented as stable.

                - Faster than mergeSort in practice because,
                - it uses less space.

            void quickSort(std::vector<Airport>& arr, const int& low, const int& high) {
                if (low < high) {
                    int p = partition(arr, low, high);
                    
                    quickSort(arr, low, p-1);
                    quickSort(arr, p+1, high);
                }
            }

            int partition(std::vector<Airport>& arr, const int& low, const int& high) {
                int swapIndex = low;
                for (size_t i = low; i < high; i++) {
                    if (arr[i] < arr[high]) {
                        swap(arr[swapIndex], arr[i]);
                        swapIndex++;
                    }
                }
                swap(arr[swapIndex], arr[high]);
                return swapIndex;
            }

        # <<< C++ HEAP >>> #
        
            - "Heapify" Array,              Then Transform it into a Max Heap
            - Max Heap: The parent node must always be greater than or equal to the child nodes
            - Swap root node with the last node         And delete the last node from the heap
            - Process visualization ~= "REVERSE SELECTION SORT"
            - If the parent node is stored at index I, the left child can be calculated by 2 * I + 1 and the right child by 2 * I + 2 (assuming the indexing starts at 0).

            # <<< INFO >>> #

                - It divides the input list into two parts one sorted and one unsorted.
                - Initially the sorted section is empty and the unsorted section is the entire input list,
                - which is maintained as a heap data structure.
                - In each iteration the largest element is extracted from the unsorted heap sector and,
                - placed at the start of the sorted section, in a constant time operation.
                - The unsorted section is then rearranged to maintain its heap (?and variance/invariance?).
                - This process is repeated until the sorted section is actually the size of the entire list.
                - ~= Similar to selectionSort

                - AVG. PERFORMANCE:         O(N log(N))     - 1 Extract next element (# constant for each element, therefore, 1 * N)
                                                            - N Extract all element
                                                            - && log(N) Rearrange the elements of the unsorted section
                - SPACE COMPLEXITY:         O(1)            - 
                - NOT STABLE                                - # Because of its arbitrary rearrangement of elements to maintain the heap during the sorting process

                - Slower than quickSort because the constant factor of heapSort,
                - is larger than that of quickSort

            void heapSort(std::vector<Airport>& arr) {
                for (int i = arr.size() / 2 - 1; i >= 0; i--) {
                    heapify(arr, arr.size(), i);
                }

                for (int i = arr.size() - 1; i > 0; i--) {
                    swap(arr[0], arr[i]);

                    heapify(arr, i, 0);
                }
            }

            void heapify(std::vector<Airport>& arr, const int& size, const int& start) {
                int largest = start;
                int left = start * 2 + 1;
                int right = start * 2 + 2;

                if (left < size && arr[left] > arr[largest]) {
                    largest = left;
                }

                if (right < size && arr[right] > arr[largest]) {
                    largest = right;
                }

                if (largest != start) {
                    swap(arr[start], arr[largest]);
                    heapify(arr, size, largest);
                }
            }

        # <<< C++ SHELL >>> #

    # <<< C++ HYBRID SORTING >>> #
    
        # <<< C++ TIMSORT >>> #

            # <<< INFO >>> #

                - Designed to take advantage of increasing or decreasing runs that,
                - naturally occur in the input list.
                - It iterates over the input list collecting runs, and places them on an auxiliary stack.
                - If a run is too small, more elements are added to it via binary search insertion sort,
                - whenever TimSort merge criteria it met, runs from the stack are merged together.
                - This is repeated until there is only one run left on the stack.
                - 
                - In the merge routine, TimSort implements a couple of key optimizations,
                - elements that are already in the right place are located first via binary search,
                - saving a few swaps, and then if TimSort notices that one run is always winning,
                - it enters galloping mode, where it looks for the winning runs next loss and,
                - automatically merges all elements up to that point.
                -
                - You can think of TimSort as a highly optimized mergeSort

                - AVG. PERFORMANCE:         O(N log(N))     - 
                - SPACE COMPLEXITY:         O(N)            - 
                - STABLE                                    - 
                - QUICK FOR MOSTLY SORTED LISTS             - 

        # <<< C++ INTROSORT >>> #

            # <<< INFO >>> #

                - It judiciously chooses between quickSort, heapSort and insertionSort.
                - It begins with quickSort and then switches to heapSort in large lists,
                - this happens when the recursion depth of quickSort exceeds a level,
                - proportional to the log of the size of the input list,
                - and finally it switches to insertionSort once the partition size is small enough.
                - 
                - By combining the best parts of these three algorithms IntroSort avoids,
                - the worst case time complexity of quickSort which is O(N^2) and,
                - it avoids quickSort's large constant factor on small input lists.

                - AVG. PERFORMANCE:         O(N log(N))     - 
                - SPACE COMPLEXITY:         O(log(N))       - 
                - NOT STABLE                                - Because heapSort and quickSort are not stable

    # <<< C++ SEARCHES >>> #

        # <<< C++ LINEAR >>> #
        
            - Iterate over all values util find target
            - O(N)

            # <<< RETURN POINTER >>> #

                Airport* linearSearch(std::vector<Airport>& arr, std::string_view target) {
                    for (Airport& item : arr) {
                        if (item.getName() == target) {             // Return something if found or return null
                            return &item;                           // Returning pointers works HOWEVER
                        }                                           // If the vector resizes 
                    }                                               // !! The return pointer may point to the wrong address !!
                    return nullptr;                                 // Breaking the program
                }

            # <<< RETURN std::optional >>> #

                #include <optional>

                std::optional<Airport> temp = linearSearch(list, "aa");
                if (temp) { std::cout << temp.value() << "\n"; }
                
                std::optional<Airport> linearSearch(std::vector<Airport>& arr, std::string_view target) {
                    for (Airport& item : arr) {
                        if (item.getName() == target) {                 // Return a copy      ?? SOLUTION return & ??
                            return std::optional<Airport>(item);
                            //return item;                              // Both ways work
                        }
                    }
                    return std::optional<Airport>();
                    //return {};                                        // Both ways work
                }

        # <<< C++ BINARY >>> #
        
            - Split in half every iteration
            - O(log(N))

            #include <optional>

            std::optional<Airport> temp = binarySearch(list, "aa");
            if (temp) { std::cout << temp.value() << "\n"; }
            
            std::optional<Airport> binarySearch(std::vector<Airport>& arr, std::string_view target) {
                int low = 0;
                int mid;
                int high = arr.size() - 1;
                while (low <= high) {
                    mid = (low + high) / 2;
                    if (target > arr[mid].getName()) {
                        low = mid + 1;
                    }
                    else if (target < arr[mid].getName()) {
                        high = mid - 1;
                    }
                    else {
                        return std::optional<Airport>(arr[mid]);
                    }
                }
                return std::optional<Airport>();
            }

    Reverse Order       - 
    Shuffle             - 

# <<< C++ TYPE PUNNING >>> #

    Type Punning        - Passes a TYPE1/CLASS1 memory value into a TYPE2/CLASS2
    (copy memory value) - Avoiding copies and conversions + Fast + Size
                        - TYPE1/CLASS1 must have the same memory size as TYPE2/CLASS2 (when not * or &)
    
    # <<< STRUCT >>> #

        struct Test { int a; int b; char c; };      (|*->aaaabbbbc???|...)

        Test zed(11,22,'a');                        (*-> == "POINTER REPRESENTATION")
                                                    (12 total, 9 used)
        int* i_ptr = (int*)&zed;                - Test(9 Bytes) -> int(4 Bytes)   (increment == jump 4 Bytes)
        std::cout << *(i_ptr) << "\n";          - |*->aaaa|bbbb|c???|...          (prints a(11))
        std::cout << *(i_ptr+1) << "\n";        - |aaaa|*->bbbb|c???|...          (prints b(22))
        std::cout << i_ptr[0] << "\n";          - |*->aaaa|bbbb|c???|...          (prints a(11))
        std::cout << i_ptr[1] << "\n";          - |aaaa|*->bbbb|c???|...          (prints b(22))

        char* c_ptr1 = (char*)&zed;             - Test(9 Bytes) -> char(1 Byte)   (increment == jump 1 Byte)
        std::cout << *(c_ptr1+8) << "\n";       - |a|a|a|a|b|b|b|b|*->c|?|?|?|... (prints c('a'))
        char* c_ptr2 = ((char*)(i_ptr+2));      - int(4 Bytes) -> char(1 Byte)    (increment == jump 1 Byte)
        std::cout << *(c_ptr2) << "\n";         - |a|a|a|a|b|b|b|b|*->c|?|?|?|... (prints c('a'))

        Test* ptr = &zed;                       - Test(9 Bytes) -> Test(9 Bytes)  (increment == jump 9 Bytes)
        std::cout << *((int*)ptr) << "\n";      - Test(9 Bytes) -> int(4 Bytes)   (increment == jump 4 Bytes)
        std::cout << *((int*)ptr+1) << "\n";    - Test(9 Bytes) -> int(4 Bytes)   (increment == jump 4 Bytes)
        std::cout << *((char*)ptr+8) << "\n";   - Test(9 Bytes) -> char(1 Byte)   (increment == jump 1 Byte)

    array e.g.
                        - int arr[5] {0,2,0,4,5};
    Itself ptr          - *arr   = 1;               (1,2,0,4,5)         arr + i    == &arr[i]
                        - *(a+2) = 3;               (1,2,3,4,5)         *(arr + i) == arr[i]
                        - 
                        - for (int* ptr = arr; ptr <= arr + 4; ptr++) {
                        -     std::cout << *ptr << "\n";
                        - }
                        - 
    External ptr        - int* ptr = &arr[0];                           *(ptr + i) == arr[i]
                        - for (size_t i = 0; i < 5; i++) {
                        -     std::cout << *ptr << "\n";
                        -     ptr++;
                        - }
                        - for (ptr = &arr[0]; ptr <= &arr[5]; ptr++) {
                        -     std::cout << *ptr << "\n";
                        - }

    # <<< 2D-ARRAY >>> #
                                                                - 2dArr + i       == &2dArr[i]
        int 2dArr[2][2] {{1,2}, {3,4}};                         - *(2dArr + i)    == &2dArr[i]
        for (int* ptr = *2dArr; ptr <= *2dArr + 3; ptr++) {
            std::cout << *ptr << "\n";                          - **(2dArr + i)   == 2dArr[i][0]
        }                                                       - **(2dArr + i)+k == 2dArr[i][k]

    # <<< POINTER TO THE WHOLE ARRAY >>> #

        int arr[5] {1,2,3,4,5};
        int (*ptr)[5];                      - A pointer to five integer elements
        ptr = &arr;                         - It points to the whole array (~=2D-ARRAY)
        **ptr == arr[0];

        int 2dArr[2][3] {{1,2,3}, {4,5,6}}
        int (*ptr)[3] = &2dArr;             - *ptr == &2dArr[0] {1,2,3}
        ptr++;                              - *ptr == &2dArr[1] {4,5,6}

    # <<< char* >>> #

        Some functions behave different e.g.

        char* behaves like a string.

        char str[] {"Hello World"};

        char* ptr1 = str;                   - ptr1 == "Hello World"
        char* ptr2 = &str[6];               - ptr2 == "World"
        
        std::cout << ptr1 << "\n";          - "Hello World"
        std::cout << ptr2 << "\n";          - "World"

        std::cout << *ptr1 << "\n";         - 'H'
        std::cout << *ptr2 << "\n";         - 'W'

        std::cout << (int)*ptr1 << "\n";    - 72
        std::cout << (int)*ptr2 << "\n";    - 87

# <<< C++ UNION, ANONYMOUS >>> #

    Union               - Union members share same memory location, unlike structs/classes
                        - Union size is defined by the size of its largest member
                        - Similar to structs/classes + some restrictions (e.g. no virtual funcs)
    Uses                - Used with Type Punning
                        - More than one "name" for the same variable

    # <<< C++ UNION "SAVING MEMORY" STRUCTS >>> #

        Suppose that you need TOW structures in ONE e.g.
                                                        - Airport (name, capacity, tracks, area)
                                                        - Human   (name, gender, age)
        struct City {           // TOTAL == 37
            std::string name;   // ~16 Bytes
            int capacity;       // 4 Bytes
            int tracks;         // 4 Bytes
            double area;        // 8 Bytes
            int age;            // 4 Bytes
            char gender;        // 1 Byte
        }

        SOLUTIONS:

        # <<< C++ NAMED >>> #

            struct City {                   // 32 Bytes  BECAUSE (name + Info)
                std::string name;           // ~16 Bytes
                union                       // 16 Bytes  BECAUSE  sizeof(Airport) > sizeof(Human)
                {
                    struct                  // 16 Bytes         |AAAABBBBCCCCCCCC|
                    {
                        int capacity;       // 4 Bytes  A
                        int tracks;         // 4 Bytes  B
                        double area;        // 8 Bytes  C
                    } Airport;
                    struct                  // 5 Bytes          |ZZZZY???????????|
                    {
                        int age;            // 4 Bytes  Z
                        char gender;        // 1 Byte   Y
                    } Human;
                } Info;                     // my_air.Info.Airport.area ...;
            };                              // my_hum.Info.Human.age ...;

        # <<< C++ ANONYMOUS >>> #

            struct City {                   // 32 Bytes  BECAUSE (name + Union)
                std::string name;           // ~16 Bytes
                union                       // 16 Bytes  BECAUSE  sizeof(struc1) > sizeof(struc2)
                {
                    struct   {              // 16 Bytes         |AAAABBBBCCCCCCCC|
                        int capacity;       // 4 Bytes  A
                        int tracks;         // 4 Bytes  B
                        double area;        // 8 Bytes  C
                    };
                    struct   {              // 5 Bytes          |ZZZZY???????????|
                        int age;            // 4 Bytes  Z
                        char gender;        // 1 Byte   Y
                    };
                };                          // my_air.area ...;
            };                              // my_hum.age ...;

    Suppose that you want to represent the same DATA in different TYPES + Compatible with Arrays
    e.g.

    struct Vetor2 {
        float x, y;
    };
    struct Vetor4 {
        union {                         - Anonymous union       - Make a union between both structs
            struct {                    - Anonymous struct
                float x, y, z, w;                               - 4 Axes ( x, y, z, w )
            };
            struct {                    - Anonymous struct
                Vetor2 a, b;                                    - 4 Axes ( a = (x, y), b = (z, w) )
            };
        };                              - Anonymous make member vars belong to the non-anonymous (Vetor4)
    };

    uses                - Vetor4 vec = { 1.0f, 2.0f, 3.0f, 4.0f };
                        - vec. ...x, y, z or w...       == float
                        - vec. ...a or b...             == Vetor2

# <<< C++ TRACK MEMORY ALLOCATIONS >>> #

    void* operator new(size_t size)
    {
        std::cout << "Allocating " << size << " bytes\n";

        return malloc(size);
    }

    void operator delete(void* memory, size_t size)
    {
        std::cout << "Freeing " << size << " bytes\n";

        free(memory);
    }

    int main() {...}

# <<< C++ lvalues, rvalues >>> #

    (left vs right)
    lvalues                 - Object has an identifiable location in memory
    rvalues                 - Object has no identifiable location in memory

    e.g.                    - int returnValue() {  return 20;  }
                            - int& returnRef()  {  static int value = 30;    return value;  }
                            - int x = 10;
                            - int y = returnValue();
                            - returnRef() = 40;
                            - 
    lvalues                 - lvalues == ( x,  y,  returnRef() )
    rvalues                 - rvalues == ( 10, 40, returnValue() )

    Only lvalues            - int& a = x;           (Run)
                            - int& b = 10;          (Fail)
    Both                    - const int& a = x;     (Run)
                            - const int& b = 10;    (Run)       (int temp = 10;  const int& b = temp)
    Only rvalues            - int&& a = x;          (Fail)
                            - int&& b = 10;         (Run)

    Uses                    - Can be used with function overload,
                            - in order to differentiate/enforce (rvalues from lvalues) inputs

    !!! C++ guarantees that a local temporary variable will be valid as long as there is a reference to it !!!
    !!! The lifetime of a temporary object may be extended by binding to a const lvalue reference or to an rvalue reference !!!

# <<< C++ std::move SEMANTICS (C++11) >>> #

    Semantics               - Move to avoid Copying/Allocating memory + Faster

    Idea                    - Human a;
                            - Human b = std::move(a);
                            - a == (Empty "in a good state" avoiding crashes when needed "such as destructor call")
                            - b == (Contains all previous a INFO)

    #include <utility>      - std::exchange();

    class Human                                     - Move Constructor
    {                                               - Used when:
        ...                                         - When a temporary value(rvalue) is passed to the constructor
        Human(Human&& source) noexcept {
            name(std::move(source.name));           // explicit move of a member of class type      (string has a move constructor)
            age (std::exchange(source.age, 0));     // explicit move of a member of non-class type  (age does not have (Primitive))

            // my_pointer = source.my_pointer;      // In case of pointers remember
            // source.my_pointer = nullptr;
        }
        ...
    };

    ---                             - Child Constructor call Move Constructor
    class Hero : public Human {
        private:
            ...
        public:
            ...
            Hero(const Hero& source) : Human(source) {}             - Calls Copy Constructor
            Hero(Hero&& source)      : Human(source) {}             - Calls Copy Constructor

            Hero(Hero&& source)    : Human(( Human&& )source ) {}   - Calls Move Constructor
            Hero(Hero&& source)    : Human(std::move( source ))     - Calls Move Constructor (Better)
            {
                power = std::move(source.power);
            }
    };
    ---

    # <<< C++ std::move BEHAVIOR >>> #

        class B : Human {
            std::string name2;
            int age2;
            // implicit move constructor B::(B&&)
            // calls Human's move constructor
                // calls name2's move constructor
                // and makes a bitwise copy of age2
        };

        class D : B {
            D() {}
            ~D() {}                 // destructor would prevent implicit move constructor D::(D&&)
            D(D&&) = default;       // forces a move constructor anyway
        };

    # <<< C++ operator= std::Move >>> #

        Usually "operator=" makes a copy, however, it can be overloaded to use std::move()

        Idea                - Human a;
                            - Human b;
                            - b = a;
                            - a == (Empty "in a good state" avoiding crashes when needed "such as destructor call")
                            - b == (Contains all previous a INFO)

        #include <utility>  - std::exchange();

        class Human                                         - Assign operator
        {                                                   - Used when:
            ...                                             - When assigning an object to an already constructed object
            Human& operator=(Human&& source) noexcept {
                if (this != &other)                         // Prevent my_h1 = std::move(my_h1);
                {
                    // delete my_pointer;                   // First delete all current data (""this->"")
                    
                    name(std::move(source.name));           // explicit move of a member of class type      (string has a move constructor)
                    age (std::exchange(source.age, 0));     // explicit move of a member of non-class type  (age does not have (Primitive))

                    // my_pointer = source.my_pointer;      // In case of pointers remember
                    // source.my_pointer = nullptr;
                }

                return *this;
            }
            ...
        };

# <<< C++ Operator-> >>> #

    struct Vector3 {
        int x,y,z;
    }

    int offset = (int)&((Vector3*)nullptr)->x;      - offset == 0
    int offset = (int)&((Vector3*)nullptr)->y;      - offset == 4
    int offset = (int)&((Vector3*)nullptr)->z;      - offset == 8

# <<< C++ OPTIONAL, VARIANT, ANY >>> #

    # <<< C++ OPTIONAL >>> #

        include <optional>      - Handle data that may or may not be there

        std::optional< std::string > ReadFile (const std::string& filepath) {
            ...
            if (file.is_open()) {
                // Read File ...
                return text;                - OR return std::optional< std::string >(text);
            }
            return {};                      - OR return std::optional< std::string >();
        }

        int main() {
            std::optional< std::string > data = ReadFile (...);
            if (data.has_value()) {
                std::cout << "File read successfully\n;
            }
            else {
                std::cout << "File could not be open\n;
            }
        }

        !!! AVOID COPIES !!!            - std::optional<TYPE*>

    # <<< C++ VARIANT >>> #

        #include <variant>  - """ SAFER UNION """ + USES MORE MEMORY
                            - When you do not know/care the data you are storing
                            - Store any TYPE given inside <...>

        Declaration         - std::variant< std::string, int > data;        (0 == std::string, 1 == int)
        Assign              - data = "StringText";
        Get                 - std::get< std::string > (data);               (Success)
                            - data = 312;
                            - std::get< int > (data);                       (Success)
                            - std::get< std::string > (data);               (Exception)
        TYPE Index          - data.index();
                                - returns 1                                 (data == int == 1)
        Safe Get            - if (auto value = std::get_if<std::string>(&data))
                            - { std::string& v = *value; }

    # <<< C++ ANY >>> #

        #include <any>      - """ SAFER void* """
                            - std::variable without specifying accepted TYPES
                            - " Slower and Less safe than std::variable "
                            - Store any data

        Declaration         - std::any data;
        Dec + Assign        - std::any data = std::make_any();
        Assign              - data = 2;
                            - data = true;
                            - data = std::string("Hello");
        Get                 - std::any_cast< std::string > (data);
                                - if data is String                         (Success)
                                - if data is not String                     (Exception)

# <<< C++ VISUAL BENCHMARKING >>> #

    chrome://tracing
    https://www.youtube.com/watch?v=xlAH4dbMVnU&t=319s&ab_channel=TheCherno

    Copy and paste

# <<< C++ UNDEFINED BEHAVIOR >>> #

    Result may vary from compiler to compiler
    e.g.
    callFunc( value++, value++);

    Access https://wandbox.org/ to test with different compiler

# <<< C++ BINARY AND BITWISE OPERATORS >>> #

    Manipulate Binary and bits (Math with base 2)

    <<          - Bit shift left
    >>          - Bit shift right
    &           - AND
    |           - OR
    ^           - XOR
    ~           - NOT

    Inside code     - int i = 5;
    Most CPUS       - [0000 0101] [0000 0000] [0000 0000] [0000 0000]       (4 bytes)   ("Inverse")
    Some CPUS       - [0000 0000] [0000 0000] [0000 0000] [0000 0101]       (4 bytes)
    Memory view     -    [05]         [00]        [00]        [00]          (4 bytes)   (Hexadecimal)

    Unsigned Integers Bitwise Operations

    i <<= 1;        - [0000 1010] [0000 0000] [0000 0000] [0000 0000]       (i == 10)   (Double)
    i >>= 1;        - [0000 0101] [0000 0000] [0000 0000] [0000 0000]       (i == 5)    (Half)

    create mask     - unsigned int mask = 0b00000100;
    i & mask        - [0000 0101] [0000 0000] [0000 0000] [0000 0000]       (i)
                    - [0000 0100] [0000 0000] [0000 0000] [0000 0000]       (mask)
    return          - [0000 0100] [0000 0000] [0000 0000] [0000 0000]       (remove all, except)
                    - if return value == 0; Bit was 0                       (check if Bit is 0 or 1)
                    - else if value >0; Bit was 1

    create mask     - unsigned int mask = 0b10100000;
    i | mask        - [0000 0101] [0000 0000] [0000 0000] [0000 0000]       (i)
                    - [1010 0000] [0000 0000] [0000 0000] [0000 0000]       (mask)
    return          - [1010 0101] [0000 0000] [0000 0000] [0000 0000]       (Add)

    create mask     - unsigned int mask = 0b00000100;
    invert mask     - mask = ~mask;
    i & mask        - [0000 0101] [0000 0000] [0000 0000] [0000 0000]       (i)
                    - [1111 1011] [1111 1111] [1111 1111] [1111 1111]       (mask)
    return          - [0000 0001] [0000 0000] [0000 0000] [0000 0000]       (Keep all, except)

    (Exclusive/XOR) - 0 ^ 0 == 0
                    - 0 ^ 1 == 1
                    - 1 ^ 0 == 1
                    - 1 ^ 1 == 0
    i ^ i == 0

    # <<< C++ INT BITS >>> #

        signed int n = 0b [1000 0000] [0000 0000] [0000 0000] [0000 0000];      (-2147483648)
        signed int p = 0b [0000 0000] [0000 0000] [0000 0000] [0000 0000];      (0)
        signed int n = 0b [1111 1111] [1111 1111] [1111 1111] [1111 1111];      (-1)
        signed int p = 0b [0111 1111] [1111 1111] [1111 1111] [1111 1111];      (2147483647)

        unsigned int u = 0b [1111 1111] [1111 1111] [1111 1111] [1111 1111];    (MAX_INT)
        u + 1  $[0000 0001]$ [0000 0000] [0000 0000] [0000 0000] [0000 0000]    (0)

# <<< C++ OPERATORS OVERLOADING >>> #

    In C++ you can make any operator do anything just by overloading
    https://en.cppreference.com/w/cpp/language/operators

    e.g.
    Instead of creating     - TYPE addFunction(const TYPE& other) {...}
    Overload operator+      - TYPE operator+  (const TYPE& other) {...}

    Calls                   - my_obj.addFunction(my_obj2);
                            - my_obj.operator+  (my_obj2);      // Inside class
                            - my_obj + my_obj2                  // Outside class

    MORE EXAMPLES IN # <<< C++ ITERATORS >>> #

    Operator List:

    # <<< C++ operator< >>> #

        Make an object comparable

        bool Airport::operator<(const Airport& other) const {
            return (name < other.name) ? true:false;
        }

    # <<< C++ operator> >>> #

        After implementing operator<

        bool Airport::operator>(const Airport& other) const {
            return (! (operator<(other)));
        }

    # <<< C++ operator== >>> #

        bool Airport::operator==(const Airport& other) const {
            return (name == other.name) ? true:false;
        }

    # <<< C++ operator= >>> #

        void Airport::operator=(const Airport& other) {
            name = other.name;
        }

    operator+
    operator[]
    operator+=
    operator++
    ...
    operator<<
    operator>>
    operator&
    operator|
    operator^
    operator~
    ...

# <<< C++ STATIC ANALYSIS >>> #

    Applications that find possible code mistakes

    clang-tidy

# <<< C++ constexpr >>> #

    constexpr size_t size() const {             - constexpr == constant expression
        return S;                               - This function can be evaluated at compile time
    }                                           - """ returns const variable """

    constexpr int* ptr          - The pointer itself is const, not the value
                                - == int* const ptr;

# <<< C++ Creating Data Structures >>> #

    Because we use Templates, the entire code is in a header file

    # <<< C++ ARRAY >>> #

        #pragma once

        #include <iostream>

        template<typename T, size_t S>
        class Array {
            private:
                T m_data[S];
            public:
                constexpr size_t size() const {             // constexpr == constant expression
                    return S;                               // This function can be evaluated at compile time
                }                                           // """ returns const variable """

                T& operator[] (size_t index) {
                    return m_data[index];                   // operator[] for non-const Objects
                }
                const T& operator[] (size_t index) const {
                    return m_data[index];                   // operator[] for const Objects
                }

                T* begin() {                        // Allows for each iterations
                    return &m_data[0];
                }
                T* end() {                          // Allows for each iterations
                    return &m_data[SIZE];
                }

                ...
        };
    
    # <<< C++ VECTOR >>> #

        #pragma once

        #include <iostream>

        template<typename T>
        class Vector {
            private:
                T* m_data = nullptr;        // mutable array
                size_t m_size = 0;          // current index
                size_t m_capacity = 0;      // current size reserved
            public:
                Vector() {
                    ReAlloc(2);             // Start by reserving some space
                }

                ~Vector() {                 // Only works when typename T is not a pointer,
                                            // However, is the user responsibility to delete them.

                    clear();
                    ::operator delete(m_data, m_capacity * sizeof(T));  // Does not call destructors
                }

                void push_back(const T& value) {                        // Add
                    if (m_size >= m_capacity) {
                        ReAlloc( m_capacity + m_capacity / 2 );
                    }

                    m_data[m_size] = value;
                    m_size++;
                }

                void push_back(T&& value) {                             // Add
                    if (m_size >= m_capacity) {
                        ReAlloc( m_capacity + m_capacity / 2 );
                    }

                    m_data[m_size] = std::move(value);
                    m_size++;
                }

                template <typename... Args>                             // Make
                T& emplace_back(Args&&... args) {
                    if (m_size >= m_capacity) {
                        ReAlloc( m_capacity + m_capacity / 2 );
                    }

                    new(&m_data[m_size]) T(std::forward<Args>(args)...);    // Make inside
                                                                            // new != new()

                    // m_data[m_size] = T(std::forward<Args>(args)...);     // Unpack arguments, forward them to T's constructor
                                                                            // Move it to m_data[m_size]

                    m_size++;
                    return m_data[m_size-1];
                }

                void pop_back() {                               // Remove last
                    if (m_size > 0) {
                        m_size--;
                        m_data[m_size].~T();                    // Explicitly call the destructor
                    }
                }

                void clear() {                                  // Clear
                    for (size_t i = 0; i < m_size; i++) {
                        m_data[i].~T();                         // Explicitly call the destructor
                    }

                    m_size = 0;
                }

                const T& operator[](size_t index) const {       // only view (const)
                    return m_data[index];
                }
                T& operator[](size_t index) {                   // modifiable
                    return m_data[index];
                }

                size_t size() const {
                    return m_size;
                }

                T* begin() {                            // Allows for each iterations
                    return &m_data[0];
                }
                T* end() {                              // Allows for each iterations
                    return &m_data[m_size];
                }
            private:
                void ReAlloc(size_t newCapacity) {              // ReSize capacity (grow or shrink)
                                                                // Copy/Move data to new array

                    T* newData = (T*)::operator new( newCapacity * sizeof(T) );
                                                                    //
                                                                    // returns void
                                                                    // Does not call constructors
                                                                    // Just alloc memory
                                                                    // (~C++ malloc)
                    size_t OriginalSize = m_size;
                    if (newCapacity < m_size) {
                        m_size = newCapacity;
                    }

                    for (size_t i = 0; i < m_size; i++) {
                        // newData[i] = std::move(m_data[i]);       // newData[i] has only sizeof(T). It is not an object of type T
                        new (&newData[i]) T(std::move(m_data[i]));  // Use new() to solve this problem
                                                                    // new() uses the memory (&)
                                                                    // and inserts a value in it
                    }

                    for (size_t i = 0; i < OriginalSize; i++) {
                        m_data[i].~T();
                    }

                    ::operator delete(m_data, m_capacity * sizeof(T));  // Does not call destructors
                                                                        // Just free memory
                                                                        // (~C++ free)
                    m_data = newData;
                    m_capacity = newCapacity;
                }
        };

    # <<< C++ LINKED LIST >>> #

        Single   Linked List    - Navigation is forward only
        Double   Linked List    - Forward and backward navigation
        Circular Linked List    - Last element is linked to the first element

        Head and Tail           - with sentinel nodes
                                - without sentinel nodes

        # <<< LL >>> #

            #pragma once

            #include <stdexcept>
            #include "node.h"

            template <typename T>
            class LL {
                private:
                    Node<T> m_head;
                    Node<T> m_tail;
                    size_t m_size = 0;
                public:
                    LL() {
                        //std::cout << "LL CONSTRUCTOR" << "\n";
                        m_head.setNext(&m_tail);
                        m_tail.setPrev(&m_head);
                    }
                    ~LL() {
                        //std::cout << "LL DESTRUCTOR" << "\n";
                        Node<T>* prevNode = nullptr;
                        Node<T>* currNode = m_head.getNext();
                        
                        while (currNode != &m_tail) {
                            prevNode = currNode;
                            currNode = currNode->getNext();
                            //std::cout << "DELETED WHILE - ";
                            //if (prevNode->getData()) {
                                //std::cout << *prevNode->getData();
                            //}
                            //std::cout << "\n";
                            delete prevNode;
                        }
                    }

                    void add(T& value) {
                        Node<T>* toAdd = new Node<T>(value);
                        insertion(toAdd, m_size);
                    }
                    void add(T&& value) {
                        Node<T>* toAdd = new Node<T>(std::move(value));
                        insertion(toAdd, m_size);
                    }

                    void insert(T& value, size_t index) {
                        Node<T>* toAdd = new Node<T>(value);
                        insertion(toAdd, index);
                    }
                    void insert(T&& value, size_t index) {
                        Node<T>* toAdd = new Node<T>(std::move(value));
                        insertion(toAdd, index);
                    }

                    void remove(size_t index) {
                        Node<T>* toRemove = remotion(index);
                        delete toRemove;
                    }

                    T& get(size_t index) {
                        return *(getter(index)->getData());
                    }

                    size_t size() const {
                        return m_size;
                    }

                private:
                    void insertion(Node<T>* toAdd, size_t index) {
                        if (index < 0 || index > m_size) {
                            throw std::invalid_argument("Index out of bounds");
                        }

                        Node<T>* nextNode = m_head.getNext();
                        for (size_t i = 0; i < index; i++) {
                            nextNode = nextNode->getNext();
                        }
                        Node<T>* prevNode = nextNode->getPrev();

                        prevNode->setNext(toAdd);
                        toAdd->setPrev(prevNode);
                        toAdd->setNext(nextNode);
                        nextNode->setPrev(toAdd);
                        m_size++;
                    }

                    Node<T>* remotion(size_t index) {
                        if (index < 0 || index >= m_size) {
                            throw std::invalid_argument("Index out of bounds");
                        }

                        Node<T>* toRemove = m_head.getNext();
                        for (size_t i = 0; i < index; i++) {
                            toRemove = toRemove->getNext();
                        }
                        Node<T>* prevNode = toRemove->getPrev();
                        Node<T>* nextNode = toRemove->getNext();

                        prevNode->setNext(nextNode);
                        nextNode->setPrev(prevNode);
                        m_size--;
                        return toRemove;
                    }

                    Node<T>* getter(size_t index) {
                        if (index < 0 || index >= m_size) {
                            throw std::invalid_argument("Index out of bounds");
                        }

                        Node<T>* toGet = m_head.getNext();
                        for (size_t i = 0; i < index; i++) {
                            toGet = toGet ->getNext();
                        }

                        return toGet;
                    }
            };

        # <<< NODE >>> #

            #pragma once

            #include <iostream>

            template <typename T>
            class Node {
                private:
                    Node<T>* prev = nullptr;
                    Node<T>* next = nullptr;
                    T* data = nullptr;
                    bool memAllocated = false;
                public:
                    Node() {
                        //std::cout << "DEFAULT CONSTRUCTOR" << "\n";
                    };
                    Node(T& data) {
                        //std::cout << "RVALUE CONSTRUCTOR" << "\n";
                        this->data = &data;
                    }
                    Node(T&& data) {
                        //std::cout << "LVALUE CONSTRUCTOR" << "\n";
                        this->data = new T(std::(data));
                        memAllocated = true;
                    }
                    ~Node() {
                        //std::cout << "NODE DESTRUCTOR" << "\n";
                        if (memAllocated) {
                            //std::cout << "LVALUE DELETED" << "\n";
                            delete data;
                        }
                    }

                    void setPrev(Node<T>* prev) {
                        this->prev = prev;
                    }
                    void setNext(Node<T>* next) {
                        this->next = next;
                    }

                    Node<T>* getPrev() const {
                        return prev;
                    }
                    Node<T>* getNext() const {
                        return next;
                    }
                    T* getData() const {
                        return data;
                    }
                    
                    friend std::ostream& operator<<(std::ostream& out, const Node<T>& node) {
                        out << *(node.data);
                        return out;
                    }
            };

    # <<< C++ BST >>> #

        # <<< BST >>> #

            #pragma once

            #include "node.h"
            #include <stdexcept>
            #include <list>

            template <typename T>
            class BST {
                private:
                    Node<T>* root = nullptr;
                public:
                    BST() = default;
                    ~BST() {
                        std::list<Node<T>*> queue;
                        queue.push_back(root);
                        while (!queue.empty()) {
                            Node<T>* currNode = queue.front();
                            queue.pop_front();
                            if (currNode != nullptr) {
                                queue.push_back(currNode->getLeftChild());
                                queue.push_back(currNode->getRightChild());
                                delete currNode;
                            }
                        }
                    }

                    void add(T& data) {
                        Node<T>* toAdd = new Node<T>(data);
                        insertion(toAdd);
                    }
                    void add(T&& data) {
                        Node<T>* toAdd = new Node<T>(std::move(data));
                        insertion(toAdd);
                    }
                    void remove(const T& data) {
                        Node<T>* toRemove = search(data);
                        if (toRemove == nullptr) {
                            std::cout << "Value not in" << "\n";
                        }
                        else {
                            if (toRemove->getRightChild() == nullptr && toRemove->getLeftChild() == nullptr) {
                                if (toRemove == root) {
                                    delete root;
                                    root = nullptr;
                                }
                                else {
                                    Node<T>* parent = toRemove->getParent();
                                    if (parent->getRightChild() == toRemove) {
                                        parent->setRightChild(nullptr);
                                    }
                                    else {
                                        parent->setLeftChild(nullptr);
                                    }
                                    delete toRemove;
                                }
                            }
                            else if (toRemove->getRightChild() != nullptr) {
                                Node<T>* rightChild = toRemove->getRightChild();
                                if (rightChild->getLeftChild() == nullptr) {
                                    if (rightChild->getRightChild() == nullptr) {
                                        toRemove->setRightChild(nullptr);
                                    }
                                    else {
                                        toRemove->setRightChild(rightChild->getRightChild());
                                        rightChild->getRightChild()->setParent(toRemove);
                                    }
                                    moveData(toRemove, rightChild);
                                    delete rightChild;
                                }
                                else {
                                    Node<T>* currNode = rightChild->getLeftChild();
                                    Node<T>* prevNode = currNode;
                                    while (currNode != nullptr) {
                                        prevNode = currNode;
                                        currNode = currNode->getLeftChild();
                                    }
                                    Node<T>* parent = prevNode->getParent();
                                    moveData(toRemove, prevNode);
                                    if (prevNode->getRightChild() == nullptr) {
                                        parent->setLeftChild(nullptr);
                                    }
                                    else {
                                        parent->setLeftChild(prevNode->getRightChild());
                                        prevNode->getRightChild()->setParent(parent);
                                    }
                                    delete prevNode;
                                }
                            }
                            else {
                                Node<T>* leftChild = toRemove->getLeftChild();
                                if (leftChild->getRightChild() == nullptr) {
                                    if (leftChild->getLeftChild() == nullptr) {
                                        toRemove->setLeftChild(nullptr);
                                    }
                                    else {
                                        toRemove->setLeftChild(leftChild->getLeftChild());
                                        leftChild->getLeftChild()->setParent(toRemove);
                                    }
                                    moveData(toRemove, leftChild);
                                    delete leftChild;
                                }
                                else {
                                    Node<T>* currNode = leftChild->getRightChild();
                                    Node<T>* prevNode = currNode;
                                    while (currNode != nullptr) {
                                        prevNode = currNode;
                                        currNode = currNode->getRightChild();
                                    }
                                    Node<T>* parent = prevNode->getParent();
                                    moveData(toRemove, prevNode);
                                    if (prevNode->getLeftChild() == nullptr) {
                                        parent->setRightChild(nullptr);
                                    }
                                    else {
                                        parent->setRightChild(prevNode->getLeftChild());
                                        prevNode->getLeftChild()->setParent(parent);
                                    }
                                    delete prevNode;
                                }
                            }
                        }
                    }
                    bool contains(const T& data) {
                        return (search(data) != nullptr);
                    }

                    void printBFS() {
                        std::list<Node<T>*> queue;
                        queue.push_back(root);
                        std::cout << "[";
                        while (!queue.empty()) {
                            Node<T>* currNode = queue.front();
                            queue.pop_front();
                            if (currNode != nullptr) {
                                std::cout << *currNode->getData() << ", ";      // , or \n
                                queue.push_back(currNode->getLeftChild());
                                queue.push_back(currNode->getRightChild());
                            }
                        }
                        std::cout  << "]\n";
                    }

                private:
                    void insertion(Node<T>* toAdd) {
                        if (contains(*toAdd->getData())) {
                            std::cout << "Value already in" << "\n";
                        }
                        else {
                            if (root == nullptr) {
                                root = toAdd;
                            }
                            else {
                                Node<T>* currNode = root;
                                Node<T>* prevNode = nullptr;
                                while (currNode != nullptr) {
                                    prevNode = currNode;
                                    if (*toAdd->getData() > *currNode->getData()) {
                                        currNode = currNode->getRightChild();
                                        if (currNode == nullptr) {
                                            prevNode->setRightChild(toAdd);
                                            toAdd->setParent(prevNode);
                                        }
                                    }
                                    else {
                                        currNode = currNode->getLeftChild();
                                        if (currNode == nullptr) {
                                            prevNode->setLeftChild(toAdd);
                                            toAdd->setParent(prevNode);
                                        }
                                    }
                                }
                            }
                        }
                    }

                    void moveData(Node<T>* to, Node<T>* from) {
                        to->deleteData();
                        to->setData(from->getData());
                        if (from->isMemoryAllocated()) {
                            to->setIsMemoryAllocated(true);
                            from->setIsMemoryAllocated(false);
                        }
                    }

                    Node<T>* search(const T& data) {
                        Node<T>* currNode = root;
                        while (currNode != nullptr) {
                            if (data > *currNode->getData()) {
                                currNode = currNode->getRightChild();
                            }
                            else if (data < *currNode->getData()) {
                                currNode = currNode->getLeftChild();
                            }
                            else {
                                return currNode;
                            }
                        }
                        return nullptr;
                    }
            };

        # <<< NODE >>> #

            #pragma once

            #include <iostream>

            template <typename T>
            class Node {
                private:
                    Node<T>* m_parent = nullptr;
                    Node<T>* m_leftChild = nullptr;
                    Node<T>* m_rightChild = nullptr;
                    T* m_data = nullptr;
                    bool is_memoryAllocated = false;
                public:
                    Node() = default;
                    Node(T& data) {
                        m_data = &data;
                    }
                    Node(T&& data) {
                        m_data = new T(std::move(data));
                        is_memoryAllocated = true;
                    }
                    ~Node() {
                        deleteData();
                    }

                    void setParent(Node<T>* parent) {
                        m_parent = parent;
                    }
                    void setLeftChild(Node<T>* leftChild) {
                        m_leftChild = leftChild;
                    }
                    void setRightChild(Node<T>* rightChild) {
                        m_rightChild = rightChild;
                    }
                    void setData(T* data) {
                        m_data = data;
                    }
                    void setIsMemoryAllocated(bool state) {
                        is_memoryAllocated = state;
                    }

                    Node<T>* getParent() {
                        return m_parent;
                    }
                    Node<T>* getLeftChild() {
                        return m_leftChild;
                    }
                    Node<T>* getRightChild() {
                        return m_rightChild;
                    }
                    T* getData() {
                        return m_data;
                    }
                    bool isMemoryAllocated() {
                        return is_memoryAllocated;
                    }

                    void deleteData() {
                        if (is_memoryAllocated) {
                            delete m_data;
                            is_memoryAllocated = false;
                        }
                    }

                    friend std::ostream& operator<<(std::ostream& out, const Node<T>& node) {
                        out << *node.data;
                        return out;
                    }
            };

    # <<< C++ TRIES >>> #
    # <<< C++ HASH TABLE >>> #
    # <<< C++ HEAP >>> #
    # <<< C++ GRAPHS >>> #

# <<< C++ ITERATORS >>> #

    Implement iteration

    Inside my VECTOR.H
    ...
    template<typename Vector>
    class VectorIterator
    {
        public:
            using ValueType     = typename Vector::ValueType;
            using PointerType   = ValueType*;
            using ReferenceType = ValueType&;
        public:
            VectorIterator(PointerType ptr)
                : m_ptr(ptr); {}

            VectorIterator& operator++()                        // prefix operator
            {                                                   // ++var;
                m_ptr++;
                return *this;
            }
            VectorIterator& operator++(int)                     // postfix operator
            {                                                   // var++;
                VectorIterator iterator = *this;
                ++(*this);
                return iterator;
            }
            VectorIterator& operator--()                        // prefix operator
            {                                                   // --var;
                m_ptr--;
                return *this;
            }
            VectorIterator& operator--(int)                     // postfix operator
            {                                                   // var--;
                VectorIterator iterator = *this;
                --(*this);
                return iterator;
            }

            ReferenceType operator[](int index)
            {
                return *(m_ptr + index);
            }

            PointerType operator->()
            {
                return m_ptr;
            }

            ReferenceType operator*()
            {
                return *m_ptr;
            }

            bool operator==(const VectorIterator& other) const
            {
                return m_ptr == other.m_ptr;
            }
            bool operator!=(const VectorIterator& other) const
            {
                return !(*this == other);
            }
            
        private:
            PointerType m_ptr;
    };
    ...
    template<typename T>
    class Vector {
        public:
            using ValueType = T;
            using Iterator  = VectorIterator<Vector<T>>;
        ...
        public:
            Iterator begin() {
                return Iterator(m_data);
            }

            Iterator end() {
                return Iterator(m_data + m_size);
            }
        ...
    };

# <<< C++ typename... Args >>> #

    ... Args            - Unspecified number of arguments / Pack inputs

    Args ...            - Unpack arguments

    e.g.

    template <typename... Args>                             // Make
    T& emplace_back(Args&&... args) {
        if (m_size >= m_capacity) {
            ReAlloc( m_capacity + m_capacity / 2 );
        }

        new(&m_data[m_size]) T(std::forward<Args>(args)...);    // Make inside
                                                                // new != new()

        // m_data[m_size] = T(std::forward<Args>(args)...);     // Unpack arguments, forward them to T's constructor
                                                                // Move it to m_data[m_size]
        
        m_size++;
        return m_data[m_size-1];
    }

# <<< C++ ::operator delete, ::operator new, new(), delete(), KEYWORD new, KEYWORD delete >>> #

    # <<< ::operator new >>> #
    
        - T* new_data = (T*)::operator new(sizeof(T) * new_capacity);
        - 
        - returns void*
        - Does not call constructors, just allocs memory    (~C++ malloc)
        - 
        - !!! newData[i] has only sizeof(T). It is not an object of type T !!!
        - !!! Use new() to solve this !!!
        -
        - Useful for:
            - 1. By avoid the constructor now, you can use new() later and make the data inside the memory address.
            - ( Faster and Better than std::move or operator= )

    # <<< new() >>> #

        - new ( &new_data[i] ) T( constructorParameters );
        - new ( &new_data[i] ) T( std::move(m_data[i]) );
        -
        - new ( human_ptr )    Human( ... );  //calls operator new(size_t, void*) via keyword
        - 
        - Does not allocate memory, just "inserts" data in the memory address
        - 
        - !!! new() != new !!!

    # <<< ::operator delete >>> #

        - ::operator delete(m_data, sizeof(T) * capacity);
        -
        - Does not call destructors, Just frees memory      (~C++ free)
        -
        - Useful for freeing:
            - 1. Data that already called the destructor
            - 2. Unconstructed data

    # <<< ?? delete() ?? >>> #

        - delete ( &new_data[i] );
        -
        - Does not free/release memory, just cleans data of the memory address
        -
        - !!! delete() != delete !!!

    # <<< KEYWORD new >>> #

        - int* ptr = new int;
        - 
        - Actions:
            - Calls the ::operator new
            - Calls object constructor

    # <<< KEYWORD delete >>> #

        - delete ptr;
        - 
        - Actions:
            - Calls object destructor
            - Calls the ::operator delete

    :: means global namespace

# <<< C++ MEMORY >>> #

    # <<< LAYOUT >>> #

        LIFO                        - Each scope {} is a different block of memory
        Memory Layout               - https://www.geeksforgeeks.org/memory-layout-of-c-program/
    
        |----------------------|
        |        System        |    - Command Line Arguments
        |----------------------|
        |        Stack         |    - Memory is finite and "small"
        |                      |    - The developer isn't in full control of the memory lifetime
        |                      |    - Lifetime is controlled by the scope mechanism
        |- - - - - - - - - - - |    - e.g. Local variable, functions
        |          ||          |
        |          ||          |
        |          ||          |
        |          \/          |
        |                      |
        |                      |
        |                      |
        |          /\          |
        |          ||          |
        |          ||          |
        |          ||          |
        |- - - - - - - - - - - |    - Memory is finite and "large"
        |                      |    - The developer is in full control of when the memory is allocated and released
        |                      |    - Lifetime is explicitly controlled through new and delete operators
        |        Heap          |    - e.g. Additional memory that can be queried during run time
        |----------------------|
        |    Uninitialized     |
        |        Data          |
        |                      |
        |----------------------|
        |     Initialized      |
        |        Data          |
        |                      |
        |----------------------|
        |        Text          |    - Text Evaluation
        |                      |    - Pre-process stage controls what code is passed to the compiler
        |----------------------|    - Everything that starts with # is evaluated at pre-process time

    # <<< STATIC MEMORY ALLOCATION >>> #

        Allocated in the STACK.
        Memory allocated during compile time.
        The memory is defined at compile time.
        The memory is fixed and cannot be increased or decreased during run time.
        Memory is deallocated in a defined order. "STACK"

    # <<< DYNAMIC MEMORY ALLOCATION >>> #

        Allocated in the HEAP.
        Memory allocated during run time.
        The memory is defined at run time.
        The memory can be increased or decreased during run time.
        Memory is deallocated without any order.

        HEAP memory can only be accessed through pointers.

        # <<< C BUILT IN FUNCTIONS >>> #

            # <<< malloc() >>> #

                malloc declared in <stdlib.h>
                short for "memory allocation"
                Used to dynamically allocate a single large block of contiguous memory,
                according to the size specified.

                Syntax:     ( void* )malloc( size_t size )

                Return:     - Success:  A pointer pointing to the first byte of the allocated memory
                            - Failure:  NULL
                            - 
                            - Memory allocated by malloc is initialized with GARBAGE VALUE

                malloc does not know the type of the pointer, it just allocates the memory requested.
                !!! The void* can be typecasted to an appropriate type !!! e.g.

                int* ptr = (int* )malloc(sizeof(int));

            # <<< calloc() >>> #

                calloc declared in <stdlib.h>
                short for "clear allocation"
                Used to dynamically allocate multiple blocks of memory.

                Difference from malloc():

                    - calloc() needs two arguments instead of one.

                    - Sintax:   void* calloc(size_t n, size_t size)
                    -
                    - n    = Number of blocks
                    - size = Size of each block
                
                Equivalency:

                    - int* ptr = (int* )calloc(10, sizeof(int));        - calloc
                    - 
                    - int* ptr = (int* )malloc(10 * sizeof(int));       - malloc
                    - 
                    - SAME RESULT, however,
                    - Memory allocated by calloc is initialized to ZERO

                Return:     - Success:  A pointer pointing to the first byte of the allocated memory
                            - Failure:  NULL

            # <<< realloc() >>> #

                realloc declared in <stdlib.h>
                Used to change the size of the memory block without losing the old data.

                Syntax:     void* realloc(void* ptr, size_t newSize)

                Return:     - Success:  A pointer pointing to the first byte of the allocated memory
                            - Failure:  NULL

                Example:

                    - int* ptr = (int* )malloc(sizeof(int));
                    - 
                    - ptr = (int* )realloc(ptr, 2*sizeof(int));
                    - 
                    - # This will allocate memory space of 2 * sizeof(int)
                    - # This function moves the contents of the old block to the new block
                    - # HOWEVER, if the new size is smaller than the old size, we may lose the data

            # <<< free() >>> #

                free declared in <stdlib.h>
                Used to release dynamically allocated memory in HEAP

                Syntax:     void free(ptr)

                e.g.

                free(my_ptr);       - User's responsibility to release the memory requested
                my_ptr = nullptr;   - GOOD PRACTICE

# <<< C++ DATA/TIME COMPLEXITY >>> #

    Data or Time complexity   - Exact complexity
    Asymptotic complexity     - Only the most relevant complexity (approximate)
    Big O Notation            - 
    
    O(1)          (constant)
    O(log n)      (logarithmic)
    O(n)          (linear)
    O(n log n)    (sub-quadratic or super-linear)
    O(n^2)        (quadratic)
    O(2^n)        (exponential)
    O(n!)         (factorial)

    # <<< EXAMPLES 1, LOOPS >>> #

        int i;          \
        int k;           |                      - Total time = 1 + 1 + 1
        int n = 20;     /                       - O(1)

        for (i = 0; i <= n; i++) {
            ...                                 - Total time = n
        }                                       - O(n)

        for (i = 0; i <= n; i++) {
            for (k = 0; k <= n; k++) {
                ...                             - Total time = n * n
            }                                   - O(n^2)
        }

        Time Complexity                         - f(n) = 3 + n + n^2
                                                - O(n^2)

    # <<< EXAMPLES 2, IF-ELSE >>> #

        int i;          \                       - Total time = 1 + 1
        int n = ...;    /                       - O(1)

        if (n == 0) {
            ...                                 - Total time = 1 + 1
        }                                       - O(1)
        else {
            for (i = 0; i <= n; i++) {
                ...                             - Total time = 1 + n
            }                                   - O(n)
        }
                                                - Worst case running time
                                                - Choose the largest block
                                                - in this case: ELSE( O(n) )

        Time Complexity                         - f(n) = 2 + n
                                                - O(n)

    # <<< EXAMPLES 3, LOGARITHMIC >>> #

        // log2(8) = 3
        // " How many times, 2 has been multiplied by itself in order to obtain value 8 "

        for (int i = 1; i <= n; i = i*2) {
            ...                                 - Total time = log2(n) + 1
        }                                       - O( log2(n) )

        for (int i = n; i >= 1; i = i/2) {
            ...                                 - Total time = log2(n) + 1
        }                                       - O( log2(n) )

# <<< C++ ITERATORS >>> #


    InputIterator - an input iterator type (supported operations: !=, *, ->, ++, *i++)
    OutputIterator - an output iterator type (supported operations: write and ++, *i++)
    ForwardIterator - an output iterator type (supported operations: !=, *, ->, ++, *i++)
    BiDirectionalIterator - an output iterator type (supported operations: !=, *, ->, ++, *i++, --)
    RandomAccessIterator - a random access iterator type (supported operations: !=, *, ->, ++, *i++, --, *i--, +, i, i[n], <, >, <=, >=)
    ContiguousIterator - an output iterator type (supported operations: !=, *, ->, ++, *i++, --, *i--, +, i, i[n], <, >, <=, >=, contiguous storage)

    The `std::back_inserter` is a type of output iterator that was introduced as part of the Standard Template Library (STL) in C++. 
    The STL, including `std::back_inserter`, has been part of C++ since the standardization of the language in 1998¹.

    In addition to the iterators you mentioned, there are also other special types of iterators provided by the STL, such as:

    - `std::front_inserter`: This is similar to `std::back_inserter`, but it inserts new elements at the beginning of the container using the container's `push_front` member function.
    - `std::inserter`: This iterator inserts new elements before the position pointed to by the iterator. It uses the container's `insert` member function.
    - `std::move_iterator`: This iterator allows elements to be moved from one container to another, rather than being copied.

    These iterators can be very useful in certain situations and can help make your code more concise and easier to understand¹². It's definitely worth getting to know them if you're doing a lot of work with the STL in C++.


# <<< C++ ??? >>> #
# <<< C++ ??? >>> #
# <<< C++ ??? >>> #











# <<< C++ BONUS >>> #

    # Using & in for each loops and in functions parameter avoids copying, however, if you want a copy to modify without affecting the real variable just do not use &

    # !!! REMEMBER, EVERYTHING IN JAVA AND PYTHON IS A POINTER !!!

    # int x = 15;           - Decimal       15
    # int x = 017;          - Octal         15
    # int x = 0x0F;         - Hexadecimal   15
    # int x = 0b00001111;   - Binary        15

    # goto keyword          - Jump to...

    # Stack
    # Queue

# <<< C++ IMPORTANT LIBRARIES >>> #

    iostream                - Core
    string                  - String
    string_view             - 
    cmath                   - Math handling         - https://en.cppreference.com/w/cpp/header/cmath
    Containers              - Data Structures
    Pseudo-random           - Random lib            - https://en.cppreference.com/w/cpp/numeric/random
    random                  - Random header         - https://en.cppreference.com/w/cpp/header/random
    fstream                 - File handling
    sstream                 - istringstream
    cctype                  - Char manip            - https://en.cppreference.com/w/cpp/header/cctype
    cstring                 - String manip          - https://en.cppreference.com/w/cpp/header/cstring
    memory                  - Smart pointers

# <<< C++ REFERENCES >>> #

    # Input/Output manip    - https://en.cppreference.com/w/cpp/io/manip
    # Operator Precedence   - https://en.cppreference.com/w/cpp/language/operator_precedence
    # Numeric Limits        - https://en.cppreference.com/w/cpp/types/numeric_limits

# <<< DICTIONARY >>> #

    # ASCII TABLE

    # Declaration                   -> int a;
    # Definition/Initialization     -> a = 22;

    # Attributes        ->  class variables
    # Methods           ->  class functions

# <<< GENERAL PROGRAMMING >>> #

    # Static Scoping        - Search this scope, if not found, search the outer scope           (Modern Languages)
    # Dynamic Scoping       - Search this scope, if not found, search the calling function      (Older Languages)


ALT + CLICK         - In Visual Studio this expand all / collapse all
                    - keyboard shortcut Ctrl + M, P to expand or Ctrl + M, O to collapse.
SHIFT + CLICK       - In Visual Studio this expand all / collapse all