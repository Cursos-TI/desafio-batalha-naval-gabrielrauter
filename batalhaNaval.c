#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define NAVIO 3
#define AGUA 0

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("\n* TABULEIRO BATALHA NAVAL *\n");
    printf("   A B C D E F G H I J\n");
    
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%2d ", i + 1);
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Verifica se é possível posicionar o navio sem sair do tabuleiro ou sobrepor
int podePosicionar(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int direcao, int diagonal) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linha, c = coluna;
            if (!diagonal) {
            if (direcao == 0) c += i;  
            else l += i;               
        } else {            
            if (direcao == 0) { l += i; c += i; }  
            else { l += i; c -= i; }               
        }

        if (l < 0 || l >= TAMANHO_TABULEIRO || c < 0 || c >= TAMANHO_TABULEIRO || tabuleiro[l][c] != AGUA) {
            return 0; 
        }
    }
    return 1;  
}

// Posiciona o navio no tabuleiro
void posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int direcao, int diagonal) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linha, c = coluna;

        if (!diagonal) {
            if (direcao == 0) c += i;      
            else l += i;                   
        } else {
            if (direcao == 0) { l += i; c += i; }  
            else { l += i; c -= i; }               
        }

        tabuleiro[l][c] = NAVIO;
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Primeiro navio: horizontal 
    if (podePosicionar(tabuleiro, 2, 3, 0, 0))
        posicionarNavio(tabuleiro, 2, 3, 0, 0);

    // Segundo navio: vertical 
    if (podePosicionar(tabuleiro, 5, 6, 1, 0))
        posicionarNavio(tabuleiro, 5, 6, 1, 0);

    // Terceiro navio: diagonal 
    if (podePosicionar(tabuleiro, 0, 0, 0, 1))
        posicionarNavio(tabuleiro, 0, 0, 0, 1);

    // Quarto navio: diagonal 
    if (podePosicionar(tabuleiro, 0, 9, 1, 1))
        posicionarNavio(tabuleiro, 0, 9, 1, 1);

    // Exibir tabuleiro
    exibirTabuleiro(tabuleiro);

    return 0;
}