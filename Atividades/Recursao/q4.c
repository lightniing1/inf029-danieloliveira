#include<stdio.h>

int soma_vetor(int numeros[], int tamanho){
    if (tamanho == 0){
        return 0;
    }

    return soma_vetor(numeros, tamanho - 1) + numeros[tamanho-1];
}


int main(void) {

    int vetor[] = {5, 5, 5};
    int tamanho = sizeof(vetor)/sizeof(vetor[0]);

    printf("%d\n", soma_vetor(vetor, tamanho) );

    return 0;
}