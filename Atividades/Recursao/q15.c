#include<stdio.h>

int numeros_decrescente(int inteiro){

    if (inteiro == 0){
        return 0;
    }

    printf("%d\n", inteiro);

    return numeros_decrescente(inteiro - 2);

}


int main(void) {

    int numero = 18;

    if (numero % 2 == 1){
        printf("Numero nao par");
    } else {
        numeros_decrescente(numero);
    }

    return 0;

}