#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para gerar o número secreto
int gerarNumSecreto() {
    return rand() % 100;  // Retorna um número entre 0 e 99
}

int main() {
    srand(time(0));  // Inicializa o gerador de números aleatórios com a hora atual, chamado uma vez
    
    int numeroSecreto = gerarNumSecreto();  // Gera o número secreto
    int chute, tentativasRestantes;
    int dificuldade;
    int pontos = 1000;  // Inicia com 1000 pontos
    
    // Escolher o nível de dificuldade
    printf("Escolha o nivel de dificuldade:\n");
    printf("1. Facil (8 tentativas)\n");
    printf("2. Medio (5 tentativas)\n");
    printf("3. Dificil (3 tentativas)\n");
    scanf("%d", &dificuldade);
    
    // Definir o número de tentativas com base no nível de dificuldade
    switch(dificuldade) {
        case 1:
            tentativasRestantes = 8;
            break;
        case 2:
            tentativasRestantes = 5;
            break;
        case 3:
            tentativasRestantes = 3;
            break;
        default:
            printf("Nivel de dificuldade invalido! Iniciando no nivel Facil.\n");
            tentativasRestantes = 8;
            break;
    }

    // Início do jogo
    while (tentativasRestantes > 0) {
        printf("\nVoce tem %d tentativas restantes. Insira seu chute: ", tentativasRestantes);
        scanf("%d", &chute);

        // Verifica se o número inserido é negativo
        if (chute < 0) {
            printf("Numeros negativos nao sao permitidos! Tente novamente.\n");
            continue;  // Pula para a próxima iteração sem contar a tentativa
        }

        // Verifica se o chute está correto
        if (chute == numeroSecreto) {
            printf("Parabens! Voce adivinhou o numero secreto!\n");
            break;  // Sai do loop, jogo ganho
        } else if (chute > numeroSecreto) {
            printf("Seu chute eh maior que o numero secreto.\n");
        } else {
            printf("Seu chute eh menor que o numero secreto.\n");
        }

        // Reduzir pontuação com base na diferença entre o chute e o número secreto
        int diferenca = abs(chute - numeroSecreto);
        pontos -= diferenca;

        tentativasRestantes--;  // Reduz o número de tentativas restantes
    }

    // Verifica se o jogador não adivinhou o número e o jogo terminou
    if (tentativasRestantes == 0 && chute != numeroSecreto) {
        printf("\nQue pena! Voce nao conseguiu adivinhar o numero secreto. O numero era %d.\n", numeroSecreto);
    }

    // Exibe a pontuação final
    printf("Sua pontuacao final eh: %d pontos.\n", pontos);
    
    return 0;
}
