package Gabriel_Lincoln_Questao8;

import java.util.*;

class Pais {
    private String nome;
    private String capital;
    private double dimensao;
    private Set<Pais> fronteiras;

    public Pais(String nome, String capital, double dimensao) {
        if (nome == null || nome.isEmpty() || capital == null || capital.isEmpty()) {
            throw new IllegalArgumentException("Nome e capital não podem ser nulos ou vazios");
        }
        this.nome = nome;
        this.capital = capital;
        this.dimensao = dimensao;
        this.fronteiras = new HashSet<>();
    }

    public String getNome() {
        return nome;
    }

    public String getCapital() {
        return capital;
    }

    public double getDimensao() {
        return dimensao;
    }

    public Set<Pais> getFronteiras() {
        return new HashSet<>(fronteiras);
    }

    public void addFronteira(Pais pais) {
        if (pais != this && !fronteiras.contains(pais)) {
            fronteiras.add(pais);
            if (!pais.getFronteiras().contains(this)) {
                pais.addFronteira(this);
            }
        }
    }

    public boolean equals(final Pais outro) {
        return this.nome.equals(outro.nome) && this.capital.equals(outro.capital);
    }

    public Set<Pais> vizinhosComuns(Pais outro) {
        Set<Pais> comuns = new HashSet<>(this.fronteiras);
        comuns.retainAll(outro.getFronteiras());
        return comuns;
    }

    @Override
    public String toString() {
        return "País: " + nome + ", Capital: " + capital + ", Dimensão: " + dimensao + " Km²";
    }
}