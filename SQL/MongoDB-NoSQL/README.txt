-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- Mongo Intro -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

-----------------------------------------------------------------------
----------------------------------------------------------------------- DATABASE CONTROL
-----------------------------------------------------------------------

-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- DATABASE


SQL Table   ->  MongoDB Collection
SQL Row     ->  MongoDB Document
SQL Column  ->  MongoDB Field
SQL value   ->  MongoDB value


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- DATABASE


exit                    -- exit mongosh

db                      -- display working database

show dbs                -- display all database

use targetDB            -- change working database

db.dropDatabase()       -- drop working database

help()

db.help()

db.collection.help()

db.collection.find.help()

db.collection.find().help()

-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- COLLECTION


show collections                -- display all collections

db.targetCollection.drop()      -- drop collection

db.createCollection("mycollection")     -- create collection on current database


-----------------------------------------------------------------------
----------------------------------------------------------------------- DATABASE TOOLS
-----------------------------------------------------------------------


mongoimport --db college --collection students --file ..\dataset\students.json


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- Mongo CRUD -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --


-----------------------------------------------------------------------
----------------------------------------------------------------------- READ
-----------------------------------------------------------------------


find(<filter>, <selection>)<ADD-ONS>


db.targetCollection.find()      -- return all matches from collection
db.targetCollection.findOne()   -- return first match from collection


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- ADD-ONS


.pretty()                   -- format output
.forEach(printjson)         -- format output


.limit( N )                         -- limit to N-documents
.sort( { k1: 1, k2: -1 } )          -- sort by k1 ascending and then by k2 descending order
.count()                            -- number of documents found
.skip( N )                          -- skip first N-documents
.projection( { k1: 1, k2: 1 } )     -- Same as selection, it specifies fields to output


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- <filter>


{}                                      -- all

{ _id: 22 }                             -- Simple object kv


{ _id: { $in: [20, 22, 24] } }          -- IN

{ _id: { $nin: [20, 22, 24] } }         -- NOT IN

{ myArr: { $all: [20, 22, 24] } }       -- myArr must have all values

{ myArr: { $size: VALUE } }             -- myArr must have SIZE == VALUE


{ _id: { $lt: VALUE  } }                -- <

{ _id: { $lte: VALUE } }                -- <=

{ _id: { $gt: VALUE  } }                -- >

{ _id: { $gte: VALUE } }                -- >=

{ _id: { $ne: VALUE  } }                -- != <>


{ $or: [ { _id: VALUE }, { k1: VALUE } ] }      -- If any is true

{ $and: [ { _id: VALUE }, { k1: VALUE } ] }     -- If all are true


{ _id: { $not: { <expression> }  } }            -- Exclude

{ age: { $exists: true } }                      -- if document contains filed


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- Range/not/REGEX Examples


    { age:      { $gt: 20, $lt: 30 } }

    { age:      { $not: { $gt: 20, $lt: 30 } } }

    { status:   { $not: { $in: ["A", "D"] } } }

    { name:     { $not: /^J/ } }


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- <selection>


{ _id: 0, k1: 1 }           -- _id always appears if not explicitly set to 0


{ k1: 0 }                   -- all fields except program appears


-----------------------------------------------------------------------
----------------------------------------------------------------------- CREATE
-----------------------------------------------------------------------


insert(<object>)            -- deprecated


db.targetCollection.insertOne( { k1: "v1", k2: "v2" } )
db.targetCollection.insertMany( [ { k1: "v1", k2: "v2" }, { k3: "v3", k4: "v4" } ] )


db.targetCollection.bulkWrite()


-----------------------------------------------------------------------
----------------------------------------------------------------------- DELETE
-----------------------------------------------------------------------


remove(<filter>, <option>)          -- deprecated


db.targetCollection.deleteOne()
db.targetCollection.deleteMany()


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- <filter>


{}                      -- remove all documents in collection

{ k1: v1, k2: v2 }      -- Simple object kv


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- <option>


{ justOne: true }       -- for deprecated. Delete just first match


-----------------------------------------------------------------------
----------------------------------------------------------------------- UPDATE
-----------------------------------------------------------------------


update(<filter>,<update>,<option>)          -- deprecated


db.targetCollection.updateOne()
db.targetCollection.updateMany()


db.targetCollection.findOneAndUpdate()      -- return document before update

db.targetCollection.findOneAndUpdate(       -- return document after update
  <filter>,<update>,
  { returnDocument: "after" }
);


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- <update>


{ $set: {k1: "v1", k2: "v2"} }

{ $unset: {k1: "", k2: 1} }

{ $inc: { "k1": VALUE } }

{ $inc: { "k1": -VALUE } }


{ $push: { "array_field": "new_value" } }
            --
            -- $push operator adds elements to the end of an array if the array exists.
            -- If the array does not exist it will be created with the given elements
            

{ $push: { "array_field": { $each: ["new_value1", "new_value2"] } } }
            --
            -- $each operators is used to push multiple values to an array on one "$push" operation.

{ $push: { "array_field": { $each: [...], $slice: -3 } } }
            --
            -- operator is used with the "$push" operator to make sure that an array will not grow bigger that a certain size.
            -- positive == first elements | negative == last elements

{ $push: { "array_field": { $each: [...], $sort: { "field_to_sort": -1 } } } }
            --
            -- You can sort an array before pushing more items to the array
            -- positive == ascending | negative == descending


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- <option>


{ multi: true }


-----------------------------------------------------------------------
----------------------------------------------------------------------- UPDATE (replace)
-----------------------------------------------------------------------


replace(<filter>,<object>)


db.targetCollection.replaceOne()
db.targetCollection.replaceMany()


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- Mongo AGGREGATION -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --


db.targetCollection.aggregate( [ { <process>: { <objects> } } ] )


-----------------------------------------------------------------------
----------------------------------------------------------------------- <process>
-----------------------------------------------------------------------


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- $group


    -- This does the aggregation (GROUP BY)


[
    {
    _id: null,                                  -- group everything into a single document
    total: { $sum: '$price' },
    }
]

[
    {
    _id: "$fieldName",                          -- group everything into unique fieldName
    totalById: { $sum: '$price' },
    }
]

[
    {
    _id: [ "$fieldName1", "$fieldName2" ],      -- group everything into unique fieldName1 + fieldName2
    totalTimesById: { $sum: 1 },
    } 
]

    -- OR

[
    {
    _id: { fieldName1: "$fieldName1", fieldName2: "$fieldName2" },
    totalTimesById: { $sum: 1 },
    } 
]


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- $match


    -- This is often used to filter out documents. (WHERE/HAVING)
    -- !! should appear as early as possible !!
    -- That in turn reduces the number of documents that the next process will work on.
    -- For example, it would be used with $gt, $lt,   etc…. and then the grouping will be less to process.


[
   { $match: { "itemsSold": { $gt: 10 } } },
   { $group: { _id: "$product", totalSales: { $sum: "$saleAmount" } } }
]

[
   { $group: { _id: "$product", totalSales: { $sum: "$saleAmount" } } }
   { $match: { "totalSales": { $gt: 100 } } },
]


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- $sort


    -- Sorts document (ORDER BY)


[
   { $sort: { "field1": 1, "field2": -1 } }
]


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- $skip


    -- This allows the process to skip forward (or skip past) the number of documents and then continue the processing


[
    { $skip: 10 }
]


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- $limit


    -- This applies a limit to the number of documents to look at starting with the current position and counting


[
    { $limit: 5 }
]


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- $project


    -- Select which fields to include or exclude in the documents that are passed to the next stage
    -- can rename a filed


[
    { $project: { field1: 1, field2: 1 } }
]


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- $unwind 


    -- This is used to unwind document that are using arrays.
    -- When using an array, the data is kind of pre-joined and this operation will be undone with this to have individual documents again.
    -- With this stage we will increase the number of documents for the next stage.


[
    { $unwind: "$arrayField" }
]


-----------------------------------------------------------------------
----------------------------------------------------------------------- <objects> + OPERATORS
-----------------------------------------------------------------------


$sum        - Sums up the defined value from all documents in the collection.

$avg        - Calculates the average of all given values from all documents in the collection.

$min        - Gets the minimum of the corresponding values from all documents in the collection.

$max        - Gets the maximum of the corresponding values from all documents in the collection.



$push       - Inserts the value to an array in the resulting document.
            + { $group : { _id : "$fieldName", url : { $push: "$url" } } }

$addToSet   - Inserts the value to an array in the resulting document but does not create duplicates.
            + { $group : { _id : "$fieldName", url : { $addToSet : "$url" } } }

$first      - Gets the first document from the source documents according to the grouping.
            - Typically this makes only sense together with some previously applied "$sort"-stage.
            + { $group : { _id : "$fieldName", first_url : { $first : "$url" } } }

$last       - Gets the last document from the source documents according to the grouping.
            - Typically this makes only sense together with some previously applied "$sort"-stage.
            + { $group : { _id : "$fieldName", last_url : { $last : "$url" } } }


-----------------------------------------------------------------------
----------------------------------------------------------------------- EXPRESSIONS
-----------------------------------------------------------------------


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- MATH


"$add" : [expr1[, expr2, ..., exprN]]	    -- Takes one or more expressions and adds them together.

"$subtract" : [expr1, expr2]	            -- Takes two expressions and subtracts the second from the first.

"$multiply" : [expr1[, expr2, ..., exprN]]	-- Takes one or more expressions and multiplies them together.

"$divide" : [expr1, expr2]	                -- Takes two expressions and divides the first by the second.

"$mod" : [expr1, expr2]	                    -- Takes two expressions and returns the remainder of dividing the first by the second.


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- DATE


-- There are operators to extract data information. These operators take a date expression and return a number.
    $year,
    $month,
    $week,
    $dayOfMonth,
    $dayOfWeek,
    $dayOfYear,
    $hour,
    $minute,
    $second


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- STRING


"$substr" :     -- Substring
"$concat" :     -- Concatenation
"toLower" :     -- Lowercase
"toUpper" :     -- Uppercase


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- LOGICAL


"$not" : expression
"$and" : [expr1, expr2, ..., exprN]
"$or"  : [expr1, expr2, ..., exprN]


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- LOGICAL


CONDITIONAL OPERATIONS

"$cond"   : [booleanExpr, trueExpr, falseExpr]      -- Conditional
"$ifNull" : [expr, replacementExpr]                 -- if value returned is not null expression is returned


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- Mongo TODO -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

-----------------------------------------------------------------------
----------------------------------------------------------------------- TODO
-----------------------------------------------------------------------

-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- TODO
