# <<< CORE >>> #

    #include <iostream>         - library provides access to the standard input and output objects.

    # <<< INPUT/OUTPUT >>> #

        cout << var << endl;
            - cout      - the object representing the standard output device
            - <<        - the insertion operator
            - endl      - '\n' + flushes the buffer

        cin >> var;
            - cin       - the object representing the standard input device
            - >>        - the extraction operator

        cin.getline(str, n);

        # <<< !! cin SECURE UTILIZATION !! >>> #

            ! cin is can fail, so it is important to check if it is still working after calling it !

            if (cin.fail()) {
                cin.clear();
                cin.ignore(10000, '\n');
            }

# <<< FUNCTION >>> #

    Functions in C++ requires all parameter types to be included in the function prototypes.
    
    We call functions that support a compound type the helper functions for that type.

# <<< NAMESPACE >>> #

    Namespaces are artificial scopes created to avoid naming conflicts.

    # <<< CREATING >>> #

        namespace identifier {
            ...
        }

    # <<< ACCESSING >>> #

        To access a namespace identifier use double colon (::).
        We call this double colon the scope resolution operator.

        nameSpaceId::ID

    # <<< EXPOSE >>> #
    
        Exposing a single identifier or a complete namespace simply adds the identifier(s) to the hosting namespace.

        using namespace nameSpaceID;    // Whole namespace
        using nameSpaceID::ID;          // Single ID

# <<< HEADER FILE >>> #

    To avoid contaminating system header files, we include header files in the following order:

        #include < ... > - system header files
        #include " ... " - other system header files
        #include " ... " - your own header files
        
    We insert namespace declarations and directives after all header file inclusions.










# <<< THEORY >>> #

# <<< INTRODUCTION >>> #

    The principles of software engineering suggest that each component should be highly cohesive and that the collection of
    components should be loosely coupled.

    Developers work consists of smaller stand alone and testable sub-projects;
    sub-projects that are transferrable, practical, upgradeable and possibly even usable within other future applications.

    C++ is an object-oriented programming language specifically designed to provide a simple, comprehensive feature set for
    programming modern applications without loss in performance. C++ combines the efficiencies of the C language with the object oriented
    features necessary for the development of large applications.

    # <<< ADDRESSING COMPLEXITY >>> #

        Large applications are complex
        identify the most important features of the problem
        and express them in terms of data and activities.

        The following structure diagram identifies the activities.

        # <<< DIAGRAM >>> #

            Functional Programming


            -                           Course Participation
                                                |
                    |-----------------------------------------------------------|
                    |                           |                               |
            Enroll in a course          Enroll in a Hybrid Course           Earn a Grade

        If we switch our attention to the objects involved,
        we say that a Course has a Code and uses a Grading Scheme and that a Hybrid Course is a kind of Course.

        # <<< DIAGRAM >>> #

            Object Oriented Programming

                        "has a"                       "uses a"
            Code ---------------(|) Course ()--------------- Grading Scheme
                                        /\
                                        || "is a kind of"
                                        ||
                                    Hybrid Course

        In switching our attention from the activities in the structure chart to the objects in the relationship diagram we have switched
        from a procedural description of the problem to an object-oriented description.

        Learning to divide a complex problem into objects and to identify the relationships amongst the objects is the subject matter of
        system analysis and design courses.

    # <<< PROGRAMMING LANGUAGES >>> #

        C++ contains almost all of C as a subset

        |----------------------------| 
        |                  |---------|---|
        |         C++      |     C   |   |
        |                  |---------|---|
        |----------------------------|

        # <<< C x C++ x JAVA >>> #

            C has no object-oriented support. C leaves us no choice but to design our programming solutions in terms of activity
            oriented structures.

            C++ is hybrid. It augments C with object-oriented features. C++ lets us build our solutions partly from activities and
            partly from objects. The main function in any C++ program is a C function, which is not object-oriented. C++ stresses
            compile-time logic.

            Java is purely object-oriented. It excludes all non-object-oriented features. Java leaves us no choice but to design our
            solutions using an object-oriented structures.

        # <<< FEATURES OF C++ >>> #

            Using C++ to learn object-oriented programming has several advantages for a student familiar with C. C++ is

            - nearly a perfect superset of C
            - a multi-paradigm language
                - procedural (can focus on distinct activities)
                - object-oriented (can focus on distinct objects)
            - realistic, efficient, and flexible enough for demanding projects
                - large applications
                - game programming
                - operating systems
            - clean enough for presenting basic concepts
            - comprehensive enough for presenting advanced programming concepts
        
            The file extension for any C++ source code is .cpp.

        # <<< Type Safety >>> #

            Type safety in central to C++.

            A type-safe language traps syntax errors at compile-time, diminishing the amount of buggy code that escapes to the client. C++
            compilers use type rules to check syntax and generate errors or warnings if any type rule has been violated.

            C compilers are more tolerant of type errors than C++ compilers.

            In C++ all prototypes list their parameter types,
            which has forced all C++ compilers to check for argument/parameter type mismatches at compile-time.

        # <<< NAMESPACE >>> #

            In applications written simultaneously by several developers, chances are high that some developers will use the same identifier
            for different variables in the application. If so, once they assemble their code, naming conflicts will arise. We avoid such
            conflicts by developing each part of an application within its own namespace and scoping variables within each namespace.

            A namespace is a scope for the entities that it encloses. Scoping rules avoid identifier conflicts across different namespaces.

            namespace identifier {

            }

            The identifier after the namespace keyword is the name of the scope. The pair of braces encloses and defines the scope.

            # <<< COMMON USAGE >>> #
    
                By far the most common use of namespaces is for classifying
                    - struct-like types
                    - function types

        # <<< C (PC) x C++ (PC) x C++ (HC) >>> #

            # <<< C PROCEDURAL CODE >>> #

                #include <stdio.h>

                The two functions - main() and printf() - specify activities. These identifiers share the global namespace

            # <<< C++ PROCEDURAL CODE >>> #

                #include <cstdio>
                using namespace std;

                <cstdio> is the C++ version of the C header file <stdio.h>.
                This header file declares the prototype for printf() within the std namespace.
                std denotes standard.

            # <<< C++ HYBRID CODE >>> #

                #include <iostream>
                using namespace std;

                The object-oriented syntax consists of:

                # <<< The directive >>> #

                        #include <iostream>

                    inserts the <iostream> header file into the source code. The <iostream> library provides access to the standard
                    input and output objects.

                # <<< The object >>> #

                        cout

                    represents the standard output device.

                # <<< The operator >>> #

                        <<

                    inserts whatever is on its right side into whatever is on its left side.

                # <<< The manipulator >>> #

                        endl
                    
                    represents an end of line character along with a flushing of the output buffer.

    object-oriented languages are designed for solving large, complex problems

# <<< OBJECT TERMINOLOGY >>> #

    Object-oriented programming reflects the way in which we manage day-to-day tasks
    A chunk in object-oriented programming is called an object.
    The shared structure of a set of similar objects is called their class.
    This shared structure includes the structure of the data in the similar objects as well as the logic that works on that data.

    # <<< ABSTRACTION >>> #

        Programming solutions to application problems consist of components. The process of designing these solutions involves
        abstraction. In the C programming language, we abstract common code, store it in a structure or function and refer to that
        structure or function from possibly multiple places in our source code, thereby avoiding code duplication.

        An object-oriented programming solution to an application problem consists of components called objects. The process of
        designing an object-oriented solution likewise involves abstraction. We distinguish the most important features of the object,
        identify them publicly and hide the less important details within the object itself.

        Each object has a crisp conceptual boundary and acts in ways appropriate to itself.

    # <<< CLASSES >>> #

        We describe the structure of similar objects in terms of their class. Objects of the same class have the same structure, but possibly
        different states. The variable types that describe their states are identical, but generally have different values.

        We say that each object is an instance of its class

    # <<< UML >>> #

        The Unified Modelling Language (UML) is a general-purpose modeling language developed for describing systems of objects and
        relationships between their classes. This language defines standard symbols for classes and their relationships. The connectors
        shown in the relationship diagram below are UML connectors.

                    "has a"                       "uses a"
            Code ---------------(|) Course ()--------------- Grading Scheme
                                        /\
                                        || "is a kind of"
                                        ||
                                    Hybrid Course

        # <<< THE CLASS DIAGRAM >>> #

            The primary graphic in UML is the class diagram: a rectangular box with three compartments:
                1. the upper compartment identifies the class by its name
                2. the middle compartment identifies the names and types of its attributes
                3. the lower compartment identifies the names, return types and parameter types of its operations
            
            # <<< EXAMPLE >>> #

                                Code
                ------------------------------------
                number :                int
                title :                 char*
                ------------------------------------
                getCode() :             int
                getTitle() :            const char*
                setCode(int) :          void
                setTitle(const char*) : void

        The naming conventions include:
            - begin each class name with an upper case letter
            - begin each member name with a lower case letter
            - use camel case throughout all names - capitalize the first letter of every word after the first word

        # <<< TERMINOLOGY >>> #

            UML uses the terms attributes and operations. Some object-oriented languages use different terms.
            Equivalent terms are:

                - attributes (UML) -> fields, data members, properties, member variables
                - operations (UML) -> methods (Java), procedures, messages, member functions

            The C++ language standard uses the terms data members and member functions exclusively

    # <<< ENCAPSUlATION >>> #

        Encapsulation is the primary concept of object-oriented programming. It refers to the integration of data and logic within a class'
        implementation that establishes the crisp interface between the implementation and any client. Encapsulation maintains high
        cohesion within a class and low coupling between the class' implementation and any one of its clients.

        A class definition declares the variables and the function prototypes. The variables store each object's data and the functions
        contain the logic that operates on that data. Clients access objects through calls to these functions without knowledge of the data
        stored within the objects or the logic that manipulates that data.

        Encapsulation shields the complex details of a class' implementation from its interface; that is, its crisp external representation.
        As long as the classes in a programming solution are well-encapsulated, any programmer can upgrade the internal structure of any
        object developed by another programmer without changing any client code.

    # <<< INHERITANCE AND POLYMORPHISM >>> #

        Two object-oriented concepts are prominent in our study of the relationships between classes:

            - Inheritance - one class inherits the structure of another class
            - Polymorphism - a single interface provides multiple implementations

        These are special cases of encapsulation in the sense of distinguishing interface and implementation to produce highly cohesive
        objects that support minimal coupling to their clients.

        # <<< INHERITANCE >>> #

            Inheritance relates classes that share the same structure. For example, the Hybrid Course class inherits the entire
            structure of the Course class and adds some further structure. We say that the hybrid course 'is-a-kind-of' Course and depict
            the inheritance relationship using an arrow drawn from the more specialized class to the more general class:

                Course <----- Hybrid Course

            Inheriting one class from another allows us to utilize existing technology. We only provide the code that implements additional
            structure.

        # <<< POLYMORPHISM >>> #

            Polymorphism relates the implementation for an object based on its type. In the Figure below, the HybridCourse object
            involves a different mode of delivery than the Course object, but the same assessments. Both objects belong to the same
            hierarchy: both are Course objects.

            A mode() query on a Course type reports a different result than a mode() query on a Hybrid Course type. On the other
            hand, an assessments() query on a Course type reports the same result as on an HybridCourse type.

            Course          Object -> mode() == A1
            Course          Object -> assessment() == A2
            HybridCourse    Object -> mode() == B1
            HybridCourse    Object -> assessment() == A2

            Polymorphic programming allows us to minimize the duplication of code amongst objects that belong to the same inheritance
            hierarchy.

# <<< MODULAR PROGRAMMING >>> #

    A modular design consists of a set of modules, which are developed and tested separately. Modular programming implements
    modular designs and is supported by both procedural and object-oriented languages. The C programming language supports
    modular design through library modules composed of functions. The stdio module provides input and output support, while
    hiding its implementation details; typically, the implementation for scanf() and printf() ships in binary form with the
    compiler. The stdio.h header file provides the interface, which is all that we need to complete our source code.

    # <<< MODULES >>> #

        A well-designed module is a highly cohesive unit that couples loosely to other modules. The module addresses one aspect of the
        programming solution and hides as much detail as practically possible. A compiler translates the module's source code
        independently of the source code for other modules into its own unit of binary code.

        To translate the source code of any module the compiler only needs certain external information. This information includes the
        names used within the module but defined outside the module. To enable this in C++, we store the source code for each module in
        two separate files:

            - a header file - defines the class and declares the function prototypes
            - an implementation file - defines the functions and contains all of the logic

        The file extension .h (or .hpp) identifies the header file. The file extension .cpp identifies the implementation file.

        Note, however, that the names of the header files for the standard C++ libraries do not include a file extension (consider for
        example, the <iostream> header file for the cout and cin objects).

        # <<< EXAMPLE >>> #

            The implementation file for the main module includes the header files for itself (main.h) and the Transaction module
            (Transaction.h). The main.h file contains definitions specific to the main module and the Transaction.h file
            contains definitions specific to the Transaction module.

            The implementation file for the Transaction module includes the header files for itself (Transaction.h) and the
            iostream module. The Transaction.h file contains definitions specific to the Transaction module and the iostream
            file contains definitions specific to the iostream module.

            An implementation file can include several header files but DOES NOT include any other implementation file. Note the absence
            of any direct connections between the implementation files


            We compile each implementation (*.cpp) file separately and only once. We do not compile header (*.h) files.
            A compiled version of iostream's implementation file is part of the system library

    # <<< STAGES OF COMPILATION >>> #

        Comprehensive compilation consists of three independent but sequential stages (as shown in the figure below):
        1. Preprocessor - interprets all directives creating a single translation unit for the compiler - (inserts the contents of all
            #include header files), (substitutes all#define macros)
        2. Compiler - compiles each translation unit separately and creates a corresponding binary version
        3. Linker - assembles the various binary units along with the system binaries to create one complete executable binary


            main.h
            main.cpp        ------> Main Translation unit --------> main binary
            Transaction.h
                                                                                        ====> Executable
            Transaction.h
            Transaction.cpp ------> Transaction Translation unit -> Transaction binary
            iostream                                        ------> iostream binary

            ======================> ==============================>   ======================>
            PREPROCESSOR                    COMPILER                        LINKER

    # <<< UNIT TESTS >>> #

        Unit testing is integral to modular programming. A unit test is a code snippet that tests a single assumption in a module or work
        unit of a complete application. Each work unit is a single logical component with a simple interface. Functions and classes are
        typical examples.

        We use unit tests to examine the work units in an application and rerun the tests after each upgrade. We store the test suite in a
        separate module.

    # <<< Good Programming Practice >>> #

        It is good programming practice to write the suite of unit tests for the work units in a module as soon as we have defined the
        header file and before coding the bodies of the work units. As we complete implementation details, we continue testing our
        module to ensure that it produces the results that we expect and to identity the work that needs to be done.

    # <<< DEBUGGING TECHNIQUES >>> #

        # <<< PROGRAMMING ERRORS >>> #

            Programming errors that require debugging skills are of two kinds:
                - syntactic
                - semantic

            # <<< SYNTACTIC >>> #

                Syntactic errors are errors that break the rules of the programming language. The most common syntactic errors in C++ language
                programs are:
                    - missing semi-colon after a struct or class definition
                    - unnecessary semi-colon terminator in a #define directive
                    - undeclared variable name or missing header file
                    - mismatched parentheses
                    - left-side of an assignment expression is not a defined memory location
                    - return statement is missing

            # <<< SEMANTIC >>> #

                Semantic errors are errors that fail to implement the intent and meaning of the program designer. The more common semantic
                errors are:
                    - = instead of ==
                    - iteration without a body (for/while followed by a semi-colon)
                    - uninitialized variable
                    - infinite iteration
                    - incorrect operator order in a compound expression
                    - dangling else
                    - off-by-one iteration
                    - integer division and truncation
                    - mismatched data types
                    - & instead of &&

        # <<< IDENTIFYING ERRORS >>> #

            # <<< SYNTACTIC ERRORS >>> #

                Techniques for identifying syntactic errors include
                    - IDE intellisense
                    - compiler error messages (compiler output)
                    - comparing error messages from different compilers - some are more cryptic than others
                    - reading code statements (walkthroughs)
        
            # <<< SEMANTIC ERRORS >>> #

                Techniques for identifying semantic errors include:
                    - vocalization - use your sense of hearing to identify the error (compound conditions)
                    - intermediate output - cout statements at critical stages
                    - walkthrough tables
                    - interactive debugging using
                        - Visual Studio IDE - integrated debugger for Windows OSs
                        - Eclipse IDE - integrated debugger for Linux OSs
                        - gdb - GNU debugger for gcc

            # <<< IDE TRACING EXAMPLE >>> #

                The following steps trace through the execution of our Transaction application using the Visual Studio IDE debugger

                    - Select the file named main.cpp
                    - Move the cursor to the left-most column of the for statement in the main() function and left-click | This places a red
                    - dot in that column, which identifies a breakpoint
                    - Move the cursor to the left-most column of the closing brace for the function and left-click | This places a red dot in the
                    - column, which identifies another breakpoint
                    - Select Debug -> Start Debugging | Execution should pause at the first executable statement
                    - Observe the values under the Locals tab in the Window below the source code
                    - Press F10 and answer the three input prompts
                    - Select the source code Window
                    - Observe the values under the Locals tab in the Window below the source code
                    - Press F10 3 times and note the value of i
                    - Press F5, note where execution pauses and observe the value of i
                    - Press F5 again to exit

                The keystrokes for the various debugging options are listed next to the sub-menu items under the Debug menu.

# <<< TYPES OVERLOADING >>> #

    Object-oriented languages inherit from their non-object-oriented predecessors the concepts of variable declarations, data types,
    data structures, logic constructs, and modular programming.

    References and overloading, which the C++ language adds to its C core, is important in the design of polymorphic objects.

    # <<< TYPES >>> #

        The built-in types of the C++ language are called its fundamental types.
        The C++ language, like C, admits struct types constructed from these fundamental types and possibly other struct types.
        The C++ language standard refers to struct types as compound types. (The C language refers to struct types as derived types.)

        # <<< FUNDAMENTAL TYPES >>> #

            Integral Types (store data exactly in equivalent binary form and can be signed or unsigned)
                bool - not available in C
                char
                int - short, long, long long
            Floating Point Types (store data to a specified precision - can store very small and very large values)
                float
                double - long double


            # <<< BOOL >>> #

                The bool type stores a logical value: true or false.
                The ! operator reverses that value: !true is false and !false is true.
                ! is self-inverting on bool types, but not self-inverting on other types.

            # <<< BOOL TO INT >>> #
            
                Conversions from bool type to any integral type and vice versa require care. true promotes to an int of value 1, while
                false promotes to an int of value 0. Applying the ! operator to an int value other than 0 produces a value of 0, while
                applying the ! operator to an int value of 0 produces a value of 1. Note that the following code snippet displays 1 (not 4)

                Both C and C++ treat the integer value 0 as false and any other value as true.

        # <<< COMPOUND TYPES >>> #

            A compound type is a type composed of other types. A struct is a compound type. An object-oriented class is also a compound
            type. To identify a compound type we use the keywords struct or class.


            The C++ language requires the keyword identifying a compound type only in the declaration of that type. The language does not
            require the keyword struct or class in a function prototype or an object definition.

            Recall that the C language requires the keyword struct throughout the code

        # <<< auto KEYWORD >>> #

            The auto keyword was introduced in the C++11 standard. This keyword deduces the object's type directly from its initializer's
            type. We must provide the initializer in any auto declaration.

            For example,

                auto x = 4; // x is an int that is initialized to 4
                auto y = 3.5; // y is a double that is initialized to 3.5

            auto is quite useful: it simplifies our coding by using information that the compiler already has.

    # <<< DECLARATIONS AND DEFINITIONS >>> #

        Modular programming can result in multiple definitions. To avoid conflicts or duplication, we need to design our header and
        implementation files accordingly. The C++ language distinguishes between declarations and definitions and stipulates the onedefinition
        rule.

        # <<< DECLARATION >>> #

            A declaration associates an entity with a type, telling the compiler how to interpret the entity's identifier. The entity may be a
            variable, an object or a function.
            For example, the prototype

                int add(int, int);

            declares add() to be a function that receives two ints and returns an int. This declaration does not specify what the function
            does; it does not specify the function's meaning.
            For example, the forward declaration

                struct Transaction;

            declares Transaction to be of structure type. A forward declaration is like a function prototype: it tells the compiler how to
            interpret the entity's identifier. It tells the compiler that the entity is a valid type, but does not specify the entity's meaning.
            
            Although a declaration does not necessarily specify meaning, it may specify it. Specifying a meaning is an optional part of any
            declaration.

        # <<< DEFINITION >>> #

            A definition is a declaration that associates a meaning with an identifier.
            For example, the following definitions attach meanings to Transaction and to display():

                struct Transaction {
                int acct; // account number
                char type; // credit 'c' debit 'd'
                double amount; // transaction amount
                };

                void display(const Transaction* tr) { // definition of display
                cout << "Account " << tr->acct << endl;
                cout << (tr->type == 'd' ? " Debit $" : " Credit $") << endl;
                cout << tr->amount << endl;
                }
                

            In C++, each definition is an executable statement. We may embed it amongst other executable statements.
            For example, we may place a definition within an initializer:

                for (int i = 0; i < n; i++)
                //...

        # <<< ONE DEFINITION RULE >>> #

            In the C++ language, a definition may only appear once within its scope. This is called the one-definition rule.
            For example, we cannot define Transaction or display() more than once within the same code block or translation unit.

        # <<< DECLARATIONS ARE NOT NECESSARILY DEFINITIONS >>> #
        
            Forward declarations and function prototypes are declarations that are not definitions. They associate an identifier with a type,
            but do not attach any meaning to that identifier. We may repeat such declarations several times within the same code block or
            translation unit.

            Header files consist of declarations. When we include several header files in a single implementation file, multiple declarations
            may occur. If some of the declarations are also definitions, this may result in multiple definitions within the same translation unit.
            Any translation unit must not break the one-definition rule. We need to design our header files to respect this rule.

        # <<< DESIGNING AWAY MULTIPLE DEFINITION >>> #
        
            A definition that appears more than once within the same translation unit generates a compiler error.
            Two solutions are shown below.

                # <<< FORWARD DECLARATION SOLUTION >>> #

                    Include a prototype or forward declaration in a "foreign" header file.

                # <<< COMPOUND SOLUTION >>> #

                    Include the prototype in a "foreign" header file.

        # <<< PROPER HEADER FILE INCLUSION >>> #
        
            To avoid contaminating system header files, we include header files in the following order:

                #include < ... > - system header files
                #include " ... " - other system header files
                #include " ... " - your own header files

            We insert namespace declarations and directives after all header file inclusions.

    # <<< SCOPE >>> #

        The scope of a declaration is the portion of a program over which that declaration is visible. Scopes include

            - global scope - visible to the entire program
            - file scope - visible to the source code within the file
            - function scope - visible to the source code within the function
            - class scope - visible to the member functions of the class
            - block scope - visible to the code block

        The scope of a non-global declaration begins at the declaration and ends at the closing brace for that declaration. A non-global
        declaration is called a local declaration. We say that an identifier that has been locally declared is a local variable or object.

    # <<< GOING OUT OF SCOPE >>> #

        Once a declaration is out of its scope, the program has lost access to the declared variable or object. Identifying the precise point
        at which a variable's or object's declaration goes out of scope is important in memory management.

        # <<< SHADOWING >>> #

            An identifier declared with an inner scope can shadow an identifier declared with a broader scope, making the latter temporarily
            inaccessible.

    # <<< FUNCTION OVERLOADING >>> #

        In object-oriented languages functions may have multiple meanings. Functions with multiple meanings are called overloaded
        functions. C++ refers to functions first and foremost by their identifier and distinguishes different meanings by differing
        parameter lists. For each identifier and parameter list combination, we implement a separate function definition. C++ compilers
        determine the definition to select by matching the argument types in the function call to the parameters types in the definition.
        
        # <<< FUNCTION SIGNATURE >>> #

            A function's signature identifies an overloaded function uniquely. Its signature consists of

                - the function identifier
                - the parameter types (ignoring const qualifiers or address of operators as described in references below)
                - the order of the parameter types

            The return type and the parameter identifiers are not part of a function's signature.

            C++ compilers preserve identifier uniqueness by renaming each overloaded function using a combination of its identifier, its
            parameter types and the order of its parameter types. We refer to this renaming as name mangling.

        # <<< PROTOTYPES >>> #

            A function prototype completes the function's signature by specifying the return type. However, the parameter identifiers are also
            optional in the prototype. The prototype provides sufficient information to validate a function call.

            A prototype without parameter types identifies an empty parameter list. The keyword void, which the C language uses to
            identify no parameters is redundant in C++. We omit this keyword in C++.

            # <<< PROTOTYPE REQUIRED >>> #

                A programming language may require a function declaration before any function call for type safety. The declaration may be
                either a prototype or the function definition itself. The compiler uses the declaration to check the argument types in the call
                against the parameter types in the prototype or definition. The type safety features of C++ require a preceding declaration.

            # <<< DEFAULT PARAMETER VALUES >>> #

                We may include default values for some or all of a function's parameters in the first declaration of that function.
                The parameters with default values must be the rightmost parameters in the function signature.

                Declarations with default parameter values take the following form:

                    type identifier(type[, ...], type = value);

                The assignment operator followed by a value identifies the default value for each parameter.

                Specifying default values for function parameters reduces the need for multiple function definitions if the function logic is
                identical in every respect except for the values received by the parameters.

                Each call to display() must include enough arguments to initialize the parameters that don't have default values. In this
                example, each call must include at least one argument. An argument passed to a parameter that has a default value overrides the
                default value.

    # <<< REFERENCE >>> #

        A reference is an alias for a variable or object. Object-oriented languages rely on referencing. A reference in a function call
        passes the variable or object rather than a copy. In other words, a reference is an alternative to the pass by address mechanism
        available in the C language. Pass-by-reference code is notably more readable than pass-by-address code. To enable referencing,
        the C++ rules on function declarations are stricter than those of the C language.
        
        The declaration of a function parameter that is received as a reference to the corresponding argument in the function call takes the
        form
        
            type identifier(type& identifier, ... )
        
        The & identifies the parameter as an alias for, rather than a copy of, the corresponding argument. The identifier is the alias for the
        argument within the function definition. Any change to the value of a parameter received by reference changes the value of the
        corresponding argument in the function call.


        Technically, the compiler converts each reference to a pointer with an unmodifiable address.

    # <<< ARRAY OF POINTERS >>> #

        Arrays of pointers are data structures like arrays of values. Arrays of pointers contain addresses rather than values. We refer to
        the object stored at a particular address by dereferencing that address. Arrays of pointers play an important role in implementing
        polymorphism in the C++ language.

        An array of pointers provides an efficient mechanism for processing the set. With the objects' addresses collected in a contiguous
        array, we can refer to each object indirectly through the pointers in the array and process the data by iterating on its elements.

    # <<< KEYWORD >>> #

        The 84 keywords of the C++11 standard are listed below. We cannot use any of these keywords as identifiers. Those shaded in
        grey are also C keywords. The italicized keywords are alternative tokens for operators.

            alignas     alignof     and         and_eq      asm             auto            bitand
            bitor       bool        break       case        catch           char            char16_t
            char32_t    class       compl       const       constexpr       const_cast      continue
            decltype    default     delete      do          double          dynamic_cast    else
            enum        explicit    export      extern      false           float           for
            friend      goto        if          inline      int             long            mutable
            namespace   new         not         not_eq      noexcept        nullptr         operator
            or          or_eq       private     protected   public          register        reinterpret_cast
            return      short       signed      sizeof      static          static_assert   static_cast
            struct      switch      template    this        thread_local    throw           true
            try         typedef     typeid      typename    union           unsigned        using
            virtual     void        volatile    wchar_t     while           xor             xor_eq

        C++ compilers will successfully compile any C program that does not use any of these keywords as identifiers provided that that
        program satisfies C++'s type safety requirements. We call such a C program a clean C program

# <<< DYNAMIC MEMORY >>> #

    Various components of object-oriented programs can be reused by other applications. An important aspect of object designing is
    including flexibility in their memory requirements to enhance reusability. Objects are more reusable by different clients if they
    account for their own memory needs internally. These memory requirements may depend on problem size, which might not even
    be known approximately at compile-time. Programming languages address this aspect of reusability by supporting dynamic
    memory allocation.

    # <<< STATIC AND DYNAMIC MEMORY >>> #

        The memory accessible by a C++ program throughout its execution consists of static and dynamic components. After the user
        starts an application, the operating system loads its executable into RAM and transfers control to that executable's entry point (the
        main() function). The loaded executable only includes the memory allocated at compile time. During execution, the
        application may request more memory from the operating system. The system satisfies such requests by allocating more memory
        in RAM. After the application terminates and returns control to the operating system, the system recovers all of the memory that
        the application has used.

        # <<< STATIC MEMORY >>> #

            The memory that the operating system allocates for the application at load time is called static memory. Static memory includes
            the memory allocated for program instructions and program data. The compiler determines the amount of static memory that each
            translation unit requires. The linker determines the amount of static memory that the entire application requires.

            The application's variables and objects share static memory amongst themselves. When a variable or object goes out of scope its
            memory becomes available for newly defined variables or objects. The lifetime of each local variable and object concludes at the
            closing brace of the code block within which it has been defined:

                // lifetime of a local variable or object
                for (int i = 0; i < 10; i++) {
                double x = 0; // lifetime of x starts here
                // ...
                } // lifetime of x ends here
                for (int i = 0; i < 10; i++) {
                double y = 4; // lifetime of y starts here
                // ...
                } // lifetime of y ends here

            Since the variable x goes out of scope before the variable y is declared, the two variables may occupy the same memory location.
            This system of sharing memory amongst local variables and objects ensures that each application minimizes its use of RAM.

            Static memory requirements are determined at compile-link time and do not change during execution. This memory is fast, fixed
            in its amount and allocated at load time.

        # <<< DYNAMIC MEMORY >>> #

            The memory that an application obtains from the operating system during execution is called dynamic memory.
            Dynamic memory is distinct from the static memory. While the operating system allocates static memory for an application at
            load time, the system reserves dynamic memory, allocates it and deallocates it at run-time.

            # <<< SCOPE CONSIDERATIONS >>> #

                To keep track of an application's dynamic memory, we store the address of each allocated region in a pointer variable. We allocate
                memory for this pointer itself in static memory. This pointer variable must remain in scope as long as we need access to the data
                in the allocated region of dynamic memory.

            # <<< LIFETIME >>> #

                The lifetime of any dynamically allocated memory ends when the pointer holding its address goes out of scope. The application
                must explicitly deallocate the allocated region of dynamic memory within this scope. If the application neglects to deallocate the
                allocated region, that memory becomes inaccessible and irrecoverable until the application returns control to the operating
                system.

                Unlike variables and objects that have been allocated in static memory, those in dynamic memory do not automatically go of out
                scope at the closing brace of the code block within which they were defined. We must manage their deallocation explicitly
                ourselves.

        # <<< DYNAMIC ALLOCATION >>> #

            The keyword new allocates contiguous memory dynamically and returns the address of the memory location.
            
                pointer = new Type[size];

            The nullptr keyword identifies the address pointed to as the null address. This keyword is an implementation constant.
            Initialization to nullptr ensures that student is not pointing to any valid dereferencable address.

            Array example:

                students = new Student[n];

            The size of this array is a run-time variable and not an integer constant or constant expression.
            In the other hand, array allocated in static memory must be an integer constant or constant expression.

        # <<< DYNAMIC DEALLOCATION >>> #

            The keyword delete followed by the address of a dynamically allocated region of memory deallocates the memory that
            the corresponding new operator had allocated.

            delete pointer;
            delete [] students;

            pointer = nullptr;
            students = nullptr;

            The nullptr assignment ensures that student now holds the null address. This optional assignment eliminates the possibility
            of deleting the original address a second time, which is a serious run-time error. Deleting the nullptr address has no effect.
            
            Note that omitting the brackets in a deallocation expression deallocates the first element of the array, leaving the other elements
            inaccessible.

            Deallocation does not return dynamic memory to the operating system. The deallocated memory remains available for subsequent
            dynamic allocations. The operating system only reclaims all of the dynamically allocated memory once the application has
            returned control to the system.

        # <<< MEMORY ISSUES >>> #

            Issues regarding dynamic memory allocation and deallocation include:

            # <<< MEMORY LEAK >>> #

                Memory leaks are one of the most important bugs in object-oriented programming. A memory leak occurs if an application loses
                the address of dynamically allocated memory before that memory has been deallocated. This may occur if

                    - the pointer to dynamic memory goes out of scope before the application deallocates that memory
                    - the pointer to dynamic memory changes its value before the application deallocates the memory starting at the address
                        stored in that pointer

                Memory leaks are difficult to find because they often do not halt execution immediately. We might only become aware of their
                existence indirectly through subsequently incorrect results or progressively slower execution.

            # <<< INSUFFICIENT MEMORY >>> #

                On small platforms where memory is severely limited, a realistic possibility exists that the operating system might not be able to
                provide the amount of dynamic memory requested. If the operating system cannot dynamically allocate the requested memory,
                the application may throw an exception and stop executing.

# <<< MEMBER FUNCTION >>> #























# <<< Header Files >>> #

    Hidden logic is when the programmer include external libraries and functions declarations in the .cpp file.
    This hides the logic necessary to understand what this module utilizes.
    Therefore include in header everything that is public, and include in the .ccp everything that is private.

    Keep header inclusions in header files.

    "using namespaces" are not included in header since it is not considered logic required to the module work.

# <<< Preprocessor >>> #

    # <<< EXAMPLE >>> #

        firstPart.aaa {
            #include <iostream>
            using namespace std;
            int main() {
                cout << "Something" << endl;
        }

        secondPart.bbb {
                cout << "Nothing" << endl;
                return 0;
            }
        }
        
        main.cpp {
            #include "firstPart.aaa"
            #include "secondPart.bbb"
        }

        This code works because preprocessor is only copying and pasting

    All lines that starts with # are processed before compiling.
    Namely, during preprocessor time where the source code is combined into translations units.
    Additionally during preprocessor time all lines that starts with # are executed.

    In the case of headers, all their content are copied into the place where #include is located.

# <<< OVERLOADING >>> #

    function overloading is only based on their signature.
        - function identifier
        - function parameters types (IGNORING const and &)
        - order of function parameters types

# <<< DEFAULT PARAMETERS >>> #

    default values should be the leftmost parameters in the function signature.

    int add(int num1, int num2 = 10);