package Questao3;

public class Disciplina {
    private String nomeDaDisciplina;
    private String codigoDaDisciplina;
    private String professor;

    public Disciplina(String nomeDaDisciplina, String codigoDaDisciplina, String professor) {
        this.nomeDaDisciplina = nomeDaDisciplina;
        this.codigoDaDisciplina = codigoDaDisciplina;
        this.professor = professor;
    }

    public String getNomeDaDisciplina() {
        return nomeDaDisciplina;
    }

    public String getCodigoDaDisciplina() {
        return codigoDaDisciplina;
    }

    public String getProfessor() {
        return professor;
    }

    public void setNomeDaDisciplina(String nomeDaDisciplina) {
        this.nomeDaDisciplina = nomeDaDisciplina;
    }

    public void setCodigoDaDisciplina(String codigoDaDisciplina) {
        this.codigoDaDisciplina = codigoDaDisciplina;
    }

    public void setProfessor(String professor) {
        this.professor = professor;
    }
}