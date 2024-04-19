package Disciplinas_UFJ.Programação_Orientada_a_Objetos.Aula2;

public class Principal {

    public static void main(String[] args) {
        Retangulo r1 = new Retangulo(10, 5);
        Retangulo r2 = new Retangulo(20, 2);
        
        //r1.baseRetangulo = 5;  // exemplo de valor
        //r1.alturaRetangulo = 10;  // exemplo de valor
        
        System.out.println("A área do retângulo é: " + r1.calculaArea());
        System.out.println("A área do retângulo é: " + r2.calculaArea());
    }
}
