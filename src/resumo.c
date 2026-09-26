#include <stdio.h>
#include "resumo.h"

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
