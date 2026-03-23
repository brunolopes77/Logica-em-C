#include <stdio.h>

int main () {

    int idade = 0;
    printf("Valor inicial inserido: %d.\n", idade);

    printf("Digite sua idade:\n");
    scanf("%d", &idade);
    
    printf("Sua idade é: %d.\n", idade);

    return 0;
}