#include <stdio.h>
#include <string.h>
#include "cadastro.h"
#include "relatorio.h"

CadastroAluPro listar_todos_alu_pro(int posicao, int tipo){
    CadastroAluPro alu_pro;
    if (tipo == 0){
        strcpy(alu_pro.nome, listaAlunos[posicao].nome);
        //strcpy(alu_pro.CPF, listaAlunos[posicao].CPF);
        //strcpy(alu_pro.dataNascimento, listaAlunos[posicao].dataNascimento);
        //listaAlunos[posicao].matricula = alu_pro.matricula;
        //listaAlunos[posicao].sexo = alu_pro.sexo;
        listaAlunos[posicao].cod_disciplina = alu_pro.cod_disciplina;
    } else {
        strcpy(alu_pro.nome, listaProfs[posicao].nome);
        //strcpy(alu_pro.CPF, listaProfs[posicao].CPF);
        //strcpy(alu_pro.dataNascimento, listaProfs[posicao].dataNascimento);
        //listaProfs[posicao].matricula = alu_pro.matricula;
        //listaProfs[posicao].sexo = alu_pro.sexo;
        listaProfs[posicao].cod_disciplina = alu_pro.cod_disciplina;
    }
    return alu_pro;
}

Disciplinas listar_todas_disciplinas(int posicao){
    Disciplinas disciplina;
        strcpy(disciplina.nome_disciplina, listaDisciplinas[posicao].nome_disciplina);
        //listaDisciplinas[posicao].cod_disciplina = disciplina.cod_disciplina;
        //listaDisciplinas[posicao].matricula_professor = disciplina.matricula_professor;
        //listaDisciplinas[posicao].semestre_disciplina = disciplina.semestre_disciplina;

    return disciplina;
}

void menuRelatorio(){

    printf("*******************\n");
    printf("Modulo Relatório\n");
    printf("*******************\n");
    printf("Qual menu deseja acessar?\n");
    printf("1 - Alunos\n 2 - Professores\n 3 - Disciplinas\n");

}


int mainRelatorio(void){

    int termina;
    int menu;
    int i;

    menuRelatorio();
    scanf("%d", &menu);

    switch (menu){
        case 1:
        {
            CadastroAluPro aluno;
            printf("Listando alunos...\n");
            for (i = 0; i < 5 /* MUDAR AQUI DEPOIS */; i++){
                aluno = listar_todos_alu_pro(i, 0);
                printf("%s", aluno.nome);
                printf("%d", aluno.cod_disciplina);
            };
            break;
        }

        case 2:
        {
            CadastroAluPro professor;
            printf("Listando professores...\n");
            for (i = 0; i < 5 /* MUDAR AQUI DEPOIS */; i++){
                professor = listar_todos_alu_pro(i, 1);
                printf("%s", professor.nome);
            };
            break;
        }

        case 3:
        {
            Disciplinas disciplina;
            printf("Listando disciplinas...\n");
            for (i = 0; i < 5 /* MUDAR AQUI DEPOIS */; i++){
                disciplina = listar_todas_disciplinas(i);
                printf("%s", disciplina.nome_disciplina);
            };
            break;
        } 
        default:
            break;
    }
    
    return 0;
}