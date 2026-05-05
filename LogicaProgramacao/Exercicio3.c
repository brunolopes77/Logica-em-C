#include <stdio.h>

void leMatriz(int a[3][3], int b[3][3]){
    int i, j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("Digite um numero para sua primeria matriz: \n");
            scanf("%d", &a[i][j]);
        }
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("Digite um numero para sua segunda matriz: \n");
            scanf("%d", &b[i][j]);
        }
    }

}

void subtraiMatriz(int a[3][3], int b[3][3], int diferenca[3][3]){
    int i, j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            diferenca[i][j] = a[i][j] - b[i][j];
        }
    }
}

void transposta(int diferenca[3][3], int transposta[3][3]){
    int i, j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            transposta[j][i] = diferenca[i][j];
        }
    }

}

void imprimeMatriz(int diferenca[3][3], int transposta[3][3]){
     int i, j;

    printf("Matriz diferenca:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
                printf("%d", diferenca[i][j]);
                printf(" ");
            }
        printf("\n");
    }

    printf("Matriz transposta:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
                printf("%d", transposta[i][j]);
                printf(" ");
            }
        printf("\n");
    }

}

int main(){
    int matrizA[3][3];
    int matrizB[3][3];
    int matrizDiferenca[3][3];
    int matrizTransposta[3][3];

    leMatriz(matrizA, matrizB);
    subtraiMatriz(matrizA, matrizB, matrizDiferenca);
    transposta(matrizDiferenca, matrizTransposta);
    imprimeMatriz(matrizDiferenca, matrizTransposta);
    
    return 0;
}