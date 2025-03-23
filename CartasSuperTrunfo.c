#include <stdio.h>
#include <string.h>

typedef struct {
    char estado[3];
    char codigo[10];
    char cidade[50];
    int populacao;
    float area;
    float PIB;
    int pontos_turisticos;
    float densidade_populacional;
    float PIB_per_capita;
} Carta;

void calcular_metricas(Carta *carta) {
    carta->densidade_populacional = carta->populacao / carta->area;
    carta->PIB_per_capita = carta->PIB / carta->populacao;
}

void exibir_carta(Carta carta) {
    printf("Estado: %s\n", carta.estado);
    printf("Código: %s\n", carta.codigo);
    printf("Cidade: %s\n", carta.cidade);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f\n", carta.area);
    printf("PIB: %.2f\n", carta.PIB);
    printf("Pontos Turísticos: %d\n", carta.pontos_turisticos);
    printf("Densidade Populacional: %.2f\n", carta.densidade_populacional);
    printf("PIB per capita: %.2f\n", carta.PIB_per_capita);
}

int main() {
    
    Carta carta1 = {"SP", "SP001", "São Paulo", 12300000, 1521.11, 678.9, 300};
    Carta carta2 = {"RJ", "RJ001", "Rio de Janeiro", 6000000, 1200.27, 450.5, 250};

    calcular_metricas(&carta1);
    calcular_metricas(&carta2);

    printf("Carta 1:\n");
    exibir_carta(carta1);
    printf("\nCarta 2:\n");
    exibir_carta(carta2);

    char atributo_escolhido[] = "População";
    float valor_carta1 = carta1.populacao;
    float valor_carta2 = carta2.populacao;

    printf("\nComparação de cartas (Atributo: %s):\n", atributo_escolhido);
    printf("Carta 1 - %s (%s): %.2f\n", carta1.cidade, carta1.estado, valor_carta1);
    printf("Carta 2 - %s (%s): %.2f\n", carta2.cidade, carta2.estado, valor_carta2);

    if (valor_carta1 > valor_carta2) {
        printf("Resultado: Carta 1 (%s) venceu!\n", carta1.cidade);
    } else if (valor_carta1 < valor_carta2) {
        printf("Resultado: Carta 2 (%s) venceu!\n", carta2.cidade);
    } else {
        printf("Resultado: Empate!\n");
    }

    return 0;
}