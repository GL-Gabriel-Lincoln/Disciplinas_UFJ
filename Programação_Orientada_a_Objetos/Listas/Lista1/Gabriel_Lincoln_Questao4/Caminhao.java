package Gabriel_Lincoln_Questao4;

public class Caminhao extends Veiculo {
    private double capacidadeDeCarga;

    public Caminhao(String cor, double potencia, int anoDeFabricacao, double valor, double capacidadeDeCarga) {
        super(cor, potencia, anoDeFabricacao, valor);
        this.capacidadeDeCarga = capacidadeDeCarga;
    }

    public double getCapacidadeDeCarga() {
        return capacidadeDeCarga;
    }

    public void setCapacidadeDeCarga(double capacidadeDeCarga) {
        this.capacidadeDeCarga = capacidadeDeCarga;
    }
}
