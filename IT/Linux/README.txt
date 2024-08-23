# <<< SYNTAX PRINCIPLE >>> #

    "!! PAY ATTENTION TO THE PLACEMENT !!"

    # <<< COMMANDS >>> #

        command argument1 argument2 ...

        command is:
                            - "Commands allow you to interact with OS"

        argument can be:
                            - "FILE PATHNAME"
                            - "OPTION / FLAG"
                            - "TEXT"

        option is:
                            - "To modify the command behavior or output."

        SPACE/SPACES/TAB    - "separates arguments from arguments or commands"
        ;                   - "separates commands from commands"

        |                   - "transfer output to next command"

    # <<< STANDARD OUT/IN/ERR >>> #

        "Redirect"
        "The position may vary"

        <                   - [standard input]
        >                   - [standard output + overwrite]
        >>                  - [standard output + append]
        2>                  - [standard error + overwrite]
        2>>                 - [standard error + append]

        <<+
                            - "INLINE/TERMINAL input for commands"
                            - "STOP AT + OR DEFINED SYMBOL"

                            - "E.G."
                            - grep 2 > line2.txt <<+
                            - line 1
                            - line 2
                            - line 3
                            - +
                            
                            - "E.G."
                            - (grep 2 > line2.txt) <<+
                            - line 1
                            - line 2
                            - line 3
                            - +

    ()                  - "group commands to be executed together"
                        - "Useful when using STANDARD INPUT OR OUTPUT"
                        - (cmd1 | cmd2 | cmd3) >> file                  - "Final output is appended"
                        - (cmd1 | cmd2 | cmd3) < file                   - "Input goes first to cmd1"
                        - (cmd1; cmd2; cmd3) >> file                    - "All 3 outputs are appended"

    \                   - "spread command over multiple lines"

    # <<< PATHS >>> #

        .                   - current path 
        ..                  - parent path

        dir1/f.txt          - relative path                                         - "Do not start with /"
        ~                   - relative-to-home pathname     - [/home/username]      - "Access other users' home"
        /home/username/     - absolute path

    # <<< FILENAME EXPANSION >>> #

        "Filename Expansion are used for command file management and file manipulation commands."

        - "more efficient (less typing)"            - "!! DO NOT MISTAKE WITH REGEX !!"

        - *         - "0 or more characters  (any character)"
        - ?         - "exactly one character (any character)"
        - []        - "match characters within square brackets"
        - [!]       - "match characters not within square brackets (opposite)"

        # <<< EXAMPLES >>> #

            - "SOME TIME IS WORKS SOME TIMES IT DOES NOT"
            - "TO MAKE SURE IT WILL WORK USE " INSIDE [] "
            - "HOWEVER THE ISSUE IS DEEPER THAN THIS"

            - ls [0-9][0-9][0-9].txt
            - ls [a-z][a-z][a-z].txt
            - ls [A-Z][A-Z][A-Z].txt
            - ls [a-zA-Z0-9][a-zA-Z0-9][a-zA-Z0-9].txt
            - ls *.???

    # <<< ESCAPE CHAR >>> #

        \                   - Escape all special chars
        ''                  - Escape all special chars
        ""                  - Escape some special chars          - "ENVIRONMENT VARIABLES still work"

    # <<< BLACK HOLE >>> #

		- The /dev/null file ( sometimes called the bit bucket or black hole )
		- is a special system file that discards stdout or stderr.
		- This is useful to "throw away " unwanted command output or errors.

		# <<< EXAMPLES >>> #

			- ls 2> /dev/null
			- ls > /dev/null
			- find / name " tempfile " 2> /dev/null

# <<< CORE >>> #

    alias [NICKNAME]=['COMMAND']
    
        alias                               - "alias command without an argument will display all the aliases currently set"
        
        alias listMyDir=ls                  - "Gives a nickname to a command"

        alias detailedList='ls -l'          - "With options"

        alias clearfile='cat /dev/null >'   - "command + FilePath"


        "!! .bash_profile !! save permanently, not recommended to modify"
        "!! ~/.bashrc !! start-up file"

    unalias [NICKNAME]

        unalias listMyDir                   - "Remove alias"

    awk [-F""] ['selection_criteria {action}'] [FROM]   

        "awk is mostly used for pattern scanning and processing"
        "It searches one or more files to see if they contain lines that matches"
        "Then it performs the associated actions"

        "The awk command is useful for reading database files to produce reports"
        "And also works in a pipeline as a filter"

        FLAG:

        -F"..."     - "Custom input record separator (default: SPACE or TAB)"


        SELECTION CRITERIA:

        "!!! ADVANCED REGEX DEFAULT !!!"

        '/pattern/       {...}'         - "Search for match in all fields"
        '$1 ~ /pattern/  {...}'         - "Search for match in field 1 of each line"
        '$1 !~ /pattern/ {...}'         - "Search for NO match in field 1 of each line"


        RELATIONAL ( >, >=, <, <=, ==, != )

        '$1 < numeric   {...}'          - "Numeric comparisons"
        '$1 == "string" {...}'          - "String comparisons"

        LOGICAL ( ||   && )

        '... && ...   {...}'
        '(... || ...) {...}'            - "Works with ()"


        ACTION:

        "!! WHAT AND HOW TO PRINT !!"

        '/.../'                         - "{print} is the default when anything is specified"
        '{print}'
        '... {print}'
        '... {print $0}'
        '... {print $3, $1}'
        '... {print NR, $3, $1}'

        , == "add field separator"

        awk 'address {print $1, $2}'            - "',' == default output field separator"
        awk 'address {print $1 OFS $2}'         - "OFS == default output field separator"
        awk 'address {print $1 " - " $2}'       - "Custom output field separator"


        BUILT IN VARIABLES (WORKS WITH selection_criteria and action)

        $0          - All fields
        $1 ... $9   - Fields 1 through 9         (Field 1 is the first column)
        ${10}       - Fields after 9

        FILENAME    - Name of the current input file
        NF          - Number of fields in the current record
        NR          - Record number of the current record

        FS          - Input field separator (default: SPACE or TAB)
        RS          - Input record separator (default: NEWLINE)
        OFS         - Output field separator (default: SPACE)
        ORS         - Output record separator (default: NEWLINE)


        EXAMPLES:

        awk -F";" 'address {command}'           - "Custom input record separator"

        awk 'address {print $NF}'               - "Prints last field"

        awk 'NR >= 2 && NR <= 5 {print}'        - "Prints specific lines"
                                                - "!! SIMILAR TO SED LINE ADDRESSING !!"


        awk '$6'            - "Prints records containing at least 6 fields"
        awk 'NF >= 6'       - "Prints records containing at least 6 fields"

    bg [%JOB_NUM]
        - "Brings process from stopped sate to running background"
        - "AKA it starts a suspended background process"

        "NOTE: You can use the bg command WITHOUT arguments to run recent in the background."
        "From the jobs command, the process that has a plus sign "+" indicates the most recent process placed into the background."

    cal [day, month, year]

        - []                    - "Current month + Select day"
        - [year]                - "Show 12 months "
        - [month, year]         - "Show month"
        - [day, month, year]    - "Show month + Select day"

    cat [FROM] [FROM] ...
        - "Display files contents / read"       - "(small files)"

    cd [FROM]
        - "Change directory"

    clear
        - "Clear terminal"

    cp [FROM] [FROM] ... [TO]
        - "COPY"

        - R                 - "RECURSIVELY / ALLOWS copying directory"
        - r                 - "RECURSIVELY / ALLOWS copying directory"


        "!!! MORE THAN 2 ARGUMENTS REQUIRES LAST ARGUMENT TO BE A DIR !!!"

        "!!! REQUIRES R PERMISSION !!!"

    cut [...] [FROM]
        [-c1-10] [FROM]                 - "CUT FROM CHAR 1 TO CHAR 10"
        [-f1-10] [-d" "] [FROM]         - "CUT FROM COLUMN 1 TO COLUMN 10"
                                        - "EACH COLUMN IS DIVIDED BY ' '"       - aka -d" "
                                        - "THE DEFAULT VALUE IS TAB"

        -d          - "DEFINE DELIMITER"
        -d$'\t'     - "TAB"

        "!! WHILE ON SENECA USE -d ALWAYS !!"

    date
        - "Current OS time"
            - "e.g."            - [Mon Feb 20 17:33:39 EST 2023]


        - "FORMAT"

        date +"..."
        date "+..."

        %D – Display date as mm/dd/yy
        %Y – Year (e.g., 2020)
        %m – Month (01-12)
        %B – Long month name (e.g., November)
        %b – Short month name (e.g., Nov)
        %d – Day of month (e.g., 01)
        %j – Day of year (001-366)
        %u – Day of week (1-7)
        %A – Full weekday name (e.g., Friday)
        %a – Short weekday name (e.g., Fri)
        %H – Hour (00-23)
        %I – Hour (01-12)
        %M – Minute (00-59)
        %S – Second (00-60)

    diff [FILE1] [FILE2]
        - "Display differences between files"

    df [FROM]

        - "shows the used disk space on the file system that contains filename[FROM]."

    du

        - "short for disk usage, is used to estimate file space usage."
        - "the du command can be used to track the files and directories which are consuming excessive amount of space on hard disk drive."

    echo [TEXT]
        - "ENTER TEXT"

        - echo ["..."] > filename           - "WRITE TO FILENAME"


        -n              - "display text without the newline character"


        echo  ... ...           - "print line"      - "!! although it works with more than one word, prefer "" !!"
        echo '...'              - "!! Escape all special chars  !!"
        echo "..."              - "!! Escape some special chars !!"


        "!! ADVANCED !!"


            echo 'Hello'            \\      Normal message
            echo 'Hello'    >&1      ||     Explicitly redirection to stdout     (display)
            echo 'Hello'    1>&1    //      Explicitly redirect output           (non-error)

            echo 'Error'    >&2     \\      Redirect Normal message to stderr   (Error-display)
            echo 'Error'    1>&2    //      Explicitly redirect output

            ecchhoo 'eR"            \\      Normal error message
            ecchhoo 'eR"    2>&1     ||     Redirect Error message to stdout    (display)
            ecchhoo 'eR"    2>&2    //      Explicitly redirection to stderr     (Error-display)


            File descriptor 1 is stdout and File descriptor 2 is stderr.

            Using > to redirect output is the same as using 1>.
            This says to redirect stdout (file descriptor 1).

            Normally, we redirect to a file. However, we can use >&
            to redirect to stdout (file descriptor 1) or stderr (file descriptor 2) instead.

            Therefore, to redirect stdout (file descriptor 1) to stderr (file descriptor 2),
            you can use >&2

    egrep ["EXTENDED_REGEX"] [FROM]
        - "grep -E          AKA         Extended Regex"

    exit        
            - "LOGOUT"

    fc
        -l              - "display last 16 commands"

    fg [%JOB_NUM]
        - "Bring background process to the foreground"

        "NOTE: You can use the fg command WITHOUT arguments to run recent in the background."
        "From the jobs command, the process that has a plus sign "+" indicates the most recent process placed into the background."

    file [FROM]
        - "Display information about the file"

    find [FROM] [-name "..."]
        - "STARTING HERE, SEARCH" "..."

        [FROM] [-name "..."]            - "STARTING AT" [FROM] "SEARCH" "..."

        [-size +50k]                    - "FILES GREATER THAN 50KB"
        [-size -50k]                    - "FILES LESS THAN 50KB"

        [-mmin +5]                       - "FILES MODIFIED MORE THAN 5 MINUTES AGO"
        [-mmin -5]                       - "FILES MODIFIED LESS THAN 5 MINUTES AGO"


        "!!!!! PATH NEEDS TO PRECEDE FLAGS !!!!!"
        "!!!!! WORKS WITH FILE EXPANSION !!!!!"


        Examples:
            find ~ -name "*.c"
            find ~ -name "A?"


        -size n[cwbkMG]
              File uses n units of space.  The following suffixes can be used:

              `b'    for 512-byte blocks (this is the default if no suffix is used)
              `c'    for bytes
              `w'    for two-byte words
              `k'    for Kilobytes (units of 1024 bytes)
              `M'    for Megabytes (units of 1048576 bytes)
              `G'    for Gigabytes (units of 1073741824 bytes)

    grep ["SIMPLE_REGEX"] [FROM]
        - "Display lines that MATCH/CONTAINS PATTERN"
        - "!!! GREP IS FOR SEARCHING INSIDE THE FILE. IT IS NOT FOR SEARCHING FILES THEMSELVES !!!"

        grep ‘chevy’        cars        "Simple search"
        grep -w ‘chevy’     cars        "Only complete words"
        grep -n ‘chevy’     cars        "Line numbers"
        grep -c ‘chevy’     cars        "Count"
        grep -i ‘chevy’     cars        "Ignore case"
        grep -ic ‘chevy’    cars        "Ignore case give count"
        grep -r ‘chevy’     .           "Recursive (open all files and dirs until bottom)"
        grep -irc ‘checy’   .           "Recursive for counts ignoring cases"
        grep -v ‘chevy’     cars        "Invert or opposite of search"

        grep -r -l 'chevy'  .           "Recursive + only display filenames containing match"

        "!! Using . means to open all files in the current directory to search for the word !!"

    head [FROM]
        - "Default is 10 FIRST/TOP LINES"

        head -20 [FROM]                 - "FIRST 20 LINES"

        head -20 [FROM] | tail -10      - "LINES 10 to 20"

    history
        - "display all stored commands"

        "!! ~/.bash_history !! stores recently executed command lines"

    hostname

        "Returns the machine your are logged on"

    kill [PROCESS]
        - "Terminates a process"
        - "Check MANAGING PROCESSES for how to kill foreground processes using shortcuts"

        "NOTE: WiTHOUT flags, default SIGTERM signal (#15) is sent"
        "NOTE: You need to be the OWNER to kill a process"

        -[PID]
        -%[NUM]

        -9 [PID]            -"SIGTERM #9"
        -9 %[NUM]           -"SIGTERM #9"

    jobs
        - "Display jobs running"

        "In the jobs command output, jobs that display a plus sign (+) indicates the most recent process"
        "placed in to the background, and a minus sign (-) indicates the second most recent process"
        "placed into the background."

    less [FROM]
        - "DISPLAY / NAVIGATE FILES CONTENTS / READ"       - "(large files)"        - "NEW MORE"

    ln [FROM] [TO]
        - "create a hard link"                  - ".hard.lnk"

        -s              - "SYMBOLIC LINK"       - ".sym.lnk"

    logout      
            - "LOGOUT"

    ls [FROM]
        - "LIST"
        -l              - "DETAILED"
        -R              - "RECURSIVELY"
        -a              - "HIDDEN FILES"        - ".filename"
        -A              - "HIDDEN FILES"        - ".filename"           - "current and parent dir are not displayed"

        -d              - "List directory instead of its contents"      - "Similar to pwd"

        -i              - "INDEX / I-NODE NUMBER"                       - "Finger-print"

        -F              - "ADD / AFTER DIR OR ADD * AFTER EXECUTABLE"

    mv [FROM] [FROM] ... [TO]
        - "MOVE / RENAME"

        "!!! MORE THAN 2 ARGUMENTS REQUIRES LAST ARGUMENT TO BE A DIR !!!"

    mail [TO]
        - "SENDS EMAIL TO ... "

        "!!! ctrl+d TO EOT / EXIT BODY !!!"

        - mail [TO]                             - "Will prompt for subject, then for body"
        - mail -a attach.txt [TO]               - "Will prompt for subject, then for body"
        - mail -s "subject" [TO]                - "Will prompt for body"
        - mail [TO] < attach.txt                - "Will prompt for subject"

    man [COMMAND]
        - "DISPLAY COMMAND MANUAL"
        - k [REGEX]             - "TRY FINDING REGEX IN MANUAL"

    mkdir [TO]
        - "CREATE DIRECTORIES"
        -p                      - "CREATE PARENT DIRECTORIES AT THE SAME TIME"

        mkdir mydir1
        mkdir mydir{1..4}

        mkdir -p d1/d2/d3/mydir5

    more [FROM]
        - "DISPLAY FILES CONTENTS / READ"       - "(small files)"       - "OLD / WORSE THAN LESS"

    passwd [USERNAME]
        - "CHANGE PASSWORD"

    ping [FROM]

        - "check whether a network is available and if a host is reachable."

    ps
        - "ps (process status) command displays Basic listing of processes in current user’s terminal"

        -l                  - "Detailed listing in current user’s terminal"

        -ef                 - "Detailed listing ALL processes running on entire system"
                            - ps -ef|grep nano
                                - "Easier to find"      - "!! MUST BE ON SAME NODE !!"

        ps aux              - "Detailed listing of processes for ALL users and background running services"

        -U [USERNAME]       - "Basic listing of processes running for a particular user"

    pwd
        - "PRINT WORKING DIRECTORY"

    rm [FROM]
        -r              - "REMOVE CONTENTS / NOT EMPTY DIRECTORY"
        -i              - "ASK CONFIRMATION"

        -f              - "Force a deletion operation without rm prompting you for confirmation. For example if a file is unwritable."

    rmdir [FROM]
        - "REMOVE DIRECTORY"

    sed [-n] [-r] ''[address] [instruction]' [FROM]
        
        "Streaming Editor(sed) manipulates files contents or filters pipeline"
        "this command acts like a 'on the fly' text editor"
        
        "The sed command does NOT change content inside a text file"
        "The output can be redirected to another file"
        "It can filter pipeline to be displayed"
        

        "ADDRESS (MATCH CONDITION):"
        5                           - "line 5"
        5,7                         - "line 5 to line 7 (INCLUSIVE)"
                                    - "!! 1 is the first line of the file !!"
        /regular expression/        - "matching"
                                    - "!! NORMAL REGEX BY DEFAULT !!"
                                    - "If NO address is present, the instruction will apply to ALL lines"

        "INSTRUCTION (OPERATION):"

        p           - "Print lines that match the address (commonly used with n option)"
        d           - "Omit (delete) display of lines that match the address"
        q           - "Print lines until(inclusive) line that matches address then quit processing"
        
        s/a/z/      - "replace the first match of 'a' with 'z', once per line" "(Substitute)"
        s/a/z/g     - "global / apply to all"
                    - "!!! zaaa ... !!!"    - "without g"
                    - "!!! zzzz ... !!!"    - "with g"

        -r      - "ADVANCED REGEX"
        -n      - "SUPPRESS DEFAULT OUTPUT"
                - "!!!! ONLY p WORKS WITH -n !!!!"

        "EX:"

        sed -n 'p'                      - "DISPLAY ALL LINES ONCE"

        sed '/line/ p'  f.txt           - "DISPLAY EVERYTHING. + DUPLICATE MATCHED LINES"
        sed -n '/line/ p'  f.txt        - "DISPLAY ONLY MATCHING REGEX."

        sed '5 q'  f.txt                - "DISPLAY EVERYTHING UNTIL LINE 5(INCLUSIVE)"
        sed '/bye/ q'                   - "PRINT LINE BY LINE UNTIL LINE WITH 'bye'(INCLUSIVE)"

        sed 's/hello/bye/' f.txt        - "REPLACE ONE MATCH PER LINE"
        sed 's/hello/bye/g' f.txt       - "REPLACE ALL MATCHES IN LINE"


        sed 's/hello/bye &/'            - "!!! & is a special character !!!"
                                        - "It gets the value matched and use it"
                                "hello" => "bye hello"
        sed 's/hello/bye/'      "hello" => "bye"


        sed '2,5 s/hello/bye/g'         - "Replace only in the matched lines"
        sed '/regex/ s/hello/bye/g'     - "Replace only in the matched lines"

        
        ls | sed ...                    - "PIPELINE / FILTER"

        sed -n 's/hello/bye/ p' f.txt   - "REPLACE + PRINT LINES MATCHED"
                                        - "! NOT EFFICIENT !"
                                        - "! REMOVE -n AND p == SAME OUTPUT !"

    set

        "Temporarily set positional parameters"

        set [arg1] [arg2] ...       - "Delete previous positional parameters"
                                    - "and assign new ones"

        set | more                  - "Shell environment variables"

    sleep [x]
        - "SLEEP FOR X SECONDS"

    ssh [SERVER]
        ssh mtrx-node05pd       - "Change node !! In senecacollege !!"

    sort [FROM]
        - "SORT ALPHABETICALLY BY DEFAULT"

        -r                  - "Reverse order"
        -n                  - "Sort numerically"

    tail [FROM]
        - "DEFAULT IS 10 LAST/BOTTOM LINES"

        tail -20 [FROM]                 - "LAST 20 LINES"


        tail -20 [FROM] | head -10      - "LINES -20 to -10"

    tee [TO]
        - "TEE IS USED TO DUPLICATE THE OUTPUT"

        - "E.G."
        - cmd1 | tee myFile.txt | cmd2              - "SENT DATA TO myFile.txt AND cmd2"

    test [CONDITION / LOGIC EXPRESSION]

        "Evaluate expression"
        " !!!!! A set of square brackets [ ] can be used to represent the test command. !!!!! "
        " !!!!! There must be spaces between the square brackets and the test condition. !!!!!"


        name="John Smith"
        test $name = "John Smith"
        echo $?                 - "Output: 0"       - "TRUE == 0"

        test $name = "John Smithhh"
        echo $?                 - "Output: 1"       - "FALSE == 1"

        test 5 -gt 10
        echo $?                 - "Output: 1"       - "FALSE == 1"

        test 5 -lt 10           
        echo $?                 - "Output: 0"       - "TRUE == 0"


        "!!!! CANNOT USE < or > !!!!"
        "!!!! Since those are redirection symbols !!!!"


        -eq             - Equal to
        -ne             - Not equal to
        -lt , -le       - Less than, Less than or equal to
        -gt, -ge        - Greater than, greater than or equal to


        -f              - file_pathname Regular filename exists
        -d              - file_pathname Directory filename exists
        -s              - file_pathname Regular filename is non-empty
        -w              - file_pathname file exists / write permission is granted

        -z              - the length of STRING is zero
        -n              - the length of STRING is nonzero


        "!!! USE COMPOUND OPERATORS || (OR) && (AND) !!!"

            [ $n lt 0 ] || [ $n gt 100 ]

        "!!! USE COMMANDS EXIT VALUES !!!"

            ! echo $n | egrep "^[-]?[0-9]{0,}$" 2> /dev/null > /dev/null

        "!!! COMBINE EVERYTHING !!!"

            ! echo $n | egrep "^[-]?[0-9]{0,}$" 2> /dev/null > /dev/null || [ $n -lt -5 ] || [ $n -gt 100 ]

        https://www.geeksforgeeks.org/shell-scripting-test-command/

    top
        -"provides a realtime status of running processes."
        -"Windows task manager"

    touch [FROM]
        - "CREATE FILE      /       GIVE A NEW TIMESTAMP TO THE FILE"

        - touch f1 f2 f3 f4
        - touch f{1..4}

    tr [FROM_THIS] [TO_THIS] < [INPUT_FROM]
        - "TRANSLATE THIS INTO THIS FROM INPUT FILE"

        - "e.g."            - tr ["a-z"] ["A-Z"] < myText.txt
        - "e.g."            - tr [a-z] [A-Z] < myText.txt
        - "e.g."            - tr "a-z" "A-Z" < myText.txt

    tree [FROM]
        - "Like ls -R"
        - "But with a different look"

        - "Works with some ls flags"

    uname [OPTIONS]

        - "UNIX Name"

        Function                                    |   Shortcut
        --------------------------------------------|-------------
        Kernel Name 	                            |   -s
        Kernel Release 	                            |   -r
        Kernel Version* 	                        |   -v
        Network Node Name (Hostname) 	            |   -n
        Machine architecture 	                    |   -m
        Processor architecture 	                    |   -p
        Hardware Platform (OS architecture) 	    |   -i
        Operating System 	                        |   -o

    uniq [FROM]
        - "Displays identical consecutive lines only once"

    wc [FROM]
        - "Show num of lines, num of words, num of chars"

        - l                 - "Show number of lines"
        - w                 - "Show number of words"
        - c                 - "Show number of chars"

    which [COMMAND]
        "check if the name is recognized as a Unix/Linux command."

        "You can use the which command to determine the full pathname of the shell."
        
        which ls
        which bash

    w
        - "Same as who, but with more information"

    who
        -"USER LOGGED IN THE CURRENT NODE"

    whoami
        -"CURRENT USER'S USERNAME"

    who am i

        "Same as whoami, but with more information"

    ![#]          
        - "re executes command by command number (obtained from history command)"

    ![abc]
        - "re-executes last command beginning with string "abc"

    [COMMAND] &
        - "run in the background"
        - "add after the command"
        - [cmd] [&]

        sleep 500 & sleep 600 & sleep 700 &

# <<< PERMISSION >>> #

    # <<< WHY >>> #

        Since Unix / Linux operating file systems allow for multiple user accounts,
        It is essential to have a system to share or limit access to directories and
        files contained within the file system.

    # <<< THEORY >>> #

        "Symbolic Method:           [rwx]"
        "Octal (Absolute) Method:   [777]"

        [-]         - "file"
        [d]         - "directory"
        [b, c]      - "device file"

        [--- --- ---]       - "(Stakeholders)"
        1           - "user"
        2           - "group"
        3           - "others"

        [rwx]

        "file"
                [r] - "Read permission"         - "(read file's contents)"
                [w] - "Write permission"        - "(edit file's contents)"      "!! REQUIRES R PERMISSION !!"
                [x] - "Execute permission"      - "(run file)"                  "!! REQUIRES R PERMISSION !!"


                "!! [w] touch ... > works without [r] permission !!"
                "!! [w] vi and nano requires [r] permission to write !!"

        "Dir"
                [r] - "Read permission, list files in the directory"        "!! REQUIRES X PERMISSION !!"
                [w] - "Write permission, create/delete files inside dir "   "!! REQUIRES X PERMISSION !!"
                [x] - "Access permission, access files in the directory"    "!! ONLY cd WORKS !!"


                "!! [r] allows user to see the name of all files and dirs inside directory !!"
                "!! [r] only hides filenames, user can still read files contents !!"

                "!! [w] allows user to create or delete new files and dirs inside directory !!"
                "!! [w] files contents can still be modified without [w] permission !!"

        "chmod never changes the permissions of symbolic links."

    chmod [PERM] [FROM]

        - R                         - "recursively subdirectory and directory"

        - [u=rwx,go=rw]             - "SET PERMISSION TO"
        - [u+rwx,go-rw]             - "ADD / REMOVE PERMISSION"
        - [ugo=]                    - "REMOVE ALL"

        - chmod +rwx [FROM]         - "ADD / REMOVE PERMISSION TO ALL STAKEHOLDERS"

        - [733]                     - "SET PERMISSION TO"
                                    - "(4 = r, 2 = w, 1 = x)"
                                    - "(First num = user, Second num = group, Third num = others)"

    chmod ??? ~         - "Passthrough permission"      - "??? Can be any number (711)"

    umask {MASK}
        {}      - "display current mask"
                - "default is 022"
                -
        file    - (Intended = 666)	    (rw-rw-rw-)
				- (umask    = 022)	    (----w--w-)
				- (default  = 644)	    (rw-r--r--)
                -
        dir     - (Intended = 777)	    (rwxrwxrwx)
				- (umask    = 022)	    (----w--w-)
				- (default  = 755)	    (rwxr-xr-x)

        {MASK}  - "Apply mask, files created now have different perm"      "!! RESET AFTER LOGOUT !!"
        

        0: No permissions are removed.
        1: The execute bit is unset in the permissions.
        2: The write bit is unset in the permissions.
        4: The read bit is unset in the permissions.

        "!!!! Note: The files cannot be given execution permissions by default as it can
        cause a security concern, and Linux systems are pretty much known for their amazing
        security, so that wouldn’t be good. !!!!"

        umask 000 == (rw-rw-rw-) (666) (FILE)       (666 - 000 == 666)
        umask 000 == (rwxrwxrwx) (777) (DIR)        (777 - 000 == 777)


        "!!! EXECUTE PERMISSIONS ARE AUTOMATICALLY PROMOTED IN FILES !!!"
        umask 055 == (rw--w--w-) (622) (FILE)       (666 - 055 == 611 -> 622)
        umask 033 == (rw-r--r--) (644) (FILE)       (666 - 033 == 633 -> 644)
        umask 011 == (rw-rw-rw-) (666) (FILE)       (666 - 011 == 655 -> 666)
        umask 000 == (rw-rw-rw-) (666) (FILE)       (666 - 000 == 666 -> 666)



        Example: umask 543

        Making a directory:

        When we make a new directory, the permissions will be calculated as
        (full permissions for directory) – (umask value) i.e. 777 – 543 = 234

        234, can be clarified more as:
            2 for the owner, that is 010 in binary, so write permissions for the owner.
            3 for the group members, that is 011 in binary, so write and execute permissions for the group members.
            4 for everyone else, that is 100 in binary, so only read permission for everyone else.

        Making a file:

        When we make a new directory, the permission will be given out similarly but with a slight
        change as follows: (full permissions for file) – (umask value) i.e. 666-543 = 123
        
        Linux does not provide execute permissions by default, even if it is specified in the umask. 
        123 can be clarified more as:
            1 for the owner, that is 001 in binary, so execute permission should be given to the owner,
                but Linux doesn’t give execute permissionMaking a directory:s by default, so, the value is 
                promoted by one and we get 010, and write permission will be granted to the owner.
            2 for the group members, that is 010 in binary, so write permissions for the group members.
            3 for everyone else, that is 011 in binary, so write and execute permission for everyone else,
                but again execute permission cannot be provided, so the value will be promoted one more time,
                and we will get 100, so read permission will be granted to everyone else.

    # <<< CHANGE OWNER >>> #

        chown [OPTIONS] USER[:GROUP] FILE(s)

        "Superuser permissions are necessary to execute the chown command."

    # <<< SUPERUSER >>> #

        "Standard users can use root's privileges if they are empowered to do so with:"

        su ...
        sudo ...

        "!! Caution is advised when using superuser privileges since allows modification of the whole system !!"

# <<< REMOTE CONNECTION >>> #

	# <<< DOS COMMANDS >>> #
		- cls
			- clear terminal

		- dir
			- list folders

		- mkdir [...FolderName...]
			- create folder

		- cd
			- Change directory

		- copy con [...FileName...]
			- Copy/Create a file with text.
			- Exit with ^Z + enter

    # <<< SCP >>> #

        "Secure Copy"

        "!!! REMEMBER : !!!"

        scp local.file username@host:destination-pathname       - "copy to remote from local"
        scp local.file username@host:                           - "copy to remote from local (SAME NAME)"
        scp user@host:file-pathname local-pathname              - "copy to local from remote"

        scp -r local.file username@host:destination-pathname    - "COPY DIRECTORY"

    # <<< SFTP >>> #

        "Secure File Transmission Control Protocol"

        sftp user@host

        "!! USE ! TO ESCAPE TO WINDOWS SHELL !!"

        lls                     - "Local list"
        ls                      - "Remote list"

        lpwd                    - "Local"
        pwd                     - "Remote"

        lmkdir                  - "Local"
        mkdir                   - "Remote"

        lcd                     - "Local"
        cd                      - "Remote"

        put localFileName       - "Upload file to remote"
        put localFileName remoteFileName

        get remoteFileName      - "Download file from to local"
        get remoteFileName localFileName

        quit / bye / exit       - "EXIT"

    # <<< SSH >>> #

        "ACCESS REMOTE PC FORM A LOCAL ONE"

        ssh user@host [cmd]

# <<< TERMINAL SHORTCUTS >>> #

    # <<< SHORTCUTS WHEN READING TEXT >>> #

        ENTER           - "DOWN ONE LINE"
        SPACE           - "DOWN ONE PAGE"
        CTRL + B        - "UP ONE PAGE"
        /pattern        - "SEARCH FOR PATTERN"
                            - "e.g."  [/name]
                            - "Will match all "name" in the text"
        Q               - "QUIT / EXIT READING"

    ctrl + d    - "LOGOUT"

    ctrl + l    - "Clear terminal"
    ctrl + u    - "Clear line before cursor"

    up arrow    - "Command history"
    down arrow  - "Command history"

    ctrl + w    - "Deletes previous word"
    ctrl + a    - "Move cursor to the beginning of the line"
    ctrl + e    - "Move cursor to the end of the line"
    alt + f     - "Forward one word"
    alt + b     - "Back one word"

    ctrl + h            - "Backspace"
    ctrl + Backspace    - "Backspace"

    ctrl + c    - "Terminates a process running in the foreground"
    ctrl + z    - "Sends a process running in the foreground into the background. Process is stopped (suspended) in background and requires bg command to run in background."

# <<< ENVIRONMENT VARIABLES >>> #

    Variable    |       Name Purpose
    ------------|---------------------------------------------------------------
        PS1     |   Primary shell prompt
        PWD     |   Absolute path of present working directory
        HOME    |   Absolute path to user's home
        PATH    |   List of directories where commands / programs are located
        HOST    |   Host name of the computer
        USER    |   Name of the user logged in
        SHELL   |   Name (type) of current shell used

--- --- ---

# <<< VI COMMANDS >>> #

    vi [filename]

    i	                - Enter INPUT mode
    <esc>	            - Return to COMMAND MODE

    x	                - Delete text to the right

    W	                - Move forward one word
    B	                - Move back one word

    dd	                - Cut line (Also used for DELETE)
    yy	                - Copy Line
    p / P	            - Paste Cut/Copied Text below/above line

    u	                - Undo previous editing command

    # <<< MOVEMENTS >>> #

        h       - left
        j       - down
        k       - up
        l       - right

        <shift><$>  - move cursor to the end of the line
        <shift><^>  - move cursor to the beginning of the line

    :help	            - Display help screen

    :x	                - Save editing changes and exit
    :w name	            - Save editing changes to "name"
    :q	                - Exit without saving changes
    :q!	                - Abort editing session (UNSAVED changes)

    :%s/this/that/g     - replace

# <<< NANO COMMANDS >>> #

    nano [filename]

    <ctrl><SPACEBAR>,       - Move forward one word
    <esc><SPACEBAR>	        - Move backward one word

    <ctrl><a>,              - Move to beginning of line
    <ctrl><e>	            - Move to end of line

    <ctrl><k>	            - Cut line
    <esc>6	                - Copy Line
    <ctrl><u>	            - Paste Cut/Copied Text

    <ctrl><g>	            - Display help screen (ctrl-x to exit help screen)

    <ctrl><x>	            - Save editing changes and exit
    <ctrl><o>	            - Save editing changes


    <ctrl><f>               - move one character forward in a line.
    <ctrl><b>               - move one character backwards in a line.

--- --- ---

# <<< REGEX >>> #

    "REGEX"
    /REGEX
    /REGEX/

    A regular expression is a combination of two types of characters: literals and special characters.

    # <<< THEORY >>> #

        FILENAME EXPANSION vs REGEX

        Filename Expansion are used for command file management and file manipulation commands.

        # <<< FILENAME EXPANSION COMMANDS INCLUDING >>> #
        
            ls, rm, mv, cp, cat, less, more, head,
            tail, sort, uniq, grep, tr, cut, wc

        REGEX expressions are used to search, edit and manipulate text.
        This can represent text contained in a file or within a pipeline command.
        Works as a filter in pipelines.

        Patterns are used by string searching algorithms for "find" or "find and replace" operations on strings,
        or for input validation.

        # <<< REGULAR EXPRESSION COMMANDS INCLUDING >>> #

                grep , egrep, man, more, less, vi, sed, awk

    # <<< SIMPLE (LITERAL) REGULAR EXPRESSION >>> #

        "The simplest regular expression is a series of letters and numbers, (tabs or spaces).
        A simple (literal) regular expression consists of normal characters, which used to match patterns."


        "..."                       - "Just a string"

        "The problem with using simple (literal) regular expressions
        is that only simple or general patterns are matched."

    # <<< COMPLEX REGULAR EXPRESSION >>> #

        "Complex Regular Expressions use symbols to help match text for more precise (complex) patterns."

        .       - Any Character Except New Line         !! IF INSIDE [] IT IS JUST A CHAR !!
                                                        grep "[.]"
                                                        grep "\."
                                                        Have the same output

        ^       - Beginning of a String                 !! IF OUTSIDE [] !!
        $       - End of a String

        []      - Matches Characters in brackets
        [^ ]    - Matches Characters NOT in brackets

        *       - 0 or More                             !! MULTIPLY PREVIOUS CHARACTER !!
                                                        grep ".*"           - any character, 0 or more
                                                        grep "i*"           - 0 or more 'i'
                                                        grep "ii*"          - 1 or more 'i'

        # <<< EXAMPLES >>> #

            grep "^beginning" a.txt
            grep "end$" a.txt
            grep "^[^a-z].*[a-z]$" a.txt

            grep '^$' a.txt                             "Match only blank lines"

    # <<< EXTENDED REGULAR EXPRESSION >>> #

        "Extended Regular Expressions consist of additional special characters to "extend"
        the capability of regular expressions."

        \       - Scape special characters

        |       - Either/Or
        ( )     - Group

        +       - 1 or More                                     !! APPLY TO PREVIOUS CHAR !!
        ?       - 0 or One                                      !! APPLY TO PREVIOUS CHAR !!
        {3}     - Exact Number                                  !! APPLY TO PREVIOUS CHAR !!
        {3,4}   - Range of Numbers (Minimum, Maximum)           !! APPLY TO PREVIOUS CHAR !!
        {3,}    - 3 or more                                     !! APPLY TO PREVIOUS CHAR !!

        # <<< EXAMPLES >>> #

            egrep "^[0 9]{1,}$" a.txt
            egrep "^[+-]{0,1}[0-9]{0,1}{1,}$" a.txt
            egrep "^[0-9]{1,}[.]{0,1}[0-9]{0,}$" a.txt

            egrep "(the ){2,}" a.txt
                       /\
                       ||     !! REMEMBER SPACE !!

            egrep "(this |that ){1,}" a.txt
            egrep "(a|b|c){3,}" a.txt

        # <<< BONUS >>> #

            \d      - Digit (0-9)
            \D      - Not a Digit (0-9)
            \w      - Word Character (a-z, A-Z, 0-9, _)
            \W      - Not a Word Character
            \s      - Whitespace (space, tab, newline)
            \S      - Not Whitespace (space, tab, newline)

            \b      - Word Boundary
            \B      - Not a Word Boundary

            ?!      - Look ahead

            [a-zA-Z0-9_.+-]+@[a-zA-Z0-9-]+\.[a-zA-Z0-9-.]+

--- --- ---

# <<< SHELL SCRIPTS >>> #

    nano filename.bash
    chmod u+x filename.bash
    filename.bash

    # This is a comment
        - "SHELL ignores this line"

    #!/bin/bash
        - "SHEBANG LINE is a special comment at top of your shell script"
        - "Forces the shell script to run in a specific shell, which"
        - "could prevent errors in case an older shell does not recognize"
        - "newer features from recent shells"
        - "!!! IT MUST APPEAR IN THE FIRST LINE !!!"
        - "!!! OTHERWISE IT IS TREATED AS A REGULAR COMMENT !!!"

        - "You can use the which command to determine the full pathname of the shell."

    # <<< CONTROL FLOW // THEORY >>>> #

        So far, we have created Bash Shell Scripts that execute Linux commands
        in a fixed sequence.

        Although those type of scripts can be useful, we can use control flow
        statements that will control the sequence of the running script
        based on various situations or conditions.

        Control Flow Statements are used to make your shell scripts more
        flexible and allow them to adapt to changing situations.

        A logic statement is used to determine which Linux commands to be
        executed based on the result of a test condition or command

    # <<< CONTROL FLOW // IF >>> #
    
        # <<< $? >>> #

            The special parameter $? is used to determine the exit status of the
            previously issued Linux command or Linux pipeline command.

            !!!!!
            The exit status will either display a zero (representing TRUE)
            or a non-zero number (representing FALSE).
            !!!!!

        # <<< IF >>> #

            if test ...
            then
                ...
            fi


            --- OR ---


            if [ ... ]
            then
                ...
            fi

        # <<< IF ELSE >>> #

            if test ...
            then
                ...
            else
                ...
            fi


            --- OR ---


            if [ ... ]
            then
                ...
            else
                ...
            fi

        # <<< IF ELIF ELSE >>> #

            if test ...
            then
                ...
            elif test ...
            then
                ...
            else
                ...
            fi


            --- OR ---


            if [ ... ]
            then
                ...
            elif [ ... ]
            then
                ...
            else
                ...
            fi

    # <<< CONTROL FLOW // FOR >>> #

        "variable i stores each value"

        for i                       # iterates over positional parameters
        do
        command(s)
        done

        for i in ...                # iterates over a given list E.G. ($*)
        do
        command(s)
        done

        for i in ... ... ... ...    # iterates over a manually defined list
        do
        command(s)
        done

        for i in $(command)         # iterates over the commands output
        do
        command(s)
        done

    # <<< CONTROL FLOW // WHILE >>> #

        while [ ... ]
        do
            ...
        done

    # <<< ENVIRONMENT/USER VARIABLES >>> #

        variables are classified into two groups:

        # <<< SYSTEM (SHELL) VARIABLES >>> #

            Describes the OS system’s working environment which can be used in a shell script.

            set | more

            Variable    |       Name Purpose
            ------------|---------------------------------------------------------------
                PS1     |   Primary shell prompt
                PWD     |   Absolute path of present working directory
                HOME    |   Absolute path to user's home
                PATH    |   List of directories where commands / programs are located
                HOST    |   Host name of the computer
                USER    |   Name of the user logged in
                SHELL   |   Name (type) of current shell used


            Placing a dollar sign $ before a variable name will
            cause the variable to expand to the value
            contained in the variable.

            Examples:
                - echo “My current location is: $PWD”
                - who | grep $USER
                - echo $HOST

        # <<< USER-CREATED VARIABLES >>> #
        
            Customized variables created by the programmer for use in a shell script.
            The name of a variable can be any sequence of letters and numbers,
            but it must NOT begin with a number!


            User-defined variables are variables which can be created by the user
                - exist in the current session
                - can be used for customized purposes


            Data can be stored and removed within a variable using an equal sign 
            !!!!! no spaces on either side of equal sign !!!!!
            !!!!! this also works in the terminal (outside script) !!!!!

            # <<< CREATE >>> #

                varName=value           - "Definition / Declaration"
                $varName                - "Accessing the value / variable"

                name="Pablo Nicola"
                echo $name

            # <<< DELETE >>> #

                There are a few methods to remove a variable’s value:

                variableName=
                unset variableName

                name=
                unset name

    # <<< POSITIONAL PARAMETERS >>> #

        A positional parameter is a variable within a shell program;
        its value is set from an argument specified on the command line
        that invokes the program or by the set command within the script.

        myScript.bash arg1 arg2 arg3 arg4 ...
        {
            set arg1 arg2 arg3 arg4 ...
        }

        Positional parameters are numbered and are referred to with a preceding
        "$": $1, $2, $3, ... ${10}, ${11}, ... and so on.


        " !! $0 refers to either the name of shell where command was issued,"
        " or name of shell script file being executed. !!"

        echo "$0"       - "output: myScript.bash"


        # <<< BONUS >>> #

            set 22 33 44 55 66 77 88 99 11

            echo $10        - "Output: 220"
                            - "$1 == 22 + string literal 0"

            echo {15}       - "Output: "
                            - "Over bound index returns nothing"

    # <<< SPECIAL PARAMETERS >>> #

        Parameter   | Purpose
        ------------|---------------------------------------------------------------------------
        $*          | Display all positional parameters.
        “$*”        | Containing values of all arguments separated by a single space
        “$@”        | Multiple double-quoted strings, each containing the value of one argument
        $#          | Represents the number of parameters (not including the script name)
        $?          | Exit Status of previous command (discussed in next lesson)


        $*      == arg1 arg2 arg3 arg4 ...
        "$*"    == "arg1 arg2 arg3 arg4 ..."            - "!! Iterates only once in for loops !!"
        "$@"    == ""arg1"arg2"arg3"arg4"...""          - "!! Works normally in for loops !!"
 
    # <<< COMMAND SUBSTITUTION >>> #

        Command substitution is a facility that allows a command to be run
        and its output to be pasted back on the command line as arguments
        to another command.

        Usage:
            command1 $(command2) or command1 `command2`

        Examples:
            file $(ls)

            mail –s “message” $(cat email-list.txt) < message.txt

            echo "The current directory is $(pwd)"
            echo "The current hostname is $(hostname)"
            echo "The date is: $(date +'%A %B %d, %Y')"

            for i in `ls`
            ...

            for i in $(ls)
            ...

    # <<< MATH OPERATIONS >>> #

        As opposed to other programming languages,
        in shell scripting, all characters (including numbers) are stored as text.

        math construct (( )) convert numbers stored as text into binary numbers.

        OUTPUT EX:
            echo "$((num1-num2))"

        EXECUTION EX:
            ((result=num1+num2))
            ((result=$num1+$num2))


            ((i++))

            ((i=$i+1))
            ((i=i+1))
            
            i=$((i+1))
            i=$(($i+1))

        Operator    | Description
        ------------|---------------------------
        +           | Addition
        -           | Subtraction
        *           | Multiplication
        /           | Division
        %           | Remainder
        **          | Exponentiation
        ++          | Increment (increase by 1)
        --          | Decrement (decrease by 1)

    # <<< RUNNING SHELL SCRIPTS WITHIN SHELL SCRIPTS >>> #

        "If you want the value variables to transfer to “inside” the shell script,"
        "you would need to use the export command prior to executing the inside shell script."

        myScript.bash
        {
            var1=10
            export var1

            ./myScript2.bash
        }

    # <<< LINUX COMMANDS >>> #

        just write the command in the file

        echo [...]

            -n              - "display text without the newline character"


            echo  ...               - "!! Works with only one word !!"
            echo '...'              - "!! Escape all special chars !!"
            echo "..."              - "!! Escape some special chars !!"
                                    - "Recommended to use double-quotes"

        set [...] [...] [...] ...

            set [...] [...] [...]       - "manually set the value of call parameters"
                                        - "access parameters: $1 ... $9 ..."
                                        - "access parameters: ${10} ... ${99...} ..."

        read [VarName]

            "Like scanf. Prompts user, waits for input,"
            "then stores the data into a variable after ENTER" 


            -p              - "prompts the user for data without requiring the echo command"


            echo -n "Enter your age: "
            read age

            read -p "Enter your name: " name

            "!!! read automatically creates the variable !!!"

        readonly [VarName]

            "prevents the user from changing the value of the variable"
            "while the shell script is running"
            "or during the duration of your shell session"

            readonly name           - "like const"

        shift [NUMBER]

            "move positional parameters to the left by [NUMBER] positions."

            myScript arg1 arg2 arg3 ...
            {
                echo $1         # == arg1
                shift 1
                echo $1         # == arg2
            }

        test [LOGIC EXPRESSION]

            "check core definition"

        exit [NUMBER]

            "The exit statement is used to terminate a shell script."

            "This statement is very useful when combined with logic in a shell script."
            "The exit command can contain an argument to provide the exit status"
            "of your shell script."

            if [ ... ]
            then
                exit ...
            fi

        break
        
            "The break statement is used to terminate a loop"
            "Although the loop terminates, the shell script will continue running."

            while [ ... ]
            do
                ...
                if [ ... ]
                then
                    break
                fi
                ...
            done










# <<< GENERAL CONCEPTS >>> #

    # <<< OS >>> #

        The OS is responsible for:
		MANAGE RESOURCES, providing programs what they need to run.
		Providing INTERFACE, allowing the OS to communicate with the user.

    # <<< INTERFACES >>> #

        Allow the user to communicate with the OS

        Shell interprets your command and passes the instructions to the OS,
        which communicates with the hardware and returns the output to the user.

        Graphical User Interface            - "REQUIRES MORE BANDWIDTH"
        Menu Driven Interface
        Command Line Interface              - "UNIX/LINUX = SHELL / BASH SHELL"

    # <<< LINUX/UNIX >>> #

        Portable because it is written in C             - It can run on others types of computers

        Allows multi-users
		Allows multi-tasking
		Allows multi-processing
		Ease to share files between users 
		Ease to use internet-related utilities

        GNU General Public License (GPL)

        # <<< KERNEL >>> #

            HARDWARE <-> KERNEL <-> USER SPACE(OS)

            Kernels communicate with the hardware 
            Software interacts with the kernel 

    # <<< MATRIX >>> #

        Matrix is a cluster of virtual computers
        It is a cost effective alternative to servers

        Cluster = several Computers connected together

        # <<< LOGIN >>> #

            Seneca requires VPN and MFA

            Open terminal
            ssh to the matrix using username
            password

            SSH Secure Shell Client
            Quick connect
            password

        # <<< SENECA SERVERS >>> #

            my.senecacollege.ca	        - Learning Content Management System (Link to Resources / Student Grades / Online Quizzes)
            ict.senecacollege.ca	    - Online access to slides, documents via webpage links
            wiki.cdot.senecacollege.ca	- Student Notes / Tutorials (weekly, review) / Practice Questions / Resources
            matrix.senecacollege.ca	    - Linux Account for "hands-on Practice"

    # <<< DIRECTORIES / FILE SYSTEM >>> #

        To organize files, they should be stored in directories.
        To organize directories, they should become sub-directories inside a parent directory.

        The Unix/Linux file system is hierarchical.
        All paths start at the root directory.

        A pathname is used to specify a route to a file within the file system.
        The delimiting character is most commonly the slash ("/").

        # <<< EXAMPLES >>> #

            /	                - Root directory (ancestor to all directories)
            /home	            - Used to store users’ home directories
            /home/username	    - A specific User's Home Directory
            /bin	            - Common system binaries (commands)
            /usr/bin	        - Common utilities (commands) for users.
            /usr/sbin	        - Common utilities for system administration
            /etc	            - System administration files (eg. passwd)
            /var	            - Dynamic files (log and mail files)
            /tmp , /var/tmp	    - Temporary files for programs
            /dev	            - Device driver files (terminals, printers, etc.)

        # <<< HIDDEN FILES >>> #

            Hidden files start with .
            Uses:
                        - To clean up directories
                        - To hide backups
                        - to protect important files

        # <<< NAMING RULES >>> #

            - case sensitive            - be consistent with the case
            - adopt a consistent directory naming scheme
            - meaningful names
            - avoid non-alphanumeric characters
            - avoid using spaces        - (consider periods, hyphens, and underscores instead)

    # <<< DATA REPRESENTATION >>> #

        Digital computers are electronic devices that contain a series of circuits and
        voltage levels that can store / represent data.

    # <<< BASE CONVERSIONS >>> #

        # <<< DECIMAL >>> #
			0 - 9

			To binary:
				11 to binary = 1011
				2 | 11 | 1
				2 |  5  | 1
				2 |  2  | 0
				       1
				       /\ MSB (most significant bit)

			To Hex:
				47 to hex = 2F
				16 | 47 | F
				          2
				         /\ MSB (most significant bit)

			To Octal:
				40 to octal = 50
				8 | 40 | 0
				        5

		# <<< BINARY >>> #
			0 - 1

			Representation:
				...number...B
				(...number...)₂

			To decimal:
				0 * 128 + ... + 0 * 1 = decimal
				2^7  ...  2^0             = decimal

			To Hex:
				0010 1111 1111 = 2FF
				2	F	F
				0010	1111	1111

			To Octal:
				010 001 010 = 212
				2	1	2
				010	001	010

			Terminology:
				MSB (most significant bit)
				LSB (less significant bit)
				           \/ MSB    \/ LSB
					00101110B

		# <<< HEXADECIMAL >>> #
			0 - 9 - a - f

			Representation:
				...number...H
				(...number...)₁₆

			To decimal:
				0 * 256 + ... + 0 * 1 = decimal
				16^2 ... 16^0           = decimal

			To binary:
				2FF = 0010 1111 1111
				2	F	F
				0010	1111	1111

		# <<< OCTAL >>> #
			0 - 7

			Representation:
				...number...O
				(...number...)₈

			To decimal:
				0 * 64 + ... + 0 * 1 = decimal
				8 ^ 2 ... 8 ^ 0         = decimal

			To binary:
				212 = 010 001 010
				2	1	2
				010	001	010

    # <<< LINKING FILES >>> #

        Each file is unique in the file system (size, timestamp, content, name, ... METADATA).

        Each file has its own unique i-node number in the file system.
        The i-node is an index (data structure) that provides information about the file.

        cp          - Separated Backup
        ln          - Synchronized Backup
        ln -s       - Pathname shortcut

        # <<< HARD LINK >>> #
        
            A Hard link is a reference to the same index on a file system.
            Advantages:
                - Hard links remains even if the original file has been removed.
                - Any changes will be reflected in both original hard-linked files.
                - Useful for backups.

            Disadvantages:
                - Take-up more space.
                - Cannot hard link directories.
                - Cannot hard ling files from different Unix/Linux serves.

        # <<< SYMBOLIC LINK >>> #

            A Symbolic Link is an indirect pointer to a file and are also known as
            a soft link or symlink.
            The symbolic link file contains the pathname to the original file.

            Advantages:
                - Shortcut to other files.
                - Can link files and directories.
                - Can create links on different Unix/Linux servers.

            disadvantages:
                - Not good for backup purposes.
                - Can point to a nonexistent file ("Broken link")
                - !!! DOES NOT UPDATE REFERENCE AUTOMATICALLY (PATHNAME SHORTCUT) !!!

    # <<< MANAGING PROCESSES >>> # 

        All programs(tasks) that are running on a Unix/Linux computer system
        are referred to as processes.

        # <<< CHARACTERISTICS >>> #

            - Each process has an owner
            - Each process has a unique ID (PID)
            - Processes keep their PID for their entire life.
            - Usually a parent sleeps (i.e. suspended) when a child is running
            (the exception is when the child process is running in the background)

            - UNIX / Linux processes are hierarchical.The process structure can have
            children processes, great grandchild processes, etc.

        Processes in UNIX can run in the foreground or background.
        Commands issued from the shell normally run in the foreground.
        Programs / Commands can be run in the background by placing an ampersand & after the command.

        For example: command &

        # <<< MANAGING FOREGROUND >>> #
        
            Processes that run in the terminal are known as foreground processes

            ctrl + c    - "Terminates a process running in the foreground"
            ctrl + z    - "Sends a process running in the foreground into the background.
                        Process is stopped (suspended) in background and requires bg command
                        to run in background."

        # <<< MANAGING BACKGROUND >>> #

            Processes that do not run in the terminal are known as background processes

            fg      - (foreground) command moves a background job into the foreground.
            bg      - resumes suspended jobs from the current environment.
            jobs    - utility displays the status of jobs that were started in the current shell environment.

    # <<< GREP SED AWK >>> #

        regex search            - grep
        on the fly editor       - sed
        database search         - awk

    # <<< SHELL SCRIPTS >>> #

        https://en.wikipedia.org/wiki/Shell_script

        A shell script is a computer program designed to be run by the Unix shell. (command-line interpreter)
        Typical operations include:
            - file manipulation
            - program execution
            - printing text

        Shell scripts allow us to automate the execution of commonly issued:
            - Linux commands
            - shell operations
            - math calculations
            - logic/loop operations

        # <<< CREATING >>> #

            First, plan the steps you want to accomplish. (list the commands required)
            Second, create the shell script via a text editor based on the plan you created.

            Third, avoid using filenames of already existing Linux Commands to avoid confusion,
            run "which [...]" command to check if the name is recognized as a Unix/Linux command.

            Adding an extension to the shell script filename
            helps identifying the type of shell that it was designed to run.

                - clean-directory.bash
                - copy-directory-structure.csh

        # <<< RUNNING >>> #

            In order to run your shell script by name, you need
            to first assign execute permissions for the user.

            chmod u+x myscript.bash

            To run your shell script, you can issue the shell
            script’s pathname using a relative, absolute, or relative-to-home pathname.
            Examples:
                - ./myscript.bash
                - /home/username/myscript.bash
                - ~/myscript.bash

            # <<< ADVANCED >>> #

                FYI: You can run a shell script without execute
                permissions by issuing the shell command followed by the shell script’s pathname.
                
                Example:
                    - bash ~pnicola/scripts/my.bash
                    - bash my.bash
                    - "!! remember BASH before filename !!"

                You can add the current directory that contains the shell
                script so it can be issued only by filename (not pathname).

                Example:
                    - PATH=$PATH:.
                    - "!!! ONLY LASTS DURING ONE SESSION !!!"

                To be persistent on new shell instances, setting the PATH
                environment variable would need to be added in your
                profile (start-up) file (discussed in a later lesson).

        # <<< VARIABLES >>> #

            Variables are used to store information to be referenced and
            manipulated in a computer program. They also provide a way of labeling
            data with a descriptive name, so our programs can be understood more
            clearly by the reader and ourselves.

            It is helpful to think of variables as containers that hold information.
            Their sole purpose is to label and store data in memory. This data can
            then be used throughout your program.

            Placing a dollar sign "$" prior to the variable name will cause
            the variable to expand to the value contained in the variable. 

            # <<< ENVIRONMENT VARIABLES >>> #

                You can issue (set | more) to view all variables.

        # <<< STARTUP FILES >>> #

            Shell configuration (start-up) files are scripts that are run when you log in, log
            out, or start a new shell. Start-up files can be used, for example, to set the prompt
            and screen display, create local variables, or create temporary Linux commands (aliases).
            
            The file pathname /etc/profile belongs to the root user and is the first start up file
            that executes when you log in, regardless of shell.
            
            The /etc/bashrc file is used for setting the default Bash shell environments for users.
            It is generally NOT used to generate output from commands.
            
            User specific config start up files are in the user's home directory:
            ~/.bash_profile runs when you log in
            ~/.bashrc runs when you start an interactive sub-shell.
            You can use ~/.bash_profile to issue commands that produce output (eg.date,echo“hello”)

        # <<< LOGOUT FILES >>> #

            There are files that reset or restore the environment or properly
            shut down running programs when the user logs out of their shell.
            
            User specific logout start up files are in the user's home directory:
            ~/.bash_logout
