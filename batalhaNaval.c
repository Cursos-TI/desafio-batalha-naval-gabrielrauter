#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define NAVIO 3
#define AGUA 0
#define HABILIDADE 5
#define TAMANHO_HABILIDADE 5

// Exibe o tabuleiro com valores reais (0, 3, 5)
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

// Verifica se pode posicionar navio
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

        if (l < 0 || l >= TAMANHO_TABULEIRO || c < 0 || c >= TAMANHO_TABULEIRO || tabuleiro[l][c] != AGUA)
            return 0;
    }
    return 1;
}

// Posiciona navio
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

// matriz Cone
void gerarCone(int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    int padrao[3][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1}
    };

    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            habilidade[i][j] = (i < 3) ? padrao[i][j] : 0;
        }
    }
}

// matriz Cruz
void gerarCruz(int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    int padrao[3][5] = {
        {0, 0, 1, 0, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 1, 0, 0}
    };

    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            habilidade[i][j] = (i < 3) ? padrao[i][j] : 0;
        }
    }
}

// matriz Octaedro
void gerarOctaedro(int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    int padrao[3][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
    };

    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            habilidade[i][j] = (i < 3) ? padrao[i][j] : 0;
        }
    }
}

// Aplica habilidade ao tabuleiro
void aplicarHabilidade(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE], int origemLinha, int origemColuna) {
    int offset = TAMANHO_HABILIDADE / 2;

    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            int linhaTab = origemLinha - offset + i;
            int colunaTab = origemColuna - offset + j;

            if (linhaTab >= 0 && linhaTab < TAMANHO_TABULEIRO &&
                colunaTab >= 0 && colunaTab < TAMANHO_TABULEIRO &&
                habilidade[i][j] == 1 &&
                tabuleiro[linhaTab][colunaTab] == AGUA) {
                tabuleiro[linhaTab][colunaTab] = HABILIDADE;
            }
        }
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Posicionamento dos navios
    if (podePosicionar(tabuleiro, 2, 3, 0, 0))
        posicionarNavio(tabuleiro, 2, 3, 0, 0);

    if (podePosicionar(tabuleiro, 5, 6, 1, 0))
        posicionarNavio(tabuleiro, 5, 6, 1, 0);

    if (podePosicionar(tabuleiro, 0, 0, 0, 1))
        posicionarNavio(tabuleiro, 0, 0, 0, 1);

    if (podePosicionar(tabuleiro, 0, 9, 1, 1))
        posicionarNavio(tabuleiro, 0, 9, 1, 1);

    // Criar habilidades
    int cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int octaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];

    gerarCone(cone);
    gerarCruz(cruz);
    gerarOctaedro(octaedro);

    aplicarHabilidade(tabuleiro, cone, 4, 4);       // Cone no centro
    aplicarHabilidade(tabuleiro, cruz, 7, 2);       // Cruz
    aplicarHabilidade(tabuleiro, octaedro, 6, 8);   // Octaedro

    // Exibir resultado final
    exibirTabuleiro(tabuleiro);

    return 0;
}