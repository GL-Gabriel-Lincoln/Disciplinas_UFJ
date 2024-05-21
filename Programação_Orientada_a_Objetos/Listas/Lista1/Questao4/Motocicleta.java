package Questao4;

public class Motocicleta extends Veiculo {
    private String tipoDeCapacete;

    public Motocicleta(String cor, double potencia, int anoDeFabricacao, double valor, String tipoDeCapacete) {
        super(cor, potencia, anoDeFabricacao, valor);
        this.tipoDeCapacete = tipoDeCapacete;
    }

    public String getTipoDeCapacete() {
        return tipoDeCapacete;
    }

    public void setTipoDeCapacete(String tipoDeCapacete) {
        this.tipoDeCapacete = tipoDeCapacete;
    }
}
