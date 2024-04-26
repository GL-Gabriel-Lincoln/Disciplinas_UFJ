SELECT GET_LOCK(CONCAT('pagamento', 1), 10);

UPDATE pagamento SET valorPagamento = 2.99 WHERE pagamento_ID = 1;

SELECT RELEASE_LOCK(CONCAT('pagamento', 1));

#SELECT IS_USED_LOCK(CONCAT('pagamento', 1));

#SELECT CONNECTION_ID();
