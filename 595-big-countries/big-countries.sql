# Write your MySQL query statement below

#SELECT name, population, area
#FROM World
#WHERE area>=3000000 OR population >= 25000000;

SELECT name, population, area
FROM World
WHERE area >= 3000000

UNION

SELECT name, population, area
FROM World
WHERE population >= 25000000;

#Why use UNION instead of OR?
#Index Optimization: When indexes exist on area and population, using OR can sometimes force SQL engines to perform a full table scan.

#Independent Scans: Using UNION allows the database engine to perform two fast index lookups independently and combine the distinct results, which often performs better on large tables.