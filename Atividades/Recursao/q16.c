#include<stdio.h>

int fatorial_duplo(int numero){
    if (numero < 1){
        return 1;
    }
    else {
        return numero * fatorial_duplo (numero - 2);
    }
}


int main(void) {
    printf("%d\n", fatorial_duplo(5) );
    return 0;
}