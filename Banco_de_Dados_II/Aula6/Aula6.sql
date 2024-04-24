/*USE sakila

1) SELECT * FROM pais p

INNER JOIN estado e ON p.pais_id = e.pais_id

2) SELECT * FROM pais p

INNER JOIN estado e ON p.pais_id = e.pais_id

GROUP BY p.pais_id

3) SELECT
p.nome, 
COUNT(e.estado_id) AS QuantidadeEstado 
FROM pais p

INNER JOIN estado e ON p.pais_id = e.pais_id

GROUP BY p.pais_id

4) SELECT
p.nome, 
COUNT(e.estado_id) AS QuantidadeEstado 
FROM pais p

INNER JOIN estado e ON p.pais_id = e.pais_id

GROUP BY p.pais_id

ORDER BY QuantidadeEstado DESC

5) SELECT
p.nome
FROM pais p

LEFT OUTER JOIN estado e ON p.pais_id = e.pais_id

WHERE e.pais_id IS NULL

6) SELECT
p.*
FROM pessoa p
LEFT OUTER JOIN endereco e ON p.endereco_id = e.endereco_id
WHERE e.endereco_id IS NULL
GROUP BY p.endereco_id*/





