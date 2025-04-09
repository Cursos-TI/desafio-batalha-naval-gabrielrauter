#include <stdio.h>

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[10][10]) {
    printf(" \n* TABULEIRO BATALHA NAVAL *\n");
    printf("   A B C D E F G H I J\n");
    
    for (int i = 0; i < 10; i++) {
        printf("%2d ", i + 1);  // Exibe a linha numerada
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Declaração e inicialização do tabuleiro 10x10
    int tabuleiro[10][10] = {0};

    // Posicionando o navio horizontal diretamente na linha 2, coluna 3
    for (int i = 0; i < 3; i++) {
        if (3 + i < 10) {  
            tabuleiro[2][3 + i] = 3;  
        }
    }

    // Posicionando o navio vertical diretamente na linha 5, coluna 6
    for (int i = 0; i < 3; i++) {
        if (5 + i < 10) {  
            tabuleiro[5 + i][6] = 3;  
        }
    }

    // Exibindo o tabuleiro após posicionamento dos navios
    exibirTabuleiro(tabuleiro);

    return 0;
}