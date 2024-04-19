/*02 – Altere a consulta da questão número 1, para retornar somente os cursos que tiveram turmas no ano
[ano_letivo] de 2005.*/

SELECT cr.crs_descricao, asr.ansr_descricao, tas.ano_letivo, tas.trmansr_divisao FROM adm_curso AS cr

INNER JOIN adm_anoserie asr ON cr.crs_codigo = asr.crs_codigo
INNER JOIN adm_turmaanoserie tas ON asr.ansr_codigo = tas.ansr_codigo
WHERE tas.ano_letivo LIKE "2005"