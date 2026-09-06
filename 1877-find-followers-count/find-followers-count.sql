# Write your MySQL query statement below
SELECT u.user_id, COUNT(*) AS followers_count
FROM Followers u
GROUP BY u.user_id
ORDER BY user_id ASC