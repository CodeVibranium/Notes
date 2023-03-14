# Sub query

A subqery is a query where the first query is dependent on the output of second query.
A Sub query can be used with
**IMPORTANT**: A sub query used in a **FROM** clause there must be an alias attached to it.

1. select
2. from
3. where
4. join

# Sub queries in a SELECT statement.

- A subquery in a select statement must return a value with 1 row and 1 column
- a query which returns 1 row and 1 column is also called as scaler query.

```sql
select name, price , (select max(price) from products) as maxprice from products;

select name , price , (select price from products where id = 3) as id3price from products;
```

# Sub query in a FROM statement.

- A subquery in a from clause must return data in a wide variety of formats until the ouptut is compatible with the outer query.
- A from clause in general specifies a set a rows and column that will be used with the query.
- **IMP!** The result of a sub query must be compatible with the outer query. like columns in select, where, join etc.. , because the o/p of sub query is the table the query needs.

# Sub query inside a JOIN clause.

- any sub query can be placed until the o/p of the sub query nis compatible with the outer query.

# Sub query inside a WHERE clause.

- where is caluse is used to filter the rows
- the operator used with the WHERE clause infulences the type of data to be returned from sub query
- example
- ```sql
    select * from orders where product_id in (select id from orders where price/ weight > 50)
  ```
- if operator used

  1. > then return must be a single value
  2. < then return must be a single value
  3. > = then return must be a single value
  4. <= then return must be a single value
  5. = then return must be a single value
  6. IN then return must be a single column
  7. NOT IN then return must be a single column
  8. > ALL/SOME/ANY then return must be a single column.
  9. > = ALL/SOME/ANY then return must be a single column
  10. <= ALL/SOME/ANY then return must be a single column
  11. = ALL/SOME/ANY then return must be a single column

  ## ALL (must return a single column)

  - this `ALL` Checks for all the values
  - > ALL, < ALL
  - price > ALL
  - show everything where the products are more expensive than price of all products from the industrial dept.
  - what happens is a row is slected from outer query and is iterted by all the values in the inner query until condition is false || or till end of values.

  ## SOME or ANY (must return a single column)

  - **IMP** some is an alias for any
  - it checks if any one value from inner query satisfies the condition
  - 50> price || 50 > (20,40,100) = true
  - wnat happens is a singke iterarting row from outer goes in to innere quey and check if the condition is true for any one of the values present in the inner query if condition is true it is added in the o/p else it is removed.

## Greatest

- ex: cost to ship
- ```sql
  select name, weight, GREATEST(30,2*wieght) from products;
  ```
- if the 2\*wieght is not > the 30 the value will be replaced by 30

## LEAST

- price is the least of products price \* 0.5 or 500;
- ```sql
   select name, weight, LEAST(500,price*0.5) from products;
  ```
