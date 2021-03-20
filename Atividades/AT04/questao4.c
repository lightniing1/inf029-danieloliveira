#include <stdio.h>

//https://github.com/renatoln/INF029/blob/master/listas/Lista1-Funcoes.pdf

int ler3Numeros(){

    int arr[3];

    for (int i = 0; i < 3; i++){
        printf("Insira o numero %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    printf("Os 3 numeros sao: ");

    for (int i = 0; i < 3; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}

int main(void) {

    ler3Numeros();

    return 0;
}