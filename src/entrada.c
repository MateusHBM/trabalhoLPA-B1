#include <stdio.h>
#include <math.h>
#include "entrada.h"

void mostrarPergunta(int campo) {
    switch (campo) {
        case 1: printf("Distancia em km (maior que zero): "); break;
        case 2: printf("Peso em kg (maior que zero): "); break;
        case 3: printf("Modalidade (1-Economica, 2-Expressa, 3-Prioritaria): "); break;
        case 4: printf("Protecao (0-Nao, 1-Sim): "); break;
        case 5: printf("Tentativas adicionais (inteiro >= 0): "); break;
        case 6: printf("Outra entrega? (0-Nao, 1-Sim): "); break;
    }
}

/* -1 sinaliza fim da entrada, sem aceitar uma entrega incompleta. */
double lerNumero(int campo) {
    double valor;
    int resultado;
    int caractere;

    while (1) {
        mostrarPergunta(campo);
        resultado = scanf("%lf", &valor);
        if (resultado == EOF) {
            return -1.0;
        }
        if (resultado == 1 && isfinite(valor) && valor >= 0.0) {
            return valor;
        }
        printf("Valor invalido. Informe um numero nao negativo.\n");
        if (resultado == 0) {
            do {
                caractere = getchar();
            } while (caractere != '\n' && caractere != EOF);
        }
    }
}

double lerPositivo(int campo) {
    double valor;
    do {
        valor = lerNumero(campo);
        if (valor == 0.0) {
            printf("Valor invalido. Informe um numero maior que zero.\n");
        }
    } while (valor == 0.0);
    return valor;
}

int lerInteiro(int campo, int minimo, int maximo) {
    double valor;
    while (1) {
        valor = lerNumero(campo);
        if (valor < 0.0) {
            return -1;
        }
        /* Verifica os limites antes da conversao para int. */
        if (valor >= minimo && valor <= maximo && valor == (int) valor) {
            return (int) valor;
        }
        printf("Valor invalido. Informe um inteiro entre %d e %d.\n", minimo, maximo);
    }
}
