#include<stdio.h>

int fatorial(int numero){
    if (numero < 1){
        return 1;
    }
    else {
        return numero * fatorial (numero - 1);
    }
}


int main(void) {
    printf("%d\n", fatorial(5) );
    return 0;
}