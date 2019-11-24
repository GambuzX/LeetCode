# Write your MySQL query statement below
SELECT Id
FROM Weather W1
WHERE W1.Temperature > (SELECT W2.Temperature
                        FROM Weather W2
                        WHERE DATEDIFF(W1.RecordDate, W2.RecordDate) = 1);