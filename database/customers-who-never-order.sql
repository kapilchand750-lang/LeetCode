# Write your MySQL query statement below
select name as Customers
from Customers as c
where not exists (
    select id 
    from Orders as o
    where c.id = o.customerId
);