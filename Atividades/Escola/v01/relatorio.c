#include <stdio.h>
#include <string.h>
#include "cadastro.h"
#include "relatorio.h"

CadastroAluPro listar_todos_alu_pro(int posicao, int tipo){
    CadastroAluPro alu_pro;
    if (tipo == 0){
        strcpy(alu_pro.nome, listaAlunos[posicao].nome);
        strcpy(alu_pro.CPF, listaAlunos[posicao].CPF);
        strcpy(alu_pro.dataNascimento, listaAlunos[posicao].dataNascimento);
        alu_pro.matricula = listaAlunos[posicao].matricula;
        alu_pro.sexo = listaAlunos[posicao].sexo;
        alu_pro.cod_disciplina = listaAlunos[posicao].cod_disciplina;

    } else {
        strcpy(alu_pro.nome, listaProfs[posicao].nome);
        strcpy(alu_pro.CPF, listaProfs[posicao].CPF);
        strcpy(alu_pro.dataNascimento, listaProfs[posicao].dataNascimento);
        alu_pro.matricula = listaProfs[posicao].matricula;
        alu_pro.sexo = listaProfs[posicao].sexo;
        alu_pro.cod_disciplina = listaProfs[posicao].cod_disciplina;
    }
    return alu_pro;
}

Disciplinas listar_todas_disciplinas(int posicao){
    Disciplinas disciplina;
        strcpy(disciplina.nome_disciplina, listaDisciplinas[posicao].nome_disciplina);
        disciplina.cod_disciplina = listaDisciplinas[posicao].cod_disciplina;
        //disciplina.matricula_professo = listaDisciplinas[posicao].matricula_professor;
        disciplina.semestre_disciplina = listaDisciplinas[posicao].semestre_disciplina;

    return disciplina;
}

//Vou manter isso em uma função para não perder minha sanidade depois procurando
CadastroAluPro listar_disciplina_com_alunos (int cod_disciplina, int i){
    CadastroAluPro aluno;
        if (listaAlunos[i].cod_disciplina == cod_disciplina){
            return aluno;
        }

}
/*

*/
int compara_datas(CadastroAluPro aluno1, CadastroAluPro aluno2){
    //Faz a comparação

    

};

void menuRelatorio(){

    printf("*******************\n");
    printf("Modulo Relatório\n");
    printf("*******************\n");
    printf("Qual menu deseja acessar?\n");
    printf("1 - Lista alunos\n 2 - Lista Professores\n 3 - Lista Disciplinas\n 4 - Lista diciplina com alunos matriculados\n 5 - Lista alunos por sexo\n 6 - Lista alunos ordenados por nome\n");

}

int mainRelatorio(void){

    int termina;
    int menu;
    int i, j;
    int cod_disciplina;

    menuRelatorio();
    scanf("%d", &menu);

    switch (menu){
        case 1://Lista Alunos
        {
            CadastroAluPro aluno;
            printf("Listando alunos...\n");
            for (i = 0; i < TAM_LISTA; i++){
                aluno = listar_todos_alu_pro(i, 0);
                printf("%s - %d", aluno.nome, aluno.matricula, aluno.cod_disciplina);
            };
            break;
        }

        case 2://Lista Professores
        {
            CadastroAluPro professor;
            printf("Listando professores...\n");
            for (i = 0; i < TAM_LISTA; i++){
                professor = listar_todos_alu_pro(i, 1);
                printf("%s", professor.nome);
            };
            break;
        }

        case 3://Lista Disciplinas
        {
            Disciplinas disciplina;
            printf("Listando disciplinas...\n");
            for (i = 0; i < TAM_LISTA; i++){
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
                for(i = 0; i < TAM_LISTA; i++){
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
            CadastroAluPro ListaOrdenada[TAM_LISTA];
            CadastroAluPro temporario;
            
            //Copia os nomes para não serem influenciados no array original
            for (i = 0; i < TAM_LISTA; i++){
                ListaOrdenada[i] = listaAlunos[i];
            };

            for(i = 0; i < TAM_LISTA; i++){
                for (j = i + 1; j < TAM_LISTA; j++){
                    if(strcmp(ListaOrdenada[i].nome, ListaOrdenada[j].nome) > 0){ //Compara se algum caractere é diferente. Se for, reordena.
                        //Faz a troca e repete as comparações até que esteja tudo ordernado (Dando zero no strcmp)
                        temporario = ListaOrdenada[i];
                        ListaOrdenada[i] = ListaOrdenada[j];
                        ListaOrdenada[j] = temporario;
                    }
                }
            }

            //Print lista dos alunos
            printf("Alunos em ordem alfabetica");
            for (i = 0; i < TAM_LISTA; i++){
                printf("%s ", ListaOrdenada[i]);
            }

            break;
        }

        case 7: //Lista alunos por data de nascimento
        {
            CadastroAluPro ListaOrdenada[TAM_LISTA];
            CadastroAluPro temporario;

            for (i = 0; i < TAM_LISTA; i++){
                ListaOrdenada[i] = listaAlunos[i];
            }
            
            for (i = 0; i < TAM_LISTA; i++){
                for(j = i + 1; j < TAM_LISTA; j++){
                    if (ListaOrdenada[i].diamesano.ano > ListaOrdenada[j].diamesano.ano){
                       temporario = ListaOrdenada[i];
                       ListaOrdenada[i] = ListaOrdenada[j];
                       ListaOrdenada[j] = temporario;
                    } else if (ListaOrdenada[i].diamesano.ano == ListaOrdenada[j].diamesano.ano && ListaOrdenada[i].diamesano.mes > ListaOrdenada[j].diamesano.mes){
                        temporario = ListaOrdenada[i];
                        ListaOrdenada[i] = ListaOrdenada[j];
                        ListaOrdenada[j] = temporario;
                    } else if (ListaOrdenada[i].diamesano.ano == ListaOrdenada[j].diamesano.ano && ListaOrdenada[i].diamesano.mes == ListaOrdenada[j].diamesano.dia && ListaOrdenada[j].diamesano.dia){
                        temporario = ListaOrdenada[i];
                        ListaOrdenada[i] = ListaOrdenada[j];
                        ListaOrdenada[j] = temporario;
                    }
                }
            }

            printf("Alunos em ordem alfabetica");
            for (i = 0; i < TAM_LISTA; i++){
                printf("%s ", ListaOrdenada[i]);
            }

            break;

        }
        default:
            break;
    }
    
    return 0;
}