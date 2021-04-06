#include <stdio.h>
#include "cadastro.h"
#include "relatorio.h"

int SelecaoMenu(){

    int selecao;

    printf("O que deseja acessar?\n");
    printf(" 1 - Cadastro\n 2 - Relatorios\n 0 - Sair\n");
    scanf("%d", &selecao);

    return selecao;

}

int main(void)
{
    int menu;
    int sair = 0;
    int i = 0;

    while(!sair)
    {
        menu = SelecaoMenu();

        switch (menu)
        {
        case 1:
            mainCadastro();
            break;

        case 2:
            mainRelatorio();
            break;
        
        case 0:
            sair = 1;
            break;

        default:
            printf("Menu inexistente\n");
        }
    }
}
