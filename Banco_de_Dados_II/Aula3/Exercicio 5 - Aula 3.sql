/*05 – Modifique o SQL da questão 4, para listar somente os valores que estejam ativos. O atributo mnslvlr_status
identifica o status da mensalidade, sendo: 0 (zero) são as inativas e 1 (um) as ativas.*/

SELECT 
    c.crs_descricao AS 'Curso', 
    a.ansr_descricao AS 'Ano Série', 
    mv.mnslvlr_valorintegral AS 'Valor da Mensalidade'
FROM 
    adm_curso AS c
INNER JOIN 
    adm_anoserie AS a ON c.crs_codigo = a.crs_codigo
INNER JOIN 
    tes_mensalidadevalor AS mv ON a.ansr_codigo = mv.ansr_codigo
WHERE 
    mv.mnslvlr_status = 1
