#include <stdio.h>
#include "cadastro.h"
#include <string.h>

#define TAM_CPF 10
#define TAM_NOME 21
#define TAM_DATA_NASC 11
#define TAM_LISTA 200

//Array das structs | Será necessário zerar esses arrays
//CadastroAluPro listaAlunos[TAM_LISTA];
//CadastroAluPro listaProfs[TAM_LISTA];
//Disciplinas listaDisciplinas[TAM_LISTA];

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

int Pesquisa(int matricula){ 

    //Pesquisa binaria
    int inicio = 0;
    int fim = TAM_LISTA;
    int posicao = -1;
    int meio;
    int array_busca;

    //Define se é aluno, professor ou disciplina sendo procurado
    if (matricula > 10 && matricula < 1000){
        array_busca = listaDisciplinas[meio].cod_disciplina;
    } else {
        if (matricula > 1000 && matricula < 100000){
            array_busca = listaProfs[meio].matricula;
        } else {
            array_busca = listaAlunos[meio].matricula;
        }
    }
    
    //Faz a pesquisa
    while(inicio <= fim){
        meio = fim + (inicio - fim) / 2;
        if (array_busca == matricula){
            posicao = meio;
            break;
        } else if (array_busca < matricula){
            inicio = meio + 1;
        } else if (array_busca > matricula){
            fim = meio - 1;
        }
    }

    return -1;
    
}

int AtualizaAluPro(int posicao, int tipo, CadastroAluPro alunoprofessor){

    int array_atualiza;

    if (tipo == 0){
        strcpy(listaAlunos[posicao].nome, alunoprofessor.nome);
        strcpy(listaAlunos[posicao].dataNascimento, alunoprofessor.dataNascimento);
        strcpy(listaAlunos[posicao].CPF, alunoprofessor.CPF);
        listaAlunos[posicao].sexo = alunoprofessor.sexo;
    } else {
        strcpy(listaProfs[posicao].nome, alunoprofessor.nome);
        strcpy(listaProfs[posicao].dataNascimento, alunoprofessor.dataNascimento);
        strcpy(listaProfs[posicao].CPF, alunoprofessor.CPF);
        listaProfs[posicao].sexo = alunoprofessor.sexo; 
        }

    return 0;
};

int AtualizaDisciplina (int posicao, Disciplinas disciplina){

    strcpy(listaDisciplinas[posicao].nome_disciplina, disciplina.nome_disciplina);
    listaDisciplinas[posicao].semestre_disciplina = disciplina.semestre_disciplina;
    listaDisciplinas[posicao].matricula_professor = disciplina.matricula_professor;

    return 0;
}

int selecaoCadastro(){

    int selecaoCadastro;
    printf("\n");
    printf("**********************\n");
    printf("Modulo Cadastro\n");
    printf("**********************\n");
    printf("O que deseja acessar?\n");
    printf(" 1 - Cadastrar aluno\n 2 - Cadastrar professor\n 3 - Cadastrar disciplina\n 4 - Atualizar aluno\n 5 - Atualizar professor\n 6 - Atualizar disciplina\n 7 - Excluir\n");
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