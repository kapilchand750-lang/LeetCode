# Write your MySQL query statement below
select w.id
from Weather as w
left join Weather as k
on datediff(w.recordDate, k.recordDate) = 1
where 
 k.temperature < w.temperature;
