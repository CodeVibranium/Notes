# POSTGRES

## Commands

- \q quit the postgres.

## DATA Types

![](./DataTypes.png)

### Numeric Data Type

![](./Numeric.png)

### Char Data type

![](./Char.png)

#### If using CHAR with a value postgres will remove all the extra char which exceed the length and add spaces if it dosent pass the threshold length

#### If using VARCHAR with a value postgres will remove all the extra char which exceed the length and doesn't add spaces if it dosent pass the threshold length.

### Boolean

![](./Boolean.png)

### Date

![](./Date.png)

### Time

![](./Time.png)
`SELECT ('1:23:56'::TIME)`
`SELECT ('1:23:56 PM'::TIME)` will convert the value in 24 hour clock value

### Time zone

![](./Timezone.png)
Any time value given will be converted into UTC value
1:23 am in the eastern time zone will be -5 hours

## Validation @ Database level.

1. Row Level validation

   - checks happen which data is inserted or updated.
   - NULL Constraint

   1. tells that this column cannot be null
   2. `price INTEGER NOT NULL`
   3. if table is already created then:
      - ```sql
        ALTER TABLE products
        ALTER COLUMN price SET NOT NULL
        ```
   4. IF A TABLE CONTAINS NULL VALUES.

      - set those null values to some tmp value
      - Update table
      - ```sql
        UPDATE products
        SET price =-1
        WHERE price is NULL
        ```

2. DEFAULT Value

   1. While creating table

   ```sql
    CREATE TABLE products ( id SERIAL PRIMARY KEY, name VARCHAR(50) NOT NULL, department VARCHAR(50) NOT NULL, price INTEGER DEFAULT 999, weight INTEGER
    );
   ```

   2. Updating the table

   ```sql
   ALTER TABLE products
   ALTER COLUMN price
   SET DEFAULT 999;
   ```

3. UNIQUE

   1. While creating table

   ```sql
   CREATE TABLE products (
   id SERIAL PRIMARY KEY, name VARCHAR(50) NOT NULL UNIQUE, department VARCHAR(50), price INTEGER, weight INTEGER
   )
   ```

   2. Updating the table

   ```sql
   ALTER TABLE products
   ADD UNIQUE (name);
   ```

   **CATCH**:

   1. Before you add the UNQIUE property to a column all the values inside that column needs to be unq.

4. MULTI COLUMN UNIQUES
   This means that combing values from both columns must result a unq value across the whole table

   1. While creating table

   ```sql
   CREATE TABLE products ( id SERIAL PRIMARY KEY, name VARCHAR(50), department VARCHAR(50), price INTEGER, weight INTEGER,
   UNIQUE(name, department)
   ```

   2. Updating the table

   ```sql
   ALTER TABLE products
   ADD UNIQUE (name, department);
   ```

5. CHECK
   1. While creating table
   ```sql
    CREATE TABLE products
   (
    id SERIAL PRIMARY KEY,
    name VARCHAR(50) NOT NULL,
    department VARCHAR(50) NOT NULL,
    price INTEGER CHECK (price > 0),
    weight INTEGER
    );
   ```
   2. Updating the table.
   ```sql
   ALTER TABLE products
   ADD CHECK (price > 0);
   ```
6. COALESCE()
   - Takes two params
   - return value which is NOT NULL;
   - ex:
     1. COALESCE(null,null)-> return null
     2. COALESCE(null,'')-> return ''

Examples

1. ```sql
   -- How i wrote.
   SELECT username, user_id,likes_count FROM users JOIN
   (SELECT user_id,count(*) as likes_count FROM likes GROUP BY user_id) as p
   ON users.id=p.user_id;
   ```
2. ```sql
   -- How it could have been written.
   SELECT username , count(*) from likes join users on likes.user_id=users.id group by username;

   ```

## PERFORMANCE

1. ### FULL TABLE SCAN.

   Postgres cannot directly read data from hard disk.
   Postgres pull that **heap file** (a file which contains all data regarding that table)into memory and finds that values record by record. This operation is expensive as loading a ton of info from hdd to memory and execute somekind of filtering.

   A full table scan is a low performance query

2. ### Solution INDEXING.

   Simply a tool which tells where a particular record is at.
   It helps avoiding fetching unnecessary datya fetching and filtering
   An Index is a data structure that can efficiently tell at which block and index a record is stored.

3. ### How index works

   2. Get some specific,unq peices of data
   3. Sort the data in a meaningful way.
   4. Organize that data into a tree like structure
   5. Add heplers to the root node.
   6.

4. ### Create an INDEX

   ```sql
   CREATE INDEX ON users (username);
   CREATE INDEX indexname ON users (username);
   DROP INDEX indexname;
   DROP INDEX users_username_idx;

   ```

5. ### BENCHMARKING
   ```sql
   EXPLAIN ANALYZE SELECT *
   FROM users WHERE username='Emily30';
   ```
6. ### DOWNSIDE OF INDEXES

   ```sql
   SELECT pg_size_pretty(pg_relation_size('users'));
   -- Tells about size of that table
   SELECT pg_size_pretty(pg_relation_size('users_username_idx'))
   ```

   1. Size is more.
   2. Slows down insert/update/delete - becz the index has to updated.

7. ### TYPES OF INDEXES

   ![Types of Indexes](./TypesOfIndexes.png)

8. By default Postygres creates index
   if a table has
   1. primary key
   2. unique constraint
   ```sql
      SELECT relname,relking FROM pg_class
      WHERE relkind = 'i';
   ```
9. ### How indexes are stored in HD
   1. A File is created and stored on HD.
   2. Structure of file is same as HEAP file
   3. Contains a block for meta block.
   4. Contains a block for Root block .
   5. Contains a block for leaf block .

## Query Tuning

1. ### What happens when you execute a query

   1. Query Goes thorugh different steps

      1. Parser (Undertanding meaning of the query, syntax checking)
         - Builds a query tree. It references
      2. Rewriter
         - Understands the query and excutes some parts of the query efficienlty
      3. Planner
         - Takes a look at query tree and builds the data by trying out some plans on how to efficienlty execute a query based on time required to execute a query (Where to use indexes etc ...)
      4. Executer
         - This execute the query which was palnned by planner

   2. ### Planner stage
      1. ### Explain
         - Build a query plan and display info about it.
      2. ### Explain Analyze
         - Build a query plan, run it and info about it
      3. These are used only for benchmarking and evaluating queries, cannot be used for real time data fetching.
   3. ### Metrics
      1.

## Common table expression

- Makes query easier to read

```sql

  WITH tags AS
  (SELECT user_id, created_at FROM caption_tags
  UNION ALL
  SELECT user_id, created_at FROM photo_tags)

   SELECT username, tags.created_at
   FROM users
   JOIN tags ON tags.user_id = users.id
   WHERE tags.created_at < '2010-01-07';
```
