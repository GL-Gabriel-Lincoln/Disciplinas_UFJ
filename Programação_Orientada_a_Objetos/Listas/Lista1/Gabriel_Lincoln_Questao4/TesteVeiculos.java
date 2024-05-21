package Gabriel_Lincoln_Questao4;

public class TesteVeiculos {
    public static void main(String[] args) {
        Motocicleta minhaMoto = new Motocicleta("Vermelho", 100.0, 2020, 15000.0, "Integral");
        Carro meuCarro = new Carro("Azul", 150.0, 2019, 30000.0, 4);
        Caminhao meuCaminhao = new Caminhao("Branco", 200.0, 2018, 80000.0, 10000.0);

        System.out.println("Cor da minha moto: " + minhaMoto.getCor());
        System.out.println("Número de portas do meu carro: " + meuCarro.getNumeroDePortas());
        System.out.println("Capacidade de carga do meu caminhão: " + meuCaminhao.getCapacidadeDeCarga());
    }
}