#include <stdio.h>

int main () {

    float num1 = 0, num2 = 0; 

    printf("Digite sua primeira nota: \n");
    scanf("%f", &num1);

    printf("Digite sua segunda nota: \n");    
    scanf("%f", &num2);

    float media = (num1 + num2)/2 ;
    printf("Sua média é: %.2f.\n", media);

    return 0;
}