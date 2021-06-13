#include<stdio.h>

int soma_ate_recursivo(int numero){
    if (numero <= 0){
        return 0;
    }

    return soma_ate_recursivo(numero - 1) + numero;
}


int main(void) {

    printf("%d\n", soma_ate_recursivo(0) );

    return 0;
}