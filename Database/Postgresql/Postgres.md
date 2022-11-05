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
