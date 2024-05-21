package Gabriel_Lincoln_Questao7;

public class Main {
    public static void main(String[] args) {
        Banco banco = new Banco();

        banco.criarConta(123, true, 5000);
        banco.criarConta(456, false, 0);
        System.out.println("Contas criadas: 123 (especial) e 456 (não especial)");

        banco.deposito(123, 1000);
        System.out.println("Depósito de 1000 realizado na conta 123");

        banco.saque(456, 500);
        System.out.println("Tentativa de saque de 500 na conta 456");

        boolean transferenciaRealizada = banco.transferencia(123, 456, 200);
        if (transferenciaRealizada) {
            System.out.println("Transferência de 200 da conta 123 para a conta 456 realizada com sucesso");
        } else {
            System.out.println("Transferência de 200 da conta 123 para a conta 456 não realizada. Saldo insuficiente na conta de origem.");
        }
        
        banco.imprimirContas();
    }
}