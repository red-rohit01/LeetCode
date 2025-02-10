# Write your MySQL query statement below
SELECT
    p.product_id,
    IFNULL(ROUND(SUM(p.price * u.units) / SUM(u.units), 2), 0) AS average_price
FROM
    Prices AS p
LEFT JOIN
    UnitsSold AS u
ON
    p.product_id = u.product_id
    AND u.purchase_date BETWEEN p.start_date AND p.end_date
GROUP BY
    p.product_id;

# Since we are grouping by product_id the intermediate table would look something like this:
-- p.product_id	p.price	p.start_date	p.end_date	u.units	u.purchase_date
-- 1	5	2019-02-17 | 2019-02-28	100	2019-02-25
-- 1	20	2019-03-01 | 2019-03-22	15	2019-03-01
-- 2	15	2019-02-01 | 2019-02-20	200	2019-02-10
-- 2	30	2019-02-21 | 2019-03-31	30	2019-03-22 

# If there would have been some other value with no units sold then:
-- 3	30	2019-02-21 | 2019-03-31	NULL NULL 

