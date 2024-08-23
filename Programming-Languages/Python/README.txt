import ...                              - Import libraries
import ... as ...                       - Import libraries as nickname
from ... import ..., ..., ...           - Specific import

def main():
    print("Hello")


if __name__ == '__main__':              - If program starts here,
    main()                              - execute this steps.


#               - Comment line
""" """         - Comment lines / DocStrings (when used with help())

help()          - Ask Python information

# <<< Python Output >>> #

    print("Hello " + " World")              - Print + \n
    print("Age: " + str(age))               - Cast to string before printing

    print("STR", end=" ")                   - Print + " "

    print("Min: {} and Max: {}".format(11, 22))
    print("Min: {1} and Max: {0}".format(22, 11))
    print("Min: {first} and Max: {second}".format(first=11, second=22))

    print(f"Min: {11} and Max: {22}")
    print(f"Min: {x} and Max: {y}")

    {:10}       - Allocate space / Padding
    {:<10}      - Left align     / Default
    {:>10}      - Right align
    {:^10}      - Center align

    {:.2f}      - Set float precision to ...
    {:,}        - Add comma every 3 digits
    {:b}        - Binary representation
    {:o}        - Octal representation
    {:X}        - Hexadecimal representation
    {:E}        - Scientific Notation representation

# <<< Python Input >>> #

    my_var = TYPE( input("Type input: ") )  - Get any input
                                            - Return is always string
                                            - Casting input to a specific type is good practice

# <<< Python Types >>> #

    Core Types          - string, integer, float, boolean, char

    type(my_var)        - Returns variable's type

    Indirect type       - The compiler automatically deduces the type/class

    Multiple init       - my_var1, my_var2, my_var3 = "String", 22, True

# <<< Python Strings >>> #

    # <<< Strings Actions >>> #

        len(str)                    - size

        str.find("B")               - Find first occurrence
        str.count("B")              -
        str.replace("B", "A")       - Replace each "B" with "A"

        str.split( DELIMITER )      - splits the string according to the delimiter

        " > ".join([str1, str2])    - join all strings inserting " > " between them

    # <<< String Evaluation >>> #

        str.isdigit()               - Is only digits?
        str.isalpha()               - Is only letters?
        str.isnumeric()             -
        str.isascii()               -
        str.isprintable()           -
        str.isdecimal()             -
        str.isspace()               -
        str.isalnum()               -
        str.isidentifier()          -
        str.istitle()               -

        str.endwith("...")          -

        str.isupper()               -
        str.islower()               -

    # <<< Strings Mods >>> #

        str.capitalize()    - First letter to upper

        str.upper()         - All to upper case
        str.lower()         - All to lower case

        str.strip()         - Remove whitespaces
        str.lstrip()        - Remove left whitespaces
        str.rstrip()        - Remove right whitespaces

    # <<< String Slicing >>> #

        str[start:stop:step]        - Get substring
                                        - start index
                                            - inclusive
                                            - Can be blank [:4]
                                        - stop index
                                            - exclusive
                                            - Can be blank [4:]
                                        - step can be negative

        str.slice(start,stop,step)  - Get substring

        ["H", "e", "l", "l", "o"]   - Python works with negative index
          0    1    2    3    4
         -5   -4   -3   -2   -1

# <<< Python Type Casting >>> #

    x = int("11")
    x = float("22.22")
    x = str(33)
    x = bool("true")

# <<< Python MATH >>> #

    import math

    round(x)            - To nearest integer
    math.ceil(x)        - Round up
    math.floor(x)       - Round down
    abs(x)              - How far way the number is from 0      (Absolute)
    pow(x, 2)           - x to the power of ...
    math.sqrt(x)        - Square root
    max(x,y,z)          - Find maximum value
    min(x,y,z)          - Find minimum value

# <<< Python Operators >>> #

    Math Operators                  - (+, -, *, /, %)
    Increment Operators             - (+=, -=, *=, /=, %=)
    Relational Operators            - (==, ===, !=, >, >=, <, <=)
    Logical Operators               - (||,  &&, !)                      - (false && ... anything after is not evaluated)
                                    - (or, and, not)                    - (true  || ... anything after is not evaluated)

    ==	- compares the value
    ===, is	- compares the object memory address

# <<< Python If Statements >>> #

    if x < 18:
        ...
    elif x == 18:
        ...
    else:
        ...

    if x in my_list:        - Generic .contains
        ...

# <<< Python While Statements >>> #

    while ... :
        ...

# <<< Python For Statements >>> #

    for i in range(start,end,step):     - start index = inclusive
        ...                             - stop index  = exclusive
                                        - step can be negative

    for c in str:                       - char iteration

    for item in my_list:                - for each

    for i,k in enumerate():             -

    for k,v in my_dict.items():         - Biding

# <<< Python Loop Control >>> #

    break           - Terminate the loop
    continue        - Skips to the next iteration
    pass            - Does nothing, just a placeholder

# <<< Python Data Structures >>> #

    # <<< List >>> #

        Initialization      - my_list = []
                            - my_list = [11, 22, 33, ...]
                            -
        Access              - my_list[INDEX]
                            - my_list[start:stop]


        .append(DATA)       - Inserts in the end
        .insert(x,DATA)     - Inserts in x
        .pop()              - Removes in the end
        .remove(DATA)       - Removes DATA

        .sort()             -
        .reverse()          -
        .clear()            -

        .copy()             -
        .extend(otherList)  -

        # <<< List Comprehension >>> #

            A way to create a new list with less syntax,
            can mimic some lambda functions

            my_list = [expression/value for item in iterable]
            my_list = [expression/value fOR_1 FOR_2 ...]
            my_list = [expression/value fOR_1 FOR_2 ... IF ...]
            my_list = [expression/value IF ... ELSE ... FOR_1 FOR_2 ...]
            my_list = [complex_func(value) for item in iterable]

            my_list = [i for i in range(0, 4) for x in range(0, 3) for y in range(0, 2) if i % 2 == 0]

            SAME AS         -       for i in range(0,4):
                            -           for x in range(0,3):
                            -               for y in range(0,2):
                            -                   if (i % 2 == 0):
                            -                       my_list.append(i)

            my_list = [i if i % 2 == 0 else "NOT EVEN" for i in range(0, 4) for x in range(0, 3) for y in range(0, 2)]

            SAME AS         -       for i in range(0,4):
                            -           for x in range(0,3):
                            -               for y in range(0,2):
                            -                   if (i % 2 == 0):
                            -                       my_list.append(i)
                            -                   else:
                            -                       my_list.append("NOT EVEN")

    # <<< Tuple >>> #

        Collection which is ordered and unchangeable

        Initialization      - my_tuple = ()
                            - my_tuple = ("Hello",11,"World")
                            -
        Access              - my_tuple[INDEX]
                            - my_tuple[start:stop]


        .count(DATA)        -
        .index(DATA)        -

    # <<< Set >>> #

        Collection which is unordered, unique and not indexed

        Initialization          - my_set = set()
                                - my_set = {'a', 'b', 'c'}


        .add(DATA)                  -
        .remove(DATA)               -
        .clear()                    -
        .update(other_set)          - add unique values
        .difference(other_set)      - Return this_set unique values
        .intersection(other_set)    - Return this_set not unique values

        set_1 = set_2.union(set_3)      - join sets

    # <<< Dictionary >>> #

        Changeable, unordered collection of unique key:value pairs

        Initialization          - my_dict = dict()
                                - my_dict = {'a':11, 'b':22, 'c':3}
                                -
        Access                  - my_dict['a']


        .get(KEY)               - Safe Access
        .keys()                 - Key set
        .values()               - Values list
        .items()                - Both keys and values
        .clear()                -

        .update(otherDict)      - Add/Modify
        .pop('a')               - remove

    # <<< Dictionary Comprehension >>> #

        Create dictionaries using an expression
        can replace loops and some lambda functions

        my_dict = { key: expression/value for (key, value) in iterable }
        my_dict = { key: expression/value for (key, value) in iterable IF ...}
        my_dict = { key: expression/value IF ... ELSE ... for (key, value) in iterable }
        my_dict = { key: complex_func(value) for (key, value) in iterable }

        sunny_weather = {key: value for (key, value) in weather.items() if value == "sunny"}

                            - key == city name
                            - value == city weather

        cities_weather = {key: "WARM" if value >= 23 else "COLD" for (key, value) in temperature.items()}

                            - key == city name
                            - value == city temperature

    # <<< Conversions >>> #

        my_list = list(my_tuple)

# <<< Python Reference x Shallow Copy x Deep Copy >>> #

    Works in Data Structures and Classes

    import copy

    list2 = list1                   - Both are pointing to the same object (Reference)

    x = copy.copy( y )              - Shallow copy:
                                        - One level deep
                                        - after first level, all others are References

    x = copy.deepcopy( y )          - Deep copy:
                                        - Full copy in all levels
                                        - No references

# <<< Python Function >>> #

    def my_func( param1, param2, ...):                  - Function name, (Optional Parameters)
        ...                                             - Function body
        return ...                                      - Optional Return

    def my_func( param1 = 77, param2 = 44, ...):        - Optional default value

    my_func(x, y)                                       - Call
    my_func(param2 = x, param1 = y)                     - parameter specific call

    # <<< Function Pointer >>> #

        Function are treated as objects

        func_ptr = my_func                      - func_ptr points to my_func memory address
        func_ptr()                              - Works as my_func

    # <<< High Order Functions >>> #

        1. Function that accepts a function as an argument
        2. Function that returns a function

    # <<< Lambda Functions >>> #

        Function written in one line using lambda keyword
        accepts any number of arguments, but only has one expression
        ( Useful if needed for a short period of time )

        lambda ..., arguments, ... : ...expression....

        sum_temp = lambda x, y: x + y
        sum_temp(2,22)

# <<< *args >>> #

    Parameter that will pack all arguments into a tuple

    def add(*args):
        sum = 0
        for num in args:
            sum += num
        return sum

    add(1,2,3,4,5,6,7,8,9)

# <<< **kwargs >>> #

    Parameter that will pack all arguments into a dictionary

    def my_func(**kwargs):
        for key,value in kwargs.items():
            ...

    my_func('a':11, 'b':22, 'c':33)

# <<< Python Sorting and Searching >>> #

    my_list.sort()                                  - .sort() only works with lists
    my_list.sort(reverse=True)

    sorted_dt = sorted( my_dt )                     - sorted() works with iterables (list, tuple, etc...)
                                                    - returns a sorted list
    sorted_dt = sorted( my_dt, reverse=True )

    # <<< Key= >>> #

        my_list = [("String_1", 11, 11.11),
                   ("String_2", 22, 22.22), ...]

        my_list.sort()                                      - Default == [0]        (Strings)

        integers = lambda this_list : this_list[1]
        my_list.sort( key=integers )                        - Sorted by [1]         (Integers)

        my_list.sort( key=integers, reverse=True )


    import random
    <>  random.shuffle(my_list)

# <<< Python Try Statement >>> #

    try:                        - Try body
        ...
    except ...:                 - Specific exception
        ...
    except Exception as e:      - Generic exception
        print(e)
    else:                       - If no exceptions
        ...
    finally:                    - Always executes at the end
        ...

# <<< Python File Handling >>> #

    TRY can be used to avoid program crashes, but it is optional

    # <<< File Detection >>> #

        import os

        path = "...\\message.txt"

        if os.path.exists(path):
            ...
            if os.path.isfile(path):
                ...
            elif os.path.isdir(path):
                ...
        else:
            ...

    # <<< File Reading >>> #

        import os

        path = "...\\message.txt"

        with open(path, 'r') as file:       - Open and closes the file automatically

            print(file.read())              - Reads the entire file

    # <<< File Writing >>> #

        import os

        path = "...\\message.txt"

        with open(path, 'a') as file:           - 'a'  Append mode
        with open(path, 'wr') as file:          - 'wr' Write and read mode
        with open(path, 'w') as file:           - Opening file in 'w' deletes everything inside it

            file.write("Hello World\n")

    # <<< File Copy >>> #

        import shutil

        copyfile()          - Copies contents of a file
        copy()              - copyfile() + permission mode + destination can be a directory
        copy2()             - copy() + copies metadata (file's creation and modification times)

        (file_path, destination_path)       - copy file to destination

    # <<< File Move >>> #

        import os

        source = "..."
        destination = "..."

        try:
            if os.path.exists(destination):             - Prevents overwrites
                print("File path already exists")
            else:
                os.replace(source, destination)
        except FileNotFound:
            print(source+" was not found)

    # <<< File Delete >>> #

        import os

        path = "..."

        os.remove(path)         - Does not delete FOLDERS
        os.rmdir(path)          - Only deletes empty FOLDERS

        import shutil

        shutil.rmtree(path)     - !!! DANGEROUS FUNCTION !!!
                                - It deletes the FOLDER and ALL it contents

# <<< Python Modular Programming >>> #

    Module is a file containing python code (May contain functions, classes, ...)
    Modular Programming is to separate a program into parts

    NEW FILE            - my_functions.py

    INSIDE main.py

    import my_functions as mf

    mf.sum(2,2)

# <<< Python Class >>> #

    Good practice to create classes in SPECIFIC FILES

    class Human:
        total = 0       # class variable / static

        def __init__(self, name, age):                                          - Constructor
            self.name = name        # instance variable
            self.age = age          # instance variable

        def run(self):
            print("Human is running")
            # return self                           - You can return self to allow method chaining

        def fight(self):
            print("Human cannot fight")

        def __str__(self):                                                      - to_string
            return "Human name: " + self.name + " and age: " + str(self.age)


    e.g.
    from human import Human

    my_human = Human("Mato", 22)            - Initialization

    Human.total += 1                        - Updating static variable

# <<< Python Inheritance >>> #

    instanceof                              - if h.__class__ is Hero:

    from human import Human

    class Hero(Human):
        def __init__(self, name, age, power):
            super().__init__(name, age)
            self.power = power

        def run(self):
            print("Hero is running")

        def fight(self):
            print("Hero is fighting with power: " + self.power)

        def __str__(self):
            return "Hero name: " + self.name + " and age: " + str(self.age)

# <<< Python Multiple-Inheritance >>> #

    More than one parent class

    class Scientist(Human, Intelligent):
        ...

# <<< Python Abstract Class >>> #

    Prevents initialization + enforce overrides in the child class

    from abc import ABC, abstractmethod

    class City(ABD):

        @abstractmethod                 - At least one abstract method is needed
        def info(self):
            pass

# <<< Python operators >>> #

    # <<< := operator >>> #

        assignment expression a.k.a. walrus operator,
        assigns values to variables as part of a larger expression

        # print(isLooping =  true)          - ERROR
        print  (isLooping := true)          - WORKS

        food_list = []                                                  - First var food is assigned with input
        while food := input("Add food to the list: ") != "quit":        - then the expression is evaluated
            food_list.append(food)

# <<< Python Map >>> #

    Applies a function to each item in an iterable (list, tuple, etc...)

    map(function, iterable)

# <<< Python Filter >>> #

    Creates a collection of elements from an iterable for which a function returns true

    filter(function, iterable)

    older_friends = list( filter(check_age_greater_than_18, friends_list) )

    older_friends only contains people which the function returned true

# <<< Python Reduce >>> #

    Apply a function to an iterable and reduces it to a single cumulative value.
    It performs the function on first two elements and repeats it until 1 value remains.

    reduce(function, iterable)

    letters = ["H", "E", "L", "L", "O"]

    word = reduce( lambda l1, l2 : l1 + l2, letters )

# <<< Python Zip >>> #

    Aggregates elements from two or more iterables (list, set, tuples, etc...).
    It creates a zip object with paired elements stored in tuples for each element

    combined_list = zip( first_list, second_list, ...)              - zip object

    combined_list = list( zip( first_list, second_list, ...) )      - list object

    combined_list = dict( zip( first_list, second_list) )           - if only two elements
                                                                    - it can be cast to dict

# <<< Python Time >>> #

    import time

    .ctime(0)                   - Reference point                                       (reference point + 0s)
    .time()                     - Current time in seconds since reference point         (currTime - reference point)
    .ctime(time.time())         - Current time                                          (reference point + currTime)

    t = .localtime()                    - Current time as a time_object
    format = "%B %d %Y %H:%M:%S"        - ! For more formats options go to reference !
    .strftime(format, t)                - Returns a ?? formatted time_object // formatted String ??

    t = .gmtime()               - UTC time

    str_time = "20 April, 2022"
    .strptime(str_time, "%d %B, %Y")    - String -> time_object

    # time_tuple = (year, month, day, hours, minutes, secs, day of the week, day of the year, dst)
    time_tuple = (2022, 4, 20, 4, 20, 0, 0, 0, 0)
    str_time = .asctime(time_tuple)                     - Tuple to formatted String
    str_time = .mktime (time_tuple)                     - Seconds since reference point


    time.sleep(x)         - this_thread sleeps for x seconds

# <<< Python Threading >>> #

    THREAD      - A flow of execution, each thread with their order of instructions.
                - However each thread takes a turn running to achieve concurrency.
                - GIL = global interpreter lock,
                - allow only one thread to hold control of the Python interpreter at any one time

    CPU BOUND   - program/task spends most of it's time waiting for internal events (CPU Intensive)
                - Use multiprocessing

    IO BOUND    - program/task spends most of it's time waiting for external events (User input, web scraping)
                - Use multithreading

    import threading
    import time

    threading.active_count()            - Program's threads count
    threading.enumerate()               - List of Program's threads

# <<< Python multithreading >>> #

    import threading
    import time

    thread_1 = threading.Thread( target = my_func_1, args=() )          - function parameters go
    thread_1.start()                                                    - inside args=()

    thread_2 = threading.Thread( target = my_func_2, args=() )
    thread_2.start()

    thread_3 = threading.Thread( target = my_func_3, args=() )
    thread_3.start()

    thread_1.join()                     - Main Thread is going to wait here until thread_1 finishes
    thread_2.join()                     - The .join() is optional
    thread_3.join()

# <<< Python multiprocessing >>> #

    !!! After reaching the total number of cores that your pc has, starting more processes
    will only make the program run slower. Use cpu_count() to check how many cores your pc has !!!

    from multiprocessing import Process, cpu_count
    import time

    def counter(num):
        count = 0
        while count < num:
            count += 1


    def main():
        # counter(1000000000)           - Original problem, 1 core

        process_1 = Process(target = counter, args = (250000000))
        process_2 = Process(target = counter, args = (250000000))
        process_3 = Process(target = counter, args = (250000000))
        process_4 = Process(target = counter, args = (250000000))

        process_1.start()
        process_2.start()
        process_3.start()
        process_4.start()

        process_1.join()
        process_2.join()
        process_3.join()
        process_4.join()


    if __name__ == "__main__":          - !!! If you are running on Windows !!!
        main()                          - You need to use        if __name__ == "__main__":
                                        - Multiprocessing is going to create a child of this module
                                        - and to avoid an infinite loop of children creating more
                                        - copies of this module, you need this statement

# <<< Daemon Thread >>> #

    A thread that runs in the background, not important for the program to run.
    Your program will not wait for daemon threads to complete before exiting.
    While non-daemon threads cannot normally be killed, staying alive until task is completed.

    Daemon thread can be: background tasks, garbage collection, waiting for input, long-running processes

    import threading
    import time

    def timer():
        count = 0
        while True:
            time.sleep(1)
            count += 1


    daemon_thread_1 = threading.Thread(target = timer, daemon = True)

# <<< Python EMAIL handling >>> #

    import smtplib

    sender   = "myEmail@something.com"
    receiver = "someonesEmail@something.com"
    password = "myEmailPassword"
    subject  = "my email title"
    body     = "my email contents"

    message  = f"""From: {sender}
    to: {receiver}
    Subject: {subject}\n
    {body}
    """

    server = smtplib.SMTP("smtp.something.com", 587)
    server.starttls()

    try:
        server.login(sender, password)
        server.sendmail(sender, receiver, message)

    except ...:
        ...

# <<< Python CSV Handling >>> #

    import csv

# <<< Python + REGEX >>> #

    import re

# <<< Python Unit Test >>> #











# <<< Python run from command prompt >>> #

    python my_program.py

# <<< Python pip >>> #

    Package manager                 - https://pypi.org/

    pip                             - help menu
    pip --version                   - pip version
    pip install --upgrade pip       - update pip.
    pip list --outdated             - list of outdated packages
    pip install ...                 - install package
    pip install ... --upgrade       - update package

# <<< Python .py to .exe >>> #

    (Windows defender may prevent you from running)
    (Make sure pip and pyinstaller are installed/updated)

    First create a new folder and put everything there

    In the command prompt:
    cd to the directory that contains your .py file
    pyinstaller -F -w -i icon_name.ico python_project.py
                    -
                    - F                         - (All in one file)
                    - w                         - (Removes terminal window)
                    - i icon_name.ico           - (Adds custom icon to .exe) (image needs to be .ico)
                    - python_project.py         - (Name of your main python file)

    .exe is located in the dist folder

# <<< Python Scope >>> #

    Local  Scope    - Available only inside function + Have higher priority (When name is the same)
    Global Scope    - Available everywhere

# <<< Python Libraries >>> #

    math            -
    time            -
    random          -
    shutil          -
    os              -
    time            -
    threading       -
    multiprocessing -
    smtplib         -
