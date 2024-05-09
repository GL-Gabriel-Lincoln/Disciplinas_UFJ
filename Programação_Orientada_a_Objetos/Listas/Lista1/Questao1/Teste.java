package Questao1;

public class Teste {
    public static void main(String[] args) {
        CalculadoraCompleta calc = new CalculadoraCompleta();

        System.out.println("Soma: " + calc.soma(5, 3));
        System.out.println("Subtração: " + calc.subtracao(5, 3));
        System.out.println("Multiplicação: " + calc.multiplicacao(5, 3));
        System.out.println("Divisão: " + calc.divisao(5, 3));
        System.out.println("Raiz Quadrada: " + calc.raizQuadrada(9));
        System.out.println("Potência ao Quadrado: " + calc.potenciaAoQuadrado(5));
    }
}
