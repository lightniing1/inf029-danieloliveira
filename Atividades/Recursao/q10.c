#include<stdio.h>

int quantas_vezes_aparece(int digitos, int busca){

    int vezes = 0;
    
    if (digitos <= 0){
        return 0;
    } else if ( (digitos%10) == busca) {
        vezes = 1;
    }

    digitos /= 10;

    return quantas_vezes_aparece(digitos, busca) + vezes;
}


int main(void) {

    int vezes = quantas_vezes_aparece(55565, 6);

    printf("%d\n", vezes);
    return 0;

}