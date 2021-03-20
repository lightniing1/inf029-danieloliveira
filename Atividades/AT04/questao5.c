#include <stdio.h>

//https://github.com/renatoln/INF029/blob/master/listas/Lista1-Funcoes.pdf

typedef struct
{
    int num1, num2, num3, num4;
} Numeros;

Numeros ler4Numeros(int a, int b, int c, int d){
    Numeros numero;
        numero.num1 = a;
        numero.num2 = b;
        numero.num3 = c;
        numero.num4 = d;
    return numero;
}

int main(void) {

    int valor1, valor2, valor3, valor4;

    printf("Entre com o primeiro numero");
    scanf("%d", &valor1);
    printf("Entre com o segundo numero");
    scanf("%d", &valor2);
    printf("Entre com o terceiro numero");
    scanf("%d", &valor3);
    printf("Entre com o quarto numero");
    scanf("%d", &valor4);

    Numeros numeros;
    numeros = ler4Numeros(valor1, valor2, valor3, valor4);
    printf("%d %d %d %d", numeros.num1, numeros.num2, numeros.num3, numeros.num4);


    return 0;
}