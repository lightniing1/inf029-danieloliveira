#include <stdio.h>
#include "cadastro.h"
#include <string.h>

#define TAM_CPF 10
#define TAM_NOME 21
#define TAM_DATA_NASC 11
#define TAM_LISTA 200

typedef struct {
    char nome[20];
    char sexo;
    char dataNascimento[11];
    char CPF[12];
    int matricula;
} CadastroAluPro;

CadastroAluPro listaAlunos[TAM_LISTA];
CadastroAluPro listaProfs[TAM_LISTA];

/*
CadastroAluPro Cadastro (char nome[], char sexo, char dataNascimento[], char CPF[], char tipo) {
    
    int matricula;

    CadastroAluPro C;
        strcpy(C.nome, nome);
        strcpy(C.CPF, CPF);
        strcpy(C.dataNascimento, dataNascimento);
        C.sexo = sexo;

    return C;
};
*/

void RegistraAluno(CadastroAluPro aluno){

    static int q_alunos = 0;
    
    //Colocar loop aqui

};

int selecaoCadastro(){

    int selecaoCadastro;
    printf("\n");
    printf("**********************\n");
    printf("Modulo Cadastro\n");
    printf("**********************\n");
    printf("O que deseja acessar?\n");
    printf(" 1 - Cadastrar aluno\n 2 - Cadastrar Professor\n 3 - Cadastrar Disciplina\n 4 - Atualizar\n 5 - Excluir\n");
    scanf("%d", &selecaoCadastro);

    return selecaoCadastro;
}

int mainCadastro(void){
    
    int menu;
    int sair = 0;
    
    char nome[20];
    char sexo;
    char dataNascimento[11];
    char CPF[12]; 
    char tipo;
    
    int termina = 0;
    int i = 0;    

    while(!sair)
    {
        menu = selecaoCadastro();

        switch (menu)
        {
        case 1:

            while(!termina){
                
                CadastroAluPro CadastroAluno[i];

                printf("Nome\n");
                scanf("%s", CadastroAluno[i].nome);
                /*printf("Sexo\n");
                scanf("%c", &sexo);
                printf("Data\n");
                scanf("%s", dataNascimento);
                printf("CPF\n");
                scanf("%s", CPF);*/

                RegistraAluno(CadastroAluno[i]);

                i++;

                printf("Continua?\n");
                scanf("%d", &termina);
            }  
            break;

        case 2:
            break;
        
        case 0:
            sair = 1;
            
            break;

        default:
            printf("Menu inexistente\n");
        }
    }

    return 0;
};