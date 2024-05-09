package Questao1;

public abstract class Calculadora {
    public double soma(double a, double b) {
        return a + b;
    }

    public double subtracao(double a, double b) {
        return a - b;
    }

    public double multiplicacao(double a, double b) {
        return a * b;
    }

    public double divisao(double a, double b) {
        verificaDivisor(b);
        return a / b;
    }

    private void verificaDivisor(double b) {
        if (b == 0) {
            throw new IllegalArgumentException("Divisor não pode ser zero");
        }
    }
}