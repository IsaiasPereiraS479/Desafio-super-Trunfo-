#include <stdio.h>

// Estrutura para armazenar os dados de uma carta

typedef struct {
    char nome[50];
    float area;
    unsigned long int populacao;
    float pib;
    float densidade; // calculado: populacao / area
    float super_poder; // calculado
} Carta;

// Função para calcular a densidade populacional

float calcular_densidade(unsigned long int populacao, float area) {
    return populacao / area;
}

// Função para calcular o Super Poder da carta
float calcular_super_poder(Carta carta) {
    float densidade_invertida = 1.0 / carta.densidade;
    return carta.area + (float)carta.populacao + carta.pib + densidade_invertida;
}

// Função para ler uma carta do usuário

Carta ler_carta() {
    Carta c;
    printf("\nDigite o nome do país: ");
    scanf(" %[^"]", c.nome);
    printf("Digite a área (km²): ");
    scanf("%f", &c.area);
    printf("Digite a população: ");
    scanf("%lu", &c.populacao);
    printf("Digite o PIB (em bilhões): ");
    scanf("%f", &c.pib);

    c.densidade = calcular_densidade(c.populacao, c.area);
    c.super_poder = calcular_super_poder(c);
    return c;
}

// Função para exibir uma carta

void exibir_carta(Carta c) {
    printf("\n===== %s =====\n", c.nome);
    printf("Área: %.2f km²\n", c.area);
    printf("População: %lu\n", c.populacao);
    printf("PIB: %.2f bilhões\n", c.pib);
    printf("Densidade Populacional: %.2f hab/km²\n", c.densidade);
    printf("Super Poder: %.2f\n", c.super_poder);
}

// Função para comparar atributos
int comparar(float valor1, float valor2, int maior_vence) {
    if (valor1 == valor2) return -1; // empate
    if (maior_vence) return (valor1 > valor2) ? 1 : 0;
    else return (valor1 < valor2) ? 1 : 0;
}

void comparar_cartas(Carta c1, Carta c2) {
    printf("\n===== Comparação de Atributos =====\n");

    printf("Área: %s\n", comparar(c1.area, c2.area, 1) == 1 ? c1.nome : c2.nome);
    printf("População: %s\n", comparar((float)c1.populacao, (float)c2.populacao, 1) == 1 ? c1.nome : c2.nome);
    printf("PIB: %s\n", comparar(c1.pib, c2.pib, 1) == 1 ? c1.nome : c2.nome);
    printf("Densidade Populacional: %s\n", comparar(c1.densidade, c2.densidade, 0) == 1 ? c1.nome : c2.nome);
    printf("Super Poder: %s\n", comparar(c1.super_poder, c2.super_poder, 1) == 1 ? c1.nome : c2.nome);
}

int main() {
    printf("SUPER TRUNFO - PAÍSES\n");

    // Nível Novato: Ler e exibir uma carta
    printf("\n[Nível Novato]\n");
    Carta carta_novato = ler_carta();
    exibir_carta(carta_novato);

    // Nível Aventureiro e Mestre: Ler duas cartas e comparar
    printf("\n[Nível Aventureiro e Mestre]\n");
    printf("\nCarta 1:\n");
    Carta carta1 = ler_carta();

    printf("\nCarta 2:\n");
    Carta carta2 = ler_carta();

    // Exibir as cartas
    exibir_carta(carta1);
    exibir_carta(carta2);

    // Comparar os atributos
    comparar_cartas(carta1, carta2);

    return 0;
}
