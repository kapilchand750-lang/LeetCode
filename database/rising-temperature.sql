# Write your MySQL query statement below
select w.id
from Weather as w
left join Weather as k
on w.id > k.id or w.id < k.id
where 
datediff(w.recordDate, k.recordDate) = 1 and
 k.temperature < w.temperature;
