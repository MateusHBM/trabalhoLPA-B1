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
#define PERCENTUAL_ECONOMICA 0.00
#define PERCENTUAL_EXPRESSA 0.15
#define PERCENTUAL_PRIORITARIA 0.30
#define VALOR_PROTECAO 7.50
#define VALOR_TENTATIVA_ADICIONAL 4.00

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

double identificarPercentualModalidade(int modalidade) {
    if (modalidade == 1) {
        return PERCENTUAL_ECONOMICA;
    }
    if (modalidade == 2) {
        return PERCENTUAL_EXPRESSA;
    }
    return PERCENTUAL_PRIORITARIA;
}

double calcularValorFinal(double subtotal, double peso, int modalidade,
                          int protecao, int tentativas) {
    double adicionalPeso = subtotal * identificarPercentualPeso(peso);
    double adicionalModalidade = subtotal * identificarPercentualModalidade(modalidade);
    double adicionalProtecao = 0.0;
    double adicionalTentativas = tentativas * VALOR_TENTATIVA_ADICIONAL;

    if (protecao == 1) {
        adicionalProtecao = VALOR_PROTECAO;
    }
    /* Os dois percentuais incidem sobre o mesmo subtotal inicial. */
    return subtotal + adicionalPeso + adicionalModalidade
           + adicionalProtecao + adicionalTentativas;
}

void mostrarResumo(int quantidade, double total, int economicas, int expressas,
                   int prioritarias, double maior, double menor) {
    printf("\n=== Resumo da sessao ===\n");
    printf("Quantidade total de entregas: %d\n", quantidade);
    printf("Valor total: R$ %.2f\n", total);
    printf("Entregas Economicas: %d\n", economicas);
    printf("Entregas Expressas: %d\n", expressas);
    printf("Entregas Prioritarias: %d\n", prioritarias);
    if (quantidade > 0) {
        printf("Valor medio: R$ %.2f\n", total / quantidade);
        printf("Maior valor: R$ %.2f\n", maior);
        printf("Menor valor: R$ %.2f\n", menor);
    } else {
        printf("Nenhuma entrega processada.\n");
        printf("Valor medio: nao se aplica.\n");
        printf("Maior valor: nao se aplica.\n");
        printf("Menor valor: nao se aplica.\n");
    }
}

int main(void) {
    double distancia;
    double peso;
    double subtotal;
    double adicionalPeso;
    double valorFinal;
    int modalidade;
    int protecao;
    int tentativas;
    int continuar = 1;
    int quantidade = 0;
    int economicas = 0;
    int expressas = 0;
    int prioritarias = 0;
    double total = 0.0;
    double maior = 0.0;
    double menor = 0.0;

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
        valorFinal = calcularValorFinal(subtotal, peso, modalidade, protecao, tentativas);
        printf("Valor final da entrega: R$ %.2f\n", valorFinal);
        /* A primeira entrega inicializa os extremos com um valor real. */
        if (quantidade == 0) {
            maior = valorFinal;
            menor = valorFinal;
        } else {
            if (valorFinal > maior) {
                maior = valorFinal;
            }
            if (valorFinal < menor) {
                menor = valorFinal;
            }
        }
        quantidade++;
        total += valorFinal;
        if (modalidade == 1) {
            economicas++;
        } else if (modalidade == 2) {
            expressas++;
        } else {
            prioritarias++;
        }
        continuar = lerInteiro(6, 0, 1);
    }
    mostrarResumo(quantidade, total, economicas, expressas, prioritarias, maior, menor);
    return 0;
}
