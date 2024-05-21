SELECT dr_descricao, count(mtrc_codigo) AS quantMatriculas FROM adm_diario
INNER JOIN adm_matricula ON adm_diario.trmansr_codigo = adm_matricula.trmansr_codigo
GROUP BY adm_diario.trmansr_codigo
ORDER BY quantMatriculas DESC;

/*Recupere a soma das matriculas [tes_BoletoResponsavel.BLTRSPS_VALORBRUTO]
totalizando por ano letivo*/

SELECT br.ano_letivo,
SUM(br.bltrsps_valorbruto) AS Faturamento
FROM tes_boletoresponsavel AS br
GROUP BY br.ano_letivo HAVING Faturamento < 1000000;

SELECT br.ano_letivo,
SUM(br.bltrsps_valorbruto) AS Faturamento
FROM tes_boletoresponsavel AS br
WHERE ano_letivo > 2004 
GROUP BY br.ano_letivo HAVING Faturamento > 1000000;

/*Gerar uma lista do total de materiais comercializados [tes.materialentradaitem] 
valor venda mostrar a descrição do material, diferentes de cotas, somentes os 
materiais para recibo [mtrdurs_pararecibo] = 1 retirar das listas totais*/