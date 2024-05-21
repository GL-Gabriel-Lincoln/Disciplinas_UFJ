package Gabriel_Lincoln_Questao7;

enum TipoMovimentacao {
    CREDITO, DEBITO
}

class Movimentacao {
    String descricao;
    double valor;
    TipoMovimentacao tipo;

    public Movimentacao(String descricao, double valor, TipoMovimentacao tipo) {
        this.descricao = descricao;
        this.valor = valor;
        this.tipo = tipo;
    }
}