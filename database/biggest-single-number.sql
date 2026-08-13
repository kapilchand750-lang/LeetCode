# Write your MySQL query statement below
select MAX(IFNULL(num, NULL)) as num
from MyNumbers
where num in (
    select num
    from MyNumbers
    group by num
    having Count(*) = 1
)
-- having MAX(num)
;