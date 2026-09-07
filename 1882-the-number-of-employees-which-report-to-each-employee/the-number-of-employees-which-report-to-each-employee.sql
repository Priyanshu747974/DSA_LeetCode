# Write your MySQL query statement below
SELECT 
    m.employee_id,
    m.name,
    r.reports_count,
    r.average_age
FROM (
    SELECT 
        reports_to AS employee_id,
        COUNT(*) AS reports_count,
        ROUND(AVG(age)) AS average_age
    FROM Employees
    WHERE reports_to IS NOT NULL
    GROUP BY reports_to
) r
JOIN Employees m 
    ON m.employee_id = r.employee_id
ORDER BY m.employee_id;