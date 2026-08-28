# Write your MySQL query statement below
-- select machine_id, 
-- from Activity
-- group by machine_id, process_id
-- -- group by process_id, machine_id
-- ;

select a.machine_id,
--  a.timestamp, c.timestamp,
ROUND(AVG(c.timestamp - a.timestamp), 3) as processing_time
from Activity a
inner join Activity c
on a.machine_id = c.machine_id and a.process_id = c.process_id
-- on a.machine_id = c.machine_id 
and a.activity_type = 'start' and c.activity_type = 'end'
group by machine_id
;