#include <stdio.h>

 int buscaPosicao(int m1[5][5],int y, int *linha, int *coluna){
    int i, j;
    
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if(m1[i][j] == y){
                *linha = i;
                *coluna = j;
                return 1;
            }
        }
    }
    return 0;
 }

int main(){
    int m[5][5];
    int linha, coluna;
    int x;
    for (linha = 0; linha < 5; linha++) {
        for (coluna = 0; coluna < 5; coluna++) {
            printf("Digite um numero para sua matriz: \n");
            scanf("%d", &m[linha][coluna]);
        }
    }
    printf("Digite o numero que deseja encontrar na matriz:\n");
    scanf("%d", &x);

     buscaPosicao(m, x, &linha, &coluna);
     if(buscaPosicao(m, x, &linha, &coluna) == 1){
        printf("Encontrado em(%d,%d)",linha,coluna);   
     }else{
        printf("Numero nao encontrado");
     }

    return 0;
}