INSERT INTO pessoa (pessoa_id,tipo,primeironome,segundonome,email,
							telefone,endereco_id,numeroendereco,ativo,datacadastro,
							ultimaatualizacao,foto)
VALUES (NULL,'1','GL','Gabriel Lincoln','flavio@ufj.edu.br',
			'64993248867',54,'1281','1',NOW(),NOW(),NULL);
			
SELECT * FROM pessoa WHERE primeironome LIKE 'GL';

SELECT * FROM pessoalogin;

SELECT * FROM cidade;

DELIMITER $$
CREATE TRIGGER criaLoginPessoa AFTER INSERT ON pessoa
FOR EACH ROW
BEGIN

INSERT INTO pessoalogin (pessoa_id,login,senha,datacriacao) values
(NEW.pessoa_id, NEW.email, CONCAT(NEW.segundonome,'248'), NOW());

END $$ 
DELIMITER;						
