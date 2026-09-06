# Write your MySQL query statement below
SELECT c.class
FROM Courses c
GROUP BY c.class
HAVING(
    COUNT(DISTINCT c.student) >= 5
)