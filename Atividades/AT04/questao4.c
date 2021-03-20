#include <stdio.h>

//https://github.com/renatoln/INF029/blob/master/listas/Lista1-Funcoes.pdf

int * ler3Numeros(int num1, int num2, int num3){

    static int array[3];

    array[0] = num1;
    array[1] = num2;
    array[2] = num3;

    return array;
}

int main(void) {

    int num1, num2, num3;
    
    printf("Qual o primeiro numero: ");
    scanf("%d", &num1);
    printf("Qual o segundo numero: ");
    scanf("%d", &num2);
    printf("Qual o terceiro numero: ");
    scanf("%d", &num3);

    int* result = ler3Numeros(num1, num2, num3);

    for (int i = 0; i < 3; i++){
        printf("%d ", result[i]);
    }

    return 0;
}