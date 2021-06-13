#include<stdio.h>

int fib(int numero){
    if (numero < 2){
        return 1;
    }

    return fib (numero - 1) + fib (numero - 2);

}


int main(void) {
    printf("%d\n", fib(9) );
    return 0;
}