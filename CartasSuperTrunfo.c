#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NUM_CARTAS 5
#define NUM_ATRIBUTOS 5

// Estrutura para representar uma carta de país
typedef struct {
    char nome[50];
    float atributos[NUM_ATRIBUTOS]; // 0-Área, 1-População, 2-PIB, 3-IDH, 4-Densidade
} Carta;

// Protótipos de funções
void exibirMenuAtributos(int primeiroAtributo);
void compararCartas(Carta carta1, Carta carta2, int atributo1, int atributo2);
void exibirCarta(Carta carta);

int main() {
    // Cartas pré-cadastradas
    Carta cartas[NUM_CARTAS] = {
        {"Brasil", {8515767.0, 213993437.0, 1.445, 0.765, 25.0}},
        {"Estados Unidos", {9833517.0, 331002651.0, 20.94, 0.926, 36.0}},
        {"Japao", {377975.0, 125800000.0, 5.065, 0.919, 334.0}},
        {"Alemanha", {357022.0, 83149300.0, 3.806, 0.939, 233.0}},
        {"Australia", {7692024.0, 25788200.0, 1.379, 0.944, 3.0}}
    };
    
    int opcao1, opcao2, primeiroAtributo, segundoAtributo;
    Carta cartaJogador, cartaComputador;
    
    printf("Bem-vindo ao Super Trunfo de Países!\n\n");
    
    // Selecionar cartas (simplificado - poderia ser aleatório)
    cartaJogador = cartas[0];   // Brasil
    cartaComputador = cartas[1]; // Estados Unidos
    
    printf("Sua carta:\n");
    exibirCarta(cartaJogador);
    printf("\nCarta do computador:\n");
    exibirCarta(cartaComputador);
    
    // Menu para escolher o primeiro atributo
    printf("\nEscolha o PRIMEIRO atributo para comparar:\n");
    exibirMenuAtributos(-1); // -1 indica que nenhum atributo foi escolhido ainda
    scanf("%d", &primeiroAtributo);
    
    // Validar entrada do primeiro atributo
    while(primeiroAtributo < 1 || primeiroAtributo > NUM_ATRIBUTOS) {
        printf("Opcao invalida! Escolha de 1 a %d: ", NUM_ATRIBUTOS);
        scanf("%d", &primeiroAtributo);
    }
    
    // Converter para índice do array (0 a 4)
    primeiroAtributo--;
    
    // Menu para escolher o segundo atributo (dinâmico - não mostra o primeiro)
    printf("\nEscolha o SEGUNDO atributo para comparar (diferente do primeiro):\n");
    exibirMenuAtributos(primeiroAtributo);
    scanf("%d", &segundoAtributo);
    
    // Validar entrada do segundo atributo
    while(segundoAtributo < 1 || segundoAtributo > NUM_ATRIBUTOS || 
          (segundoAtributo-1) == primeiroAtributo) {
        printf("Opcao invalida! Escolha de 1 a %d e diferente do primeiro atributo: ", NUM_ATRIBUTOS);
        scanf("%d", &segundoAtributo);
    }
    
    // Converter para índice do array (0 a 4)
    segundoAtributo--;
    
    // Comparar as cartas
    compararCartas(cartaJogador, cartaComputador, primeiroAtributo, segundoAtributo);
    
    return 0;
}

// Função para exibir o menu de atributos dinamicamente
void exibirMenuAtributos(int primeiroAtributo) {
    char* nomesAtributos[NUM_ATRIBUTOS] = {
        "Area (km²)",
        "Populacao",
        "PIB (trilhoes de USD)",
        "IDH",
        "Densidade Demografica (hab/km²)"
    };
    
    for(int i = 0; i < NUM_ATRIBUTOS; i++) {
        if(i != primeiroAtributo) {
            printf("%d. %s\n", i+1, nomesAtributos[i]);
        }
    }
}

// Função para comparar duas cartas com base em dois atributos
void compararCartas(Carta carta1, Carta carta2, int atributo1, int atributo2) {
    char* nomesAtributos[NUM_ATRIBUTOS] = {
        "Area",
        "Populacao",
        "PIB",
        "IDH",
        "Densidade Demografica"
    };
    
    printf("\n=== RESULTADO DA COMPARACAO ===\n");
    printf("Países: %s vs %s\n", carta1.nome, carta2.nome);
    printf("Atributos comparados: %s e %s\n", 
           nomesAtributos[atributo1], nomesAtributos[atributo2]);
    
    // Comparação do primeiro atributo
    printf("\nComparando %s:\n", nomesAtributos[atributo1]);
    printf("%s: %.2f\n", carta1.nome, carta1.atributos[atributo1]);
    printf("%s: %.2f\n", carta2.nome, carta2.atributos[atributo1]);
    
    int resultadoAtributo1;
    if(atributo1 == 4) { // Densidade Demográfica (menor vence)
        resultadoAtributo1 = (carta1.atributos[atributo1] < carta2.atributos[atributo1]) ? 1 : 
                            (carta1.atributos[atributo1] > carta2.atributos[atributo1]) ? -1 : 0;
    } else { // Demais atributos (maior vence)
        resultadoAtributo1 = (carta1.atributos[atributo1] > carta2.atributos[atributo1]) ? 1 : 
                            (carta1.atributos[atributo1] < carta2.atributos[atributo1]) ? -1 : 0;
    }
    
    // Exibir resultado da primeira comparação usando operador ternário
    printf("Resultado: %s\n", 
           resultadoAtributo1 == 1 ? carta1.nome : 
           resultadoAtributo1 == -1 ? carta2.nome : "Empate");
    
    // Comparação do segundo atributo
    printf("\nComparando %s:\n", nomesAtributos[atributo2]);
    printf("%s: %.2f\n", carta1.nome, carta1.atributos[atributo2]);
    printf("%s: %.2f\n", carta2.nome, carta2.atributos[atributo2]);
    
    int resultadoAtributo2;
    if(atributo2 == 4) { // Densidade Demográfica (menor vence)
        resultadoAtributo2 = (carta1.atributos[atributo2] < carta2.atributos[atributo2]) ? 1 : 
                            (carta1.atributos[atributo2] > carta2.atributos[atributo2]) ? -1 : 0;
    } else { // Demais atributos (maior vence)
        resultadoAtributo2 = (carta1.atributos[atributo2] > carta2.atributos[atributo2]) ? 1 : 
                            (carta1.atributos[atributo2] < carta2.atributos[atributo2]) ? -1 : 0;
    }
    
    // Exibir resultado da segunda comparação usando operador ternário
    printf("Resultado: %s\n", 
           resultadoAtributo2 == 1 ? carta1.nome : 
           resultadoAtributo2 == -1 ? carta2.nome : "Empate");
    
    // Calcular soma dos atributos
    float soma1 = carta1.atributos[atributo1] + carta1.atributos[atributo2];
    float soma2 = carta2.atributos[atributo1] + carta2.atributos[atributo2];
    
    printf("\nSoma dos atributos:\n");
    printf("%s: %.2f\n", carta1.nome, soma1);
    printf("%s: %.2f\n", carta2.nome, soma2);
    
    // Determinar o vencedor final
    if(soma1 > soma2) {
        printf("\nRESULTADO FINAL: %s vence!\n", carta1.nome);
    } else if(soma2 > soma1) {
        printf("\nRESULTADO FINAL: %s vence!\n", carta2.nome);
    } else {
        printf("\nRESULTADO FINAL: Empate!\n");
    }
}

// Função para exibir os dados de uma carta
void exibirCarta(Carta carta) {
    printf("Pais: %s\n", carta.nome);
    printf("Atributos:\n");
    printf("1. Area: %.2f km²\n", carta.atributos[0]);
    printf("2. Populacao: %.2f habitantes\n", carta.atributos[1]);
    printf("3. PIB: %.3f trilhoes de USD\n", carta.atributos[2]);
    printf("4. IDH: %.3f\n", carta.atributos[3]);
    printf("5. Densidade Demografica: %.2f hab/km²\n", carta.atributos[4]);
}