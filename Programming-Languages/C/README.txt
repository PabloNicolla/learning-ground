# <<< C CORE >>> #

    #include <...>                         - Import library or header
    #include <stdio.h>
    int main(void) {}                       - 
    int main(int argc, char** argv) {}      - Execution start point
                                            - argc: Number of inputs + 1 (program name)
                                            - argv: Program name + Array of programs inputs        - e.g. File names

    # <<< INPUT / OUTPUT / %... >>> #

        # <<< !! COERCION !! >>> #

            The compiler does not automatically coerce the value,
            therefore a wrong conversion specifier will not work properly.

            'printf' will print 0 or a garbage value in a mismatch datatype

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

                char *fgets(char *str, int n, FILE *stream)

                char *fgets(stdin, 64,char *str);
                char *fgets(FILE*, 64,char *str);

    //          - Single line comment
    /**/        - Multiple lines comment
    /***/       - Formatted multiple lines comment

    # <<< TYPES >>> #

        # <<< !!! THEORY !!! >>> #

            C is a typed programming language.
            The type defines how the value is stored in memory (SIZE OF BYTES)
            and what operation are admissible.

            # <<< !! TYPE SIZE !! >>> #

                !!!
                CAUTION IS ADVISED SINCE TYPES' SIZE MAY CHANGE FROM MACHINE TO MACHINE.
                RECOMMENDATION IS TO SPECIFY THE EXACT SIZE AT THE DECLARATION,
                AND CHECK IF THE SIZE IS THE SIZE EXPECTED.
                !!!

            # <<< INTEGER vs FLOAT >>> #

                !!!
                INTEGER VALUES ARE STORED EXACTLY IN MEMORY.
                FLOATING POINT VALUES ARE STORED APPROXIMATELY.
                THEREFORE, WHEN PRECISION IS REQUIRED, USE ONLY INTEGERS.
                !!!

                !!
                INTEGER MANIPULATION IS FASTER THAN FLOATING POINT.
                !!

        CORE C TYPE         |           MEANING         |       MINIMUM SIZE                |
        --------------------|---------------------------|-----------------------------------|
        char                |           character       |       8  bits     (1 byte)        |
                            |                           |                                   |
        short               |     short integer         |       16 bits     (2 byte)        |
        int                 |           integer         |       16 bits     (2 byte)        |
        long                |      long integer         |       32 bits     (4 byte)        |
        long long           | long long integer         |       64 bits     (8 byte)        |
                            |                           |                                   |
        float         (f)   |   single-precision float  |       32 bits     (4 byte)        |
        double              |   double-precision float  |       64 bits     (8 byte)        |
        long double   (L)   | extended-precision float  |       64 bits     (8 byte)        |

        # <<< INITIALIZATION >>> #

            int x;                      - single
            int a, b, c = 0, d, e;      - multiple

            int a = b = 10;             - set multiple to same value

            # <<< NUMERIC CONSTANT >>> #

                int x           = 123;
                long x          = 123L;
                long long x     = 123LL;

                float x         = 123.321F;
                double x        = 123.321;
                long double x   = 123.321L;

        # <<< CONST >>> #

            const == make a variable read-only || it does not make it a constant expression

            Constant values cannot be changed after the initialization.
            It contributes to better code:
                - When modification is needed, only initialization value requires modification.
                - Prevents unwanted used of variable from other programmers.
                - ALL_CAPS_SEPARATED_BY_UNDERSCORE

            const [TYPE] [IDENTIFIER] = x;

    # <<< MACROS AS CONST >>> #

        Macros are declared before in the first scope.
        Macros are replaced by text during compile time.
        They are not variables, nor have memory addresses.

        Macros cannot be changed after the definition.
        It contributes to better code:
            - When modification is needed, only definition value requires modification.
            - Prevents unwanted used of variable from other programmers.
            - ALL_CAPS_SEPARATED_BY_UNDERSCORE

        # Define [MACRO_NAME] [x]

        Macros are constant expressions

    # <<< ESCAPE SEQUENCE >>> #

        It is preferred to used escape sequence than using the hexadecimal value.

        Character       | Sequence 
        ----------------|----------
        alarm           |   \a
        backspace       |   \b
        form feed       |   \f
        carriage return |   \r
        vertical tab    |   \v
                        |
        horizontal tab  |   \t
        newline         |   \n
                        |
        backslash       |   \\
        single '        |   \'
        double '        |   \"
        ?               |   \?

    # <<< OPERATORS >>> #

        For more info read "MIXED-TYPE EXPRESSION" in "THEORY"

        Check "ORDER OF PRECEDENCE" to understand compound expressions

        # <<< ARITHMETIC >>> #

            # <<< INTEGER >>> #

                # <<< BINARY >>> #
                
                    operand [OPERATOR] operand

                    +       - Add
                    -       - Subtract
                    *       - Multiply
                    /       - Divide
                    %       - Reminder
                
                # <<< UNARY >>> #

                    [OPERATOR] operand

                    +       - Unary, keep the current sign
                    -       - Unary, invert the current sign

                # <<< SHORTHAND ASSIGNMENT >>> #

                    variable [OPERAND] operand

                    +=              - sum and assign
                    -=              - sub and assign
                    *=              - mul and assign
                    /=              - div and assign
                    %=              - rem and assign
                    

                    variable++      - increment 1 after execution
                    variable--      - decrement 1 after execution

                    ++variable      - increment 1 before execution
                    --variable      - decrement 1 before execution

            # <<< FLOATING >>> #

                # <<< BINARY >>> #
                
                    operand [OPERATOR] operand

                    +       - Add
                    -       - Subtract
                    *       - Multiply
                    /       - Divide
                
                # <<< UNARY >>> #

                    [OPERATOR] operand

                    +       - Unary, keep the current sign
                    -       - Unary, invert the current sign

                # <<< SHORTHAND ASSIGNMENT >>> #

                    variable [OPERAND] operand

                    +=              - sum and assign
                    -=              - sub and assign
                    *=              - mul and assign
                    /=              - div and assign
                    

                    variable++      - increment 1 after execution
                    variable--      - decrement 1 after execution

                    ++variable      - increment 1 before execution
                    --variable      - decrement 1 before execution

        # <<< RELATIONAL >>> #

            TRUE  == 1 or greater
            FALSE == 0

            ==      - Equal
            >       -
            >=      - 
            <       - 
            <=      - 
            !=      - Not Equal 

        # <<< LOGICAL >>> #

            &&          - AND           - (false && ... anything after is not evaluated)
            ||          - OR            - (true  || ... anything after is not evaluated)
            !           - NOT

            # <<< deMorgan's Law >>> #

                The opposite of a compound condition is the compound condition with all 
                sub-conditions reversed,
                all &&'s changed to ||'s and all ||'s to &&'s.

                From        - adult = !child && !senior;

                To          - adult = !(child || senior);

    # <<< CASTING >>> #

        This list follows the type rank.

        (long double)   operand	        long double version of operand
        (double)        operand	        double version of operand
        (float)         operand	        float version of operand
        (long long)     operand	        long long version of operand
        (long)          operand	        long version of operand
        (int)           operand	        int version of operand
        (short)         operand	        short version of operand
        (char)          operand	        char version of operand

        # <<< STRING CASTING >>> #

            <stdlib.h>

            # <<< FROM STRING >>> #

                int x       = atoi(str);
                double x    = atof(str);

            # <<< TO STRING >>> #

                itoa(a,buffer,2);       // here 2 means binary          Binary value =
            
                itoa(a,buffer,10);      // here 10 means decimal        Decimal value =
            
                itoa(a,buffer,16);      // here 16 means Hexadecimal    Hexadecimal value =

                ftoa(n, res, afterPoint)
                    - n          --> Input Number
                    - res[]      --> Array where output string to be stored
                    - afterPoint --> Number of digits to be considered after the point.

        # <<< POINTER CASTING >>> #

            check 'POINTER' section for more info

    # <<< IF >>> #

        - if(bool);
        - if(bool), else;
        - if(bool), else if(bool), else;
                        
        - result = (condition) ? option1 : option2;         - ternary operator
                                     (T) : (F)
        
        # <<< IF STYLE >>> #

            if(bool) ... // one line works without block

            if(bool)
                ... // one line works without block

            if(bool)
            {
                ... // more than one line
                ... // requires block
            }

    # <<< SWITCH >>> #

        "choice" has some restrictions
    
        switch (choice)
        {
        case 'A' :
        case 'a' :
            ...
            break;
        case 'B' :
        case 'b' :
            ...
            break;
        case 'C' :
        case 'c' :
            ...
            break;
        default:
            ...
        }

    # <<< DO WHILE >>> #

        declaration
        do
        {
            initialization
            change
            sequence
        } while (condition);

    # <<< WHILE >>> #

        declaration
        initialization
        while (condition)
        {
            change
            sequence
        }

    # <<< FOR >>> #

        declaration
        for (initialization; condition; change)
        {
            sequence
        }

    # <<< ARRAY >>> #

        Check "ARRAY" in "THEORY" to see more info.

        An array is a data structure consisting of an ordered set of elements of common type that
        are stored contiguously in memory.

        # <<< !!! SIZE MUST BE CONSTANT !!! >>> #

            Unfortunately constant variables cannot be used in constant expressions.
            They are considered to be variables that cannot change,
            but not constants that can be determined at compile time.

            const int n = 42;
            int arr[n]; 

            doesn't compile in C89 because n is not a constant expression. 
            (it does compile in C99 only because C99 supports VLA)
            ((VARIABLE LENGTH ARRAYS))

        type identifier [ SIZE ];
        type identifier []          = {1, 2, 3, ..., n};            - size == n
        type identifier [ SIZE ]    = {0};                          - initialize all to 0
        type identifier [ SIZE ]    = {11, 0};                      - initialize the rest to 0

        identifier[INDEX]          - Access value

        # <<< 2D ARRAY >>> #
        
            Similar to spreadsheet.
            First index     == row
            Second index    == column

            type identifier [ SIZE ][ SIZE ];

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

        # <<< !! SAFE INITIALIZATION 2D/STRUCT !! >>> #

            Uninitialized arrays contains garbage values and are unsafe to use.

            double myArray[3][12]       = {0};
            struct Student students[10] = {0};

            or, if you want to avoid the gcc warning "missing braces around initializer" 
            (the warning appears with -Wall or, more specifically -Wmissing-braces)

            double myArray[3][12]       = { {0} };
            struct Student students[10] = { {0} };

    # <<< PARALLEL ARRAY >>> #

        AKA TABLE / MAP

        ARRAY_1 holds the key
        ARRAY_2 holds the value

        INDEX are related between both arrays.

    # <<< ADDITIONAL KEYWORDS >>> #

        # <<< EXIT >>> #


        # <<< BREAK >>> #


        # <<< CONTINUE >>> #

# <<< POINTER >>> #

    type* identifier;

    type* identifier = NULL;

    type* identifier = &x;

    *identifier = ...;

    # <<< MULTIPLE INITIALIZATION >>> #

        int *a, b;              - a is a pointer
                                - b is not a pointer

    # <<< ARRAY OF POINTERS >>> #

        char *names[10];        // Only use when there is no intention to modify strings

    # <<< POINTER CASTING >>> #

        (int*)
        (char*)
        (double*)
        (float*)
        (void*)
        (MyStruct*)

    # <<< VOID POINTERS >>> #

        A void* does not mean anything. It is a pointer, but the type that it points to is not known.

        It's not that it can return "anything". A function that returns a void* generally is doing one of the following:

        It is dealing in unformatted memory. This is what operator new and malloc return:
            a pointer to a block of memory of a certain size. Since the memory does not have a type
            (because it does not have a properly constructed object in it yet), it is typeless. IE: void.

        It is an opaque handle; it references a created object without naming a specific type.
            Code that does this is generally poorly formed,
            since this is better done by forward declaring a struct/class
            and simply not providing a public definition for it.
            Because then, at least it has a real type.

        It returns a pointer to storage that contains an object of a known type.
            However, that API is used to deal with objects of a wide variety of types,
            so the exact type that a particular call returns cannot be known at compile time.
            Therefore, there will be some documentation explaining when it stores which kinds of objects,
            and therefore which type you can safely cast it to.

        And on a personal note, if you see code that uses void*'s "often", you should rethink what code you're looking at.
        void* usage, especially in C++, should be rare, used primary for dealing in raw memory.

    # <<< FUNCTION POINTER // FUNCTION VARIABLE >>> #

        Useful for passing functions as arguments to other functions.
        
        # <<< DECLARATION / USAGE >>> #

            void compareGT(int x, int y) { printf("%d\n",(x > y) ? 1:0); }
            void compareST() { printf("%d\n",(10 < 20) ? 0:1); }

            int main(void) {

                int a = 10;
                int b = 20;

                void (*func1_ptr)(int,int) = compareGT;
                void (*func2_ptr)(void) = compareST;

                func1_ptr(a, b);
                func2_ptr();

                void (*func3_ptr)(int,int) = &compareGT;
                void (*func4_ptr)(void) = &compareST;

                func3_ptr(a, b);
                func4_ptr();

                return 0;
            }

        # <<< FUNCTION PARAMETER >>> #

            int myFunction(..., int(*sum)(int,int), ...) {...}

        # <<< ARRAYS OF FUNCTIONS >>> #

            int compareGT(int x, int y) { return (x > y) ? 1:0; }
            int compareST(int x, int y) { return (x < y) ? 0:1; }

            int main(void) {

                int a = 10;
                int b = 20;

                printf("%d\n", compareGT(a,b));
                printf("%d\n", compareST(a,b));

                int (*zed[2])(int,int) = {compareGT, compareST};

                printf("%d\n", zed[0](a,b));        
                printf("%d\n", zed[1](a,b));       

                return 0;
            }

    # <<< ARRAY POINTER >>> #

            int arr[5] = {1, 2, 3, 4, 5};

            int (*ptr)[5] = &arr;

            printf("%d\n", (*ptr)[0]);
            printf("%d\n", (*ptr)[1]);
            printf("%d\n", (*ptr)[2]);
            printf("%d\n", (*ptr)[3]);
            printf("%d\n", (*ptr)[4]);

    # <<< ARRAY OF POINTERS >>> #

            int a = 1, b = 2, c = 3, d = 4, e = 5;

            int *ptr[5] = {&a, &b, &c, &d, &e};

            printf("%d\n", *ptr[0]);
            printf("%d\n", *ptr[1]);
            printf("%d\n", *ptr[2]);
            printf("%d\n", *ptr[3]);
            printf("%d\n", *ptr[4]);

    # <<< MEMORY ALLOCATION >>> #

        # <<< THEORY >>> #

            Allows the programmer to request memory from the OS
            This memory is allocated during execution, and it is called heap memory

        !! Always check if malloc, calloc or realloc returned NULL !!

        #include <stdlib.h>

        # <<< malloc >>> #

            void *malloc(size_t size)

            # <<< THEORY >>> #

                allocates uninitialized memory

            # <<< EXAMPLE >>> #

                int* x = (int*)(malloc(sizeof(int)));

                if (x == NULL)
                {
                    // diagnostic message...
                }

                *x = 11;
                printf("%d\n", *x);
                free(x);

        # <<< calloc >>> #

            void *calloc(size_t nItems, size_t size)

            # <<< THEORY >>> #

                allocates and initializes storage - zero or null characters

            # <<< EXAMPLE >>> #
        
                int* y = (int*)(calloc(1, sizeof(int)));

                if (y == NULL)
                {
                    // diagnostic message...
                }
            
                *y = 55;
                printf("%d\n", *y);
                free(y);

        # <<< realloc >>> #

            void *realloc(void *ptr, size_t size)

            # <<< THEORY >>> #

                attempts to resize the memory block pointed to by ptr that was previously allocated with a call to malloc or calloc.

                contents of the old buffer are copied to the new (as much as possible)

                does not initialize the added storage

            # <<< EXAMPLE >>> #

                // Initial memory allocation

                str = (char *) malloc(15);
                strcpy(str, "tutorialspoint");
                printf("String = %s,  Address = %u\n", str, str);

                // Reallocating memory

                str = (char *) realloc(str, 25);
                strcat(str, ".com");
                printf("String = %s,  Address = %u\n", str, str);

        # <<< free >>> #

            void free(void *ptr)

            # <<< THEORY >>> #

                deallocates the memory previously allocated by a call to calloc, malloc, or realloc.

                after calling free(), manually set the pointer's value to NULL
                this avoid mistakes

                memory is automatically freed when the program quits
                however, memory that will no longer be used should be deallocated before the program's end

            # <<< EXAMPLE >>> #

                free(x);
                free(y);
                free(str);

                x = NULL;
                y = NULL;
                str = NULL;

    # <<< MEMORY MANIPULATION >>> #

        #include <string.h>

        # <<< memcpy() >>> #

            void *memcpy(void *dest, const void *src, size_t n)

            copies n characters from memory area src to memory area dest.

        # << memmove() >>> #

            void *memmove(void *str1, const void *str2, size_t n)

            copies n characters from str2 to str1, but for overlapping memory blocks, memmove() is a safer approach than memcpy().

    # <<< BONUS >>> #

        # <<< POINTER MATH >>> #

            Expression      |   Memory/Address                      |   Value at Address
            ----------------|---------------------------------------|----------------------------------
            p               |   Yes                                 |   No
            *p              |   No                                  |   Yes
            *p++            |   Incremented after value is read     |   Unchanged
            *(p++)          |   Incremented after value is read     |   Unchanged
            (*p)++          |   Unchanged                           |   Incremented after it's used
            *++p            |   Incremented before value is read    |   Unchanged
            *(++p)          |   Incremented before value is read    |   Unchanged
            ++*p            |   Unchanged                           |   Incremented before it's used
            ++(*p)          |   Unchanged                           |   Incremented before it's used
            p*++            |   Not a pointer                       |   Not a pointer
            p++*            |   Not a pointer                       |   Not a pointer

        # <<< POINTER AND ARRAY >>> #

            Array Notation      |   Pointer Equivalent
            --------------------|----------------------
            array[0]            |   *a
            array[1]            |   *(a+1)
            array[2]            |   *(a+2)
            array[3]            |   *(a+3)
            array[x]            |   *(a+x)

        # <<< ** >>> #

            Expression      |   What It Is Data Type
            ----------------|-------------------------------------------------------
            *array[]        |   An array of pointers Array
            **array         |   An array of pointers Array (pointer-pointer)
            array+1         |   An address Pointer
            *(array+1)      |   Contents of address, what lives there String/pointer
            *(*array+n)     |   Character n of the string at *array Character

# <<< STRUCT >>> #

    Check "STRUCT" in "THEORY" for more info.

    # <<< DEFINITION / DECLARATION >>> #

        struct Tag                          // does NOT allocate any memory
        {
            [type] [identifier];
            // ... other types
        };

    # <<< INITIALIZATION >>> #

        # <<< NOT SAFE EMPTY STATE >>> #

            struct Tag identifier;

        # <<< SIMPLE EMPTY >>> #

            struct Tag {int, char, double};

            struct Tag identifier = { 0 };

        # <<< ARRAYS EMPTY >>> #

            struct Tag {int, char[], int[]}

            struct Tag identifier = { 0, {0}, {0} };

        # <<< STRUCTS EMPTY >>> #

            struct OtherTag {char, double};
            struct Tag {int, OtherTag}

            struct Tag identifier = { 0, {0, 0} };

        # <<< ARRAYS AND STRUCTS EMPTY >>> #

            struct OtherTag {char, double};
            struct Tag {int, OtherTag, int[]}

            struct Tag identifier[10] = { { 0, {0, 0}, {0} } };

                       
        struct Tag                              // DURING DEFINITION
        {
            [type] [identifier];
            // ... other types
        } identifier    = {..., {..., ...}};    // INIT HERE

    # <<< ACCESSING >>> #

        object.member       // If stack memory
        object->member      // If pointer

# <<< CHAR STRING >>> #

    # <<< !!! Use macros, and when initializing !!! >>> #

        char str[MACRO_NAME + 1]

        char name[N_CHAR + 1] = "...";      - "+1" is for null terminator
                                            - '\0' is automatically added

    # <<< INITIALIZATION WITHOUT TYPED SIZE >>> #

        char name[] = {"..."};
        char name[] = "...";                - size == N_CHAR typed + 1
                                            - '\0' is automatically added

    # <<< INITIALIZATION CHAR BY CHAR >>> #

        char name[] = {'H', 'E', 'Y', '\0'}          - !!! MANUALLY ADD THE NULL TERMINATOR !!!

    # <<< !!! char strings cannot be assigned to a new value using the '=' operator. Use strcpy() !!! >>> #

        strcpy(name, "New name");

    !!! char strings do not require to pass size since you can check the end with c != '\0' !!!

# <<< STRING LITERALS >>> #

    when you have code like 
        char *x = "hello";
    the hello string itself is stored in read-only memory
    while the variable x is on the stack (or elsewhere in writeable memory if it's a global).
    x just gets set to the address of the hello string.
    This allows all sorts of tricky things like string folding,
    so that "invalid option" (0x1000) and "valid option" (0x1002) can use the same memory block as follows:

        +-> plus:0   1   2   3   4   5   6   7   8   9   A   B   C   D   E
        |      +---+---+---+---+---+---+---+---+---+---+---+---+---+---+----+
        0x1000 | i | n | v | a | l | i | d |   | o | p | t | i | o | n | \0 |
            +---+---+---+---+---+---+---+---+---+---+---+---+---+---+----+

    Keep in mind I don't mean read-only memory in terms of ROM,
    just memory that's dedicated to storing unchangeable stuff (which may be marked really read-only by the OS).

    They're also never destroyed until main() exits.

# <<< FUNCTION >>> #

    Check "FUNCTION" in "THEORY" for more info.

    # <<< PROTOTYPE >>> #

        type identifier(type identifier);         - Identifiers are optional.
                                                    - Usually in header files,
                                                    - or at the top before definition.
                                                    -
                                                    - !! BEFORE prototypes and definition.
                                                    - If using structs or other functions inside,
                                                    - remember to define them first !!

    # <<< DEFINITION >>> #

        # <<< VOID >>> #

            void identifier(void)           // when no parameters put void
            {
                return;                     // optional when return type is void
            }

        # <<< PASS BY VALUE // COPY >>> #

            type identifier(type parameter1, type parameter2, ...)      // Header
            {                                                           // (void), if no parameters
                // Body
                // Function instructions                                                            

                return ...;     // Optional if type == void
            }

        # <<< PASS BY ADDRESS // TRUE VALUE // NO COPY >>> #

            type identifier(type *parameter1, type *parameter2, ...)    // Header
            {                                                           // (void), if no parameters
                // Body
                // Function instructions                                                            

                return ...;     // Optional if type == void
            }
        
        # <<< PASS BY ADDRESS + CONST >>> #

            // Defining parameters as const prevent modification inside function
            // AKA read only mode
            // pointers and arrays are read and write parameters by default without const

            type identifier(const type *parameter1, const type parameter2[...], ...)
            {
                // Body
                // Function instructions                                                            

                return ...;     // Optional if type == void
            }

    # <<< CALL >>> #

        identifier(argument, ..., argument);

    # <<< RETURN >>> #

        return x;

        return(x);

# <<< HEADER >>> #

    #include <filename.h>  // filename is in the system directories
    #include "filename.h"  // filename is in the current directory

    When we place source code in a header (.h) file,
            - Function prototypes
            - Macros
            - Struct definition

    !! Not required as parameter for the compiler !!
    !! Typically .h !!

    # <<< !!! AVOID MULTIPLE COPIES !!! >>> #

        #ifndef NAME_H
        #define NAME_H

        header body

        #endif

# <<< FILE HANDLING >>> #

    Check "FILE HANDLING" in "THEORY" for more info.

    #include <stdio.h>

    FILE* fp = NULL         // precaution against premature dereferencing
                            // prevent segmentation fault

    # <<< OPENING FILE >>> #

        FILE *fopen(const char file_name[], const char mode[]);
        fp = fopen("filename", "connection mode");       // returns the address of the file

        The most common connection modes are:

            "r" - read from the file
            "w" - write to the file: if the file exists, truncate its contents and then write; if the file does not exist, create a new file and then write to that file
            "a" - write to the end of the file: if the file exists, append to the end of the file; if the file does not exist, create it and then write to it

        The less common connection modes for text files are:

            "r+" - opens the file for reading and possibly writing
            "w+" - opens the file for writing and possibly reading; if the file exists, truncates its contents and then writes to the file; if the file does not exist, creates a new file and then writes to that file
            "a+" - opens the file for writing to the end of the file and possibly reading; if the file exists, appends to the end of the file; if the file does not exist, creates it and then writes to the file

        !!
        Returns null if fails to connect to the file. CAUSES:
            - Lack of permission
            - Secondary storage premature removal
            - full device
        !!

    # <<< CLOSING FILE >>> #

        int fclose(FILE *);
        fclose(fp)           // only accepts FILE pointer
                            - returns 0 if successful
                            - return EOF if unsuccessful
                                - premature removal
                                - storage is full
                                - I/O error occurs

    # <<< COMMUNICATION >>> #

        fprintf()   - formatted write to file
        fputc()     - write single character to file
        fscanf()    - formatted read from file
        fgetc()     - read single character from file

    # <<< WRITING >>> #

        int fprintf(FILE *, const char [], ...);
        fprintf(fp, "... is %d and %10.5lf ...", var1, var2, ...);

            - Same as printf();
            - the printf function is a version of fprintf that does not need to have the FILE pointer passed as the first parameter because it always writes to the file stdout.
                - returns the number of characters written


        int fputc(int ch, FILE *fp);

            - writes a single character to an open file
                - returns character written
                - returns EOF in the event of an error
                -
                - !!! check to see if the return value is EOF !!!

    # <<< READING >>> #

        int fscanf(FILE *, const char [], ...);
        fscanf(fp, "%d %lf", &sku, &price);
        fscanf(patientsFile, "%d|%15[^|]|%4[^|]|%10[^\n]");

            // same as scanf();
                - !!!! check to see if the return value is EOF !!!!


        int fgetc(FILE *fp);

            // reads a single character from an open file
                - returns the character read
                - returns EOF in the event of an error
                -
                - !!!! check to see if the return value is EOF before converting it to char type !!!!

        # <<< READ PRE-READ >>> #

            int importPatients(const char* datafile, struct Patient patients[], int max)
            {
                FILE* patientsFile;
                int i = 0, nread;

                patientsFile = fopen(datafile, "r");
                if (patientsFile == NULL)
                {
                    printf("    ERROR: Patient datafile could not be opened\n");
                }
                else
                {
                    while (feof(patientsFile) == 0 && i < max)
                    {
                        nread = fscanf(patientsFile, "%d|%15[^|]|%4[^|]|%10[^\n]", &patients[i].patientNumber, patients[i].name,
                            patients[i].phone.description, patients[i].phone.number);
                        
                        if (nread > 0)
                        {
                            i++;
                        }
                    }
                    fclose(patientsFile);
                }
                return i;
            }

    # <<< STATE OF FILE OBJECT >>> #
    
        # <<< REWIND >>> #

            rewind()    - rewind the file
                        -
                        - resets the FILE pointer to the first byte in a file
                        - (avoid disconnecting and re-connecting)

            void rewind(FILE *fp);
            rewind(fp);

        # <<< END OF FILE >>> #

            feof()      - identify the end of the file
                        -
                        - !!!!! feof does not read anything, it just checks the next byte to be read !!!!!
                        -
                        - returns 0(false) if EOF was not read
                        - returns 1(true) if EOF was read at least once

            int feof(FILE *fp);
            feof(fp);

    # <<< RECORD >>> #

        A record occupies a single line but can have different size.

                record1
        |--------------------|[\n]
                record2
        |----------------------------|[\n]
                record3
        |-----------------|[\n]
                record4
        |-----------------------|[\n]


        iterate over all characters using fgetc() until '\n' is found.
        each new line means the end of the current record.

        typical record delimiter = \n

    # <<< FIELD >>> #

        Elements inside one record.


            field1          field2          field3          field4
        |----------|[FD]|----------|[FD]|----------|[FD]|----------|[\n]



        use fscanf() with the exact conversion specifiers.

        Field delimiter = FD = Typically 'blank character'

        fscanf(fp, "%d%c%lf", &sku, &status, &price)

        !!!!!
        If one of the fields in a record stores a character or string,
        'blank characters' may not be suitable as filed delimiter.
        USE A SPECIAL CHARACTER 
        both inside the file and on fscanf

        fscanf(fp, "%d;%c;%lf", &sku, &status, &price)
        !!!!!

    # <<< TABLE >>> #

        A table is a set of records in which each record contains the same number of fields.

                                    record1
        |----------------------------------------------------------|[\n]
            field1          field2          field3          field4
        |----------|[FD]|----------|[FD]|----------|[FD]|----------|[\n]

                                    record2
        |----------------------------------------------------------|[\n]
            field1          field2          field3          field4
        |----------|[FD]|----------|[FD]|----------|[FD]|----------|[\n]

                                    record3
        |----------------------------------------------------------|[\n]
            field1          field2          field3          field4
        |----------|[FD]|----------|[FD]|----------|[FD]|----------|[\n]



        while (fscanf(fp, "%d;%c;%lf", &sku, &status, &price) == 3)
        {
            printf("%4d %c %8.2lf\n", sku, status, price);
        }

# <<< STATIC >>> #

    A static variable inside a function keeps its value between invocations.
    A static global variable or a function is "seen" only in the file it's declared in

    # <<< STATIC VARIABLE >>> #

        void foo(void)
        {
            int a = 10;             // A new var and address will be created each call
            static int b = 10;      // Only one var and address will be created at the first call

            a += 5;                 // a will always be 15
            b += 5;                 // b will increment by 5 each call

            printf("a = %d |||| b = %d", a, b);
        }

        !! Although it is not good practice, making a variable static allows using local variables' address after its scope !!
        !! The address of b can be (pointed to/returned) after the function finishes execution!!

# <<< GLOBAL VARIABLES >>> #

    Global variables adds high degree of coupling in the code and should be avoided.

    Global variables are declared outside all functions and can be used in inside other modules.

    # <<< EXAMPLE >>> #

        main.c
        {
            void add(int v1);       // link to the function 'add' defined in math.c

            int x = 10;
            
            int main(void)
            {
                add(10);
                printf("%d", x);    // output: 15
                return 0;
            }
        }

        math.c
        {
            extern int x;           // link to the global variable 'x' defined in main.c

            void add(int v1)
            {
                x += v1;
            }
        }

    !!! Local variables are more efficient and readable. !!!

# <<< DATA STRUCTURES / ALGORITHMS >>> #

    these sections are available in C++Formated.txt











# <<< LIBRARIES >>> #

    # <<< STANDARD LIBRARIES >>> #

        The standard libraries that support programming languages perform many common tasks.
        C compilers ship with the libraries that include functions for mathematical calculations,
        generation of random events and manipulation and analysis of character data.
        To access any function within any library we simply include the appropriate header file
        for that library and call the function in our source code.

        https://www.gnu.org/software/libc/manual/html_node/index.html

    # <<< MATHEMATICAL FUNCTIONS >>> #

        # <<< stdlib >>> #
            
            - The standard library

            perform the more general mathematical calculations.
            These calculations include absolute values of integers and random number generation.

            # <<< ABSOLUTE INTEGER >>> #

                Distance from 0

                -12 -> 12

                int abs(int);
                long labs(long);
                long long llabs(long long);

            # <<< RANDOM NUM >>> #

                returns a pseudo-random integer in the range 0 to RAND_MAX (implementation-dependant)

                int rand(void);

                rand() generates the same set of random numbers for every run of its host application.
                This is very useful during the debugging stage.

                int srand(unsigned seed);       - Set based on seed
                int srand(time(NULL));          - Unique seed each run
                                                - !! #include <time.h> !!

        # <<< math >>> #

            - The math library

            Use -lm to compile a program that uses <math.h>

            gcc myProgram.c -lm

            # <<< ABSOLUTE FLOAT >>> #

                -12.5 -> 12.5

                double fabs(double);
                float fabsf(float);
                long double fabsl(long double);

            # <<< FLOOR / CEILING >>> #

                16.8 -> 16.0

                double floor(double);
                float floorf(float);
                long double floorl(long double);

                16.3 -> 17.0

                double ceil(double);
                float ceilf(float);
                long double ceill(long double);

            # <<< ROUNDING >>> #

                Round to closest.

                double round(double);
                float roundf(float);
                long double roundl(long double);

            # <<< TRUNCATING >>> #

                16.7 -> 16.0

                double trunc(double);
                float truncf(float);
                long double truncl(long double);

            # <<< SQUARE ROOT >>> #

                4.0 -> 16.0

                double sqrt(double);
                float sqrtf(float);
                long double sqrtl(long double);

            # <<< POWER >>> #

                double pow(double base, double exponent);
                float powf(float base, float exponent);
                long double powl(long double base, long double exponent);

            # <<< LOGARITHMS >>> #

                natural logarithm of the argument.

                double log(double);
                float logf(float);
                long double logl(long double);

            # <<< POWER OF E >>> #

                return the natural anti-logarithm of the argument.

                double exp(double);
                float expf(float);
                long double expl(long double);

    # <<< TIME >>> #

        #include <time.h>

        time(NULL)                  - returns the current calendar time.
        time_t time(time_t *);      - time_t is a type that it is sufficiently large to hold time values


        double difftime(time_t, time_t);        - returns the difference in seconds between two
                                                - calendar time arguments.


        clock_t clock(void);        - returns the approximate process time.

        Ex:
             t0 = time(NULL);
            c0 = clock();

            for (i = 0; i < NITER; i++)
            {
                for (j = 0; j < NITER; j++)
                {
                    for (k = 0; k < NITER; k++)
                    {
                        x = x * 1.0000000001;
                    }
                }
            }

            t1 = time(NULL);
            c1 = clock();

            printf("Elapsed time is %.1lf secs\n", difftime(t1, t0));
            printf("Process time is %.3lf secs\n", (double)(c1-c0)/CLOCKS_PER_SEC);

    # <<< CHARACTER MANIPULATION/ANALYSIS >>> #

        #include <ctype.c>

        # <<< MANIPULATION >>> #

            int tolower(int);
            int toupper(int);

        # <<< ANALYSIS >>> #

            // 0 == False
            // 1 == True

            int islower(int);
            int isupper(int);

            int isalpha(int);
            int isdigit(int);

            int isspace(int);   - ' ', '\t', '\n', '\v', '\f'
            int isblank(int);   - ' ', '\t'

    # <<< STRING >>> #

        #include <string.h>

        # <<< STRING LENGTH >>> #

            strlen(cString)
        
                - returns the number of characters in a character string
                - returns the index of the null terminator byte

        # <<< STRING COPY >>>> #

            strcpy(cString_1, cString_2)
                
                - copy cString_2   ->   to cString_1

            strncpy(cString_1, cString_2, size)

                - copy cString_2   ->   to cString_1      up to size
                -
                - it limits the number of character that will be copied


            !!!
            We are responsible for ensuring that there is sufficient room in the destination string
            to hold all of the characters in the source string including the null terminator byte.
            !!!

        # <<< STRING COMPARE >>> #

            strcmp(cString_1, cString_2)

                - compares cString_1    with    cString_2

            strncmp(cStringc_1, String_2, size)

                - compares cString_1    with    cString_2     up to size
                -
                - it limits the number of character that will be compared

            Returns:

                - 0 if they are identical
                - a negative value if the first non-matching character in the first string is, under the host computer's collating sequence, lower than the character with the same index in the second string
                - a positive value if the first non-matching character in the first string is, under the host computer's collating sequence, higher than the character with the same index in the second string

        # <<< STRING CONCATENATE >>> #

            strcat(cString_1, cString_2)

                - concatenate cString_2   ->   to cString_1

            strncat(cString_1, cString_2)

                - concatenate cString_2   ->   to cString_1     up to size
                -
                - it limits the number of character that will be concatenated

            !!!
            We are responsible for ensuring that there is sufficient room in the destination string
            to hold all of the characters in the source string including the null terminator byte.
            !!!

        # <<< STRING FIND CHAR >>> #

            strchr(cString, char)

                - searches for the first occurrence of the character

            strrchar(cString, char)

                - searches for the last occurrence of the character

            Retruns:

                - a pointer to the character found in the string str
                - NULL if the character is not found.

        # <<< STRING FIND STRING >>> #

            strstr(cString, cStrToFind)

                - searches for the first occurrence of the cString

        # <<< STRING memcpy() >>> #

            void *memcpy(void *dest, const void *src, size_t n)

            copies n characters from memory area src to memory area dest.

        # <<< STRING memmove() >>> #

            void *memmove(void *str1, const void *str2, size_t n)

            copies n characters from str2 to str1, but for overlapping memory blocks, memmove() is a safer approach than memcpy().

# <<< THEORY >>> #

    # <<< INTRODUCTION >>> #

        Devices (hardware) are controlled by software.
        Software operated by user == application software.
        Application software consists of one or more programs.
        Algorithm == step-by-step procedure to solve a task.

        Instructions and information are just data,
        So they are stored together.

    # <<< HARDWARE >>> #

        # <<< CPU >>> #

            Central Processing Unit executes program instructions serially (one at a time).

            registers
                - CPU's internal memory
                - Volatile                  - Lost when powered off
                - Used for:
                    - Store used or produced data from ALU and FPA

            decode unit
                - Extract instructions from the queue and decodes it

            control unit (CU)
                - CU manages the data, but does not change it.
                - It moves data and instructions.
            
            arithmetic logic unit (ALU)
                - The ALU evaluates the simplest of instructions on integer values.

                - Arithmetic
                - Logical
                - Relational

            floating-point accelerator (FPA)
                - The FPA evaluates the simplest of instructions on floating-point values.

                - Arithmetic
                - Logical
                - Relational

        # <<< PRIMARY MEMORY >>> #

            Memory accessed directly by the CPU

            RAM
                    - Random Access Memory
                    - Volatile              - Lost when powered off
                    - Used for:
                        - Program instructions
                        - Program data

            ROM
                    - Read Only Memory
                    - Not volatile          - Persists when powered off
                    - Used for:
                        - Startup instructions

        # <<< SECONDARY STORAGE >>> #

            Check "FILE HANDLING" for more info

            Summary:
                - Slower than primary
                - Cheaper than primary
                - More resources than primary
                - Persistent data

    # <<< SOFTWARE >>> #

        Receives memory from OS when user starts the application.
        Changes user's input into expected output.
        Stored in RAM.
    
    # <<< FUNDAMENTAL UNITS >>> #

        CHECK LINUX HELP FOR BASE CONVERSION

        # <<< BIT >>> #

            The most fundamental unit of a modern computer.
            A bit is either on(1) or off(0).
            Bits are not addressable because they are small.

        # <<< BYTE >>> #

            The fundamental addressable unit of RAM.
            Consists of 2 nibbles (nibble == 4 bit).
            Consists of 8 bits.

        # <<< WORD >>> #

            Word is the natural size of the execution environment.
            It varies from CPU to CPU.

                - 16-bit CPU
                    - 2 bytes
                - 32-bit CPU
                    - 4 bytes
                - 64-bit CPU
                    - 4/8 bytes

        # <<< HEXADECIMAL >>> #

            Most convenient numbering system for organizing information.
                - 0 to F
                - holds 4 bits of data
                - 0x...

    # <<< MEMORY MODEL >>> #

        All RAM addresses are combined to form a linear map (FROM 0x...0000 to 0x...FFFF).

            RAM Chip 1              RAM Chip 2          RAM Chip 3          RAM Chip 4
        |--------------------|-------------------|-------------------|--------------------|
                                        Linear Map of RAM
        |---------------------------------------------------------------------------------|
        0x...0000                                                                 0x...FFFF
        
        Limit on Addressability
            - 32-bit register
                - up to 4GB
            - 36-bit register
                - up to 64GB
            - 64-bit register
                - up to 16EB
        
    # <<< SEGMENTATION FAULTS >>> #

            When a program tries to access or modify another program's memory.

    # <<< C COMPILER >>> #

        Compiler transforms instructions and data, so the computer can understand.

                        Compiling
        |--------------------------------------|
         Source Code -> Compiler -> Binary Code

                        Executing
        |--------------------------------------|
            Input -> Binary Code -> Output

    # <<< GENERATIONS >>> #

        Machine languages
            - These are the native languages that the CPU processes.
            - Each manufacturer of a CPU provides the instruction set for its CPU.

        Assembly languages
            - These are readable versions of the native machine languages.
            - Assembly languages simplify coding considerably.
            - Each manufacturer provides the assembly language for its CPU.

        Third-generation languages
            - These languages are procedural:
            - they identify the instructions or procedures involved in reaching a result.
            - The instructions are NOT tied to any particular machine.
            - Examples include C, C++ and Java.

        Fourth-generation languages
            - These languages describe what is to be done without specifying how it is to be done.
            - These instructions are NOT tied to any particular machine.
            - Examples include SQL, Prolog, and Matlab.

        Fifth-generation languages
            - We use these languages for artificial intelligence, fuzzy sets, and neural networks.

    # <<< C FEATURES >>> #

        C is a third generation language.

        - C is English-like
        - C is quite compact - has a small number of keywords
        - C is the lowest in level of the high-level languages
        - C can be faster and more powerful than other high-level languages
        - C programs that need to be maintained are large in number
        - C is used extensively in high-performance computing
        - UNIX, Linux and Windows operating systems are written in C and C++

    # <<< TYPES OF DATA >>> #

        # <<< CONSTANTS >>> #

            constant values are specified directly

            Check ARRAY section to understand (const VS macros)
            
            # <<< IMMEDIATE VALUES >>> #

                Appear directly in the code
                Useful when need only once

                a = 22;
                str = "Hello World";

            # <<< CONST >>> #

                Value assigned when created, and it cannot be modified after initialization.
                The variable can be used several times in the code if inside its scope.

                const float pi = 3.14;

            # <<< MACRO >>> #

                Value assigned when created, and it cannot be modified after initialization.
                The macro can be used several times in the code and it is valid in the 'entire' source code.

                #define PI 3.14

        # <<< VARIABLE >>> #

            the contents can change
            variables are data containers

    # <<< TYPED LANGUAGE >>> #

        C is a typed programming language.
        The type defines how the value is stored in memory (SIZE OF BYTES)
        and what operation are admissible.

        !!!
        CAUTION IS ADVISED SINCE TYPES' SIZE MAY CHANGE FROM MACHINE TO MACHINE.
        RECOMMENDATION IS TO SPECIFY THE EXACT SIZE AT THE DECLARATION,
        AND CHECK IF THE SIZE IS THE SIZE EXPECTED.
        !!!

        !!!
        INTEGER VALUES ARE STORED EXACTLY IN MEMORY.
        FLOATING POINT VALUES ARE STORED APPROXIMATELY.
        THEREFORE, WHEN PRECISION IS REQUIRED, USE ONLY INTEGERS.
        !!!

    # <<< COLLATING SEQUENCES >>> #

        Defines how the value will be stored in binary.

        ASCII and EBCDIC are not compatible.
            ASCII   - digits precede letters
            EBCDIC  - letters precede digits
        
        During sorting, results will vary from one to another.

        Unicode is compatible with ASCII.

    # <<< NEGATIVE VALUES >>> #

        There are three schemes for storing negative integers:

            - 2's complement notation (most popular)
            - 1's complement notation
            - sign magnitude notation

        To obtain the 2's complement of an integer:

            - flip the bits
            - add one
            - e.g.

            Bit #	    7	6	5	4	3	2	1	0
            92 =>	    0	1	0	1	1	1	0	0
            Flip Bits	1	0	1	0	0	0	1	1
            Add 1	    0	0	0	0	0	0	0	1
            -92 =>	    1	0	1	0	0	1	0	0

    # <<< FLOATING POINT VALUE >>> #

        The most popular model is the IEEE Standard 754 for Binary and Floating-Point Arithmetic.

        float (32)
            - 1-bit     sign
            - 8-bit     exponent
            - 23-bit    significant

        double (64)
            - 1-bit     sign
            - 11-bit    exponent
            - 52-bit    significant

    # <<< C RESERVED WORDS >>> #

        auto       _Bool      break     case
        char       _Complex   const     continue
        default    restrict   do        double
        else       enum       extern    float
        for        goto       if        _Imaginary
        inline     int        long      register
        return     short      signed    sizeof
        static     struct     switch    typedef
        union      unsigned   void      volatile
        while


        !! sizeof is considered an operator, and it is not a function !!

    # <<< C++ RESERVED WORDS >>> #

        asm              friend            template
        bool             mutable           this
        catch            namespace         throw
        class            new               true
        const_cast       operator          try
        delete           private           typeid
        dynamic_cast     protected         typename
        explicit         public            using
        export           reinterpret_cast  virtual
        false            static_cast       wchar_t

    # <<< MIXED-TYPE EXPRESSION >>> #

        Since CPUs process integral expressions and floating-point expressions differently
        (using the ALU and the FPA respectively),
        they only handle expressions with operands of the same type.

        Coercion is the implicit promotion or narrowing done by the compiler.
        promotion does not lose data.
        narrowing can lose data.
        truncated refers to data lost.

        The compiler only coerces when executing arithmetic or relational operation.
        Logical does not require coercion

        # <<< ARITHMETIC AND RELATIONAL >>> #

            C compiler promotes the lower type operand,
            so it has the same rank as the other operand.

        # <<< ASSIGNMENT >>> #

            x = y

                - If x's rank is higher than y, y is promoted.
                - 
                - If x's rank is lower than y, y is narrowed.

            !!!
            When narrowing a value it can be truncated.
            Therefore it will lose some data.
            !!!

    # <<< ORDER OF PRECEDENCE >>> #

        To change the order of evaluation, we introduce parentheses.
        C compilers evaluate the expressions within parentheses (( ))
        before applying the rules of precedence.


        Operator	                           |Evaluate From
        ---------------------------------------|-------------
        ++ -- (postfix)	                       |left to right
        ++ -- (prefix) + - & ! (all unary)	   |right to left
        (type)	                               |right to left
        * / %	                               |left to right
        + -	                                   |left to right
        < <= > >=	                           |left to right
        == !=	                               |left to right
        &&	                                   |left to right
        ||	                                   |left to right
        = += -= *= /= %=	                   |right to left

    # <<< STRUCTURED PROGRAMMING >>> #
    
        It is critical that the software is not only readable but also easy to upgrade and maintain.
        A structured program consists of sets of simple constructs,
        each of which has one entry point and one exit point.

        classes of constructs:

        # <<< SEQUENCE >>> #
        
            One statement follows another and the statements are executed in order.
            The simplest example of a structured construct is a sequence.

            Example Simple Statement

                // single statement
                printf("I like pizza\n");

            Example Code Block

                // code block (upgrade)
                {
                    printf("I like pizza\n");
                    printf("I want more pizza\n");
                }

        # <<< SELECTION >>> #

            Optional    Sequence
            Alternative Sequence
            Conditional Sequence

            if
            switch

        # <<< ITERATION >>> #

            Although the three constructs can behave in the same way,
            each one of them is better suited for specific cases. 

            While:
                It checks the condition first and then executes the statements;
                Therefore while loops are executed zero times if the condition is false.

                It is excellent when we do not know how many iterations we will have.
                The flag must be initialized before the loop body.

            do while:
                It executes the statements first and then checks the condition,
                so its statement will be executed at least once.

                It is excellent when we do not know how many iterations we will have.
                The flag can be initialized before or inside the loop body.
                    e.g. Waiting for correct input from the user

            for:
                It is excellent when we know how many iterations we will have.
                    e.g. Iterate over an array.
                    Since we know the array's size,
                    using a for loop is a better code style and more convenient.

        # <<< FLAG >>> #

            Flags are used in iterations constructs to ensure single-entry single-exit principle.

            (condition && flag)

            Single entry single exit principle means that modules and constructs can be replaced, upgraded, or removed
            without introducing bugs to the program. Although this is the main benefit,
            it also increases the code cohesion and reduces coupling.
                - Avoids spaghetti code
                - Easier to find bugs
                - Locate related information in the code

        During the design stage of a programming solution:

            - pseudo-coding
            - flow charting

        # <<< NESTING >>> #

            Nesting is when a construct is placed inside another construct.

    # <<< DEBUGGING >>> #

        Debugging locates 'bugs' that produce incorrect results.

        # <<< SYNTACTIC ERROR >>> #

            Syntactic errors are errors that break the rules of the programming language. The most common syntactic errors in the C language are:

            - missing semi-colon
            - undeclared variable name
            - mismatched parentheses
            - left-side of an assignment expression is not a defined memory location
            - 
            - (RELATIVE) unnecessary semi-colon terminator in a #define directive

            Techniques for identifying syntactic errors include:

            - reading code statements (walkthroughs)
            - compiler error messages (compiler output)
            - comparing error messages from different compilers, some are more cryptic than others.

        # <<< SEMANTIC ERROR >>> #
        
            Semantic errors are errors that fail to implement the intent and meaning of the program designer. The more common semantic errors are:

            - infinite iteration
            - = instead of ==
            - iteration without a body (for/while followed by a semi-colon)
            - uninitialized variable
            - incorrect operator order in a compound expression
            - dangling else
            - off-by-one iteration
            - integer division and truncation
            - mismatched data types
            - & instead of &&
            - return statement is missing
            
            Techniques for identifying semantic errors include:

            - vocalization, use your sense of hearing to identify the error (compound conditions)
            - intermediate output, printf() statements at critical stages
            - walkthrough table
            - interactive debugging using
                - Visual Studio IDE - integrated debugger for Windows OSs
                - Eclipse IDE - integrated debugger for Linux OSs
                - gdb - GNU debugger for gcc

    # <<< TESTING >>> #

        Testing ensures that all of the paths through the program envisaged by the designer
        produce correct results.

        # <<< BLACK BOX >>> #

            Black box tests are data-driven.
            We run the executable
            and treat it as a black box where all internal logic has been hidden from view.

            We test either side of the boundaries of the equivalence class
            as well as the boundary itself

        # <<< WHITE BOX >>> #

            White box testing is logic-driven.
            We treat the program as a glass box with all internal logic visible.
            Each white box test is path-oriented.

            In white box testing, we execute each possible path through the code at least once.

    # <<< ARRAY >>> #

        Programs can process extremely large amounts of data.
        The efficiency depends on how the data is organized.

        Instead of coding separated code instructions to several individual variables,
        we code only for one structure, which is grouping all of the variables inside one identifier.

        Structured data:
            - all variable shares the same type
            - stored contiguously in memory

        Code common instructions to all variables from data structure.

        The simplest data structure in C is a list of variables of the same type (ARRAY).

        An array is a data structure consisting of an ordered set of elements of common type
        that are stored contiguously in memory.

        Index start at 0, and it ends at n-1.

        C does not check array's boundaries.
        Therefore its the programmer responsibility to prevent accessing forbidden memory.

    # <<< STRUCT >>> #

        A structure type is a collection of not necessarily identical types.
        We use the structure type to define a group of variables as a single object.

        # <<< DECLARATION >>> #

            declaration does NOT allocate any memory for any object;
            it only defines the structure and the rules for objects of that type
            (in other words, this is NOT a variable declaration).

            We declare our structure globally
            and may store its declaration in a separate file called a header file

            The limit of members is based on the computer memory.

            You may declare other struct inside this struct.
            But you may not declare this struct inside itself.

        # <<< ACCESSING >>> #

            We may omit the parentheses here - &(harry.idNum) - they are unnecessary because
            the dot (.) operator binds tighter than the address-of operator.

    # <<< TYPE >>> #

        A type describes how to interpret the information stored in a region of memory.
        In the C language, a type may be a primitive type or a derived type.
            - A derived type is a collection of other types.
                - struct
            - The core language defines the primitive types.
            We cannot redefine these types or introduce new primitive types.
                - char
                - int
                - float
                - double

    # <<< HEADER FILES >>> #

        When we place source code in a header (.h) file,
            - Function prototypes
            - Macros
            - Struct definition

        we insert that header file's code into the source file that requires that information.
        When compiling multi-file source code, we only pass the .c file(s) to the compiler.
        The code in a header file is duplicated inside each C file in which it is included,
        which allows us to write code, like a struct, in one spot and edit it in that one spot alone.

        Header files play an important role in modularity and in the organization of code.
        Header files often contain additional things like macros and function prototypes.

    # <<< MODULARITY >>> #

        Procedural programming involves separating source code into self-contained components
        that can be accessed multiple times from different locations in a complete program.
        We call this approach to programming solutions modular design.

        # <<< MODULAR DESIGN >>> #

            Modular design identifies the components of a programming project that can be developed separately.
            Each module consists of a set of logical constructs that are related to one another.
            A module may refer to other modules.

            e.g. printf("");

        # <<< DESIGN PRINCIPLES >>> #

            Each module focuses on a narrow aspect of the program.
            Therefore modules simplifies the complexity of the original problem.

            Some general guidelines for defining a module include:
                - the module is easy to upgrade
                - the module contains a readable amount of code
                - the module may be used as part of the solution to some other problem

            For a structured design, we stipulate that:
                - each module has one entry point and one exit point
                - each module is highly cohesive
                - each module exhibits low coupling

        # <<< COHESION >>> #

            Cohesion describes the focus:
            A highly cohesive module performs a single task and only that task.
            Only include tasks that are related to each other.

            Unrelated task are reallocated to other modules.

        # <<< COUPLING >>> #

            Coupling describes the degree of interrelatedness of a module with other modules.
            The less information that passes between the module and the other modules the better
            the design.
            We prefer designs in which each module completely control its own computations
            and avoids transferring control data to any other module.

            To improve our design, we transfer data to the module and let it create its own flags
            before completing its task.

    # <<< FUNCTION >>> #

        The C language is a procedural programming language.
        It supports modular design through function syntax.
        Functions transfer control between one another.

        CALLER FUNCTION :  main(void) 
        CALL            :  printf("")       - Transfers control to printf()
        RETURN          :  printf("")       - After done, it returns control to main(void), the caller

        # <<< CALL >>> #

            An argument may be a constant, a variable, or an expression (with certain exceptions).
            The number of arguments in a function call
            should match the number of parameters in the function header.

        # <<< MIXING TYPES >>> #

            If the type of an argument does not match the type of the corresponding parameter,
            the compiler coerces (narrows or promotes) the value of the argument
            into a value of the type of the corresponding parameter.

        Return statement are not necessary to return control. But when used they return the control to caller.

        A function cannot be defined inside another function, only in the global scope.

        Default return type is integer.

        # <<< PROTOTYPE >>> #

            Provides information that the compiler requires to validate a function call.

            We insert prototypes near the head of our source file.

            type identifier(type [parameter], ...)             - PARAMETERS are optional.

    # <<< PASS BY VALUE >>> #

        The C language passes data from a caller to a function by value.
        That is, it passes a copy of the value and not the value itself.
        Each parameter is a variable with its own memory location.

        Pass by value facilitates modular design by localizing consequences.
        It prevents one function from making any direct change to any variable outside that function.
        Changes does not affect the arguments,
        only the parameter which are copies of the arguments.

        variables in the caller are relatively secure.

    # <<< PASS BY ADDRESS / MULTIPLE RETURN VALUES >>> #

        To change the original values,
        we pass the addresses of variables instead of their values.

        C function syntax only allows for the return of a single value.
        If a function requires more than one return value we use parameter pointers.

        A function that returns values through the parameters can reserve its single
        return value for reporting an error code produced by the function.

        Passing by address is more efficient than by value.

    # <<< ADDRESS >>> #

        Every program variable occupies a unique address in memory throughout its lifetime.

        &   - 'address of' operator
            - it gets the variable's address

        C compilers typically store addresses in 4 bytes of memory.

    # <<< POINTER >>> #

        A variable that holds an address is called a pointer.
        The * operator stands for 'data at' and is called the dereferencing or indirection operator.

        The C language supports a pointer type for every primitive or derived type.

        C compilers typically store addresses in 4 bytes of memory.

        # <<< NULL >>> #

            Each pointer type has a special value called its null value.
            The constant NULL is an implementation defined constant that contains this null value
            (typically, 0). This constant is defined in the <stdio.h> and <stddef.h> header files.

            It is good style to initialize the value of a pointer to NULL before the address is known.

        # <<< VOID* >>> #

            void *ptr is a generic type that works with all types.

        # <<< STRUCT* >>> #

            struct STUDENT *s = NULL;       - declaration

            s->member                       - accessing
            or
            (*s).member                     - accessing

        # <<< CONST >>> #

            const type* identifier;        - When value should not be modified.

        # <<< WHY STRONGLY TYPED >>> #

            The type of a pointer variable determines the number of bytes to interpret
            when converting into a data type the bit string in primary memory that starts
            at the specified address.

    # <<< VALIDATION >>> #

        When dealing with user input validation is important to ensure code assumptions are not breached.

        Some examples of validation include scanf("%d%c")
        check if scanf returned 2
        check if last character is a new line
        check if first input is valid according to the program

        IMPORTANT \n is ALWAYS left in the input buffer,
        but %c gets it so there will be no need to clear the buffer.

        getchar() always leaves the \n in the input buffer,
        consequently, it is necessary to clear the buffer every time getchar is called.
    
    # <<< ERROR MESSAGES >>> #

        Make sure to not create cryptic error messages.
        Explain the error for a average user.

    # <<< STRING >>> #

        Strings only exist in c as a users defined type, not as primitive type.

    # <<< SCOPES >>> #

        Procedural programming scopes information.

        Scoping is an essential feature of modular design.

        Scopes limit the visibility of the program data and instructions.

        Each module limits the visibility in that module.
        Each block limits the visibility in that block.

                                    Global Scope
        |--------------------------------------------------------------|
            Function                Function            Function
        |--------------------|--------------------|--------------------|
          Block       Block           Block               Blocks
        |--------|  |-------|      |---------|      |------|---------|


        Global Scope    = defined outside all functions. (High degree of coupling)
        Function Scope  = defined in function header. (AKA parameter)
        Local Scope     = defined in function body.
        Block Scope     = defined inside block/construct.

        # <<< OVERLAPPING SCOPE >>> #

            Two variables with the same name.
            The "closest scope/more local scope" variable is the one active.
            It hides the other variable during its lifetime.
            Usually means poor style and best avoided.

            int x = 5;
            {
                int x = 10;
                ...
            }
            ... // x still equals to 5

    # <<< INPUT / OUTPUT HANDLING >>> #

        Some programming languages leave input and output support to the libraries developed
        for the languages. For instance, the core C language does not include input and output
        specifications. These facilities are available in a set of functions, which are defined
        in the stdio module.

        Typically, standard input refers to the system keyboard
        and standard output refers to the system display.

        # <<< BUFFER >>> #

            # <<< INPUT BUFFER >>> #

                A buffer is a small region of memory that holds data temporarily and provides
                intermediate storage between a device and a program.
                The system store each keystroke and allows the user edit the input
                until \n (enter) key is pressed.
                \n signals the program to start extracting data from the buffer.
                The program only extracts the data that it requires
                and leaves the rest for future retrievals.

            # <<< OUTPUT BUFFER >>> #

                Standard output is line buffered. A program outputs its data to a buffer.
                That buffer empties to the standard output device separately.
                When it empties, we say that the buffer flushes.

                Output buffering lets a program continue executing without having to wait
                for the output device to finish displaying the characters it has received.

                The output buffer flushes if:

                    - it is full
                    - it receives a newline (\n) character
                    - the program terminates

        # <<< INPUT >>> #

            getchar()   - unformatted input
            scanf()     - formatted input
            
            scanf() extracts the exact amount to satisfy the specified conversion.
            It stops if the buffer is empty,
            or if it finds a character that fails to match the next conversion specified.

            In a mismatch between the conversion specifier and the next character in the buffer,
            scanf() leaves the offending character in the buffer and returns to the caller.
            In the case of an emptied buffer, scanf() waits until the user adds more data to the buffer.

            # <<< WHITESPACE >>> #

                scanf() treats the whitespace between text characters of the
                user's input as a separator between input values.
                
                scanf("%d %d")      - No need for spaces between %d and %d

            # <<< PLAIN CHAR >>> #

                Plain characters in the format string - those not preceded by the conversion
                symbol - serve a special purpose. Each such character requires exact duplication
                on input. If the user enters a plain character other than that specified in the
                format string, scanf() abandons further interpretation.

                To input % as a plain character (and distinguish it from the symbol identifying
                a conversion specifier), we insert %% into the format string.

            # <<< VALIDATION >>> #

                Since we can never predict that all users will never make mistakes in inputting data
                Validating the input is important

                Erroneous input may include:
                    - invalid characters
                    - trailing characters
                    - out-of-range input
                    - incorrect number of input fields

        # <<< OUTPUT >>> #

            putchar()   - unformatted
            printf()    - formatted

            Prefer scape sequence, since hexadecimal values may vary between systems.

    # <<< REFINING ARRAY/POINTER/STRUCT >>> #

        # <<< ARRAY >>> #

            Arrays without brackets points to the first elements address.
            Therefore it is passed by address whenever used as argument.

            Arrays do not have addresses.

            # <<< VARIABLE-LENGTH ARRAY >>> #

                int n;
                scanf("%d" &n);
                int arr[n];

                !! PORTABILITY ALERT some compiler do not accept this !!

        # <<< POINTER >>> #

            Pointer can be arrays.

            int arr = {1, 2, 3};
            int* p = arr;

            p       // *p == 1
            p + 1   // *p == 2
            p++     // *p == 3

        # <<< ARRAY/POINTER >>> #

            arr[i]	is equivalent to	*(arr + i)
            &arr[i]	is equivalent to	(arr + i)

            int arr = {1, 2, 3};
            int x;

            x = *arr;      // stores 1 in x (the value of the first element)
            x = *(arr + 1) // stores 2 in x (the value of the second element)
            x = *(arr + 2) // stores 3 in x (the value of the third element)

            Function Header:
                int foo (int arr[]);
                int foo (int* ptr);

                // Both are represent the same thing as parameters

            Function Body:
                Since arrays are not variables, they do not have addresses.
                Therefore arrays do not support arithmetic operations like pointer.

        # <<< STRUCT >>> #

            Structs are passed by value by default.
            Therefore the compiler performs member-by-member copying automatically whenever we:
                - pass an object by value
                - assign an object to an existing object
                - initialize a new object using an existing object
                - return an object by value

            Passing an object by address is efficient.
            It avoids copying all member values, saving time and space especially with large objects.

    # <<< FILE HANDLING >>> #

        Secondary storage retains its information when a computer is turned off
        and provides a mechanism for holding information beyond the execution of a program.
        Information in secondary storage can be accessed later by the same or a different program.
        This information resides in secondary memory in the form of files.

        # <<< FILE >>> #

            A file is a named area of secondary storage. The file may be fragmented;
            that is, it may consist of several parts stored at different non-contiguous locations in secondary memory.
            A file does not necessarily occupy contiguous space on the storage device.

            The byte is the fundamental storage unit of a file.
            The distinguishing feature of a file is the end-of-file mark.
            We refer to this mark as EOF. EOF typically has the value -1.

        # <<< FILE FORMAT >>> #

            text    - readable and editable data
            binary  - executable program code

            # <<< TEXT >>> #

                Data stored in text format is suitable for displaying and modifying through a text editor.
                Files stored in text format are portable across platforms that share the same character set.

                    - 52 upper and lower case alphabetic characters: A, B, ..., Z, a, b, ..., z
                    - 10 digits: 0, 1, ..., 9
                    - space
                    - null, line feed, carriage return, horizontal tab, vertical tab and form feed: \0, \l, \n, \t, \v, \f
                    - 29 graphic characters: ! # % ^ & * ( _ ) - + = ~ [ ] ' | \ ; : " { } , . < > / ?

                !! 
                This set excludes the $ and ` characters.
                The encoding for characters like $ and ` does not produce
                the same characters on all platforms
                !!

        # <<< SEQUENTIAL ACCESS >>> #

            The most common way to access data in a text file is sequentially, byte by byte.
            We process the file as a stream of bytes without skipping any byte until we reach
            the file's end-of-file (EOF) mark.

        # <<< CONNECTION >>> #

            A C program connects to a file through an object of FILE type.
            The object holds information about the file
            and keeps track of the next position to be accessed.
            We use a library function to retrieve the address of the file object,
            store that address in a pointer and subsequently access the file through that pointer.
    
        # <<< DISCONNECTING >>> #

            If the file is open for writing or appending,
            fclose() writes any data remaining in the file's buffer to the file
            and appends the end of file mark after the last character written.
            If the file is open for reading,
            fclose() ignores any data left in the file's buffer and closes the connection.

        # <<< RECORD >>> #

            A record occupies a single line in a text file and holds all of the data associated
            with one chunk of information. The record is a sequence of characters that ends with
            a record delimiter. The typical record delimiter is the newline character (\n).

    # <<< C STYLE GUIDELINES >>> #

        A well-written program is a pleasure to read.
        The coding style is consistent and clear throughout.
        Easy to find bugs and upgrade.
        Better to future maintenance and future programmers.

        https://en.wikipedia.org/wiki/Indentation_style#Allman_style

        # <<< LAYOUT >>> #

            # <<< WHITESPACE >>> #

                Whitespace enhances program readability.

                    - blank space
                    - newline
                    - horizontal tab
                    - vertical tab
                    - form feed
                    - comments

            # <<< INDENTATION >>> #

                TAB == num of spaces

                Shows that something is part of a determined block / scope.

                https://en.wikipedia.org/wiki/Indentation_style#Allman_style

            # <<< LINE LENGTH >>> #

                The practical limit on line length is 80 columns, including indentation.

            # <<< COMMENTS >>> #

                We use comments to describe what is done, rather than how it is done.

                We preface every source file with a header comment that includes:

                    - the title of the program
                    - the source file name
                    - the name of the author(s)

        # <<< BRACES >>> #

            Defines the code block start and end.

        # <<< IDENTIFIERS >>> #

            - adopt self-descriptive names, adding comments only if clarification is necessary

            - prefer nouns for variable identifiers

            - keep variable identifiers short
            temp, rather than temporary,
            id, rather than identification
            
            - avoid cryptic identifiers
            use just enough letters for the eye to infer the meaning from the context but no less
            (if you want to represent 'amount owed', ao is cryptic,
            while amtOwed is clear but concise)
            
            - keep the identifiers of counters very short
            use i rather than loop_counter,
            and n rather than numberOfIterations.
            This is context dependant
            and should only be applied to iterators and counters otherwise,
            the name becomes meaningless or cryptic.
            
            - avoid decorating the identifier with Hungarian or similar notations (data type)
            
            - use "camelNotation"
            (first letter of each word is capitalized with the exception of the first word)
            
            - avoid underscore characters
            which are commonly used in system libraries to avoid conflicts

        # <<< VARIABLES >>> #

            - declare all variables at the beginning of the function.
            - group related variables together.

            Identifiers must be descriptive and grouped together so the programmer does not need to search the entire code to find all of them.

            # <<< NAMING RULES >>> #

                - starts with a letter or an underscore (_)
                - contains any combination of letters, digits and underscores (_)
                - contains less than 32 characters (some compilers allow more, others do not)
                - is not a C reserved word

            # <<< NAMING CONVENTION >>> #

                - be self-documenting (should not require comments to describe what they are used for)
                - be concise but not so short that it is cryptic
                - accurately describes the data being stored
                - help with the reading of the code
                - use "camelNotation" (first letter of each word is capitalized with the exception of the first word)
                - avoid underscore characters which are commonly used in system libraries to avoid conflicts

        # <<< MAGIC NUMBERS >>> #

            We refer to values that appear out of nowhere in program code as magic numbers.
            We set their value in either of two ways:

                - using an unmodifiable variable
                - using a macro directive

        # <<< Miscellaneous >>> #

            Other guidelines for enhancing and maintainability readability include:

            - we avoid global variables

            - we avoid variable identifiers that end in numbers

            - we avoid using the character encodings for a particular environment.
            Instead, we use escape sequences, which are universal.
            
                char c = '\n';              - prefer
                
                char c = 10; // ASCII       - avoid

            - we initialize iteration variables in the context of the iteration.

                for (i = 0; i < 10; i++)    - prefer
                
                i = 0;                      - avoid
                for (; i < 10; i++)

            - we add special comments where code has been fine-tuned for efficient execution

            - we avoid iterations with empty bodies
            
            - we limit the initialization and iteration clauses in for statements
            to the iteration variables

            - we avoid assignment expressions nested inside logical expressions

            - we add an extra pair of parentheses where an assignment expression
            is also used as a condition

            - we remove unreferenced variable declarations from our source code

            - we remove all commented code and debugging statements from our
            release and production code

        # <<< FUNCTION >>> #

            We replace multiple return statements with flags logic and a single return statement.

            It is good programming style to:

                - place the opening brace on a separate line

                - declare a prototype for each function definition

                - include parameter identifiers in the prototype declaration as documentation

                - use generic comments and variables names to enable future use in 
                different applications without having to modify any of the function code

                - avoid calling the main() function recursively

                - limit the number of local variables to below 10, if possible
                
                - adhere to the single-entry single-exit principle having a single return statement
                
                
            We document each function at one level of abstraction above the caller.
            We precede the function header in the function definition with comments that describe:

                - what the function does (not how)
                - what the function needs (in terms of values for its parameters)
                - what the function returns (if anything)
                - We state any assumption or constraint that applies to using the function.

            For example:

            // power returns the value of base raised to
            //  the power of exponent (base^exponent)
            //
            //  power assumes that base and exponent are
            //  integer values and exponent is non-negative
            //
            int power(int base, int exponent) {...}

# <<< EXCELLENT SOURCES >>> #

    https://www.youtube.com/watch?v=q1qKv5TBaOA     - How principled coders outperform the competition 

# <<< OOP vs FP >>> #

    https://www.youtube.com/watch?v=UOkOA6W-vwc

    OOP consists of utilizing several classes to reduce redundancies

    FP consists of utilizing several functions to reduce redundancies


ALT + CLICK         - In Visual Studio this expand all / collapse all
                    - keyboard shortcut Ctrl + M, P to expand or Ctrl + M, O to collapse.
SHIFT + CLICK       - In Visual Studio this expand all / collapse all