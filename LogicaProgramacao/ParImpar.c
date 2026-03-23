#include <stdio.h>

int main() {

    int num;
    char resposta;
    do {
    printf("Digite o numéro:");
    scanf("%d", &num);
    
    if (num % 2 == 0){
        printf("Esse número é par\n");
    }else{
        printf("Esse numero é impar\n");
    }

    printf("Deseja digitar outro número?[S/N]\n");
    scanf(" %c", &resposta);
} while(resposta == 'S');

    return 0;
}