#include <stdio.h>
#include <string.h>

typedef struct
{
    int codigo;
    char nome[50];
    int quantidade;
    float preco;
} Produto;

void imprimirNotaFiscal(Produto *produtos, int *quantidades, int n)
{
    float total = 0;
    printf("Nota Fiscal:\n");
    printf("Código\tNome\t\tQuantidade\tPreço\tSubtotal\n");
    for (int i = 0; i < n; i++)
    {
        float subtotal = produtos[i].preco * quantidades[i];
        printf("%d\t%s\t\t%d\t%.2f\t%.2f\n", produtos[i].codigo, produtos[i].nome, quantidades[i], produtos[i].preco, subtotal);
        total += subtotal;
    }
    printf("Total: %.2f\n", total);
}

int main()
{

    Produto produtos[3] = {
        {1, "Produto 1", 10, 9.99},
        {2, "Produto 2", 20, 19.99},
        {3, "Produto 3", 30, 29.99}};

    int quantidades[3] = {1, 2, 3};

    imprimirNotaFiscal(produtos, quantidades, 3);

    return 0;
}
