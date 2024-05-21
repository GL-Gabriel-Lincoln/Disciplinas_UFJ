SELECT
aluno.pss_nome AS aluno,
IFNULL(GROUP_CONCAT(
	if(pr.dsctrsps_parentesco = '1', 'Pai: ',
	if(pr.dsctrsps_parentesco = '2', 'Mãe: ', 'Outro: ')),
	responsavel.pss_nome), 'Sem Parentesco') AS  Responsavel,
	dr.dr_descricao
FROM adm_pessoa AS aluno
left outer JOIN adm_pessoaresponsavel AS pr ON
	aluno.pss_codigo = pr.pss_codigoDiscente
left outer JOIN adm_pessoa AS responsavel ON
	pr.pss_codigoResponsavel = responsavel.pss_codigo
INNER JOIN adm_matricula AS mt ON
	aluno.pss_codigo = mt.pss_codigo
INNER JOIN adm_diario AS dr ON 
	mt.trmansr_codigo = dr.trmansr_codigo
GROUP BY aluno.pss_nome, dr.dr_descricao;

SELECT * FROM parentescoAlunoMatriculado
WHERE responsavel LIKE '%'


	
