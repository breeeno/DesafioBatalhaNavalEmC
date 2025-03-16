#include <stdio.h>


void nivelNovato() {
    int tabuleiro[5][5] = {0}; 

    tabuleiro[1][2] = 3;
    tabuleiro[2][2] = 3;
    tabuleiro[3][2] = 3;

    tabuleiro[2][0] = 3;
    tabuleiro[2][1] = 3;
    tabuleiro[2][2] = 3;

    printf("Posicionamento do Navio Vertical:\n");
    printf("Coordenadas: (1,2), (2,2), (3,2)\n");

    printf("Posicionamento do Navio Horizontal:\n");
    printf("Coordenadas: (2,0), (2,1), (2,2)\n");

    printf("\nTabuleiro (5x5):\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}


void nivelAventureiro() {
    int tabuleiro[10][10] = {0}; 

    tabuleiro[2][0] = 3;
    tabuleiro[2][1] = 3;
    tabuleiro[2][2] = 3;

    tabuleiro[4][4] = 3;
    tabuleiro[5][4] = 3;
    tabuleiro[6][4] = 3;

    tabuleiro[1][1] = 3;
    tabuleiro[2][2] = 3;
    tabuleiro[3][3] = 3;

    tabuleiro[7][7] = 3;
    tabuleiro[8][8] = 3;
    tabuleiro[9][9] = 3;

    printf("\nTabuleiro (10x10) - Nivel Aventureiro:\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}


void habilidadeCone(int tabuleiro[10][10], int x, int y) {
    int i, j;
    for (i = -2; i <= 2; i++) {
        for (j = -2; j <= 2; j++) {
            if (abs(i) + abs(j) <= 2 && x + i >= 0 && x + i < 10 && y + j >= 0 && y + j < 10) {
                tabuleiro[x + i][y + j] = 1;
            }
        }
    }
}

void habilidadeCruz(int tabuleiro[10][10], int x, int y) {
    for (int i = -2; i <= 2; i++) {
        if (x + i >= 0 && x + i < 10) {
            tabuleiro[x + i][y] = 1;
        }
    }
    for (int j = -2; j <= 2; j++) {
        if (y + j >= 0 && y + j < 10) {
            tabuleiro[x][y + j] = 1;
        }
    }
}

void habilidadeOctaedro(int tabuleiro[10][10], int x, int y) {
    for (int i = -2; i <= 2; i++) {
        for (int j = -2; j <= 2; j++) {
            if (abs(i) + abs(j) == 2 && x + i >= 0 && x + i < 10 && y + j >= 0 && y + j < 10) {
                tabuleiro[x + i][y + j] = 1;
            }
        }
    }
}

void exibirTabuleiro(int tabuleiro[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    printf("=== Nível Novato ===\n");
    nivelNovato();

    printf("\n=== Nível Aventureiro ===\n");
    nivelAventureiro();

    printf("\n=== Nível Mestre ===\n");
    int tabuleiroMestre[10][10] = {0}; 
    habilidadeCone(tabuleiroMestre, 5, 5);
    habilidadeCruz(tabuleiroMestre, 5, 5);
    habilidadeOctaedro(tabuleiroMestre, 5, 5);

    printf("\nTabuleiro com Habilidades (Cone, Cruz, Octaedro):\n");
    exibirTabuleiro(tabuleiroMestre);

    return 0;
}