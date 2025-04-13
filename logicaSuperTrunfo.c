
#include <stdio.h>
#include <string.h>
#include <stdlib.h> // Para atof

// Definição da estrutura da carta
typedef struct {
    char estado[50];
    char codigo[10];
    char nome[50];
    unsigned long int populacao;
    float area;
    float pib;
    int num_pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
    float super_poder;
} Carta;

// Função para calcular a densidade populacional
float calcularDensidade(unsigned long int populacao, float area) {
    if (area > 0) {
        return (float)populacao / area;
    } else {
        return 0;
    }
}

// Função para calcular o PIB per capita
float calcularPIBPerCapita(float pib, unsigned long int populacao) {
    if (populacao > 0) {
        return pib / populacao;
    } else {
        return 0;
    }
}

// Função para calcular o Super Poder de uma carta
float calcularSuperPoder(Carta carta) {
    return (float)carta.populacao + carta.area + carta.pib + carta.num_pontos_turisticos + carta.pib_per_capita + (carta.densidade_populacional > 0 ? 1.0f / carta.densidade_populacional : 0);
}

int main() {
    // Declaração de duas cartas
    Carta carta1, carta2;

    // Dados da Carta 1
    strcpy(carta1.estado, "São Paulo");
    strcpy(carta1.codigo, "SP01");
    strcpy(carta1.nome, "São Paulo");
    carta1.populacao = 12300000;
    carta1.area = 1521.11;
    carta1.pib = 780000.0;
    carta1.num_pontos_turisticos = 150;
    carta1.densidade_populacional = calcularDensidade(carta1.populacao, carta1.area);
    carta1.pib_per_capita = calcularPIBPerCapita(carta1.pib, carta1.populacao);
    carta1.super_poder = calcularSuperPoder(carta1);

    // Dados da Carta 2
    strcpy(carta2.estado, "Rio de Janeiro");
    strcpy(carta2.codigo, "RJ02");
    strcpy(carta2.nome, "Rio de Janeiro");
    carta2.populacao = 6700000;
    carta2.area = 1200.33;
    carta2.pib = 360000.0;
    carta2.num_pontos_turisticos = 100;
    carta2.densidade_populacional = calcularDensidade(carta2.populacao, carta2.area);
    carta2.pib_per_capita = calcularPIBPerCapita(carta2.pib, carta2.populacao);
    carta2.super_poder = calcularSuperPoder(carta2);

    // Escolha do atributo para comparação (altere aqui para testar outros atributos)
    char atributo_comparacao[] = "População";

    printf("Comparação de cartas (Atributo: %s):\n", atributo_comparacao);
    printf("Carta 1 - %s (%s): ", carta1.nome, carta1.estado);
    printf("Carta 2 - %s (%s): ", carta2.nome, carta2.estado);

    // Lógica de comparação baseada no atributo escolhido
    if (strcmp(atributo_comparacao, "População") == 0) {
        printf("%lu\nCarta 2 - %s (%s): %lu\n", carta1.populacao, carta2.nome, carta2.estado, carta2.populacao);
        if (carta1.populacao > carta2.populacao) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nome);
        } else if (carta2.populacao > carta1.populacao) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nome);
        } else {
            printf("Resultado: Empate!\n");
        }
    } else if (strcmp(atributo_comparacao, "Área") == 0) {
        printf("%.2f\nCarta 2 - %s (%s): %.2f\n", carta1.area, carta2.nome, carta2.estado, carta2.area);
        if (carta1.area > carta2.area) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nome);
        } else if (carta2.area > carta1.area) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nome);
        } else {
            printf("Resultado: Empate!\n");
        }
    } else if (strcmp(atributo_comparacao, "PIB") == 0) {
        printf("%.2f\nCarta 2 - %s (%s): %.2f\n", carta1.pib, carta2.nome, carta2.estado, carta2.pib);
        if (carta1.pib > carta2.pib) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nome);
        } else if (carta2.pib > carta1.pib) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nome);
        } else {
            printf("Resultado: Empate!\n");
        }
    } else if (strcmp(atributo_comparacao, "Densidade Populacional") == 0) {
        printf("%.2f\nCarta 2 - %s (%s): %.2f\n", carta1.densidade_populacional, carta2.nome, carta2.estado, carta2.densidade_populacional);
        if (carta1.densidade_populacional < carta2.densidade_populacional) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nome);
        } else if (carta2.densidade_populacional < carta1.densidade_populacional) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nome);
        } else {
            printf("Resultado: Empate!\n");
        }
    } else if (strcmp(atributo_comparacao, "PIB per capita") == 0) {
        printf("%.2f\nCarta 2 - %s (%s): %.2f\n", carta1.pib_per_capita, carta2.nome, carta2.estado, carta2.pib_per_capita);
        if (carta1.pib_per_capita > carta2.pib_per_capita) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nome);
        } else if (carta2.pib_per_capita > carta1.pib_per_capita) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nome);
        } else {
            printf("Resultado: Empate!\n");
        }
    } else {
        printf("Atributo de comparação inválido!\n");
    }

    return 0;
}