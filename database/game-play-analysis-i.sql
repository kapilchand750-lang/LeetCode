# Write your MySQL query statement below
select player_id, event_date as first_login
from Activity
group by player_id
having min(event_date);
