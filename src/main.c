#include <stdio.h>
#include <limits.h>
#include "entrada.h"
#include "calculo.h"
#include "resumo.h"

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
