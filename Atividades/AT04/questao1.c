#include <stdio.h>

//https://github.com/renatoln/INF029/blob/master/listas/Lista1-Funcoes.pdf

int soma (int x, int y){
    return x + y;
}

int main(void) {

    int valor1, valor2, resultado;

    printf("Valor para soma 1: ");
    scanf("%d", &valor1);
    printf("Valor para soma 2: ");
    scanf("%d", &valor2);
    
    resultado = soma(valor1, valor2);

    printf("Resultado da soma: %d", resultado);

    return 0;
}