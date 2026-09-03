# Write your MySQL query statement below
select query_name,
Round(SUM(rating/position)/COUNT(*), 2) as quality,
ROUND(SUM(
    CASE 
    when rating < 3 then 1
    else 0
    END
)/COUNT(*)*100, 2) as poor_query_percentage
from Queries
group by query_name;
