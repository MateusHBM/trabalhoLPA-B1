#include "calculo.h"

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
