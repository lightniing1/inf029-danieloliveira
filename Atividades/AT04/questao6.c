#include <stdio.h>

//https://github.com/renatoln/INF029/blob/master/listas/Lista1-Funcoes.pdf

void ler3Letras(){

    char letra[3];

    printf("Entre com 3 letras\n");

    for (int i = 0; i < 3; i++){
        printf("Qual a %d letra? ", i+1);
        scanf(" %c", &letra[i]);
    };

    for (int i = 0; i < 3; i++){
        printf("%c ", letra[i]);
    };
    
    return;
}

int main(void) {
    
    ler3Letras();

    return 0;
    
}