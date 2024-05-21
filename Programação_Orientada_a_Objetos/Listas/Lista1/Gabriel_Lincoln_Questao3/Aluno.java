package Gabriel_Lincoln_Questao3;

public class Aluno extends Pessoa {
    private String curso;
    private Disciplina[] disciplinas;

    public Aluno(String cpf, String nome, int idade, String curso, Disciplina[] disciplinas) {
        super(cpf, nome, idade);
        this.curso = curso;
        this.disciplinas = disciplinas;
    }

    public String getCurso() {
        return curso;
    }

    public void setCurso(String curso) {
        this.curso = curso;
    }

    public Disciplina[] getDisciplinas() {
        return disciplinas;
    }

    public void setDisciplinas(Disciplina[] disciplinas) {
        this.disciplinas = disciplinas;
    }
}