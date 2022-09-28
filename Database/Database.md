# Overview

> Database is used to store information , data is either persisted in memory / files and retrive data whenever required

## Data base design (List of large cities)

> Process of designing a db

1. What kind of thing are we storing?

   > List of **CITIES**

   > This will be a table ( a collection of records)

2. What properties does thing we have?

   > each city will have country ,cityname population and area

   > Propties are used to create columns in the table

3. What type of data does each of those properties have ?

   > city name and country name will be string

   > population and area will be integer
   > Each column will store a very specific data of a specific data type

## Creating a table

- `CREATE TABLE cities(name VARCHAR(50),country VARCHAR(50) population INTEGER, area INTEGER);`

- **CREATE TABLE** is **_keyword_** and keywords should always be **CAPITALIZED**

- **cities** is a **identifiers** and identifiers can be both lower and uppercase

## Insert Data into Table

> To insert into a table list out all the coolums you want add and the way you add data into column shoud be in the same order of the table colum order

- `INSERT INTO cities(name,country,population,area)`
  `VALUES('TOKYO','JAPAN',555555555555,7848525);`

- `INSERT INTO cities(name,population,country,area)`
  `VALUES('TOKYO','JAPAN',555555555555,7848525);`
- Population will be JAPAN
- **_ORDER IS IMPORANT_**

### INSERT Multiple rows in a sigle Query

- `INSERT INTO cities (name, country,population,area)`
  `VALUES ("INDIA","DELHI",4541522482,544444),`
  `VALUES ("SHANGHAI","CHAINA",24154114,54454);`

## Retrieve data from Table

- `SELECT * FROM table`

  `SELECT column names in anyorder seperated with comma FROM table`

## Process data before we can retrieve data

- Population density=population/area
- `SELECT name, population/density FROM cities`
- population/density will create a imaginary column in the db's
- Integer range 2.14Billion

## CREATE a imaginary column

- `SELECT name, population/ density AS peoplepersqkm FROM cities`

## Operations on STRINGS

1. CONCAT()
2. LENGTH()
3. UPPER()
4. LOWER()

## FILTER records

### WHERE

- `SELECT name, area FROM cities HWERE area>4000`
- TO understand what happends when this query hits db engine
  it divides the query int o parts and executes them ina order

  like this

  1.  FROM cities
  2.  WHERE area > 4000
  3.  SELECT name, area

### Comparison operators used with WHERE

- **SQL fact** comparison is done for evry row

1. = _are values equal_
2. `>` _is value of the left greater_
3. < _is value on the left lesser_
4. =>
5. IN _Is value present in the list_
6. <=
7. <> _are the values not equal_
8. != _same as above_
9. BETWEEN _range_ ex(`area BETWEEN 2000 AND 4000`)
10. NOT IN _is the not present in the list_

- EX: `SELECT * FROM cities WHERE area BETWEEN 2000 AND 8000`
- EX: `SELECT * FROM cities WHERE name IN ('DELHI','TOKYO')` Here we are saying is give me every record where name in record includes any on the names listed in IN
  EX: `SELECT * FROM cities WHERE name NOT IN ('DELHI','TOKYO')` Here we are saying is give me every record where name in record dosent include any of the names listed in IN

### MULTIPLE COMPARISON

> To do a multiple comparison we use the AND operator and the OR operator

- EX `SELECT * FROM cities WHERE are NOT IN(1200,8000) AND name!='DELHI`. Here we saying give me all the records where area is not 1200 and area is not 8000 and the name in that record should not be delhi

- EX `SELECT * FROM cities WHERE are NOT IN(1200,8000) OR name='DELHI`. Here we saying give me all the records where area is not 1200 and area is not 8000 or the name in that record should be delhi

- `SELECT name, manufacturer FROM phones WHERE manufacturer= 'Apple' OR manufacturer='Samsung'`
- `SELECT name, manufacturer FROM phones WHERE manufacturer IN ('Apple','Samsung')`

## UPDATING Records

- `UPDATE cities SET population=100 WHERE name='Tokyo';`

> SET will update the column value with the assigned value
