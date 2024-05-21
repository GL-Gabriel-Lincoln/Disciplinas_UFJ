package Gabriel_Lincoln_Questao7;

import java.util.*;

class Banco {
    Map<Integer, ContaCorrente> contas = new HashMap<>();

    void criarConta(int numero, boolean especial, double limite) {
        if (!contas.containsKey(numero)) {
            contas.put(numero, new ContaCorrente(numero, especial, limite));
        } else {
            System.out.println("Conta já existe.");
        }
    }

    ContaCorrente buscarConta(int numero) {
        return contas.get(numero);
    }

    boolean excluirConta(int numero) {
        if (contas.containsKey(numero)) {
            contas.remove(numero);
            return true;
        } else {
            return false;
        }
    }

    boolean transferencia(int numContaOrigem, int numContaDestino, double valor) {
        ContaCorrente contaOrigem = buscarConta(numContaOrigem);
        ContaCorrente contaDestino = buscarConta(numContaDestino);

        if (contaOrigem != null && contaDestino != null) {
            if (contaOrigem.saque(valor)) {
                contaDestino.deposito(valor);
                return true;
            }
        }
        return false;
    }

    void deposito(int numeroConta, double valor) {
        ContaCorrente conta = buscarConta(numeroConta);
        if (conta != null) {
            conta.deposito(valor);
        } else {
            System.out.println("Conta não encontrada.");
        }
    }

    void saque(int numeroConta, double valor) {
        ContaCorrente conta = buscarConta(numeroConta);
        if (conta != null) {
            conta.saque(valor);
        } else {
            System.out.println("Conta não encontrada.");
        }
    }

    void imprimirContas() {
        for (ContaCorrente conta : contas.values()) {
            System.out.println("Número da conta: " + conta.numero);
            conta.imprimirSaldo();
        }
    }
}