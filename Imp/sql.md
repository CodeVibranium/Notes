1.a. select _ from users where date_joined >= '2023-01-20';
1.b. select _ from products where price > 500;
1.c. select count(distinct user*id) from orders;
2.a select * from products order by stock*quantity desc limit 1;
2.b select avg(price) from products;
2.c select count(*) from orders where date*ordered between '2023-02-01' and '2023-02-28';
3.a select users.username from products join orderdetails on orderdetails.product_id = products.product_id join orders on orders.order_id = orderdetails.order_id join users on orders.user_id = users.user_id where products.product_name='Laptop Pro';
3.b select * from (select \_ from users where users.username = 'Alice') as alice join orders on orders.user_id = alice.user_id join orderdetails on orderdetails.order_id = orders.order_id join products on products.product_id not in (select product_id from products);
3.c select users.username ,count(\*) as total_orders from orders join users on orders.user_id = users.user_id group by orders.user_id,users.username order by total_orders desc limit 3;
4.a

categories
category_id | name

products
product_id | product_name | category_id

orders
order_id | order_date | product_id

retieve product name and the total number of orders for each product in the "Electronics" category.

select max(product_name), sum (orders.order_id) from products left join orders on products.product_id = orders.product_id inner join categories on products.category_id = categories.category_id group by product_id, categories.name having categories.name ="Electronics" ;

product_id | product_name | category_id | order_id | order_date | product_id | category_id | name |

orders

order_id | user_id | date_ordered
----------+---------+--------------

orderdetails

orderdetail_id | order_id | product_id | quantity_ordered
----------------+----------+------------+------------------

products
product_id | product_name | price | stock_quantity |
------------+-------------------------+---------+----------------

user_id | username | email | date_joined
---------+----------+-------------------+-------------

**For every order, compute the total cost (i.e., sum of quantity_ordered \* product price for each product in that order).**

select orders.order_id ,sum(quantity_ordered)\* sum(products.price) as total_cost_per_order from orders join orderdetails on orderdetails.order_id = orders.order_id join products on products.product_id = orderdetails.product_id group by orders.order_id order by total_cost_per_order desc ;

**Identify the day with the highest sales (total cost).**

select

. Identify products that have been ordered more than 3 times.

select product*name from products where product_id in (select product_id as total_orders from orderdetails group by product_id having count(*)>3 );
select avg(order_id) from orders group by user_id;
select product_name, sum(orderdetails.quantity_ordered)\*orderdetails.quantity_ordered as total_cost from orderdetails join products on products.product_id = orderdetails.product_id group by orderdetails.order_id,product_name,orderdetails.quantity_ordered;

. Identify the day with the highest sales (total cost).
select date_ordered from orderdetails join orders on orders.order_id = orderdetails.order_id join products on products.product_id = orderdetails.product_id group by date_ordered ;

Show products that have been ordered by at least 3 different users.
