# Write your MySQL query statement below
# select name as Customers from customers where name not in 
# (
# select name from customers as c inner join orders as o  on o.customerId=c.id
# ) 

select c.name as Customers from customers as c where c.id not in (select o.customerid from orders as o); 
 