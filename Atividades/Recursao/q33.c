#include<stdio.h>

int menor_do_array(int numero[], int tamanho, int menor){

    if (tamanho == 0){
        return menor;
    } 
    
    if (numero[tamanho] < menor){
        menor = numero[tamanho];
        return menor_do_array(numero, tamanho-1, menor);
    }

    return menor_do_array(numero, tamanho-1, menor);
}


int main(void) {

    int array[] = {5,4,3,2,1,4};
    int tamanho = (sizeof(array)/sizeof(array[0])-1);

    printf("%d\n", menor_do_array(array, tamanho, array[0]) );
    return 0;

}