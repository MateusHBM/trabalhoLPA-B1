#include <stdio.h>
#include "distancia.h"

float lerDistancia() {

    float distancia;

    printf("Digite a distancia: ");
    scanf("%f", &distancia);

    while (distancia <= 0) {

        printf("Valor invalido. Digite novamente: ");
        scanf("%f", &distancia);
    }

    return distancia;
}


float lerPeso() {

    float peso;

    printf("Digite o peso: ");
    scanf("%f", &peso);

    while (peso <= 0) {

        printf("Valor invalido. Digite novamente: ");
        scanf("%f", &peso);
    }

    return peso;
}


int lerModalidade() {

    int modalidade;

    printf("1 - Economica\n");
    printf("2 - Expressa\n");
    printf("3 - Prioritaria\n");

    scanf("%d", &modalidade);

    while (modalidade < 1 || modalidade > 3) {

        printf("Valor invalido. Digite novamente: ");
        scanf("%d", &modalidade);
    }

    return modalidade;
}


int lerProtecao() {

    int protecao;

    printf("Protecao? 1-Sim 0-Nao: ");
    scanf("%d", &protecao);

    while (protecao != 0 && protecao != 1) {

        printf("Digite 0 ou 1: ");
        scanf("%d", &protecao);
    }

    return protecao;
}


int lerTentativasAdicionais() {

    int tentativas;

    printf("Tentativas adicionais: ");
    scanf("%d", &tentativas);

    while (tentativas < 0) {

        printf("Digite 0 ou maior: ");
        scanf("%d", &tentativas);
    }

    return tentativas;
}


int perguntarContinuar() {

    int continuar;

    printf("Outra entrega? 1-Sim 0-Nao: ");
    scanf("%d", &continuar);

    while (continuar != 0 && continuar != 1) {

        printf("Digite 0 ou 1: ");
        scanf("%d", &continuar);
    }

    return continuar;
}