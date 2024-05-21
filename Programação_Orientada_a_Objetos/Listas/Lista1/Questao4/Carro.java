package Questao4;

public class Carro extends Veiculo {
    private int numeroDePortas;

    public Carro(String cor, double potencia, int anoDeFabricacao, double valor, int numeroDePortas) {
        super(cor, potencia, anoDeFabricacao, valor);
        this.numeroDePortas = numeroDePortas;
    }

    public int getNumeroDePortas() {
        return numeroDePortas;
    }

    public void setNumeroDePortas(int numeroDePortas) {
        this.numeroDePortas = numeroDePortas;
    }
}
