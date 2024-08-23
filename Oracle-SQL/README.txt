-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- BASICS REVIEW -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --


    * means all columns
    '' for string values
    "" for objects (columns)

    ...
    FROM dual; -- dual is a workplace table in ORACLE SQL


-----------------------------------------------------------------------
----------------------------------------------------------------------- ORDER OF EXECUTION
-----------------------------------------------------------------------


    FROM (ON, USING, and JOIN)
    DISTINCT
    WHERE
    GROUP BY
    HAVING
    SELECT      -- ALIASES ARE DEFINED HERE
    ORDER BY    -- ALIASES ONLY WORK HERE
                -- USE 1, 2, 3, ..., n TO AVOID ALIASES
                -- 1 means first column in SELECT


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- TCL -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

-----------------------------------------------------------------------
----------------------------------------------------------------------- TRANSACTIONS
-----------------------------------------------------------------------


    -- disables or enables the default auto-commit mode for the current session.
    SET AUTOCOMMIT ON;
    SET AUTOCOMMIT OFF;

    -- starts a new transaction. 
    SET TRANSACTION READ WRITE;

    -- commits the current transaction, making its changes permanent.
    COMMIT;

    -- sets a pointer to a location that can be rolled back to.
    SAVEPOINT mySavepoint;

    -- rolls back the current transaction, canceling its changes.
    ROLLBACK TO mySavepoint;
    ROLLBACK;


    /*
        a. The user has established a new connection to the server and has a blank sheet ready to go, starts a new transaction
        b. The user uses the BEGIN statement in Oracle SQL, this will start a new transaction
        c. The user executes a COMMIT statement, the current transaction is committed, and a new transaction starts.
        d. The user executes ANY DDL statement.  This automatically triggers an auto-commit of the current transaction and starts a new transaction.
    */


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- DDL -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

-----------------------------------------------------------------------
----------------------------------------------------------------------- DATA TYPES
-----------------------------------------------------------------------


    p - precision, the total number of digits
    s - scale, number of digits right of the decimal place
    n - size, numeric value

    Fixed width strings                                 char(n)
    Variable width strings                              varchar(n)
    Variable width strings with UNICODE characters      nvarchar(n)
    Integers (up to 255)                                number(3)
    Integers (up to 32,000)                             shortinteger
    Integers (over 32,000 up to 2,000,000,000)          integer
    Decimals                                            number(p,s)
    Dates                                               Date
    Booleans                                            number(1)


-----------------------------------------------------------------------
----------------------------------------------------------------------- CONSTRAINTS
-----------------------------------------------------------------------

-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- THEORY


    CONSTRAINT NAME     KEYWORD         DESCRIPTION

    Required            NOT NULL        - Ensures that a column cannot have a NULL value
    Unique              UNIQUE          - Ensures that all values in a column are different
    Primary Key         PRIMARY KEY     - A combination of a NOT NULL, UNIQUE and INDEX. Uniquely identifies each row in a table
    Foreign Key         FOREIGN KEY     - Prevents actions that would destroy links between tables
    Check Range         CHECK           - Ensures that the values in a column satisfies a specific condition
    Default Value       DEFAULT         - Sets a default value for a column if no value is specified
    Index               CREATE INDEX    - Used to create and retrieve data from the database very quickly


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- COLUMN LEVEL


    ... NOT NULL
    ... UNIQUE
    ... PRIMARY KEY
    ... REFERENCES table_name(column)       - Needs to be first
    ... CHECK(conditions)
    ... DEFAULT(value)

    <colName> <INT GENERATED BY DEFAULT ON NULL AS IDENTITY PRIMARY KEY,>


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- TABLE LEVEL


    -- When adding constraint on table creation time remove `ADD`
    -- use `ADD` inside ALTER TABLE statement
    
    
    ADD CONSTRAINT required_ CHECK (column IS NOT NULL);
    ADD CONSTRAINT unique_ UNIQUE(column);
    ADD CONSTRAINT pk_ PRIMARY KEY(column1, ...);
    ADD CONSTRAINT fk_ FOREIGN KEY (thisColumn) REFERENCES table_name(thatColumn);
    ADD CONSTRAINT chk CHECK (conditions);
   
   
    MODIFY column DEFAULT value;            -- Works only in alter


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- INDEX


    CREATE UNIQUE INDEX index_name
    ON table_name (column1, column2, ...);
    
    
    DROP INDEX index_name;


-----------------------------------------------------------------------
----------------------------------------------------------------------- CREATE
-----------------------------------------------------------------------


    CREATE TABLE <tableName> (
        <fieldName_1> <datatype> <constraints>,
        <fieldName_2> <datatype> <constraints>,
    ....
        <fieldName_n> <datatype> <constraints>,
        CONSTRAINT <constraintName> <constraintType> <constraint parameters> 
    );


-----------------------------------------------------------------------
----------------------------------------------------------------------- CREATE AS
-----------------------------------------------------------------------


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- TABLE (copy from another table)


CREATE TABLE table_name AS
    SELECT column1, column2, ...
    FROM table_name
    WHERE condition; 


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- VIEW


-- Views are executed every time they are asked/needed. It is just a string storing the SQL SELECT


CREATE VIEW view_name AS
    SELECT column1, column2, ...
    FROM table_name
    WHERE condition; 


-----------------------------------------------------------------------
----------------------------------------------------------------------- CREATE OR REPLACE
-----------------------------------------------------------------------


-- UPDATES VIEW


CREATE OR REPLACE VIEW view_name AS
    SELECT column1, column2, ...
    FROM table_name
    WHERE condition; 


-----------------------------------------------------------------------
----------------------------------------------------------------------- ALTER
-----------------------------------------------------------------------


    ALTER TABLE table_name
    <action>


    -- ACTIONS:

        ADD column_name datatype;
        ADD column_name datatype <constraint>;  -- Attention when adding required fields to a non-empty table
                                                -- 1. Add without being required
                                                -- 2. Insert data
                                                -- 3. Alter table to be required field


        DROP COLUMN column_name;
        DROP CONSTRAINT constraint_name;


        RENAME COLUMN old_name TO new_name;
        RENAME CONSTRAINT old_name TO new_name;


        MODIFY column_name datatype;            -- change datatype
        MODIFY column_name DEFAULT NULL;        -- drop default constraint


-----------------------------------------------------------------------
----------------------------------------------------------------------- DROP
-----------------------------------------------------------------------

-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- STAND ALONE DROP


    DROP TABLE table_name;
    DROP VIEW view_name;
    DROP INDEX index_name;


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- IGNORE CONSTRAINTS


    DROP TABLE table_name CASCADE CONSTRAINTS;


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- ALTER TABLE OPTIONS


    DROP CONSTRAINT constraint_name;
    DROP COLUMN column_name;

    MODIFY column_name DEFAULT NULL;


-----------------------------------------------------------------------
----------------------------------------------------------------------- CREATE EXAMPLES
-----------------------------------------------------------------------

-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- Table and column level constraints


    CREATE TABLE L5_movies (
        mID         INT             PRIMARY KEY,
        title       VARCHAR(35)     NOT NULL,
        releaseYear INT             NOT NULL,
        director    INT             NOT NULL,
        score       DECIMAL(3,2),
        CONSTRAINT score_chk CHECK (score BETWEEN 0 AND 5)
    );


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- Only column level constraints


    CREATE TABLE L5_actors (
        aID         INT             PRIMARY KEY,
        firstName   VARCHAR(20)     NOT NULL,
        lastName    VARCHAR(30)     NOT NULL
    );


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- 2PK + 2FK Bridge table


    CREATE TABLE L5_castings (
        movieID     INT,
        actorID     INT,
        CONSTRAINT castings_pk PRIMARY KEY (movieID, actorID),
        CONSTRAINT castings_movies_fk FOREIGN KEY (movieID) REFERENCES L5_movies(mID),
        CONSTRAINT castings_actors_fk FOREIGN KEY (actorID) REFERENCES L5_actors(aID)
    );


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- NORMAL


    CREATE TABLE L5_directors (
        directorID  INT             PRIMARY KEY,
        firstName   VARCHAR(20)     NOT NULL,
        lastName    VARCHAR(30)     NOT NULL
    );


-----------------------------------------------------------------------
----------------------------------------------------------------------- COPY TABLE EXAMPLE
-----------------------------------------------------------------------


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- Empty copy


    CREATE TABLE employee2 AS
        SELECT *
        FROM employees
        WHERE 1 = 0;            -- can be any expression that results to false


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- FULL copy


    CREATE TABLE employee2 AS
        SELECT *
        FROM employees;


-----------------------------------------------------------------------
----------------------------------------------------------------------- ALTER EXAMPLE
-----------------------------------------------------------------------


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- Add FK


    ALTER TABLE L5_movies
        ADD CONSTRAINT movies_directors_fk FOREIGN KEY (director) REFERENCES L5_directors(directorID);


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- Add unique


    ALTER TABLE L5_movies
        ADD CONSTRAINT title_uniq UNIQUE(title);
        
        
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- Add column


    ALTER TABLE employee2
        ADD username VARCHAR(25);


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- Remove FK


    ALTER TABLE L5_movies
        DROP CONSTRAINT movies_directors_fk;


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- Remove unique


    ALTER TABLE L5_movies
        DROP CONSTRAINT title_uniq;


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- Remove column


    ALTER TABLE employee2
        DROP COLUMN username;


-----------------------------------------------------------------------
----------------------------------------------------------------------- DROP EXAMPLES
-----------------------------------------------------------------------


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- Drop tables


    -- !! order of deletion is important !! pay attention to constraints !!
    -- Drop the tables with no FKs constraints first

    DROP TABLE L5_castings;
    DROP TABLE L5_movies;
    DROP TABLE L5_actors;
    DROP TABLE L5_directors;
    DROP TABLE employee2;


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- Drop views


    DROP VIEW vwCustomerOrder;


-----------------------------------------------------------------------
----------------------------------------------------------------------- VIEWS EXAMPLES
-----------------------------------------------------------------------


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- Create OR (alter without dropping)


    CREATE OR REPLACE VIEW vwCustomerOrder AS
        SELECT customerNumber,
            orderNumber,
            orderDate,
            productName,
            quantityOrdered,
            priceEach
        FROM customers
            LEFT OUTER JOIN orders USING(customerNumber)
            LEFT OUTER JOIN orderDetails USING(orderNumber)
            LEFT OUTER JOIN products USING(productCode);


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- Permissions (DCL) -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --


    REVOKE ALL PRIVILEGES ON newEmployees FROM PUBLIC;

    GRANT SELECT ON newEmployees TO dbs211_232nee24;

    GRANT INSERT, UPDATE, DELETE ON newEmployees TO dbs211_232nee24;

    REVOKE ALL PRIVILEGES ON newEmployees FROM dbs211_232nee24;


    -- Data concurrency means that many users can access data at the same time.

    -- Data consistency means that each user sees a consistent view of the data,
    -- including visible changes made by the user's own transactions and transactions of other users.

    -- Use the GRANT statement to grant:
        -- System privileges to users and roles.
        -- Roles to users and roles
        -- Object privileges for a particular object to users, roles, and PUBLIC

    -- Use the REVOKE statement to:
        -- Revoke system privileges from users and roles
        -- Revoke roles from users and roles
        -- Revoke object privileges for a particular object from users and roles

    -- Both needs ADMIN OPTION privilege to use


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- DML -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --


-----------------------------------------------------------------------
----------------------------------------------------------------------- SELECT
-----------------------------------------------------------------------


    SELECT column1, column2, ...    -- STANDARD
    FROM table_name;


    SELECT DISTINCT *   -- Apply to everything and returns only unique rows
    FROM table_name;


    MIN(column)         -- Returns the smallest value of the selected column.
    MAX(column)         -- Returns the largest value of the selected column.
    COUNT(column)       -- Returns the number of rows that matches a specified criterion.
    AVG(column)         -- Returns the average value of a numeric column.
    SUM(column)         -- Returns the total sum of a numeric column.
    SQRT(column)
    MOD(dividend, divisor)

    CONCAT(column1, column2)
    SUBSTR(column1, start_index, num_of_chars_to_capture)
    LENGTH(column)

    TO_CHAR(column, 'Mon, dd yyyy)
    TO_DATE(column, 'mmddyy')
    EXTRACT(month from column) AS ...

    column_name (AS) alias_name     -- `AS` is optional


-----------------------------------------------------------------------
----------------------------------------------------------------------- FROM
-----------------------------------------------------------------------


    table_name (AS) alias_name;     -- `AS` is optional and should be avoided for columns
                                    -- since it does not work with joins
                                    -- The alias in tables works like an absolute path
                                    -- Give priority to the side you are keeping

                                    -- !! NO ALIAS when joining with USING(column) !!

-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- JOIN
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --


    -- RULE: because an inner join is used, it does not matter if this is t.teamID or p.teamID
    -- RULE: outer joins are different and careful consideration is required.

                                    
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- (INNER) JOIN

    
    table1 INNER JOIN table2
        ON table1.column_name = table2.column_name;


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- LEFT  (OUTER) JOIN
    
    
    table1 LEFT JOIN table2
        ON table1.column_name = table2.column_name
        -- INVERSE
        WHERE table2.column_name IS NULL;


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- RIGHT (OUTER) JOIN
    

    table1 RIGHT JOIN table2
        ON table1.column_name = table2.column_name;
        -- INVERSE
        WHERE table1.column_name IS NULL;


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- FULL  (OUTER) JOIN
    
    
    table1 FULL OUTER JOIN table2
        ON table1.column_name = table2.column_name
        -- INVERSE
        WHERE table1.column_name IS NULL
        OR table2.column_name IS NULL;


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- GOOD TO KNOW


    -- You can use other expressions to join tables besides ON x = y
    -- x != y
    -- y BETWEEN x.min AND x.max


-----------------------------------------------------------------------
----------------------------------------------------------------------- WHERE
-----------------------------------------------------------------------


    SELECT column1, column2, ...    -- Standard
    FROM table_name
    WHERE condition;
    

    condition1 AND condition2 AND condition3 ...;
    condition1 OR condition2 OR condition3 ...;
    NOT condition;
    
    NOT LIKE ...
    columnN LIKE pattern;           -- search for a specified pattern in a column.
        -- LIKE 'a__%'
        -- At least 3 chars long starting with 'a'
        
        -- -- -- -- -- -- -- WILD CARDS
            -- _        Represents a single character
            -- %        Represents zero or more characters
            -- []       Represents any single character within the brackets
            -- ^        Represents any character not in the brackets
            -- -        Represents any single character within the specified range
            -- /        Scape wild card


    IN (value1, value2, ...);       -- IN operator is a shorthand for multiple `OR` conditions.
    IN (SELECT STATEMENT); 


    column > ANY(value1, value2, ...);
    column >= ALL(value1, value2, ...);
    
    
    BETWEEN value1 AND value2;      -- BETWEEN is inclusive
    NOT BETWEEN value1 AND value2;


    column_name IS NULL;            -- = NULL does not work
    column_name IS NOT NULL;        -- != NULL does not work


    -- -- -- -- -- -- -- USEFUL

    TRIM()
    LOWER()                         -- ALWAYS LOWER STRINGS BEFORE ANY COMPARISON
    UPPER()
    TO_CHAR(column, 'Mon, dd yyyy)
    TO_DATE(column, 'mmddyy')


-----------------------------------------------------------------------
----------------------------------------------------------------------- ORDER BY
-----------------------------------------------------------------------


    ORDER BY
    column1, column2, ... ASC|DESC; -- Use column2 only if column1 matches


-----------------------------------------------------------------------
----------------------------------------------------------------------- INSERT INTO
-----------------------------------------------------------------------


    -- Add rows to a table


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- LONG FORM, single insert


    INSERT INTO <tableName> ( <fieldList comma separated> )
        VALUES ( <Value list comma separated> );


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- SHORT FORM, single insert


    INSERT INTO <tableName> ( <Value list comma separated> );


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- SHORT FORM, multiple inserts
    
    
    INSERT ALL
        INTO <tableName> VALUES ( <value list comma separated> )
        INTO <tableName> VALUES ( <value list comma separated> )
        INTO <tableName> VALUES ( <value list comma separated> )
        SELECT * FROM dual;


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- COPY FROM TABLE


    INSERT INTO <tableName> (<fieldList>) 
        SELECT <fieldList> 
        FROM <tableName>
        WHERE <condition>         -- optional
        ORDER BY <fieldList>;     -- optional


-----------------------------------------------------------------------
----------------------------------------------------------------------- UPDATE
-----------------------------------------------------------------------


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- Change already existing values (rows)


    UPDATE <tableName> 
        SET <column1> = <value1>,
            <column2> = <value2>,
            <column3> = <value3>
    WHERE <condition>;          -- optional


-----------------------------------------------------------------------
----------------------------------------------------------------------- DELETE
-----------------------------------------------------------------------


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- Delete already existing values (rows)


    DELETE FROM <tableName>
    WHERE <condition>               -- optional 


-----------------------------------------------------------------------
----------------------------------------------------------------------- RANGE | FETCH
-----------------------------------------------------------------------


    SELECT *
    FROM table_name
    ORDER BY column_name(s)         -- DESC and ASC matters
    OFFSET 10 ROWS                  -- Remove this line to get first 10 lines instead of (n > 10 AND 20 <= n)
    FETCH FIRST 10 ROWS ONLY;

    
    WHERE ROWNUM > 10 AND ROWNUM <= 20;     -- ALSO WORKS


------------------------------------------------------------------------
------------------------------------------------------------------------ SELECT EXAMPLES
------------------------------------------------------------------------


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- Selects all columns
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- Order first by lastName, if it matches, uses firstName to solve the tie


    SELECT *
    FROM customers
    ORDER BY contactLastName ASC,
        contactFirstName DESC;


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- Starts with `s` and contains `e`


    SELECT *
    FROM customers
    WHERE LOWER(contactFirstName) LIKE 's%e%';


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- Column and Table ALIAS
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- c. is like an absolute path to the column


    SELECT c.customerNumber,
        c.customerName,
        TRIM(c.contactLastName) || ', ' || TRIM(c.contactFirstName) AS lastAndFirstName,
        c.phone
    FROM customers c
    WHERE LOWER(TRIM(country)) = 'canada';


------------------------------------------------------------------------
------------------------------------------------------------------------ JOIN EXAMPLES
------------------------------------------------------------------------


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- ANSI 89


    SELECT employeeNumber, firstName, lastName, city, phone, postalCode
    FROM employees e,
        offices o
    WHERE e.officeCode = o.officeCode
        AND LOWER(country) = 'france';


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- ANSI 92


    SELECT employeeNumber, firstName, lastName, city, phone, postalCode
    FROM employees INNER JOIN offices USING(officeCode)
    WHERE LOWER(country) = 'france';


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- Multiple tables


    SELECT c.customerNumber,
        o.orderNumber,
        orderDate,
        productName,
        quantityOrdered,
        priceEach
    FROM products p
        INNER JOIN orderDetails od
            ON od.productCode = p.productCode
        INNER JOIN orders o
            ON o.orderNumber = od.orderNumber
        RIGHT OUTER JOIN customers c
            ON c.customerNumber = o.customerNumber;

-----------------------------------------------------------------------
----------------------------------------------------------------------- DELETE EXAMPLES
-----------------------------------------------------------------------


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- Delete specific ones


    DELETE FROM employees
    WHERE employeeNumber = 2323
        OR employeeNumber = 9876;


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- Delete whole table's data


    DELETE FROM employee2;


-----------------------------------------------------------------------
----------------------------------------------------------------------- UPDATE  EXAMPLES
-----------------------------------------------------------------------


    UPDATE employees
    SET jobTitle = 'Head Cashier'
    WHERE employeeNumber = 2323;


-----------------------------------------------------------------------
----------------------------------------------------------------------- INSERT  EXAMPLES
-----------------------------------------------------------------------


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- LONG form


    INSERT INTO employees 
        (employeeNumber, lastName, firstName, extension, email, officeCode, reportsTo, jobTitle)
        VALUES (2323, 'Nicola', 'Pablo', 'x1234', 'pnicola@myseneca.ca', 4, 1088, 'Cashier');


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- SHORT from + MULTIPLE


    INSERT ALL
        INTO employees VALUES (2323, 'Nicola', 'Pablo', 'x1234', 'pnicola@myseneca.ca', 4, 1088, 'Cashier')
        INTO employees VALUES (9876, 'Smith', 'John', 'x4444', 'john@smith.com', 4, 1088, 'Cashier')
        SELECT * FROM dual;


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- COPY from


    INSERT INTO employee2 (employeeNumber, lastName, firstName, extension, email, officeCode, reportsTo, jobTitle)
        SELECT * FROM employees;
        

-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- OTHERS -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --


-----------------------------------------------------------------------
----------------------------------------------------------------------- TABLE SCHEMA/INFO
-----------------------------------------------------------------------


    DESC customers; 
    -- OR --                 -- (name of the column, nullability and data type).
    DESCRIBE customers;


-----------------------------------------------------------------------
----------------------------------------------------------------------- STRING FUNCTIONS
-----------------------------------------------------------------------


    LOWER(column)
    UPPER(column)
    TRIM(column)
    CONCAT(column1, column2)
    SUBSTR(column1, start_index, num_of_chars_to_capture) -- -1 means the end
    LENGTH(column)


    TO_CHAR(column, 'Mon, dd yyyy')        -- date to char
    
    ||         -- Concatenate operator
    
    
    REPLACE(column, 'from', 'to')
    INSTR(column, 'str')            -- returns the numeric position of a named string
    LPAD(column, 10, '*')           -- pads the character value right justified
    RPAD(column, 10, '*')           -- pads the character value shown by the amount not filled by the field
    INITCAP(column)                 -- capitalize words


-----------------------------------------------------------------------
----------------------------------------------------------------------- MATH FUNCTIONS
-----------------------------------------------------------------------


    CEIL(column)
    FLOOR(column)
    ROUND(column, precision)
    TRUNC(column, precision)
    SQRT(col)
    MOD(dividend, divisor)


-----------------------------------------------------------------------
----------------------------------------------------------------------- NULL FUNCTIONS
-----------------------------------------------------------------------


    -- Group functions ignore NULLs
    -- USE NVL to make them consider NULLs e.g.(NVL(column, 0))


    NVL(column, new_value_if_column_is_null)
    NVL2(column, new_value_if_column_is_not_null, new_value_if_column_is_null)

    NULLIF(expr1, expr2)    -- null if both are equal, expr1 otherwise
    COALESCE(list)          -- returns first non-null


-----------------------------------------------------------------------
----------------------------------------------------------------------- DATE FUNCTIONS 
-----------------------------------------------------------------------


    TO_DATE(column, 'mmddyy')       -- string to date
    SYSDATE                         -- get today

    MONTHS_BETWEEN(date1, date2)
    ADD_MONTHS(column, n)           -- n = number of months
    NEXT_DAY(column, 'DAY')         -- adds until column's date falls in DAY of the week
    LAST_DAY(column)                -- last day of the month
    ROUND(column, 'date_format')    -- round date
    TRUNC(column, 'date_format')    -- truncate date
                                    -- date_format examples ('MONTH' / 'DD' / 'YEAR')

    (column + n)                    -- n = number of days to add
    (column + h/24)                 -- n = hours to add ??
    (date - date)                   -- days in between ??

    EXTRACT (month FROM column) AS alias;
    EXTRACT (day FROM colum) AS alias;
    EXTRACT (year FROM column) AS alias;

    DATEDIFF


-----------------------------------------------------------------------
----------------------------------------------------------------------- DATE FORMATS
-----------------------------------------------------------------------


    Numeric day     -- dd, DD           -- Starts `today`
    Weekly day      -- day, Day, DAY    -- Starts `beginning of the week (the last Sunday)`

    Numeric Month   -- mm, MM
    Written Month   -- mon, Mon, MON, month, Month, MONTH

    Numeric Year    -- yy, yyyy, YY, YYYY
    Written year    -- year, Year, YEAR


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- ADVANCED DATE


    fm              -- fm better format spaces/gaps inside date
    Ddspth          -- First / Second / Third / ... / Thirty-First
    ddth            -- 1st / 2nd / 3rd / 4th / .. 31st
    DY              -- Three letter abbreviation

    HH24:MI:SS AM   -- clock


    `TO_DATE('2020', 'yyyy') == 2020 + sysdate_month + sysdate_day` -- Example only


-----------------------------------------------------------------------
----------------------------------------------------------------------- DATE EXAMPLES
-----------------------------------------------------------------------

-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- Find first Tuesday after one year from date


    SELECT last_name,
        hire_date,
        TO_CHAR(
            NEXT_DAY(ADD_MONTHS(hire_date, 12), 'TUESDAY'),
            'fmDAY, Month "the" Ddspth "of year" YYYY'
        ) AS "REVIEW DAY"
    FROM employees
    WHERE hire_date >= TO_DATE('2019', 'yyyy')
    ORDER BY NEXT_DAY(ADD_MONTHS(hire_date, 12), 'TUESDAY');


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- Years between dates


    SELECT last_name,
        hire_date,
        ROUND(MONTHS_BETWEEN(SYSDATE, hire_date) / 12, 1) AS years_hired
    FROM employees
    WHERE hire_date < TO_DATE('2010-10-01', 'YYYY-MM-DD')
    ORDER BY years_hired;


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- Get tomorrow


    SELECT TO_CHAR(SYSDATE + 1, 'Month ddth "of year" YYYY')
    FROM dual;


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- GROUP BY (DML) -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- HAVING (DML) -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- Aggregate FUNCTIONS -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --


-----------------------------------------------------------------------
----------------------------------------------------------------------- Theory
-----------------------------------------------------------------------


    -- Single-Row functions return one value per row
    -- Multi-Row function(aggregate) return one value per group of rows


-----------------------------------------------------------------------
----------------------------------------------------------------------- GROUP BY
-----------------------------------------------------------------------


    SELECT column1,
        column2,
        column3,
        SUM(column4)
    FROM table
    GROUP BY -- Include all non aggregated columns
        column1,
        column2,
        column3


    -- RULE: Any field in the SELECT clause that is not part of an aggregate function MUST be in the GROUP BY clause.


-----------------------------------------------------------------------
----------------------------------------------------------------------- HAVING
-----------------------------------------------------------------------


    SELECT column1,
        column2,
        column3,
        SUM(column4)
    FROM table
    GROUP BY -- Include all non aggregated columns
        column1,
        column2,
        column3
    HAVING -- Include conditions 


-----------------------------------------------------------------------
----------------------------------------------------------------------- Aggregate FUNCTIONS
-----------------------------------------------------------------------


    -- Any time you use aggregate functions you must consider using GROUP BY


    COUNT(column)
    SUM(column)
    MIN(column)
    MAX(column)
    AVG(column)
    STDDEV(column)
    VARIANCE(column)


-----------------------------------------------------------------------
----------------------------------------------------------------------- WHERE vs. HAVING (+ EXAMPLES)
-----------------------------------------------------------------------

-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- Get total salary per department


    SELECT department_id,
        SUM(salary)
    FROM employees
    GROUP BY department_id
    ORDER BY 2 DESC;


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- Get total salary per department where department_id > 40


    SELECT department_id,
        SUM(salary)
    FROM employees
    WHERE department_id > 40
    GROUP BY department_id
    ORDER BY 2 DESC;
    
    -- OR (Prefer WHERE for this one but both works)
    
    SELECT department_id,
        SUM(salary)
    FROM employees
    GROUP BY department_id
    HAVING department_id > 40
    ORDER BY 2 DESC;


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- Get total salary per department where hire_date > 2002


    SELECT department_id,
        SUM(salary)
    FROM employees
    WHERE TO_DATE(hire_date, 'yy-mm-dd') > TO_DATE('2002-01-01', 'yyyy-mm-dd')
    GROUP BY department_id
    ORDER BY 2 DESC;
    
    -- For this one HAVING does not work but WHERE does.
    
    SELECT department_id,
        SUM(salary)
    FROM employees
    GROUP BY department_id
    HAVING TO_DATE(hire_date, 'yy-mm-dd') > TO_DATE('2002-01-01', 'yyyy-mm-dd')
    ORDER BY 2 DESC;


    /*
        RULE: if column is not in GROUP BY you must use WHERE
        RULE: if column is not AGGREGATED prefer WHERE
        RULE: if column is in GROUP BY prefer WHERE
        RULE: if column is AGGREGATED use HAVING
    */


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- USER INPUT -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --


    DEFINE varName = value      -- Manual automatic input
    UNDEFINE varName            -- Remove variable


    &varName            -- Prompt user input

    &&varName           -- Prompt once and allow for reuse of variable


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- Example


    SELECT location_id 
    FROM locations 
    WHERE LOWER(city) LIKE '%' || TRIM(LOWER(&cityInput)) || '%'    -- Give user flexibility


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- OTHERS


    SET VERIFY ON


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- SUB-QUERIES (DML) -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --


-----------------------------------------------------------------------
----------------------------------------------------------------------- Theory
-----------------------------------------------------------------------


    -- First, execute the sub-query.
    -- Second, use the result of the sub-query in the outer query.


    -- Provide an alternative way to query data that would require complex joins and unions.
    -- Make the complex queries more readable.
    -- Allow a complex query to be structured in a way that it is possible to isolate each part.


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- Types of Query Results


    Table   - any data set that has at least one column, number of rows is irrelevant.
    List    - a result set that contains exactly one column, number of rows is irrelevant
    Scalar  - a result that is guaranteed to only ever have one column and one row.


-----------------------------------------------------------------------
----------------------------------------------------------------------- FROM JOIN SUB-QUERIES (AKA inline view)
-----------------------------------------------------------------------


    SELECT e.first_name || ' ' || e.last_name,
        e.salary,
        jg.grade,
        c.totalSales * e.commission_pct
    FROM employees e
        JOIN (
            SELECT o.rep_no,
                SUM(ol.price * ol.qty) AS totalSales
            FROM orders o
                JOIN orderLines ol ON o.order_no = ol.order_no
            GROUP BY rep_no
        ) c ON e.employee_id = c.rep_no
        JOIN job_grades jg ON e.salary BETWEEN jg.lowest_sal AND jg.highest_sal
    WHERE c.totalSales * e.commission_pct > 15000
        AND jg.grade = 'D'
    ORDER BY e.salary;


-----------------------------------------------------------------------
----------------------------------------------------------------------- WHERE/HAVING SUB-QUERIES (AKA nested sub-query)
-----------------------------------------------------------------------


    SELECT * 
    FROM (
        SELECT employee_id, first_name, last_name
        FROM employees
        WHERE department_id IN (
            SELECT department_id
            FROM departments
            WHERE location_id IN (
                SELECT location_id 
                FROM locations 
                WHERE lower(city) LIKE '%' || TRIM(lower('&cityInput')) || '%'
                )
            )
        )
    WHERE upper(first_name) LIKE 'S%';


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- GOOD TO KNOW


    -- DO NOT USE single-row operators when SUB-QUERY returns more than one row
    -- (=, !=, <>, >, >=, <, <=)


    -- Add one of the following when MULTI-ROW is a possible return

    WHERE
        x IN (SUB-QUERY)        - x is equals to one of list's value                    -- NULL safe
        x NOT IN (SUB-QUERY)                                                            -- !! CAUTION with NULLs !!

        x = ANY(SUB_QUERY)      - same as IN                                            -- NULL safe
        x != ANY(SUB_QUERY)     - same as NOT IN                                        -- !! CAUTION with NULLs !!

        x > ANY(SUB_QUERY)      - x is greater than the smallest/lowest list's value    -- !! CAUTION with NULLs !!
        x > ALL(SUB_QUERY)      - x is greater than the biggest/highest list's value    -- !! CAUTION with NULLs !!

        x < ANY(SUB_QUERY)      - x is less than the biggest/highest list's value       -- !! CAUTION with NULLs !!
        x < ALL(SUB_QUERY)      - x is less than the smallest/lowest list's value       -- !! CAUTION with NULLs !!
        

    -- In advanced queries, the IN comparator can accept multiple columns on both sides.

    SELECT x, y, title
    FROM coordinates
    WHERE (x, y) IN ( (3,4), (5,6), (7,3), (-2,8) );

    -- is a possible use of the IN comparator including multiple columns on both sides. 


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- EXAMPLE


    SELECT prod_no, prod_type, prod_name, prod_sell
    FROM products
    WHERE (prod_type, prod_sell) IN
          (SELECT prod_type, min(prod_sell)        -- Lowest price for each product type
          FROM products
          GROUP BY prod_type)
    ORDER BY prod_type;


-----------------------------------------------------------------------
----------------------------------------------------------------------- ADVANCED: Correlated sub-queries
-----------------------------------------------------------------------

    /*
        A more powerful type of sub-query is the correlated sub-query in which the inner query references,
        and is dependent on, a column or alias from the outer query.
        Unlike the sub-queries above, each of these inner queries need to be run for each of the rows in the outer query,
        since the inner query is dependent on the current outer query row.
    */


    SELECT *
    FROM employees
    WHERE salary > 
          (
            SELECT AVG(revenue_generated)
            FROM employees AS dept_employees
            WHERE dept_employees.department = employees.department         -- "employees." refers to outer query
        );                                                                 -- This is what defines the dependency


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- SETS (DML) -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

-----------------------------------------------------------------------
----------------------------------------------------------------------- INTERSECT
-----------------------------------------------------------------------


    -- The Oracle INTERSECT operator to is used to compare two queries and returns rows that are output by both.


    SELECT <list of columns>
    FROM table1

    INTERSECT 

    SELECT <list of columns>
    FROM table2
    ORDER BY <...>; -- Optional, placed on last query


    /*
        RULES:
            - The number and the order of columns must be the same in the two queries.
            - The data type of the corresponding columns must be in the same data type group such as numeric or character.
    */


    -- 1, 2, 3
    INTERSECT
    -- 2, 3, 4

    -- OUTPUT: 2, 3


-----------------------------------------------------------------------
----------------------------------------------------------------------- UNION
-----------------------------------------------------------------------


    -- The UNION operator is a set operator that combines result sets of two or more SELECT statements into a single result set.


    SELECT column_list_1
    FROM T1

    UNION 

    SELECT column_list_1
    FROM T2
    ORDER BY <...>; -- Optional, placed on last query


    /*
        RULES:
        - Same as INTERSECT
    */


    -- 1, 2, 3
    UNION
    -- 2, 3, 4

    -- OUTPUT: 1, 2, 3, 4


-----------------------------------------------------------------------
----------------------------------------------------------------------- UNION ALL
-----------------------------------------------------------------------


    -- By default, the UNION operator returns the unique rows from both result sets.
    -- If you want to retain the duplicate rows, you explicitly use UNION ALL as follows:


    SELECT column_list_1
    FROM T1

    UNION ALL

    SELECT column_list_1
    FROM T2
    ORDER BY <...>; -- Optional, placed on last query


    /*
        RULES:
        - Same as INTERSECT
    */


    -- 1, 2, 3
    UNION ALL
    -- 2, 3, 4

    -- OUTPUT: 1, 2, 3, 2, 3, 4


-----------------------------------------------------------------------
----------------------------------------------------------------------- MINUS
-----------------------------------------------------------------------


    -- The Oracle MINUS operator compares two queries and returns distinct rows from the first query that are not output by the second query.
    -- In other words, the MINUS operator subtracts one result set from another.


    SELECT column_list_1
    FROM T1

    MINUS

    SELECT column_list_1
    FROM T2
    ORDER BY <...>; -- Optional, placed on last query


    /*
        RULES:
        - Same as INTERSECT
    */


    -- 1, 2, 3
    UNION ALL
    -- 2, 3, 4

    -- OUTPUT: 1


-----------------------------------------------------------------------
----------------------------------------------------------------------- ORACLE UNION vs. JOIN
-----------------------------------------------------------------------


    -- 1, 2, 3
    UNION
    -- 2, 3, 4

    -- REAL OUTPUT: 1        -- Appends vertically
                    2
                    3
                    4

    -- 1, 2, 3
    INNER JOIN
    -- 2, 3, 4

    -- REAL OUTPUT: 2, 2    -- Appends horizontally
                    3, 3


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- CASE WHEN -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- CASE...END returns a value


    CASE column
        WHEN condition1 THEN result1
        WHEN condition2 THEN result2
        WHEN conditionN THEN resultN
        ELSE result                            -- Optional
    END;


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- EXAMPLE

    
    SELECT
        CASE
            WHEN 1=1 THEN '1 = 1 IS TRUE'
            ELSE 'none is true'
        END AS "column alias"
    FROM dual;


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- CASE...END CASE; does not return a value


    CASE column
        WHEN condition1 THEN result1
        WHEN condition2 THEN result2
        WHEN conditionN THEN resultN
        ELSE result                            -- Optional
    END CASE;


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- EXAMPLE


    DECLARE
      semester CHAR(1);
    BEGIN
      semester := 'S';            -- defined semester with value S
      CASE 
        WHEN semester = 'F' THEN DBMS_OUTPUT.PUT_LINE('Fall Term');
        WHEN semester = 'W' THEN DBMS_OUTPUT.PUT_LINE('Winter Term');
        WHEN semester = 'S' THEN DBMS_OUTPUT.PUT_LINE('Summer Term');
        ELSE DBMS_OUTPUT.PUT_LINE ('Wrong Value');
      END CASE;
    END;


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- BEGIN...END -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- EXCEPTION...RAISE -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --


-----------------------------------------------------------------------
----------------------------------------------------------------------- STANDARD EXAMPLES
-----------------------------------------------------------------------


    BEGIN
        INSERT INTO employee2 
            SELECT * FROM employees;
        COMMIT;
        DBMS_OUTPUT.PUT_LINE('Transaction Successful!');
    EXCEPTION
        WHEN OTHERS THEN        -- Catch any exception
            ROLLBACK;
            DBMS_OUTPUT.PUT_LINE('Transaction Failed, rolled back');
    END;


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- RAISE EXAMPLE


    BEGIN
        -- Your SQL statements go here
        INSERT INTO my_table (my_column) VALUES ('my_value');
        UPDATE my_table SET my_column = 'new_value' WHERE my_column = 'old_value';
    EXCEPTION
        WHEN OTHERS THEN
            ROLLBACK;
            RAISE;              --  The RAISE statement propagates the error, so you can see what went wrong
    END;


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- PL/SQL PROCEDURE -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --


-----------------------------------------------------------------------
----------------------------------------------------------------------- CREATION section PROGRAMMING SYNTAX
-----------------------------------------------------------------------


    CREATE OR REPLACE PROCEDURE procedure_name(parameter-list) AS


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --  parameter-list


    parameter_name MODE parameter_type


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --  parameter-list TYPEs


    -- in PL/SQL, you don’t need to specify the precision and scale (like NUMBER(9,2)) when declaring a parameter of type NUMBER.
    -- The precision and scale are used when defining a column of type NUMBER in a table, but they’re not used in this context.

    -- NUMBER, CHAR, VARCHAR, DATE


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --  parameter-list MODEs


    -- -- -- IN
    
    -- This is the default mode. If you define a parameter as IN,
    -- you are saying that the caller should provide a value for the parameter when it calls the procedure or function.
    -- The procedure or function can then use this value, but it cannot change it.
    -- In other words, IN parameters are read-only.


    -- -- -- OUT

    -- If you define a parameter as OUT, you are saying that the procedure or function will change the value of the parameter and
    -- pass it back to the caller. The caller can then use this new value. OUT parameters are write-only,
    -- which means you cannot pass a value into a procedure or function using an OUT parameter, but you can get a value out.


    -- -- -- IN OUT

    -- If you define a parameter as IN OUT, you are saying that the caller should provide a value for the parameter and
    -- that the procedure or function can change this value and pass it back to the caller. So, IN OUT parameters are both readable and writable.


-----------------------------------------------------------------------
----------------------------------------------------------------------- DECLARATION section PROGRAMMING SYNTAX
-----------------------------------------------------------------------


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --  ASSIGNMENT :=


    my_var NUMBER := 42;


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --  JUST DECLARATION


    v_my_var  EMPLOYEES.FIRST_NAME%TYPE;
    v_my_var2 NUMBER;


-----------------------------------------------------------------------
----------------------------------------------------------------------- BODY section PROGRAMMING SYNTAX
-----------------------------------------------------------------------


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --  SELECT ... ASSIGNMENT


    SELECT FIRST_NAME, LAST_NAME, EMAIL, PHONE_NUMBER, HIRE_DATE, JOB_ID
    INTO v_first_name, v_last_name, v_email, v_phone, v_hire_date, v_job_id        -- values must be declared in DECLARATION section


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --  IF-THEN-ELSE


    IF condition THEN
        -- Code to execute if condition is true
    ELSE
        -- Code to execute if condition is false
    END IF;


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --  IF-THEN-ELSIF


    IF condition1 THEN
        -- Code to execute if condition1 is true
    ELSIF condition2 THEN
        -- Code to execute if condition1 is false and condition2 is true
    ELSE
        -- Code to execute if both conditions are false
    END IF;


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --  CASE


    CASE 
        WHEN condition1 THEN result1
        WHEN condition2 THEN result2
        ELSE result3
    END CASE;


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --  FOR LOOP


    FOR counter IN [ REVERSE ] lower_bound..upper_bound LOOP        -- e.g. (FOR i IN 1..4 LOOP)
        -- Code to execute for each value of counter from lower_bound to upper_bound
        -- starts at lower number and increments by 1 until upper condition is met.
        -- REVERSE is optional,
        -- starts at upper number and decreases by 1 until lower condition is met.
        -- Works with CURSORs e.g. (FOR item IN cur)
        -- item behaves like a table. (item.columnName)
    END LOOP;


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --  BASIC LOOP


    LOOP
        -- Code to execute repeatedly
        -- !! REQUIRE an EXIT STATEMENT !!
    END LOOP;


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --  WHILE LOOP


    WHILE [ NOT ] condition LOOP
        -- Code to execute repeatedly while the condition is true
        -- e.g. (WHILE run LOOP ...) where run BOOLEAN := true/false
    END LOOP;


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --  LOOPS STATEMENTS


    EXIT WHEN condition;            -- Condition to exit the loop
    EXIT;                           -- Exits the loop
    CONTINUE;                       -- Skips to the next iteration
    CONTINUE WHEN condition;        -- Condition to exit the current iteration


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --  GOTO


    <<label_name>>
    BEGIN
        GOTO label_name;
    END;


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --  NULL


    IF condition THEN
        NULL; -- Do nothing if condition is true
    ELSE 
        -- Code to execute if condition is false 
    END IF;


-----------------------------------------------------------------------
----------------------------------------------------------------------- CURSORs
-----------------------------------------------------------------------


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --  THEORY


    -- Cursor:
    -- It is a pointer to a private SQL area that stores information about the processing of a SELECT or DML statement.
    -- Cursors are typically used when you want to retrieve multiple rows and process each row individually.
    -- Associated during compile time.

    -- Ref Cursor:
    -- A ref cursor, or cursor variable, is a data type that holds a cursor value in the same way that a NUMBER variable can hold a number value.
    -- The main difference is that you can change the query associated with a cursor variable at runtime, whereas you can’t with a regular cursor.
    -- This makes ref cursors more flexible because you can reuse the same cursor variable for different queries.
    -- Ref cursors are typically used when you want to return a cursor from a function or procedure, or pass a cursor as a parameter.


    -- CURSORs work with FOR LOOPs


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --  CURSOR


    ...
    CURSOR cur IS
        SELECT column
        FROM table
    ...
    BEGIN
        ...


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --  OPEN;...CLOSE;
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --  FETCH...INTO...; variables


    BEGIN
        ...
        OPEN cur;
            LOOP
                FETCH cur INTO my_var;            -- if cur has many columns you need many variables
                EXIT WHEN cur%NOTFOUND;
                -- process each my_var
            END LOOP;
        CLOSE cur;
        ...
    END ...;


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --  OPEN;...CLOSE;
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --  FETCH...INTO...; table


    CURSOR cur IS SELECT * FROM table

    my_row  EMPLOYEES%ROWTYPE

    BEGIN
        ...
        OPEN cur;
            LOOP
                FETCH cur INTO my_row;
                EXIT WHEN cur%NOTFOUND;
                -- process each my_row columns
                -- my_row.id, my_row.salary
            END LOOP;
        CLOSE cur;
        ...
    END ...;


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --  FOR row IN cur LOOP


    -- row  TABLE%ROWTYPE       -- optional

    BEGIN
        ...
        FOR row IN cur LOOP
            ...
            -- row.column1
            -- row.column2
            ...
        END LOOP;
        ...
    END ...;


    -- OTHER SYNTAX


    BEGIN
        ...
        FOR row IN (SELECT * FROM TABLE) LOOP
            ...
            -- row.column1
            -- row.column2
            ...
        END LOOP;
        ...
    END ...;


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --  REF CURSOR (runtime)


        ...
        TYPE ref_cursor IS REF CURSOR;
        cur ref_cursor;
    BEGIN
        OPEN cur FOR SELECT column FROM table;
            ...
        CLOSE cur;
        ...
    END ...;


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --  REF CURSOR (runtime) (implicit)


    BEGIN 
      SELECT attr_name INTO var_name FROM table_name WHERE CONDITION; 
    END;


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- EXPLICIT CURSOR ATTRIBUTES


    Attributes      Value

    %ISOPEN         TRUE: if the cursor is open
                    FALSE: if the cursor is not open

    %FOUND          INVALID_CURSOR: if the cursor is not open
                    NULL: before we fetch the first row
                    FALSE: if the fetch row is successfully
                    TRUE: if no row is fetched in the fetch statement

    %NOTFOUND       INVALID_CURSOR: if the cursor is not open.
                    NULL: before we fetch the first row

    %ROWCOUNT       INVALID_CURSOR: if the cursor is not open
                    Otherwise: It returns the number of rows returned from the cursor


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- IMPLICIT CURSOR ATTRIBUTES (runtime)


    Cursor      Attribute       Cursor Variable Description

    %ISOPEN     SQL%ISOPEN      This attribute is automatically managed by the Oracle engine.
                                It checks if a cursor is open. If the cursor is open, it returns TRUE;
                                otherwise, it returns FALSE.

    %FOUND      SQL%FOUND       This attribute checks if a SELECT statement has returned one or more rows or if
                                a DML statement (INSERT, UPDATE, DELETE) has affected one or more rows.
                                If affected, it returns TRUE; otherwise, it returns FALSE.
                                If a SELECT or DML statement has not been executed, it returns NULL.

    %NOTFOUND   SQL%NOTFOUND    This attribute is used after a SELECT INTO statement.
                                If the statement returns no rows and fires a no_data_found PL/SQL exception,
                                you can check SQL%NOTFOUND. If no row is affected, it returns TRUE; otherwise, it returns FALSE.

    %ROWCOUNT   SQL%ROWCOUNT    This attribute returns the number of rows affected by
                                a SELECT statement or a DML statement (INSERT, UPDATE, DELETE).
                                If a SELECT or DML statement has not been executed, it returns NULL.


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- EXPLICIT CURSOR WITH PARAMETERS


    ...
    CURSOR product_cursor (price_1 NUMBER, price_2 NUMBER) IS
        SELECT *
        FROM    products
        WHERE   prod_sell BETWEEN price_1 AND price_2;

    BEGIN
        OPEN product_cursor (100, 500);         -- parameters hard coded in example
                                                -- normally this would come from user input
            LOOP
                FETCH product_cursor INTO p_product;  -- fetch a row into p_products
                EXIT WHEN product_cursor%notfound;
            
                dbms_output.put_line(p_product.prod_name || ': ' ||p_product.prod_sell);
            END LOOP;
        CLOSE product_cursor;
    ...


-----------------------------------------------------------------------
----------------------------------------------------------------------- EXCEPTION section PROGRAMMING SYNTAX
-----------------------------------------------------------------------


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --  BODY


EXCEPTION
    WHEN exception THEN         -- specific exception first
        ...;
    WHEN someExcep THEN         -- ignore exception; just quietly exit the local PL/SQL bloc
        NULL;
    WHEN OTHERS THEN            -- any other exception
        ...;


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --  RAISE


                                -- SIMILAR TO throw
    RAISE;                      -- re-raises the current exception and propagates it outward. It still need to be handled.
    RAISE exception_name;       -- raises a specific predefined exception or a user-defined exception.


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --  SQLERRM


    DBMS_OUTPUT.PUT_LINE('An error occurred: ' || SQLERRM); --  returns the error message associated with the most recently raised error exception


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --  NO_DATA_FOUND


    -- This exception is raised when a SELECT ... INTO statement returns no rows.


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --  TOO_MANY_ROWS


    -- This exception is raised when a SELECT ... INTO statement returns more than one row.


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --  INVALID_NUMBER


    -- This exception is raised when an attempt is made to convert a character string into a number,
    -- and the string cannot be converted into a valid number.


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --  ZERO_DIVIDE


    -- This exception is raised when an attempt is made to divide a number by zero.


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --  DUP_VAL_ON_INDEX


    -- This exception is raised when an attempt is made to insert or update a duplicate value in a column where
    -- the primary key or unique constraint is enabled.


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --  VALUE_ERROR


    -- This exception is raised when an arithmetic, conversion, truncation, or size-constraint error occurs.


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --  CASE_NOT_FOUND


    -- This exception is raised when a CASE statement's condition match was not found and
    -- it does not have the ELSE block


-----------------------------------------------------------------------
----------------------------------------------------------------------- PROCEDURE FULL SYNTAX
-----------------------------------------------------------------------


    CREATE OR REPLACE PROCEDURE my_procedure AS         -- Procedure creation Section (mandatory)
        my_var NUMBER := 42;                            -- Declaration Section (optional)
    BEGIN                                               -- Executable Section (mandatory)
        dbms_output.put_line (my_var);
    EXCEPTION                                           -- Exception-Handling Section (optional)
        WHEN OTHERS THEN
            dbms_output.put_line ('An error occurred: ' || SQLERRM);
    END my_procedure;
    /                                                   -- COMPILES the PROCEDURE (optional)
                                                        -- This is vital when executing the whole .sql file in one go...
                                                        -- Forgetting it will crash during EXECUTE


-----------------------------------------------------------------------
----------------------------------------------------------------------- CALLING PROCEDURES + EXAMPLE
-----------------------------------------------------------------------


    SET SERVEROUTPUT ON  -- This command enables the output from the DBMS_OUTPUT package to be displayed in SQL*Plus

    CREATE OR REPLACE PROCEDURE even_or_odd (inNumber IN NUMBER) AS
    BEGIN
      IF MOD(inNumber, 2) = 0
        THEN dbms_output.put_line(inNumber || ' is an even number');
      ELSE
        dbms_output.put_line(inNumber || ' is an odd number');
      END IF;
    EXCEPTION
      WHEN OTHERS THEN
        DBMS_OUTPUT.PUT_LINE('An error occurred: ' || SQLERRM);
    END even_or_odd;
    /


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --  NON-INTERACTIVE CALL


    BEGIN
        even_or_odd(10); -- replace 10 with your input number
    END;


    -- OR


    EXECUTE even_or_odd(10);
    EXEC even_or_odd(10);


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --  INTERACTIVE CALL


    ACCEPT prod_type CHAR PROMPT 'Please enter a product type: '
    ACCEPT amount NUMBER PROMPT 'Please enter the amount to increase the selling price by: '

    BEGIN
      update_price_fortype('&prod_type', &amount);
    END;


    -- OR


    EXECUTE update_price_fortype('&prod_type', &amount);
    EXEC update_price_fortype('&prod_type', &amount);


-----------------------------------------------------------------------
----------------------------------------------------------------------- MORE EXAMPLE
-----------------------------------------------------------------------


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --  SELECT...INTO


    SET SERVEROUTPUT ON
    CREATE OR REPLACE PROCEDURE find_me (empNumber IN NUMBER) AS
      v_first_name  EMPLOYEES.FIRST_NAME%TYPE;
      v_last_name   EMPLOYEES.LAST_NAME%TYPE;
      v_email       EMPLOYEES.EMAIL%TYPE;
      v_phone       EMPLOYEES.PHONE_NUMBER%TYPE;
      v_hire_date   EMPLOYEES.HIRE_DATE%TYPE;
      v_job_id      EMPLOYEES.JOB_ID%TYPE;
    BEGIN
      SELECT FIRST_NAME, LAST_NAME, EMAIL, PHONE_NUMBER, HIRE_DATE, JOB_ID
      INTO v_first_name, v_last_name, v_email, v_phone, v_hire_date, v_job_id
      FROM EMPLOYEES
      WHERE EMPLOYEE_ID = empNumber;

      DBMS_OUTPUT.PUT_LINE('First name: ' || v_first_name);
      DBMS_OUTPUT.PUT_LINE('Last name: ' || v_last_name);
      DBMS_OUTPUT.PUT_LINE('Email: ' || v_email);
      DBMS_OUTPUT.PUT_LINE('Phone: ' || v_phone);
      DBMS_OUTPUT.PUT_LINE('Hire date: ' || TO_CHAR(v_hire_date, 'DD-MON-YY'));
      DBMS_OUTPUT.PUT_LINE('Job title: ' || v_job_id);
    EXCEPTION
      WHEN NO_DATA_FOUND THEN
        DBMS_OUTPUT.PUT_LINE('No employee found with ID ' || empNumber);
      WHEN OTHERS THEN
        DBMS_OUTPUT.PUT_LINE('An error occurred: ' || SQLERRM);
    END find_me;


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --  UPDATE...SET + SQL%ROWCOUNT;


    SET SERVEROUTPUT ON
    CREATE OR REPLACE PROCEDURE update_price_fortype (prodType IN VARCHAR2, amount IN NUMBER) AS
      rows_updated NUMBER;
    BEGIN
      UPDATE products
      SET prod_sell = prod_sell + amount
      WHERE LOWER(prod_type) = LOWER(TRIM(prodType)) AND prod_sell > 0;
      
      rows_updated := SQL%ROWCOUNT;
      
      DBMS_OUTPUT.PUT_LINE('Number of rows updated: ' || rows_updated);
      
      ROLLBACK;
    EXCEPTION
      WHEN OTHERS THEN
        DBMS_OUTPUT.PUT_LINE('An error occurred: ' || SQLERRM);
    END update_price_fortype;


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --  CURSOR + LOOP + FETCH;


    SET SERVEROUTPUT ON
    CREATE OR REPLACE PROCEDURE price_report AS
      low_price products.prod_sell%type;
      high_price products.prod_sell%type;
      sell_price NUMBER;
      low_count NUMBER;
      fair_count NUMBER;
      high_count NUMBER;
      
      CURSOR prices IS
        SELECT prod_sell
        FROM products;
    BEGIN
      low_count := 0;
      fair_count := 0;
      high_count := 0;

      SELECT (AVG(prod_sell) - MIN(prod_sell)) / 2
      INTO low_price
      FROM products;
      
      SELECT (MAX(prod_sell) - AVG(prod_sell)) / 2
      INTO high_price
      FROM products;
      
      OPEN prices;
        LOOP

          FETCH prices INTO sell_price;
            EXIT WHEN prices%notfound;

            IF (sell_price < low_price) THEN
              low_count := low_count + 1;
            ELSIF (sell_price > high_price) THEN
              high_count := high_count + 1;
            ELSIF ((sell_price >= low_price) AND (sell_price <= high_price)) THEN
              fair_count := fair_count + 1;
            END IF;

        END LOOP;
    CLOSE prices;

      dbms_output.put_line('Low: '  || low_count);
      dbms_output.put_line('Fair: ' || fair_count);
      dbms_output.put_line('High: ' || high_count);

    END price_report;


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- PL/SQL ANONYMOUS BLOCKS -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --


    -- Procedures that are used only once

    DECLARE
      inNumber NUMBER := 10;
    BEGIN
      IF MOD(inNumber, 2) = 0
        THEN dbms_output.put_line(inNumber || ' is an even number');
      ELSE
        dbms_output.put_line(inNumber || ' is an odd number');
      END IF;
    EXCEPTION
      WHEN OTHERS THEN
        DBMS_OUTPUT.PUT_LINE('An error occurred: ' || SQLERRM);
    END;


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- PL/SQL FUNCTIONS -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- THEORY


    -- Functions can be used in typical SQL statements like SELECT, INSERT, UPDATE, DELETE, MERGE, while procedures cannot.
    -- Functions can be used in both SQL and PL/SQL. Procedures, on the other hand, require PL/SQL.


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- FULL SYNTAX


    CREATE [OR REPLACE] FUNCTION function_name (parameter_list)
        RETURN return_type
    IS/AS
        [declarative section]
    BEGIN
        [executable section]
    [EXCEPTION]
        [exception-handling section]
     RETURN return_value
    END;


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- FUNCTION EXAMPLE


    SET SERVEROUTPUT ON
    CREATE OR REPLACE FUNCTION find_max_price
    RETURN NUMBER
    IS
        max_price NUMBER := 0;

    BEGIN
        -- get the maximum prod_sell price
        SELECT MAX(prod_sell)
        INTO max_price
        FROM products;
        
        -- return the max price
        RETURN max_price;
    END;


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- Pre-defined Exceptions PL/SQL -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --


| Exception             | Oracle Error  | SQLCODE   | Description
|-----------------------|---------------|-----------| It is raised when...
| ACCESS_INTO_NULL      | 06530         | -6530     | ... a null object is automatically assigned a value.
| CASE_NOT_FOUND        | 06592         | -6592     | ... none of the choices in the WHEN clause of a CASE statement is selected, and there is no ELSE clause.
| COLLECTION_IS_NULL    | 06531         | -6531     | ... a program attempts to apply collection methods other than EXISTS to an uninitialized nested table or varray, or the program attempts to assign values to the elements of an uninitialized nested table or varray.
| DUP_VAL_ON_INDEX      | 00001         | -1        | ... duplicate values are attempted to be stored in a column with unique index.
| INVALID_CURSOR        | 1001          | -1001     | ... attempts are made to make a cursor operation that is not allowed, such as closing an unopened cursor.
| INVALID_NUMBER        | 1722          | -1722     | ... the conversion of a character string into a number fails because the string does not represent a valid number.
| LOGIN_DENIED          | 1017          | -1017     | ... a program attempts to log on to the database with an invalid username or password.
| NO_DATA_FOUND         | 1403          | +100      | ... a SELECT INTO statement returns no rows.
| NOT_LOGGED_ON         | 1012          | -1012     | ... a database call is issued without being connected to the database.
| PROGRAM_ERROR         | 6501          | -6501     | ... PL/SQL has an internal problem.
| ROWTYPE_MISMATCH      | 06504         | -6504     | ... a cursor fetches value in a variable having incompatible data type.
| SELF_IS_NULL          | 30625         | -30625    | ... a member method is invoked, but the instance of the object type was not initialized.
| STORAGE_ERROR         | 06500         | -6500     | ... PL/SQL ran out of memory or memory was corrupted.
| TOO_MANY_ROWS         | 01422         | -1422     | ... a SELECT INTO statement returns more than one row.
| VALUE_ERROR           | 06502         | -6502     | ... an arithmetic, conversion, truncation, or size constraint error occurs.
| ZERO_DIVIDE           | 01476         | 1476      | ... an attempt is made to divide a number by zero.


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- ADVANCED (TODO) -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

    CAST()


    MERGE ?
    TRUNCATE ?
    COMMENT ?



BEGIN
  EXECUTE IMMEDIATE 'DROP TABLE prod19';
EXCEPTION
  WHEN OTHERS THEN
    IF SQLCODE != -942 THEN
      RAISE;
    END IF;
END;
/

BEGIN
  EXECUTE IMMEDIATE 'DROP TABLE trans19';
EXCEPTION
  WHEN OTHERS THEN
    IF SQLCODE != -942 THEN
      RAISE;
    END IF;
END;
/
