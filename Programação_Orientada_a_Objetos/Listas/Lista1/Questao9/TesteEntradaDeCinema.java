package Questao9;

import java.time.LocalDate;
import java.time.LocalTime;

public class TesteEntradaDeCinema {
    public static void main(String[] args) {

        EntradaDeCinema entrada = new EntradaDeCinema(LocalDate.of(2024, 5, 20), LocalTime.of(15, 30), "Sala 1", 50.0);

        System.out.println(entrada.toString());

        double desconto = entrada.calculaDesconto(LocalDate.of(2010, 1, 1));
        System.out.println("Desconto para menor de 12 anos: " + desconto);

        desconto = entrada.calculaDesconto(LocalDate.of(2005, 1, 1), 12345);
        System.out.println("Desconto para estudante de 12 a 15 anos: " + desconto);

        desconto = entrada.calculaDescontoHorario();
        System.out.println("Desconto para horário antes das 16h: " + desconto);
    }
}