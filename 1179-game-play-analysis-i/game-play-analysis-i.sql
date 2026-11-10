# Write your MySQL query statement below
SELECT player_id, MIN(event_date) AS first_login
FROM Activity AS t1
GROUP BY t1.player_id
ORDER BY t1.event_date ASC;