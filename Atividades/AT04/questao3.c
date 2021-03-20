#include <stdio.h>

//https://github.com/renatoln/INF029/blob/master/listas/Lista1-Funcoes.pdf

int fatorial (int x){

    if (x < 0) {
        //printf("Erro: Numero negativo\n");
        return -1;
    };

    if (x == 0){
        //printf("Fatorial de 0 e 1");
        return 1;
    };
    
    return x * fatorial(x - 1);
}

int main(void) {

    int valor, resultado;

    printf("Entre com o numero para calcular o fatorial ");
    scanf("%d", &valor);

    resultado = fatorial(valor);

    if (resultado == -1){
        printf("Erro: Numero Negativo");
    } else {   
        printf("%d", resultado);
    }

    return 0;
}