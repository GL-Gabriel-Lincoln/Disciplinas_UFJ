#include <stdio.h>

typedef struct ContaCorrente
{
    int numero_conta;
    char nome[50];
    float saldo;
} Tipo_ContaCorrente;

int quantidade_contas;
Tipo_ContaCorrente contas[100];

void iniciarConta(int i)
{
    printf("\nInforme o nome do cliente: ");
    scanf("%s", contas[i].nome);
    printf("\nInforme o número da conta: ");
    scanf("%d", &contas[i].numero_conta);
    printf("\nInforme o saldo inicial:");
    scanf("%f", &contas[i].saldo);
    printf("\nConta %d inicializada com sucesso!\n", contas[i].numero_conta);
}

void depositar(int i)
{
    float valor = 0.0;
    printf("\nO seu saldo atual é de %.2f. Digite o valor que deseja depositar: ", contas[i].saldo);
    scanf("%f", &valor);
    contas[i].saldo += valor;
}

void sacar(int i)
{
    float valor = 0.0;
    printf("\nO seu saldo atual é de %.2f. Digite o valor que deseja retirar: ", contas[i].saldo);
    scanf("%f", &valor);
    if (contas[i].saldo < valor)
    {
        printf("\nSaldo insuficiente!\n");
    }
    else
    {
        contas[i].saldo -= valor;
    }
}

void imprimirContas()
{
    for (int i = 0; i < quantidade_contas; i++)
    {
        printf("\nNome: %s\nNúmero da Conta: %d\nSaldo: %.2f\n", contas[i].nome, contas[i].numero_conta, contas[i].saldo);
    }
}

int main(void)
{
    printf("Informe a quantidade de contas que deseja criar: ");
    scanf("%d", &quantidade_contas);

    for (int i = 0; i < quantidade_contas; i++)
    {
        iniciarConta(i);
        depositar(i);
        sacar(i);
    }

    imprimirContas();

    return 0;
}
