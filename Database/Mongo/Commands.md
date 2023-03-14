## Create documents

There are two methods to create documents

- `insertOne(aSingleDocument)`
- `insertMany(listofdoc,configurationToAddDoc)`
- `insert()` has ability to add a single as well as multiple documents

- Id reflects when they were created too.

## Ordered insert

- Default behaviour, every element is processed stand alone, but if write operation fails for any reason, this results,other write documents will be aborted, but the inserted documents cannot be rolled back.
- To fix that use`configurationToAddDoc`-> `ordered:false`
- It will still continue inserting documents even if some insertions fail.

## Journal

- The idea of journal is keep aware of the commands, that wre going to run, it is important to have journal because if by some reason the machine stops, no data/ command will be saved
- Backup todo-list.

## Write concern

- insertOne(), `insertmany(,{writeConcern:{w:1}})`
- This means that the program want the write operation to be addressed and acknowledge by the db.

## Atomicity

-

## Import data

- `mongoimport nameofthefiletoimport -d whichdatabase -c whichcollection --jsonArray(tell there are multiple documents) --drop(drops the collection if it exists else it would have appended)`

## Type of operators

1. Query Selectors - find data and read
2. Projection Operators - modify data presentation
3. Aggregation (pipeline, operators)
4. Update -modify data

## Query selectors and Projection operators

Query

- Comparison
- Evaluation
- Logical
- Arrays
- Element
- Comments
- Geospatial

Projection

- $
- $elemMatch
- $meta
- $slice

## Read documents

- ```js
  findOne(); // finds first document by default
  find({ age: 32 }); // equality filter
  find({ age: { $gt: 32 } }); // range filter
  db.movies.find({ genres: { $in: ["Drama", "Romance"] } }); //finds all the documents which has Drama or Romance or both
  $or = "returns everything that matches the condition";
  db.movies.find({ $or: [{ "rating.average": { $lt: 5 } }, { "rating.average": { $gt: 9.3 } }] });
  $nor = "return all document neither any of the specified conditionds are met.";
  ```

## $or

- When using `$or`, you start the find with `$or` telling mongodb that we will have multiple conditions and or means return documents that match any condition.
- `db.movies.find({ $or: [{ "rating.average": { $lt: 5 } }, { "rating.average": { $gt: 9.3 } }] });`
- return all document where avg is either lt 5 or gt 9.3 but nothing in between.

## $nor

- returns all document that dosent match either of the conditions.
- `db.movies.find({$nor:[{"rating.average":{$gt:9}},{genres:["Drama"]}]})`
- The above query will return all the document where documents avg is less than 9 and genres should not only be Drama but can include drama.

## $and

- takes an array, telling mongo we can have multiple condition
- `db.movies.find({$and:[{"rating.average":{$gt:5}},{genres:"Drama"}]})`
- This query finds documents where rating avg is gt 5 and genres include Drama
- `db.movies.find({$and:[{"rating.average":{$gt:5}},{genres:["Drama"]}]})`
- This query finds documents where rating avg is gt 5 and genres only include Drama
- `db.movies.find({rating.average:{$gt:5},{genres:"Drama"}})`
- The above query is same as and,
- The main reaason of having a `$and` operator is that `{genres:"Drama",genres:"Horror"}`, this code is supposed to search fordocument which have both Drama and Horror. But in a js object when there is already a key :value and you re-declaring the same key, you are overwritng the value of that key

## $not $and

- `db.movies.find({$nor:[{$and:[{"rating.average":{$gt:9}},{genres:["Drama"]}]}]})`
- returns all the document where rating is not gt 9 and genres is not only Drama.

## $not

- returns the document that **do not match** the query expression

## $exists

- `db.users.find({age:{$exists:true,$gte:30}})`
- finds all documents in which age is present and gte to 30
- return documents even if key has vaue of null
- `db.users.find({age:{$exists:true,$ne:null}})`

## $type

- `db.users.find({phone:{$type:"double"}}})`

## $regex

- `db.movies.find({summary:{$regex:/musical/}}})`

## $expr

- `db.movies.find({$expr:{$gt:["$collection","$production"]}})`
- this query will find all the documents where collection of movie is greater than the cost of production and the `$` is used to tell mongo that look at the value of these `["$collection","$production"]` fields in document instead as text.

- ```js
  db.movies.find({
    $expr: {
      $gt: [
        {
          $cond: {
            if: { $gt: ["$collection", "$production"] },
            then: { $subtract: ["$collection", "$production"] },
            else: 0,
          },
        },
        100,
      ],
    },
  });
  ```
- This query find will return all the documents where the difference between collection and production is greater than 100

## $size

- `db.movies.find({moviesDoneByActors:{$size:10}})`
- This query will give all the actor name whose movie collection embedded document length is 10
- Unfoutunately, we cannot do $gt and $lt that queries in $size.

## $all

- `db.movies.find({genres:["actions","thriller"]})`
- this query will find document where genres is exactly same in document (indexes too)
- `db.movies.find({genres:{$all:['actions','thriller']}})`
- this query will find all documents where genres is equal to given ignoring indexes.

## $elemMatch

- helps in finding data inside a nestedDocument and makes sure that finding the data happens in a nested doc instead of whole document.
- `db.movies.find({hobbies:{$elemMatch:{title:"Cooking",frequency:{$gte:3}}}})`

## sort skip and limit is order after find()

## Projection

- select only a few column from returning documents
- `db.movies.find({},{name:1,title:1,"ratings.average":1})`

## $slice related to arrays

- `db.movies.find({"rating.average":{$gt:9}},{genres:{$slice:2},name:1})`
- `db.movies.find({"rating.average":{$gt:9}},{genres:{$slice:[skip,limit]},name:1})`
- `db.movies.find({"rating.average":{$gt:9}},{genres:{$slice:[1,2]},name:1})`

## Update Documents

## updateOne()

- `$set` doesnt overwrite the value, it will define some changes to mongodb to evealute and if those makes sense mongodb will update
- `db.users.updateOne({_id: ObjectId("63941b9dcd5809cbf92b7aaf")},{$inc:{age:2},$set:{isCooking:false}})`

## Increment

- `db.users.updateOne({_id: ObjectId("63941b9dcd5809cbf92b7aaf")},{$inc:{age:2}})`

## Updating

- `db.users.updateOne({_id: ObjectId("63941b9dcd5809cbf92b7aad")},{$set:{hobbies:[{title:"Playing",freq:2},{title:"Swimming",freq:2}]}})`

## Both

- ```js
  db.users.updateOne({\_id: ObjectId("63941b9dcd5809cbf92b7aad")},{$set:{hobbies:[{title:"Playing",freq:2},{title:"Swimming",freq:2}]}})
  ```

## $min

- Any value which greater than min val, this query will update the value
- `db.users.updateOne({name:"Manuel"},{$set:{age:40}})`
- `db.users.updateOne({name:"Manuel"},{$min:{age:35}})`
- Now, as the age is 40 and we are checking for min age of 35, this query will update age to 35
- $min only changes value if the new value if lower than the existing value.

## #max

- $min only chnages the value if the bew value is higher than the existing value
- `db.users.updateOne({name:"Manuel"},{$set:{age:40}})`
- `db.users.updateOne({name:"Manuel"},{$min:{age:45}})`

## mul

- the operator will update the value by multliplying the number with existing value
- `db.users.updateOne({$mul:{age:2}})`

## get rid of a field

- ## $unset
  `db.users.updateMany({isCooking:false},{$unset:{isCooking:""}})`

## update a field name

ex : age -> total age

### $rename

- `db.users.updateMany({},{$rename:{age:"totalAge"}})`

## upsert

- update document even when ypu dont know if a document exists and if doesn't exist create a document
- `db.users.updateOne({name:"Ali"},{$set:{age:22,email:"ali@bst.com",hobbies:[{title:"a",freq:2}]}},{upsert:true})`

## Updating first matched nested documents in an array

- ```js
  db.users.updateMany(
    { hobbies: { $elemMatch: { title: "Sports", frequency: { $gte: 3 } } } },
    { $set: { "hobbies.$.newField": true } }
  );

  db.users.updateMany(
    { hobbies: { $elemMatch: { title: "Sports", frequency: { $gte: 3 } } } },
    { $set: { "hobbies.$.bys": true }, shahed: "ali" }
  );
  ```

- This `hobbies.$`, here the `$` is reference to the first found nested document and add a new key value pair in that

## Updating all matched nested documents in an arrays

- ```js
  db.users.updateMany(
    { hobbies: { $elemMatch: { title: "Sports", frequency: { $gte: 3 } } } },
    { $set: { "hobbies.$[].newField": true } }
  );
  db.users.updateMany(
    { "hobbies.frequency": { $gt: 2 } },
    { $set: { "hobbies.$[].greaterThan2": true } }
  );
  ```
- This `hobbies.$[]` will updated all the found nested documents

## find and update specific fields

## push data in to an array

## $addToSet

it is similar to push but, it cannot add/push duplicate values into the array.

- `db.users.updateMany({},{$push:{courses:"SSC (X)"}})`

## how to push multiple values into array using updateMany

- `db.users.updateMany({},{$push:{courses:{$each:['Degree',"BCA"]}}})`

## Remove elements from array

- ## $pull
- describe how to pull / remove data from array
- Remove nested array data
- `db.users.updateMany({},{$pull:{"courses.1":"Intermediate (BIE)"}})`

## Delete

- db.users.drop()
- db.dropDatabase()

## Indexes

### What are indexes?

- An Index is an ordered list of all the values for the field that you indexed and each item in the list is points to its document. By this methods are the list is properly segregated and ordered mongodb can find the document efficiently as it need to traverse all the documents now

### Why to use Index

- Improves read update and delete query speed

- Default nature is to go through all documents and find the documents where conditions matches

- An index is expensive when you are creating and updating the document as you also need to update the data with respect to that document

## Explain

- `db.persons.explain().find({"dob.age":{$gt:60}})`
- Without an index, mongodb by default will run a `COLLSCAN`.
- `db.persons.explain("executionStats").find({_id: ObjectId("6394b4491015866588e7b3b3")})`
- As `_id` is already an index, findbyId takes no time to run.
- `db.persons.explain("executionStats").find({"dob.age":{$gt:60}})`
- `.explain("executionStats")` commands gives detailed analysis of how the query was executed and amount of documents it went through and time taken

## How to create an Index?

- ```js
  db.collection.createIndex({ key: order(ASC || DESC) });
  db.persons.createIndex({ "dob.age": 1 });
  ```

## Cons of indexing

- Indexing can only slow the query when the find query returns a large portion because it first has to go throught entire index list and find the ponted document and return it as now sources (index list) is greater it has to do 2 steps to return data which can effect the query time.
  it is slow.
- The main idea of using an index is to quickly find the small portion of the data (usually 10 to 20% of the data) not the other way around

## Compound index

- `db.persons.dropIndex({gender:1})`
- Ex Indexing documents by male and age is > 40
- order of fields matter
- `db.persons.createIndex({"dob.age":1,gender:1})`

## getIndexes

- `db.collection.getIndexes()`

## Configuring indexes

- `db.contacts.createIndex({email:1},{unique:true})`
- this query will createIndex on email and makes email completely uniques across the collection

## partial index

- indexing only things which we are going to use daily.
- `db.users.createIndex({email:1},{unique:true,partialFilterExpression:{email:{$exists:true}}})`
- This query creates and index on email field,but email is not mandatory so we are indexing only emails which are in the document. This step has been taken because mongodb assumes that not sepcifying an email field is also unq and it should be allowed to one user only.

## Time to live index.

## Aggregation

- Alternative to find with some steps
- $match -> filter
- $sort
- $group
- $project
- `db.collection.aggregate()`
- ```js
  db.persons
    .aggregate([
      { $match: { "dob.age": { $gt: 50 } } },
      {
        $group: {
          _id: { gender: "$gender" },
          totalNoPeople: { $sum: 1 },
          avgAge: { $avg: "$dob.age" },
        },
      },
      { $sort: { $totalNoPeople: 1 } },
    ])
    .pretty();
  ```

- ## $project
- used to transform the query - like select from sql
- ```js
  db.persons.aggregate([
    { $project: { _id: 0, gender: 1, fillName: { $concat: ["$name.first", " ", "$name.last"] } } },
  ]);
  ```

## Differnce between $project and $group

- is that group takes many documents combines them and outputs an single documnet where as $projects takes each documnet and updates some data to that documnet
