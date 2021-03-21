#include <stdio.h>

//https://github.com/renatoln/INF029/blob/master/listas/Lista1-Funcoes.pdf

char * ler3Letras(char let1, char let2, char let3){

    static char letra[3];

    letra[0] = let1;
    letra[1] = let2;
    letra[2] = let3;
    
    return letra;
}

int main(void) {
    
    char letra1[1];
    char letra2[1];
    char letra3[1];

    char* result;

    printf("Digite a primeira letra: ");
    scanf("%c", &letra1);
    printf("Digite a segunda letra: ");
    scanf(" %c", &letra2);
    printf("Digite a terceira letra: ");
    scanf(" %c", &letra3);

    result = ler3Letras(letra1[0], letra2[0], letra3[0]);

    for (int i = 0; i < 3; i++){
        printf("%c ", result[i]);
    }

    return 0;
    
}