/*03 – Descreva qual é a função do SLQ abaixo:*/

SELECT c.crs_descricao, a.ansr_descricao, ta.trmansr_divisao, ta.ano_letivo
FROM adm_curso AS c
INNER JOIN adm_anoserie AS a ON c.crs_codigo = a.crs_codigo
INNER JOIN adm_turmaanoserie AS ta ON a.ansr_codigo = ta.ansr_codigo
WHERE ta.ano_letivo = 2005 AND c.crs_descricao LIKE 'Ensino Médio';

/*Essa consulta SQL é utilizada para obter uma lista de descrições de cursos, anos/séries,
divisões de turmas/anos/séries e anos letivos, especificamente para o ano de 2005 e para
cursos descritos como ‘Ensino Médio’*/