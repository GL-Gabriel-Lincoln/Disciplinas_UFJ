package Programação_Orientada_a_Objetos.Aula3;

public class Principal {
    public static void main(String[] args) {

        Circunferencia c1 = new Circunferencia(5);
        
        c1.setRaioCircunferencias(4);
        
        System.out.println("A área da circuferencia é: " + c1.getRaioCircunferencia());

        Circunferencia c2 = new Circunferencia(5);

        c2.setRaioCircunferencias(5);

        System.out.println("A área da circuferencia é: " + c2.getRaioCircunferencia());
    }
}
