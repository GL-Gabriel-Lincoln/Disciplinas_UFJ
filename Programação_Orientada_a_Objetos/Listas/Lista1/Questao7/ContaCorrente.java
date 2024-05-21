package Questao7;

import java.util.*;

class ContaCorrente {
    int numero;
    double saldo;
    boolean especial;
    double limite;
    List<Movimentacao> movimentacoes = new ArrayList<>();

    public ContaCorrente(int numero, boolean especial, double limite) {
        this.numero = numero;
        this.especial = especial;
        this.limite = limite;
    }

    void deposito(double valor) {
        if (valor > 0) {
            saldo += valor;
            movimentacoes.add(new Movimentacao("Deposito", valor, TipoMovimentacao.CREDITO));
        } else {
            System.out.println("Valor de depósito deve ser positivo.");
        }
    }

    boolean saque(double valor) {
        if (valor > 0 && valor <= saldo + (especial ? limite : 0)) {
            saldo -= valor;
            movimentacoes.add(new Movimentacao("Saque", valor, TipoMovimentacao.DEBITO));
            return true;
        } else {
            System.out.println("Valor de saque inválido ou saldo insuficiente.");
            return false;
        }
    }

    void imprimirSaldo() {
        System.out.println("Saldo: " + saldo);
    }

    void imprimirExtrato() {
        System.out.println("Extrato:");
        for (Movimentacao mov : movimentacoes) {
            System.out.println(mov.descricao + ": " + (mov.tipo == TipoMovimentacao.CREDITO ? "+" : "-") + mov.valor);
        }
    }
}