# Write your MySQL query statement below
SELECT mgr.employee_id as employee_id, mgr.name as name, COUNT(emp.employee_id) as reports_count, ROUND(AVG(emp.age)) as average_age
FROM employees emp JOIN employees mgr
ON emp.reports_to=mgr.employee_id
GROUP BY mgr.employee_id
ORDER BY mgr.employee_id


-- mgr.employee_id	mgr.name	emp.employee_id	emp.age	emp.reports_to
-- 101	Alice	201	30	101
-- 101	Alice	202	35	101
-- 102	Bob	203	40	102
-- 102	Bob	204	38	102
