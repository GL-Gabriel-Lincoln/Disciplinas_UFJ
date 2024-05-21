package Questao9;

import java.time.LocalDate;
import java.time.LocalTime;
import java.time.Period;

public class EntradaDeCinema {
    private LocalDate dataDoFilme;
    private LocalTime horario;
    private String sala;
    private double valor;

    public EntradaDeCinema(LocalDate dataDoFilme, LocalTime horario, String sala, double valor) {
        this.dataDoFilme = dataDoFilme;
        this.horario = horario;
        this.sala = sala;
        this.valor = valor;
    }

    public double calculaDesconto(LocalDate dataNascimento) {
        int idade = Period.between(dataNascimento, LocalDate.now()).getYears();
        if (idade < 12) {
            return valor * 0.5;
        } else {
            return valor;
        }
    }

    public double calculaDesconto(LocalDate dataNascimento, int numeroCarteiraEstudante) {
        int idade = Period.between(dataNascimento, LocalDate.now()).getYears();
        if (idade >= 12 && idade <= 15) {
            return valor * 0.6;
        } else if (idade >= 16 && idade <= 20) {
            return valor * 0.7;
        } else if (idade > 20) {
            return valor * 0.8;
        } else {
            return valor;
        }
    }

    public double calculaDescontoHorario() {
        if (horario.isBefore(LocalTime.of(16, 0))) {
            return valor * 0.9;
        } else {
            return valor;
        }
    }

    @Override
    public String toString() {
        return "Data do Filme: " + dataDoFilme +
                "\nHorário: " + horario +
                "\nSala: " + sala +
                "\nValor: " + valor;
    }
}
