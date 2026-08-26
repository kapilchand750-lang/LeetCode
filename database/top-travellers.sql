# Write your MySQL query statement below
select name, COALESCE(SUM(distance), 0) as travelled_distance
from Users u
left join Rides r
on u.id = r.user_id
group by name
order by travelled_distance DESC, name ASC;