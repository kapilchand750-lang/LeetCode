# Write your MySQL query statement below
-- with cs as (
--     select min(id) as min_id
--     from Person
--     group by email
-- )
-- delete from Person
-- where id not in (
--     select min_id from cs
-- );


-- delete from Person
-- where id in (
--     select p.id 
--     from Person as p
--     inner join Person d
--     on p.id > d.id and p.email = d.email
-- );


delete p
from Person p
inner join Person d
on p.id > d.id
and p.email = d.email;