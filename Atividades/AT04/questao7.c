#include <stdio.h>

//https://github.com/renatoln/INF029/blob/master/listas/Lista1-Funcoes.pdf

void ler3Palavras(){

    char palavra_1[50];
    char palavra_2[50];
    char palavra_3[50];

    fgets(palavra_1, 50, stdin);
    fgets(palavra_2, 50, stdin);
    fgets(palavra_3, 50, stdin);

    printf("%s", palavra_1);
    printf("%s", palavra_2);
    printf("%s", palavra_3);

    return;
}

int main(void) {
    
    ler3Palavras();

    return 0;
    
}