#include <stdio.h>
#include "cadastro.h"
#include <string.h>

#define TAM_CPF 10
#define TAM_NOME 21
#define TAM_DATA_NASC 11
#define TAM_LISTA 200

//Structs
typedef struct {
    char nome[20];
    char sexo;
    char dataNascimento[11];
    char CPF[12];
    int matricula;
} CadastroAluPro; //Stuct para cadastro de alunos e professores

typedef struct
{
    char nome_disciplina;
    int cod_disciplina;
    int semestre_disciplina;
    CadastroAluPro professor;
} Disciplinas;


//Array das structs | Será necessário zerar esses arrays
CadastroAluPro listaAlunos[TAM_LISTA];
CadastroAluPro listaProfs[TAM_LISTA];
Disciplinas listaDisciplinas[TAM_LISTA];

//Funções
void RegistraAluno(CadastroAluPro aluno){

    static int qtd_alunos = 0;
    static int matriculaAluno = 100001;
    int i = 0;

    //Falta cadastrar outros dados (No momento está cadastrando apenas o nome)

    strcpy(listaAlunos[qtd_alunos].nome, aluno.nome);
    listaAlunos[qtd_alunos].matricula = matriculaAluno;

    qtd_alunos++;
    matriculaAluno++;

    /*
    for (i = 0; i < q_alunos; i++){
        printf("Aluno %d: %s", i, listaAlunos[i].nome);
    }
    */
};

void RegistraProfessor(CadastroAluPro professor){

    static int qtd_professor = 0;
    static int matriculaProfessor = 1001;
    int i = 0;

    //Falta cadastrar outros dados (No momento está cadastrando apenas o nome)
    strcpy(listaProfs[qtd_professor].nome, professor.nome);
    listaProfs[qtd_professor].matricula = matriculaProfessor;

    qtd_professor++;
    matriculaProfessor++;

};

void RegistroDisciplina(Disciplinas disciplina){
    static int qtd_disciplina = 0;
    static int cod_disciplina = 11;
    int i = 0;

    //Falta cadastrar outros dados (Nome professor)
    strcpy(listaDisciplinas[qtd_disciplina].nome_disciplina, disciplina.nome_disciplina);
    listaDisciplinas[qtd_disciplina].cod_disciplina = cod_disciplina;
    listaDisciplinas[qtd_disciplina].semestre_disciplina = disciplina.semestre_disciplina;

    //Lista nome dos professores cadastrados para registrar na disciplina aqui

    qtd_disciplina++;
    cod_disciplina++;
}

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
    
    int termina;
    int i = 0;    

    while(!sair)
    {
        menu = selecaoCadastro();
        termina = 0;

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
            while(!termina){
                
                CadastroAluPro CadastroProfessor[i];

                printf("Nome\n");
                scanf("%s", CadastroProfessor[i].nome);
                /*printf("Sexo\n");
                scanf("%c", &sexo);
                printf("Data\n");
                scanf("%s", dataNascimento);
                printf("CPF\n");
                scanf("%s", CPF);*/

                RegistraAluno(CadastroProfessor[i]);

                i++;

                printf("Continua?\n");
                scanf("%d", &termina);
            }
            break;
        
        case 3:
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