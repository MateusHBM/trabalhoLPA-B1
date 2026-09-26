#include <stdio.h>
#include <limits.h>
#include <math.h>

#define TARIFA_POR_KM 1.20
#define BASE_ATE_5_KM 8.00
#define BASE_ATE_15_KM 12.00
#define BASE_ATE_30_KM 18.00
#define BASE_ACIMA_30_KM 25.00
#define PESO_ATE_2_KG 0.00
#define PESO_ATE_5_KG 0.05
#define PESO_ATE_10_KG 0.10
#define PESO_ACIMA_10_KG 0.20

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

double identificarValorBase(double distancia) {
    if (distancia <= 5.0) {
        return BASE_ATE_5_KM;
    }
    if (distancia <= 15.0) {
        return BASE_ATE_15_KM;
    }
    if (distancia <= 30.0) {
        return BASE_ATE_30_KM;
    }
    return BASE_ACIMA_30_KM;
}

double calcularSubtotal(double distancia) {
    return identificarValorBase(distancia) + distancia * TARIFA_POR_KM;
}

double identificarPercentualPeso(double peso) {
    if (peso <= 2.0) {
        return PESO_ATE_2_KG;
    }
    if (peso <= 5.0) {
        return PESO_ATE_5_KG;
    }
    if (peso <= 10.0) {
        return PESO_ATE_10_KG;
    }
    return PESO_ACIMA_10_KG;
}

int main(void) {
    double distancia;
    double peso;
    double subtotal;
    double adicionalPeso;
    int modalidade;
    int protecao;
    int tentativas;
    int continuar = 1;

    printf("Simulador de Entregas - Trabalho B1\n");
    printf("Use ponto para separar as casas decimais.\n");
    while (continuar == 1) {
        distancia = lerPositivo(1);
        if (distancia < 0.0) break;
        peso = lerPositivo(2);
        if (peso < 0.0) break;
        modalidade = lerInteiro(3, 1, 3);
        if (modalidade < 0) break;
        protecao = lerInteiro(4, 0, 1);
        if (protecao < 0) break;
        tentativas = lerInteiro(5, 0, INT_MAX);
        if (tentativas < 0) break;
        printf("Dados validados: %.2f km, %.2f kg, modalidade %d, protecao %d, tentativas %d.\n",
               distancia, peso, modalidade, protecao, tentativas);
        subtotal = calcularSubtotal(distancia);
        adicionalPeso = subtotal * identificarPercentualPeso(peso);
        printf("Subtotal inicial: R$ %.2f\n", subtotal);
        printf("Adicional de peso: R$ %.2f\n", adicionalPeso);
        continuar = lerInteiro(6, 0, 1);
    }
    return 0;
}
