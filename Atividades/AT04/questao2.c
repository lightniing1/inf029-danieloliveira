#include <stdio.h>

//https://github.com/renatoln/INF029/blob/master/listas/Lista1-Funcoes.pdf

int subtrai (int x, int y, int z){
    return x - y - z;
}

int main(void) {

    int valor1, valor2, valor3, resultado;

    printf("Valor para subtrair 1: ");
    scanf("%d", &valor1);
    printf("Valor para subtrair 2: ");
    scanf("%d", &valor2);
    printf("Valor para subtrair 3: ");
    scanf("%d", &valor3);

    resultado = subtrai(valor1, valor2, valor3);

    printf("Resultado da soma: %d", resultado);

    return 0;
}