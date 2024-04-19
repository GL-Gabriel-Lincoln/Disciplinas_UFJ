/*04 – Crie o SQL que retorne a RelVar com as seguintes colunas:

Curso [crs_descricao], Ano Série [ansr_descricao], Valor da Mensalidade [mnslvlr_valorintegral]

As entidades envolvidas na consulta são: adm_curso, adm_anoserie e tes_mensalidadevalor.

*/

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