# Write your MySQL query statement below
select customer_id,count(Visits.visit_id) as count_no_trans 
from Visits 
left join 
Transactions 
on Visits.visit_id= Transactions.visit_id
 where Transactions.transaction_id is null # without make any transaction
 group by customer_id     # number of time what means that is cutomer_id
 #customer id group ho gai -> 
--  is null ke baad we have -> 30,96,54,54
--  now group them kinko cutomer id ko