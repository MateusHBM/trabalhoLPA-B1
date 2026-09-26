# Trabalho B1 - Lógica de Programação e Algoritmos

## Descrição

Programa em C que simula entregas no terminal, calcula o preço de cada solicitação e apresenta um resumo da sessão.

## Funcionalidades

- Cálculo por distância, peso e modalidade: Econômica, Expressa ou Prioritária.
- Inclusão de proteção opcional e tentativas adicionais.
- Processamento de várias entregas na mesma execução.
- Resumo com quantidade, total, média, contagem por modalidade, maior e menor valor.

## Organização

Os arquivos estão na pasta `src`:

- `main.c`: coordena a sessão e atualiza os contadores.
- `entrada.c` e `entrada.h`: leitura e validação dos dados.
- `calculo.c` e `calculo.h`: tarifas e cálculo do preço.
- `resumo.c` e `resumo.h`: apresentação do resumo final.

## Validação

Distância e peso devem ser maiores que zero. A modalidade aceita 1, 2 ou 3; proteção e continuidade aceitam 0 ou 1. Tentativas adicionais devem ser inteiras e não negativas. Valores inválidos são solicitados novamente.

Os seis casos oficiais, os limites das faixas, as entradas inválidas e as sessões com várias entregas foram testados. Sessões vazias e entregas incompletas também são tratadas.

## Compilação

No PowerShell, na pasta do projeto, com GCC disponível no `PATH`:

```powershell
gcc -Wall -Wextra -pedantic src\main.c src\entrada.c src\calculo.c src\resumo.c -o lpa-trabalho-b1.exe
```

Para executar:

```powershell
.\lpa-trabalho-b1.exe
```

Informe um valor por vez e use ponto para casas decimais. Testado no Windows com GCC 16.2.0, sem avisos de compilação.

## Uso da IA

Foi utilizado o Codex, da OpenAI, para direcionamento com base no PDF do roteiro, implementação e testes do programa, orientações de execução e construção deste README.

## Fontes de Consulta

- `roteiro_trabalho_b1_lpa_2026_2.pdf`: roteiro oficial da atividade, 15 páginas; fonte das regras, requisitos, testes, documentação e critérios de avaliação.
