#include<stdio.h>

int numeros_decrescente(int inteiro){

    if (inteiro == 0){
        return 0;
    }

    printf("%d ", inteiro);

    return numeros_decrescente(inteiro - 1);

}


int main(void) {

    numeros_decrescente(10);

    return 0;

}