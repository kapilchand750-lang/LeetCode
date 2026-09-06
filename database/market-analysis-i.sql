# Write your MySQL query statement below
select o.buyer_id, u.join_date,
SUM(
    CASE
    when YEAR(order_date) = 2019 then 1
    else 0
    END
) as orders_in_2019
from Users u
left join Orders o
on u.user_id = o.buyer_id
group by u.user_id
;