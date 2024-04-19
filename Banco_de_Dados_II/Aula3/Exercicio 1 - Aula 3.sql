/*01 - Construa a consulta que recupere do banco de dados a seguinte RelVar:

Curso [crs_descricao)
Séries (ansr_descricao]
Turma (tmansr_divisao]
Ano letivo (ano_letivo]

As entidades a serem utilizadas são:
- adm_curso (que recebe os dados dos curso oferecidos pela instituição)
- adm_anoserie (as séries de cada curso)
- adm_turmaanoserie (as divisões, das séries, por exemplo: Turma A, Turma B,...)
R: A consulta retomou 337 tuplas.*/

SELECT cr.crs_descricao, asr.ansr_descricao, tas.ano_letivo, tas.trmansr_divisao FROM adm_curso AS cr

INNER JOIN adm_anoserie asr ON cr.crs_codigo = asr.crs_codigo
INNER JOIN adm_turmaanoserie tas ON asr.ansr_codigo = tas.ansr_codigo