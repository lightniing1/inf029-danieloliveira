#include<stdio.h>


int numeros_crescente(int inteiro, int maximo){

    if (inteiro == maximo){
        return 0;
    }

    inteiro = inteiro + 1;

    printf("%d\n", inteiro);

    return numeros_crescente(inteiro, maximo) + inteiro;

}

int main(void) {

    int numero = 10;
    numeros_crescente(0, numero);

    return 0;

}