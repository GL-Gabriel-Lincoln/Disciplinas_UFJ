package Questao6;

public class TesteCadernoDeEnderecos {
    public static void main(String[] args) {
        CadernoDeEnderecos caderno = new CadernoDeEnderecos("João", "123456789", "joao@email.com", "01/01/2000", "Rua 123, Cidade, Estado");

        System.out.println(caderno.getNome());
        System.out.println(caderno.getTelefone());
        System.out.println(caderno.getEmail());
        System.out.println(caderno.getDataDeAniversario());
        System.out.println(caderno.getEndereco());
    }
}