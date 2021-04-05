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
    static int matriculaAluno = 100000;
    int i = 0;

    //Falta cadastrar outros dados (No momento está cadastrando apenas o nome)

    strcpy(listaAlunos[qtd_alunos].nome, aluno.nome);
    listaAlunos[qtd_alunos].matricula = matriculaAluno;

    qtd_alunos++;
    matriculaAluno++;

   /* 
    for (i = 0; i < qtd_alunos; i++){
        printf("Aluno %d: %d - %s\n", i, listaAlunos[i].matricula, listaAlunos[i].nome);
    }
    */
};

void RegistraProfessor(CadastroAluPro professor){

    static int qtd_professor = 0;
    static int matriculaProfessor = 1000;
    int i = 0;

    //Falta cadastrar outros dados (No momento está cadastrando apenas o nome)
    strcpy(listaProfs[qtd_professor].nome, professor.nome);
    listaProfs[qtd_professor].matricula = matriculaProfessor;

    qtd_professor++;
    matriculaProfessor++;

};

void RegistroDisciplina(Disciplinas disciplina){

    static int qtd_disciplina = 0;
    static int cod_disciplina = 10;
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

    int inicio = 0;
    int fim = TAM_LISTA;
    int posicao = -1;
    int meio;
    int array_busca;
    int i;

    //Define se é aluno, professor ou disciplina sendo procurado
    if (matricula > 10 && matricula < 1000){
        for (i = 0; i < TAM_LISTA; i++){
            if (listaDisciplinas[i].cod_disciplina == matricula){
                posicao = i;
            }
        }
    } else if (matricula > 1000 && matricula < 100000){
            for (i = 0; i < TAM_LISTA; i++){
                if (listaProfs[i].matricula == matricula){
                    posicao = i;
                }
            }
        } else {
            for (i = 0; i < TAM_LISTA; i++){
                if (listaAlunos[i].matricula == matricula){
                    posicao = i;
				}
			}
		}
    return posicao;
    
}        
    /*
    //Faz a pesquisa binaria

    while(inicio <= fim){
        meio = fim + (inicio - fim) / 2;
        if (array_busca == matricula){
            //posicao = meio;
            return meio;
        } else if (array_busca < matricula){
            inicio = meio + 1;
        } else if (array_busca > matricula){
            fim = meio - 1;
        }
    }
    
    return -1;
    
}
*/
int AtualizaAluPro(int posicao, int tipo, CadastroAluPro alunoprofessor){

    //int array_atualiza;

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

int ExcluiAluPro (int posicao){
    
    int i;

    for (i = posicao; i<TAM_LISTA-1; i++){
       strcpy(listaAlunos[i].nome, listaAlunos[i+1].nome);
       listaAlunos[i].matricula = listaAlunos[i+1].matricula;
       // Colocar o resto dos dados aqui!
    }
    
    //Teste

    for (i = 0; i < 5; i++){
        printf("Aluno %d: %d - %s\n", i, listaAlunos[i].matricula, listaAlunos[i].nome);
    }

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

    int matricula = 0;
    int posicaoMatricula = 0;
    int posicaoDisciplina = 0;


    while(!sair)
    {
        menu = selecaoCadastro();
        termina = 0;

        switch (menu){
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

                    RegistraProfessor(CadastroProfessor[i]);

                    i++;

                    printf("Continua?\n");
                    scanf("%d", &termina);
                }
                break;
            
            case 3:
            {
                while(!termina){
                    
                    Disciplinas CadastroDisciplica[i];

                    printf("Nome\n");
                    scanf("%s", CadastroDisciplica[i].nome_disciplina);
                    /*printf("Sexo\n");
                    scanf("%c", &sexo);
                    printf("Data\n");
                    scanf("%s", dataNascimento);
                    printf("CPF\n");
                    scanf("%s", CPF);*/

                    RegistroDisciplina(CadastroDisciplica[i]);

                    i++;

                    printf("Continua?\n");
                    scanf("%d", &termina);
                }
                break;
            }
            case 4:
            {
                CadastroAluPro atualizaaluno;

                printf("Digite o numero de matricula\n");
                scanf("%d", &matricula);
                posicaoMatricula = Pesquisa(matricula);

                if (posicaoMatricula == -1){
                    printf("Matricula nao encontrada\n");
                } else {
                    printf("Nome\n");
                    scanf("%s", atualizaaluno.nome);
                    /*printf("Sexo\n");
                    scanf("%c", &sexo);
                    printf("Data\n");
                    scanf("%s", dataNascimento);
                    printf("CPF\n");
                    scanf("%s", CPF);*/

                    AtualizaAluPro(posicaoMatricula, 0, atualizaaluno);
                }
                //sair = 1;
                break;
            }
            case 5:
            {
                CadastroAluPro atualizaprofessor;

                printf("Digite o numero de matricula\n");
                scanf("%d", &matricula);
                posicaoMatricula = Pesquisa(matricula);

                if (posicaoMatricula == -1){
                    printf("Matricula nao encontrada\n");
                } else {
                    printf("Nome\n");
                    scanf("%s", atualizaprofessor.nome);
                    /*printf("Sexo\n");
                    scanf("%c", &sexo);
                    printf("Data\n");
                    scanf("%s", dataNascimento);
                    printf("CPF\n");
                    scanf("%s", CPF);*/

                    AtualizaAluPro(posicaoMatricula, 1, atualizaprofessor);
                }
                break;
            }
            case 6:

            {
                Disciplinas atualizadisciplina;

                printf("Digite o codigo de matricula\n");
                scanf("%d\n", &matricula);

                posicaoDisciplina = Pesquisa(matricula);

                if (posicaoDisciplina == -1){
                    printf("Disciplina nao encontrada\n");
                } else {
                    printf("Nome\n");
                    scanf("%s", atualizadisciplina.nome_disciplina);
                    //FALTA COLOCAR OS OUTROS DADOS
                    AtualizaDisciplina(posicaoMatricula, atualizadisciplina);
                }
                break;
            }
            case 7:
                printf("Digite a matricula ou codigo da disciplina: ");
            	scanf("%d", &matricula);
            	
            	posicaoMatricula = Pesquisa(matricula);
            	ExcluiAluPro(posicaoMatricula);
            	
                //Exclui aluno
                break;
                
            default:
                printf("Menu inexistente\n");
            }
    }

    return 0;
};