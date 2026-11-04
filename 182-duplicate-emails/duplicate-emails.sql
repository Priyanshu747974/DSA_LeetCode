# Write your MySQL query statement below
SELECT  t1.email as Email
FROM Person as t1
GROUP BY email
HAVING COUNT(email)>1;
