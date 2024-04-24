#include <stdio.h>
#include <string.h>

typedef struct
{
    int code;
    char name[50];
    int quantity;
    float price;
} Product;

void printInvoice(Product *products, int *quantities, int n)
{
    float total = 0;
    printf("Nota Fiscal:\n");
    printf("Código\tNome\t\tQuantidade\tPreço\tSubtotal\n");
    for (int i = 0; i < n; i++)
    {
        float subtotal = products[i].price * quantities[i];
        printf("%d\t%s\t\t%d\t%.2f\t%.2f\n", products[i].code, products[i].name, quantities[i], products[i].price, subtotal);
        total += subtotal;
    }
    printf("Total: %.2f\n", total);
}

int main()
{

    Product products[3] = {
        {1, "Produto 1", 10, 9.99},
        {2, "Produto 2", 20, 19.99},
        {3, "Produto 3", 30, 29.99}};

    int quantities[3] = {1, 2, 3};

    printInvoice(products, quantities, 3);

    return 0;
}
