#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_demografica;
} CartaPais;

void exibirCarta(CartaPais carta) {
    printf("\nDetalhes da carta:\n");
    printf("País: %s\n", carta.nome);
    printf("População: %d habitantes\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f trilhões de dólares\n", carta.pib);
    printf("Pontos turísticos: %d\n", carta.pontos_turisticos);
    printf("Densidade demográfica: %.2f hab/km²\n", carta.densidade_demografica);
}


void compararCartas(CartaPais carta1, CartaPais carta2) {
    int opcao;
    
    printf("\n=== MENU DE ATRIBUTOS ===\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("Escolha o atributo para comparação (1-5): ");
    scanf("%d", &opcao);
    
    printf("\n=== RESULTADO DA COMPARAÇÃO ===\n");
    printf("País 1: %s\n", carta1.nome);
    printf("País 2: %s\n", carta2.nome);
    
    switch(opcao) {
        case 1: 
            printf("Atributo escolhido: População\n");
            printf("%s: %d habitantes\n", carta1.nome, carta1.populacao);
            printf("%s: %d habitantes\n", carta2.nome, carta2.populacao);
            
            if (carta1.populacao > carta2.populacao) {
                printf("Vencedor: %s\n", carta1.nome);
            } else if (carta2.populacao > carta1.populacao) {
                printf("Vencedor: %s\n", carta2.nome);
            } else {
                printf("Empate!\n");
            }
            break;
            
        case 2: 
            printf("Atributo escolhido: Área\n");
            printf("%s: %.2f km²\n", carta1.nome, carta1.area);
            printf("%s: %.2f km²\n", carta2.nome, carta2.area);
            
            if (carta1.area > carta2.area) {
                printf("Vencedor: %s\n", carta1.nome);
            } else if (carta2.area > carta1.area) {
                printf("Vencedor: %s\n", carta2.nome);
            } else {
                printf("Empate!\n");
            }
            break;
            
        case 3: 
            printf("Atributo escolhido: PIB\n");
            printf("%s: %.2f trilhões de dólares\n", carta1.nome, carta1.pib);
            printf("%s: %.2f trilhões de dólares\n", carta2.nome, carta2.pib);
            
            if (carta1.pib > carta2.pib) {
                printf("Vencedor: %s\n", carta1.nome);
            } else if (carta2.pib > carta1.pib) {
                printf("Vencedor: %s\n", carta2.nome);
            } else {
                printf("Empate!\n");
            }
            break;
            
        case 4: 
            printf("Atributo escolhido: Pontos Turísticos\n");
            printf("%s: %d pontos\n", carta1.nome, carta1.pontos_turisticos);
            printf("%s: %d pontos\n", carta2.nome, carta2.pontos_turisticos);
            
            if (carta1.pontos_turisticos > carta2.pontos_turisticos) {
                printf("Vencedor: %s\n", carta1.nome);
            } else if (carta2.pontos_turisticos > carta1.pontos_turisticos) {
                printf("Vencedor: %s\n", carta2.nome);
            } else {
                printf("Empate!\n");
            }
            break;
            
        case 5:
            printf("Atributo escolhido: Densidade Demográfica (menor valor vence)\n");
            printf("%s: %.2f hab/km²\n", carta1.nome, carta1.densidade_demografica);
            printf("%s: %.2f hab/km²\n", carta2.nome, carta2.densidade_demografica);
            
            if (carta1.densidade_demografica < carta2.densidade_demografica) {
                printf("Vencedor: %s\n", carta1.nome);
            } else if (carta2.densidade_demografica < carta1.densidade_demografica) {
                printf("Vencedor: %s\n", carta2.nome);
            } else {
                printf("Empate!\n");
            }
            break;
            
        default:
            printf("Opção inválida! Por favor, escolha um número entre 1 e 5.\n");
    }
}

int main() {

    CartaPais brasil = {
        "Brasil",
        213317639,
        8515767.049,
        1.445,
        15,
        25.05
    };
    
    CartaPais eua = {
        "Estados Unidos",
        331449281,
        9833517.0,
        20.94,
        25,
        33.71
    };
    
    printf("=== CARTAS DO JOGO ===\n");
    exibirCarta(brasil);
    exibirCarta(eua);
    
    compararCartas(brasil, eua);
    
    return 0;
}
