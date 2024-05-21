package Gabriel_Lincoln_Questao6;

public class CadernoDeEnderecos {
    private String nome;
    private String telefone;
    private String email;
    private String dataDeAniversario;
    private String endereco;

    public CadernoDeEnderecos(String nome, String telefone, String email, String dataDeAniversario, String endereco) {
        this.nome = nome;
        this.telefone = telefone;
        this.email = email;
        this.dataDeAniversario = dataDeAniversario;
        this.endereco = endereco;
    }

    public String getNome() {
        return nome;
    }

    public String getTelefone() {
        return telefone;
    }

    public String getEmail() {
        return email;
    }

    public String getDataDeAniversario() {
        return dataDeAniversario;
    }

    public String getEndereco() {
        return endereco;
    }
}