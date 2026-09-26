#ifndef CALCULO_H
#define CALCULO_H

double identificarValorBase(double distancia);
double calcularSubtotal(double distancia);
double identificarPercentualPeso(double peso);
double identificarPercentualModalidade(int modalidade);
double calcularValorFinal(double subtotal, double peso, int modalidade,
                          int protecao, int tentativas);

#endif
