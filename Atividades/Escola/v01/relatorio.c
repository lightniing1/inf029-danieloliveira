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
        //alu_pro.matricula = listaAlunos[posicao].matricula;
        //alu_pro.sexo = listaAlunos[posicao].sexo;
        alu_pro.cod_disciplina = listaAlunos[posicao].cod_disciplina;

    } else {
        strcpy(alu_pro.nome, listaProfs[posicao].nome);
        //strcpy(alu_pro.CPF, listaProfs[posicao].CPF);
        //strcpy(alu_pro.dataNascimento, listaProfs[posicao].dataNascimento);
        //alu_pro.matricula = listaProfs[posicao].matricula;
        //alu_pro.sexo = listaProfs[posicao].sexo;
         alu_pro.cod_disciplina = listaProfs[posicao].cod_disciplina;
    }
    return alu_pro;
}

Disciplinas listar_todas_disciplinas(int posicao){
    Disciplinas disciplina;
        strcpy(disciplina.nome_disciplina, listaDisciplinas[posicao].nome_disciplina);
        //disciplina.cod_disciplina = listaDisciplinas[posicao].cod_disciplina;
        //disciplina.matricula_professor = listaDisciplinas[posicao].matricula_professor;
        //disciplina.semestre_disciplina = listaDisciplinas[posicao].semestre_disciplina;

    return disciplina;
}

//Vou manter isso em uma função para não perder minha sanidade depois procurando
CadastroAluPro listar_disciplina_com_alunos (int cod_disciplina, int i){
    CadastroAluPro aluno;
        if (listaAlunos[i].cod_disciplina == cod_disciplina){
            return aluno;
        }

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
    int cod_disciplina;

    menuRelatorio();
    scanf("%d", &menu);

    switch (menu){
        case 1://Lista Alunos
        {
            CadastroAluPro aluno;
            printf("Listando alunos...\n");
            for (i = 0; i < 5 /* MUDAR AQUI DEPOIS */; i++){
                aluno = listar_todos_alu_pro(i, 0);
                printf("%s - %d\n", aluno.nome, aluno.cod_disciplina);
            };
            break;
        }

        case 2://Lista Professores
        {
            CadastroAluPro professor;
            printf("Listando professores...\n");
            for (i = 0; i < 5 /* MUDAR AQUI DEPOIS */; i++){
                professor = listar_todos_alu_pro(i, 1);
                printf("%s", professor.nome);
            };
            break;
        }

        case 3://Lista Disciplinas
        {
            Disciplinas disciplina;
            printf("Listando disciplinas...\n");
            for (i = 0; i < 5 /* MUDAR AQUI DEPOIS */; i++){
                disciplina = listar_todas_disciplinas(i);
                printf("%s", disciplina.nome_disciplina);
            };
            break;
        }

        case 4: //Lista uma disciplina com os alunos matriculados
        {
            printf("Digite o código da disciplina\n");
            scanf("%d", &cod_disciplina);
            if (Pesquisa(cod_disciplina) == -1){
                printf("Disciplina não encontrada\n");
                break;
            } else {
                printf("Disciplina: %d", cod_disciplina);
                for(i = 0; i < 5 /*MUDAR AQUI DEPOIS */; i++){
                    if(listaAlunos[i].cod_disciplina == cod_disciplina){
                        printf("%s", listaAlunos[i].nome);
                    }
                }
            }
            break;
        } 

        case 5: //Lista alunos por sexo
        {
            printf("Listando alunos por sexo");
            printf("Masculino(s)");
            for (i = 0; i < 5; i++){
                if (listaAlunos[i].sexo == 'M'){
                    printf("Aluno: %s", listaAlunos[i].nome);
                }
            }
            printf("Feminino(s)");
            for (i = 0; i < 5; i++){
                if (listaAlunos[i].sexo == 'F'){
                    printf("Aluno: %s", listaAlunos[i].nome);
                }
            }
            break;
        }

        case 6: //Lista alunos ordernados por nome
        {
            break;
        }
        default:
            break;
    }
    
    return 0;
}