/*USE ufj_escolar

SELECT * FROM sis_usuario

#01) Há usuarios sem grupos de permissões

SELECT * FROM sis_usuario usr

LEFT OUTER JOIN sis_usuariogrupo usrg
	ON usr.usr_codigo = usrg.usr_codigo
WHERE usrg.usr_codigo IS NULL

#02) Mostra a lista dos usuarios com seus grupos de permissao (onde o grupo for nulo, escrever"sem grupo" e a Lista de nomes deve estar em ordem alfabética)

DROP VIEW usuarioGrupo;
CREATE VIEW usuarioGrupo AS
SELECT 
usr_nome AS nomeUsuario,
if(gp.grp_nome IS NULL, "Sem Grupo", gp.grp_nome) AS grupoPermissao,
u.usr_login AS login
FROM sis_usuario u
LEFT OUTER JOIN sis_usuariogrupo ug
	ON u.usr_codigo = ug.usr_codigo
LEFT OUTER JOIN sis_grupopermissao gp
	ON ug.grp_codigo = gp.grp_codigo
ORDER BY u.usr_nome ASC
*/




