package Gabriel_Lincoln_Questao8;

public class Main {
    public static void main(String[] args) {
        Pais brasil = new Pais("Brasil", "Brasília", 8515767);
        Pais argentina = new Pais("Argentina", "Buenos Aires", 2780400);
        Pais uruguai = new Pais("Uruguai", "Montevidéu", 176215);

        brasil.addFronteira(argentina);
        brasil.addFronteira(uruguai);
        argentina.addFronteira(uruguai);

        System.out.println("Países que fazem fronteira com o Brasil: " + brasil.getFronteiras().size());
        System.out.println("Países que fazem fronteira com a Argentina: " + argentina.getFronteiras().size());
        System.out.println("Países que fazem fronteira com o Uruguai: " + uruguai.getFronteiras().size());

        System.out.println("Vizinhos comuns entre Brasil e Argentina: " + brasil.vizinhosComuns(argentina).size());
        System.out.println("Vizinhos comuns entre Brasil e Uruguai: " + brasil.vizinhosComuns(uruguai).size());
    }
}