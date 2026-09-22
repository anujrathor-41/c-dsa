# Write your MySQL query statement below
-- select query_name, round(avg(rating/position),2) as quality,
-- round(sum(rating<3) *100/count(*),2) as poor_query_percentage
-- from Queries
-- group by query_name



-- select query_name, round(avg(rating/position),2) as quality,
-- round(SUM(
--     CASE 
--         WHEN rating < 3 THEN 1
--         ELSE 0
--     END
-- ) *100/count(*),2) as poor_query_percentage
-- from Queries
-- group by query_name



select query_name, round(avg(rating/position),2) as quality,
round(SUM(IF(rating < 3, 1, 0)) *100/count(*),2) as poor_query_percentage
from Queries
group by query_name