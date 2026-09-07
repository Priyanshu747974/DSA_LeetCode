# Write your MySQL query statement below
SELECT e.employee_id,
       e.department_id 
FROM Employee e
WHERE e.primary_flag = 'Y'
OR employee_id IN (
    SELECT employee_id
    FROM Employee
    GROUP BY employee_id
    HAVING COUNT(department_id) = 1
)