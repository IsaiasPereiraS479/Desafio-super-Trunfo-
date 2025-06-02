#include <stdio.h>
#include <string.h>

#define MAX_CIDADES 100

// Estrutura da carta
typedef struct {
    char estado[50];
    char codigo[10];
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
    float super_poder;
} Carta;

// Função para calcular o Super Poder
float calcular_super_poder(Carta c) {
    return (c.populacao * 0.2) + (c.area * 0.1) + (c.pib * 0.3) + (c.pontos_turisticos * 0.4);
}

// Cadastrar cartas
void cadastrar_carta(Carta *carta) {
    printf("Estado: ");
    scanf(" %[^"] , carta->estado);
    printf("Codigo da carta: ");
    scanf(" %[^"] , carta->codigo);
    printf("Nome da cidade: ");
    scanf(" %[^"] , carta->nome);
    printf("Populacao: ");
    scanf("%d", &carta->populacao);
    printf("Area: ");
    scanf("%f", &carta->area);
    printf("PIB: ");
    scanf("%f", &carta->pib);
    printf("Numero de pontos turisticos: ");
    scanf("%d", &carta->pontos_turisticos);

    // Cálculos
    carta->densidade_populacional = carta->populacao / carta->area;
    carta->pib_per_capita = carta->pib / carta->populacao;
    carta->super_poder = calcular_super_poder(*carta);
}

// Exibir uma carta
void exibir_carta(Carta c) {
    printf("\n--- CARTA ---\n");
    printf("Estado: %s\n", c.estado);
    printf("Codigo: %s\n", c.codigo);
    printf("Cidade: %s\n", c.nome);
    printf("Populacao: %d\n", c.populacao);
    printf("Area: %.2f\n", c.area);
    printf("PIB: %.2f\n", c.pib);
    printf("Pontos Turisticos: %d\n", c.pontos_turisticos);
    printf("Densidade Populacional: %.2f\n", c.densidade_populacional);
    printf("PIB per capita: %.2f\n", c.pib_per_capita);
    printf("Super Poder: %.2f\n", c.super_poder);
}

// Comparar cartas por atributo específico
void comparar_atributo(Carta c1, Carta c2, char atributo[]) {
    float valor1 = 0, valor2 = 0;
    int menor_vence = 0;

    if (strcmp(atributo, "populacao") == 0) {
        valor1 = c1.populacao;
        valor2 = c2.populacao;
    } else if (strcmp(atributo, "area") == 0) {
        valor1 = c1.area;
        valor2 = c2.area;
    } else if (strcmp(atributo, "pib") == 0) {
        valor1 = c1.pib;
        valor2 = c2.pib;
    } else if (strcmp(atributo, "pib_per_capita") == 0) {
        valor1 = c1.pib_per_capita;
        valor2 = c2.pib_per_capita;
    } else if (strcmp(atributo, "densidade_populacional") == 0) {
        valor1 = c1.densidade_populacional;
        valor2 = c2.densidade_populacional;
        menor_vence = 1;
    } else {
        printf("Atributo desconhecido!\n");
        return;
    }

    printf("\nComparacao de cartas (Atributo: %s):\n", atributo);
    printf("Carta 1 - %s (%s): %.2f\n", c1.nome, c1.estado, valor1);
    printf("Carta 2 - %s (%s): %.2f\n", c2.nome, c2.estado, valor2);

    if ((valor1 > valor2 && !menor_vence) || (valor1 < valor2 && menor_vence)) {
        printf("Resultado: Carta 1 (%s) venceu!\n", c1.nome);
    } else if (valor1 == valor2) {
        printf("Resultado: Empate!\n");
    } else {
        printf("Resultado: Carta 2 (%s) venceu!\n", c2.nome);
    }
}

int main() {
    Carta carta1, carta2.

    printf("Cadastro da primeira carta:\n");
    cadastrar_carta(&carta1);

    printf("\nCadastro da segunda carta:\n");
    cadastrar_carta(&carta2);

    printf("\n--- CARTAS CADASTRADAS ---\n");
    exibir_carta(carta1);
    exibir_carta(carta2);

    // Comparar usando atributo 
    comparar_atributo(carta1, carta2, "populacao"); // exemplo: "area", "pib", "densidade_populacional", "pib_per_capita"

    return 0;
}
