#include <stdio.h>

int soma(int x, int y){
   return x + y;
};

int subtracao(int x, int y){
   return x - y;
};

int multiplicacao(int x, int y){
   return x * y;
};

int divisao(int x, int y){
    return x / y;
};

int main(void){

    int selecao, x, y, resultado = 0;

    printf("Calculadora\n");
    printf("Selecione uma opcao:\n");
    printf("1 - Soma\n2 - Subtracao\n3 - Multiplicacao\n4 - Divisao\n0 - Sair\n");

    scanf("%d", &selecao);

    printf("Valores para calculo\n");
    printf("Valor 1: ");
    scanf("%d", &x);
    printf("Valor 2: ");
    scanf("%d", &y);

    switch (selecao){
    case 1:
        resultado = soma(x, y);
        printf("Resultado: %d", resultado);
        break;
    
    case 2:
       resultado = subtracao(x, y);
       printf("Resultado: %d", resultado);
        break;
    
    case 3:
        resultado = multiplicacao(x, y);
        printf("Resultado: %d", resultado);
        break;
    
    case 4:
        if(x == 0 && y == 0){
            printf("Erro: Divisao por zero");
            break;
        } else {
            resultado = divisao(x, y);
            printf("Resultado: %d", resultado);
            break;
        }
    
    default:
        printf("Opcao incorreta\n");
    }
    
    return 0;
}