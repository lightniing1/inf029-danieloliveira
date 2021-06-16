#include<stdio.h>


int numeros_crescente(int inteiro, int maximo){

    if (inteiro == maximo){
        return 0;
    }

    inteiro = inteiro + 2;

    printf("%d\n", inteiro);

    return numeros_crescente(inteiro, maximo) + inteiro;

}

int main(void) {

    int numero = 20;

    if (numero % 2 == 1){
        printf("Numero nao par");
    } else {
        numeros_crescente(0, numero);
    }
    

    return 0;

}