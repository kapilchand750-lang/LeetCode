select ifnull((select distinct salary
from Employee
order by salary DESC
limit 1, 1), NULL) as SecondHighestSalary
;