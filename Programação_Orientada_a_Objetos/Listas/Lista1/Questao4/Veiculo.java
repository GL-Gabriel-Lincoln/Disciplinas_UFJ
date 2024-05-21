package Questao4;

public class Veiculo {
    private String cor;
    private double potencia;
    private int anoDeFabricacao;
    private double valor;

    public Veiculo(String cor, double potencia, int anoDeFabricacao, double valor) {
        this.cor = cor;
        this.potencia = potencia;
        this.anoDeFabricacao = anoDeFabricacao;
        this.valor = valor;
    }

    public String getCor() {
        return cor;
    }

    public void setCor(String cor) {
        this.cor = cor;
    }

    public double getPotencia() {
        return potencia;
    }

    public void setPotencia(double potencia) {
        this.potencia = potencia;
    }

    public int getAnoDeFabricacao() {
        return anoDeFabricacao;
    }

    public void setAnoDeFabricacao(int anoDeFabricacao) {
        this.anoDeFabricacao = anoDeFabricacao;
    }

    public double getValor() {
        return valor;
    }

    public void setValor(double valor) {
        this.valor = valor;
    }
}
