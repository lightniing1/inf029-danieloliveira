#include <stdio.h>
#define MAX 50
//https://github.com/renatoln/INF029/blob/master/listas/Lista1-Funcoes.pdf

typedef struct
{
    char palavra1[MAX];
    char palavra2[MAX];
    char palavra3[MAX];
} Palavras;

Palavras ler3Palavras (char pal_1[], char pal_2[], char pal_3[]){
    Palavras P;
        for (int i=0; i<MAX; i++){
            P.palavra1[i] = pal_1[i];
            P.palavra2[i] = pal_2[i];
            P.palavra3[i] = pal_3[i];
        }
    return P;
}

int main(void) {
    
    char palavra_1[MAX];
    char palavra_2[MAX];
    char palavra_3[MAX];

    printf("Digite a primeira palavra: ");
    fgets(palavra_1, MAX, stdin);
    printf("Digite a segunda palavra: ");
    fgets(palavra_2, MAX, stdin);
    printf("Digite a terceira palavra: ");
    fgets(palavra_3, MAX, stdin);

    Palavras Pp;
    Pp = ler3Palavras(palavra_1, palavra_2, palavra_3);
    printf("Palavras 1: %s\nPalavra 2: %s\nPalavra 3 %s", Pp.palavra1, Pp.palavra2, Pp.palavra3);

    return 0;
    
}