#include<stdio.h>

int resto, soma;

int inverte(int numero){
    
    if (numero > 0){
        resto = numero % 10;
        soma = soma * 10 + resto;
        inverte(numero / 10);
    }
    else {
        return soma;
    }

}


int main(void) {
    printf("%d\n", inverte(23456) );
    printf("%d\n", inverte(123) );
    return 0;
}