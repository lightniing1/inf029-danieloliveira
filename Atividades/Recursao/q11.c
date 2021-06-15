#include<stdio.h>

int multiplicacao_por_soma(int inteiro1, int inteiro2){

    if (inteiro1 == 0){
        return 0;
    }

    return multiplicacao_por_soma(inteiro1 - 1, inteiro2) + inteiro2;

}


int main(void) {

    int resultado = multiplicacao_por_soma(5, 5);

    printf("%d\n", resultado);
    return 0;

}