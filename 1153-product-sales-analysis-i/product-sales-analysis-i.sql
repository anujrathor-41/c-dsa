# Write your MySQL query statement below
select product_name,year,price from Product right join Sales 
on Product.product_id=Sales.product_id; 