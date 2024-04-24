package Programação_Orientada_a_Objetos.Aula3;

public class Circunferencia {

    private double raio;

    Circunferencia() {

    }

    Circunferencia(double raio) {
        this.raio = raio;
    }

    public double getRaioCircunferencia() {
        return this.raio;
    }

    public void setRaioCircunferencias(double raio) {
        this.raio = raio;
    }

    double areaCircuferencia() {
        return Math.PI * Math.pow(raio, 2);
    }
}