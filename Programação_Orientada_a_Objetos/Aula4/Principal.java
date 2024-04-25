package Programação_Orientada_a_Objetos.Aula4;

public class Principal {
    public static void main(String[] args) {

        Triangulo triangulo = new Triangulo(10, 5);

        System.out.println("A área do triângulo é: " + triangulo.calcularArea());
        
        Triangulo triangulo2 = new Triangulo();

        System.out.println(triangulo2);
        
        Triangulo triangulo3 = new Triangulo(20, 10);

        System.out.println("A área do triângulo é: " + triangulo3.calcularArea());
    }
}
