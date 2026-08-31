SELECT s.product_id, year AS first_year, quantity, price
FROM Sales s
JOIN (
    SELECT product_id, MIN(year) AS fy
    FROM Sales
    GROUP BY product_id
) f
ON s.product_id = f.product_id
AND s.year = f.fy;