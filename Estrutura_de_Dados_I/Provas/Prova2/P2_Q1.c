#include <stdio.h>
#define MAX 7

int estacionamento[MAX];
int frente = 0;
int tras = 0;
int manobras[MAX] = {0};
int manobrando = 0;

void entrar(int id) {
    if ((tras + 1) % MAX == frente) {
        printf("Estacionamento cheio. Carro %d não pode entrar.\n", id);
    } else {
        estacionamento[tras] = id;
        tras = (tras + 1) % MAX;
        if (!manobrando) {
            printf("Carro %d entrou no estacionamento. Agora temos %d carros.\n", id, (tras - frente + MAX) % MAX);
        }
    }
}

void sair(int id) {
    if (frente == tras) {
        printf("Estacionamento vazio. Carro %d não está aqui.\n", id);
    } else {
        int i = frente;
        while (i != tras && estacionamento[i] != id) {
            i = (i + 1) % MAX;
        }
        if (estacionamento[i] == id) {
            manobrando = 1;
            while (estacionamento[frente] != id) {
                entrar(estacionamento[frente]);
                frente = (frente + 1) % MAX;
                manobras[id]++;
            }
            manobrando = 0;
            frente = (frente + 1) % MAX;
            printf("Carro %d saiu do estacionamento. Foi manobrado %d vezes. Agora temos %d carros.\n", id, manobras[id], (tras - frente + MAX) % MAX);
        } else {
            printf("Carro %d não está no estacionamento.\n", id);
        }
    }
}

int main() {
    printf("Bem-vindo ao nosso estacionamento! Ele pode acomodar até 7 carros.\n");
    printf("Os carros entram pela entrada A e saem pela saída B.\n");
    printf("Vamos simular algumas ações:\n");

    entrar(1);
    entrar(2);
    entrar(3);
    sair(2);
    entrar(4);
    sair(1);

    printf("Obrigado por usar nosso estacionamento!\n");
    return 0;
}