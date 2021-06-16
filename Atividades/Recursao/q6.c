#include<stdio.h>

int potencia(int base, int expoente){

    if (base <= 0){
        return 0;
    } else if (expoente <= 0) {
        return 1;
    }

    return potencia(base, expoente - 1) * base;
}


int main(void) {

    printf("%d\n", potencia(5, 3) );

    return 0;
}