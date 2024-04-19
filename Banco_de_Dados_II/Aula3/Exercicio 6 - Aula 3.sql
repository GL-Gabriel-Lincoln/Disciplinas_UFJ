/*06 – Utilizando a RelVar construída na questão 4, acrescente as seguintes colunas:
Descrição do Diário [dr_descricao] Nome do discente [dsct_nome]
Para obter a lista das tuplas é necessário relacionar as seguintes novas entidades:
- Turmas das séries [adm_turmaanoserie]
- Diários [adm_diario]
- Matrículas das turmas [adm_matricula]
- Dados do discente [adm_discente]*/

SELECT 
    c.crs_descricao AS 'Curso', 
    a.ansr_descricao AS 'Ano Série', 
    mv.mnslvlr_valorintegral AS 'Valor da Mensalidade',
    d.dr_descricao AS 'Descrição do Diário',
    ds.pss_nome AS 'Nome do discente'
FROM 
    adm_curso AS c
INNER JOIN 
    adm_anoserie AS a ON c.crs_codigo = a.crs_codigo
INNER JOIN 
    tes_mensalidadevalor AS mv ON a.ansr_codigo = mv.ansr_codigo
INNER JOIN 
    adm_turmaanoserie AS ta ON a.ansr_codigo = ta.ansr_codigo
INNER JOIN 
    adm_diario AS d ON ta.trmansr_codigo = d.trmansr_codigo
INNER JOIN 
    adm_matricula AS m ON d.trmansr_codigo = m.pss_codigo
INNER JOIN 
    adm_pessoa AS ds ON m.pss_codigo = ds.pss_codigo
GROUP BY 
    ds.pss_codigo