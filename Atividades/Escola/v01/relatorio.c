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

DataNascimento separa_dma(CadastroAluPro aluno1, CadastroAluPro aluno2){
    DataNascimento dma;
    
    char vNasc[] = "00000000";
    char data_aluno1[] = "00";
    char mes_aluno1[] = "00";
    char ano_aluno1[] = "0000";

    char vNasc2[] = "00000000";
    char data_aluno2[] = "00";
    char mes_aluno2[] = "00";
    char ano_aluno2[] = "0000";

    int i, j = 0;

    // Separa o dia, mes e ano em diferentes arrays
    for(i = 0; i < 12; i++){
        vNasc[i] = aluno1.dataNascimento[j];
        vNasc2[i] = aluno2.dataNascimento[j];
        j++;
        if (aluno1.dataNascimento[j] == '.' || aluno1.dataNascimento[j] == '-' || aluno1.dataNascimento[j] == '/'){
            j = j + 1;
        };
    };    

    j = 0;
    for (i = 0; i < 3; i++){
        if (i==2){
            break;
        } else {
        	data_aluno1[i] = vNasc[i];
            data_aluno2[i] = vNasc2[i];
		};
    };

	j = 0;
    for (; i < 5; i++){
        if (i==4){
            break;
        } else {
        	mes_aluno1[j] = vNasc[i];
            mes_aluno2[j] = vNasc2[i];
        	j++;
		};
    };
    
    j = 0;
    for (; i < 9; i++){
        if (i==8){
            break;
        } else {
        	ano_aluno1[j] = vNasc[i];
            ano_aluno2[j] = vNasc2[i];
        	j++;
		};
	};
    
    //Converte os arrays de string para int.

	int i_ano, i_ano2 = 0;
	int i_dia, i_dia2 = 0;
	int i_mes, i_mes2 = 0;

    for (i = 0; i < 4; i++){
        i_ano = i_ano * 10 + (ano_aluno1[i] - '0');
        i_ano2 = i_ano2 * 10 + (ano_aluno2[i] - '0');
    };
    
    for (i = 0; i < 2; i++){
        i_dia = i_dia * 10 + (data_aluno1[i] - '0');
        i_dia2 = i_dia2 * 10 + (data_aluno2[i] - '0');
    };
    
    for (i = 0; i < 2; i++){
        i_mes = i_mes * 10 + (mes_aluno1[i] - '0');
        i_mes2 = i_mes2 * 10 + (mes_aluno2[i] - '0');
    };

    dma.dia = i_dia;
    dma.mes = i_mes;
    dma.ano = i_ano;

    dma.dia2 = i_dia2;
    dma.mes2 = i_mes2;
    dma.ano2 = i_ano2;

    return dma;

}

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
            for (i = 0; i < 5 /* MUDAR AQUI DEPOIS */; i++){
                aluno = listar_todos_alu_pro(i, 0);
                printf("%s - %d", aluno.nome, aluno.matricula, aluno.cod_disciplina);
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
            char ListaOrdenada[TAM_LISTA][50];
            char temporario[TAM_LISTA];
            
            //Copia os nomes para não serem influenciados no array original
            for (i = 0; i < TAM_LISTA; i++){
                strcpy(ListaOrdenada[i], listaAlunos[i].nome);
            };

            for(i = 0; i < TAM_LISTA; i++){
                for (j = i + 1; j < TAM_LISTA; j++){
                    if(strcmp(ListaOrdenada[i], ListaOrdenada[j]) > 0){ //Compara se algum caractere é diferente. Se for, reordena
                        //Faz a troca e repete as comparações até que esteja tudo ordernado (Dando zero no strcmp)
                        strcpy(temporario, ListaOrdenada[i]);
                        strcpy(ListaOrdenada[i], ListaOrdenada[j]);
                        strcpy(ListaOrdenada[j], temporario);
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
            
        }
        default:
            break;
    }
    
    return 0;
}