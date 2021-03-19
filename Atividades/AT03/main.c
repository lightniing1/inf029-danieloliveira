#include <stdio.h>
#include "converte.h"

int main(void){

    int selecao;
    float temperatura, resultado;

    printf("Conversor de temperatura\n");
    printf("Para qual deseja converter?\n1 - Fahrenheit para Celsius\n2 - Celsius para Fahrenheit\n");
    scanf("%d", &selecao);
    printf("Insira a temperatura\n");
    scanf("%f", &temperatura);

    switch (selecao){
        case 1:
            resultado = ConverteEmC(temperatura);
            printf("%f", resultado);
            break;
    
        case 2:
            resultado = ConverteEmF(temperatura);
            printf("%f", resultado);
            break;
    }
    return 0;
}