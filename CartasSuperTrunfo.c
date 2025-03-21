#include <stdio.h>

typedef struct {
    char estado[3];
    char codigo[3];
    char nome[50];
    unsigned long int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
    float super_poder;
} Carta;

void lerCarta(Carta *carta) {
    printf("Digite o estado (sigla): ");
    scanf("%s", carta->estado);
    printf("Digite o código: ");
    scanf("%s", carta->codigo);
    printf("Digite o nome: ");
    scanf(" %[^\n]", carta->nome);
    printf("Digite a população: ");
    scanf("%lu", &carta->populacao);
    printf("Digite a área: ");
    scanf("%f", &carta->area);
    printf("Digite o PIB: ");
    scanf("%f", &carta->pib);
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &carta->pontos_turisticos);
}

void calcularDensidadePib(Carta *carta) {
    carta->densidade_populacional = carta->populacao / carta->area;
    carta->pib_per_capita = carta->pib / carta->populacao;
}

void calcularSuperPoder(Carta *carta) {
    carta->super_poder = carta->populacao + carta->area + carta->pib + carta->pontos_turisticos + carta->pib_per_capita + (1.0 / carta->densidade_populacional);
}

void compararCartas(Carta carta1, Carta carta2) {
    printf("\nComparação de Cartas:\n");
    printf("População: Carta %d venceu (%d)\n", (carta1.populacao > carta2.populacao) ? 1 : 2, (carta1.populacao > carta2.populacao) ? 1 : 0);
    printf("Área: Carta %d venceu (%d)\n", (carta1.area > carta2.area) ? 1 : 2, (carta1.area > carta2.area) ? 1 : 0);
    printf("PIB: Carta %d venceu (%d)\n", (carta1.pib > carta2.pib) ? 1 : 2, (carta1.pib > carta2.pib) ? 1 : 0);
    printf("Pontos Turísticos: Carta %d venceu (%d)\n", (carta1.pontos_turisticos > carta2.pontos_turisticos) ? 1 : 2, (carta1.pontos_turisticos > carta2.pontos_turisticos) ? 1 : 0);
    printf("Densidade Populacional: Carta %d venceu (%d)\n", (carta1.densidade_populacional < carta2.densidade_populacional) ? 1 : 2, (carta1.densidade_populacional < carta2.densidade_populacional) ? 1 : 0);
    printf("PIB per Capita: Carta %d venceu (%d)\n", (carta1.pib_per_capita > carta2.pib_per_capita) ? 1 : 2, (carta1.pib_per_capita > carta2.pib_per_capita) ? 1 : 0);
    printf("Super Poder: Carta %d venceu (%d)\n", (carta1.super_poder > carta2.super_poder) ? 1 : 2, (carta1.super_poder > carta2.super_poder) ? 1 : 0);
}

int main() {
    Carta carta1, carta2;

    printf("Digite os dados da Carta 1:\n");
    lerCarta(&carta1);
    calcularDensidadePib(&carta1);
    calcularSuperPoder(&carta1);

    printf("\nDigite os dados da Carta 2:\n");
    lerCarta(&carta2);
    calcularDensidadePib(&carta2);
    calcularSuperPoder(&carta2);

    compararCartas(carta1, carta2);

    return 0;
}