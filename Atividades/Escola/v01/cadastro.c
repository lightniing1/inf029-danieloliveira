#include <stdio.h>
#include "cadastro.h"
#include "validacao.h"
#include <string.h>

#define TAM_CPF 15
#define TAM_NOME 50
#define TAM_DATA_NASC 12
#define TAM_LISTA 5

//Funções

DataNascimento separa_dma(char datanascimento[]){
    DataNascimento dma;
    
    char vNasc[] = "00000000";
    char data_aluno1[] = "00";
    char mes_aluno1[] = "00";
    char ano_aluno1[] = "0000";

    int i, j = 0;

    // Separa o dia, mes e ano em diferentes arrays
    for(i = 0; i < 12; i++){
        vNasc[i] = datanascimento[j];
        j++;
        if (datanascimento[j] == '.' || datanascimento[j] == '-' || datanascimento[j] == '/'){
            j = j + 1;
        };
    };    

    j = 0;
    for (i = 0; i < 3; i++){
        if (i==2){
            break;
        } else {
        	data_aluno1[i] = vNasc[i];
		};
    };

	j = 0;
    for (; i < 5; i++){
        if (i==4){
            break;
        } else {
        	mes_aluno1[j] = vNasc[i];
        	j++;
		};
    };
    
    j = 0;
    for (; i < 9; i++){
        if (i==8){
            break;
        } else {
        	ano_aluno1[j] = vNasc[i];
        	j++;
		};
	};
    
    //Converte os arrays de string para int.

	int i_ano = 0;
	int i_dia = 0;
	int i_mes = 0;

    for (i = 0; i < 4; i++){
        i_ano = i_ano * 10 + (ano_aluno1[i] - '0');
    };
    
    for (i = 0; i < 2; i++){
        i_dia = i_dia * 10 + (data_aluno1[i] - '0');
    };
    
    for (i = 0; i < 2; i++){
        i_mes = i_mes * 10 + (mes_aluno1[i] - '0');
    };

    dma.dia = i_dia;
    dma.mes = i_mes;
    dma.ano = i_ano;
    
    return dma;

}

int RegistraAluno(CadastroAluPro aluno){

    static int qtd_alunos = 0;
    static int matriculaAluno = 100000;
    int i = 0;
    int matricula_aluno_atual = 0;

    strcpy(listaAlunos[qtd_alunos].nome, aluno.nome);
    strcpy(listaAlunos[qtd_alunos].CPF, aluno.CPF);

    strcpy(listaAlunos[qtd_alunos].dataNascimento, aluno.dataNascimento);
    
    listaAlunos[qtd_alunos].diamesano.dia = separa_dma(aluno.dataNascimento).dia;
    listaAlunos[qtd_alunos].diamesano.mes = separa_dma(aluno.dataNascimento).mes;
    listaAlunos[qtd_alunos].diamesano.ano = separa_dma(aluno.dataNascimento).ano;
    
    listaAlunos[qtd_alunos].sexo = aluno.sexo;
    listaAlunos[qtd_alunos].cod_disciplina = 0;
    listaAlunos[qtd_alunos].matricula = matriculaAluno;

    printf("%d - %s\n", listaAlunos[qtd_alunos].matricula ,listaAlunos[qtd_alunos].nome);

    matricula_aluno_atual = matriculaAluno;
    qtd_alunos++;
    matriculaAluno++;

   return matricula_aluno_atual;
};

int RegistraProfessor(CadastroAluPro professor){

    static int qtd_professor = 0;
    static int matriculaProfessor = 1000;
    int i = 0;
    int matricula_professor_atual = 0;

    strcpy(listaProfs[qtd_professor].nome, professor.nome);
    strcpy(listaProfs[qtd_professor].CPF, professor.CPF);

    strcpy(listaProfs[qtd_professor].dataNascimento, professor.dataNascimento);

    listaProfs[qtd_professor].diamesano.dia = separa_dma(professor.dataNascimento).dia;
    listaProfs[qtd_professor].diamesano.mes = separa_dma(professor.dataNascimento).mes;
    listaProfs[qtd_professor].diamesano.ano = separa_dma(professor.dataNascimento).ano;

    listaProfs[qtd_professor].sexo = professor.sexo;
    listaProfs[qtd_professor].cod_disciplina = 0;
    listaProfs[qtd_professor].matricula = matriculaProfessor;

    matricula_professor_atual = matriculaProfessor;
    qtd_professor++;
    matriculaProfessor++;

    return matricula_professor_atual;

};

int RegistroDisciplina(Disciplinas disciplina){

    static int qtd_disciplina = 0;
    static int cod_disciplina = 10;
    int i = 0;
    int cod_disciplina_atual = 0;

    strcpy(listaDisciplinas[qtd_disciplina].nome_disciplina, disciplina.nome_disciplina);
    listaDisciplinas[qtd_disciplina].cod_disciplina = cod_disciplina;
    listaDisciplinas[qtd_disciplina].semestre_disciplina = disciplina.semestre_disciplina;

    //Lista nome dos professores cadastrados para registrar na disciplina aqui

    cod_disciplina_atual = cod_disciplina;
    qtd_disciplina++;
    cod_disciplina++;

    return cod_disciplina_atual;
}

int altera_disciplina_aluno_professor(int posicao, int cod_disciplina, int tipo){

    if (tipo == 0){
        listaAlunos[posicao].cod_disciplina = cod_disciplina;
    } else {
        listaProfs[posicao].cod_disciplina = cod_disciplina;
    }

    return 0;

}

int Pesquisa(int matricula){ 

    int posicao = -1;
    int i;

    //Define se é aluno, professor ou disciplina sendo procurado
    if (matricula >= 10 && matricula < 1000){
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
    //listaDisciplinas[posicao].matricula_professor = disciplina.matricula_professor;

    return 0;
}

int ExcluiAluPro (int posicao, int matricula){
    
    int i;
    
    if (matricula >= 10 && matricula < 1000){
        for (i = posicao; i<TAM_LISTA-1; i++){
            strcpy(listaDisciplinas[i].nome_disciplina, listaDisciplinas[i+1].nome_disciplina);
            listaDisciplinas[i].semestre_disciplina = listaDisciplinas[i+1].semestre_disciplina;
        }
    } else if (matricula > 1000 && matricula < 100000){
        for (i = posicao; i<TAM_LISTA-1; i++){
            strcpy(listaProfs[i].nome, listaProfs[i+1].nome);
            strcpy(listaProfs[i].CPF, listaProfs[i+1].CPF);
            strcpy(listaProfs[i].dataNascimento, listaProfs[i+1].dataNascimento);
            listaProfs[i].matricula = listaProfs[i+1].matricula;
            listaProfs[i].sexo = listaProfs[i+1].sexo;
            listaProfs[i].cod_disciplina = listaProfs[i+1].cod_disciplina;
            
        }
    } else {
        for (i = posicao; i<TAM_LISTA-1; i++){
            strcpy(listaAlunos[i].nome, listaAlunos[i+1].nome);
            strcpy(listaAlunos[i].CPF, listaAlunos[i+1].CPF);
            strcpy(listaAlunos[i].dataNascimento, listaAlunos[i+1].dataNascimento);
            listaAlunos[i].matricula = listaAlunos[i+1].matricula;
            listaAlunos[i].sexo = listaAlunos[i+1].sexo;
            listaAlunos[i].cod_disciplina = listaAlunos[i+1].cod_disciplina;
        }
    }
    
    //Teste

    //for (i = 0; i < 5; i++){
    //    printf("Aluno %d: %d - %s\n", i, listaAlunos[i].matricula, listaAlunos[i].nome);
    //}

    return 0;
    
}

int selecaoCadastro(){

    int selecaoCadastro;
    printf("\n");
    printf("**********************\n");
    printf("Modulo Cadastro\n");
    printf("**********************\n");
    printf("O que deseja acessar?\n");
    printf(" 1 - Cadastrar aluno\n 2 - Cadastrar professor\n 3 - Cadastrar disciplina\n 4 - Atualizar Aluno/Professor\n 5 - Atualizar disciplina\n 6 - Excluir Pessoa ou Disciplina\n 0 - Voltar\n");
    scanf("%d", &selecaoCadastro);

    return selecaoCadastro;
}

int mainCadastro(void){
    
    int menu;
    int sair = 0;
    
    char nome[TAM_NOME];
    char sexo;
    char dataNascimento[TAM_DATA_NASC];
    char CPF[TAM_CPF]; 
    char tipo;
    
    int termina;
    //int valida = 0;
    int i;

    int matricula;
    int posicaoMatricula;
    int posicaoDisciplina;
    int opcao_disciplina;
    int cod_disciplina;

    while(!sair)
    {
        menu = selecaoCadastro();
        termina = 0;
        i = 0;

        switch (menu){
            case 1://Cadastra aluno
            {
                CadastroAluPro CadastroAluno;
                DataNascimento dma;

                Limpa_stdin();
                    
                printf("Digite o nome\n");
                fgets(CadastroAluno.nome, TAM_NOME, stdin);
                if (validaNome(CadastroAluno.nome) == 1){
                    printf("Tamanho máximo do nome e 20 caracteres");
                    break;
                };

                Limpa_stdin();

                printf("Digite o Sexo (M - Masculino | F = Feminino\n");
                scanf("%c", &CadastroAluno.sexo);
                if (validaSexo(CadastroAluno.sexo) == 1){
                    printf("Sexo inválido");
                    break;
                };
                    
                Limpa_stdin();
                    
                printf("Digite a Data de Nascimento (Formatos aceito: 00/00/0000)\n");
                fgets(CadastroAluno.dataNascimento, TAM_DATA_NASC, stdin);
                if (validaNascimento(CadastroAluno.dataNascimento) == 1){
                    printf("Data de nascimento inválida");
                    break;
                };
                    
                Limpa_stdin();

                printf("Digite o numero de CPF\n");
                fgets(CadastroAluno.CPF, TAM_CPF, stdin);
                if (validaCPF(CadastroAluno.CPF) == 1){
                    printf("CPF inválido");
                    break;
                };

                matricula = RegistraAluno(CadastroAluno);
                //matricula;
                    
                printf("Deseja incluir o aluno em uma disciplina? 1 - Sim, 0 - Nao\n");
                scanf("%d", &opcao_disciplina);

                if (opcao_disciplina == 1){
                    printf("Codigo da disciplina: \n");
                    scanf("%d", &cod_disciplina);
                    if (Pesquisa(cod_disciplina) == -1){
                        printf("Disciplina nao encontrada");
                    } else {
                        altera_disciplina_aluno_professor(Pesquisa(matricula), cod_disciplina, 0);
                    }
                }    
                break;
            }
            case 2://Cadastra professor
            {          
                CadastroAluPro CadastroProfessor;

                Limpa_stdin();
                
                printf("Digite o nome\n");
                fgets(CadastroProfessor.nome, TAM_NOME, stdin);
                if (validaNome(CadastroProfessor.nome) == 1){
                    printf("Tamanho máximo do nome e 20 caracteres");
                    break;
                }

                Limpa_stdin();

                printf("Digite o Sexo (M - Masculino | F = Feminino | O - Outro\n");
                scanf("%c", &CadastroProfessor.sexo);
                if (validaSexo(CadastroProfessor.sexo) == 1){
                    printf("Sexo inválido");
                    break;
                };

                Limpa_stdin();

                printf("Digite a Data de Nascimento (Formatos aceito: 00/00/0000, 00-00-0000, 00.00.0000)\n");
                fgets(CadastroProfessor.dataNascimento, TAM_DATA_NASC, stdin);
                if (validaNascimento(CadastroProfessor.dataNascimento) == 1){
                    printf("Data de nascimento inválida");
                    break;
                };

                Limpa_stdin();

                printf("Digite o numero de CPF\n");
                fgets(CadastroProfessor.CPF, TAM_CPF, stdin);
                if (validaCPF(CadastroProfessor.CPF) == 1){
                    printf("CPF inválido");
                    break;
                };
                
                matricula = RegistraProfessor(CadastroProfessor);

                printf("Deseja incluir o professor em uma disciplina? 0 - Sim, 1 - Nao\n");
                scanf("%d", &opcao_disciplina);

                if (opcao_disciplina == 0){
                    printf("Codigo da disciplina: \n");
                    scanf("%d", &cod_disciplina);
                    if (Pesquisa(cod_disciplina) == -1){
                        printf("Disciplina nao encontrada");
                    } else {
                        altera_disciplina_aluno_professor(Pesquisa(matricula), cod_disciplina, 0);
                    }  
                }
                break;
            };

            case 3://Cadastra Disciplina
            {          
                Disciplinas CadastroDisciplica;

                Limpa_stdin();

                printf("Nome da disciplina\n");
                fgets(CadastroDisciplica.nome_disciplina, TAM_NOME, stdin);
                if (validaNome(CadastroDisciplica.nome_disciplina) == 1){
                    printf("Nome invalido");
                    break;
                }

                Limpa_stdin();

                printf("Semestre da disciplina\n");
                scanf("%d", &CadastroDisciplica.semestre_disciplina);

                cod_disciplina = RegistroDisciplina(CadastroDisciplica);;

                printf("Codigo da disciplina: %d", cod_disciplina);
                break;
            }
            case 4://Atualiza Aluno ou professor
            {
                CadastroAluPro atualiza;

                printf("Digite o numero de matricula\n");
                scanf("%d", &matricula);

                if (matricula >= 10 && matricula < 1000){
                    printf("Matricula não encontrada\n");
                    break;
                } else if (matricula > 1000 && matricula < 100000){
                    posicaoMatricula = Pesquisa(matricula);
                    if (posicaoMatricula == -1){
                        printf("Matricula nao encontrada\n");
                        break;
                    } else {
                        printf("Atualizando cadastro de professor\n");

                        Limpa_stdin();
                    
                        printf("Digite o nome\n");
                        fgets(atualiza.nome, TAM_NOME, stdin);
                        if (validaNome(atualiza.nome) == 1){
                            printf("Tamanho máximo do nome e 20 caracteres");
                            break;
                        }

                        Limpa_stdin();

                        printf("Digite o Sexo (M - Masculino | F = Feminino | O - Outro\n");
                        scanf("%c", &atualiza.sexo);
                        if (validaSexo(atualiza.sexo) == 1){
                            printf("Sexo inválido");
                            break;
                        };

                        Limpa_stdin();

                        printf("Digite a Data de Nascimento (Formatos aceito: 00/00/0000, 00-00-0000, 00.00.0000)\n");
                        fgets(atualiza.dataNascimento, TAM_DATA_NASC, stdin);
                        if (validaNascimento(atualiza.dataNascimento) == 1){
                            printf("Data de nascimento inválida");
                            break;
                        };

                        Limpa_stdin();

                        printf("Digite o numero de CPF\n");
                        fgets(atualiza.CPF, TAM_CPF, stdin);
                        if (validaCPF(atualiza.CPF) == 1){
                            printf("CPF inválido");
                            break;
                        };  

                        AtualizaAluPro(posicaoMatricula, 1, atualiza);
                        printf("Cadastro atualizado\n");
                    }
                } else if (matricula > 100000){
                    posicaoMatricula = Pesquisa(matricula);
                    if (posicaoMatricula == -1){
                        printf("Matricula nao encontrada\n");
                        break;
                    } else {
                        printf("Atualizando cadastro de aluno\n");

                        Limpa_stdin();
                    
                        printf("Digite o nome\n");
                        fgets(atualiza.nome, TAM_NOME, stdin);
                        if (validaNome(atualiza.nome) == 1){
                            printf("Tamanho máximo do nome e 20 caracteres");
                            break;
                        }

                        Limpa_stdin();

                        printf("Digite o Sexo (M - Masculino | F = Feminino | O - Outro\n");
                        scanf("%c", &atualiza.sexo);
                        if (validaSexo(atualiza.sexo) == 1){
                            printf("Sexo inválido");
                            break;
                        };

                        Limpa_stdin();

                        printf("Digite a Data de Nascimento (Formatos aceito: 00/00/0000, 00-00-0000, 00.00.0000)\n");
                        fgets(atualiza.dataNascimento, TAM_DATA_NASC, stdin);
                        if (validaNascimento(atualiza.dataNascimento) == 1){
                            printf("Data de nascimento inválida");
                            break;
                        };

                        Limpa_stdin();

                        printf("Digite o numero de CPF\n");
                        fgets(atualiza.CPF, TAM_CPF, stdin);
                        if (validaCPF(atualiza.CPF) == 1){
                            printf("CPF inválido");
                            break;
                        };  

                        AtualizaAluPro(posicaoMatricula, 0, atualiza);
                        printf("Cadastro atualizado\n");
                    }
                }
                break;
            }
            case 5://Atualiza Disciplina
            {
                Disciplinas atualizadisciplina;

                printf("Digite o codigo de matricula\n");
                scanf("%d\n", &matricula);

                if (matricula >= 1000 && matricula < 100000){
                    printf("Disciplina nao encontrada");
                } else {
                    posicaoDisciplina = Pesquisa(matricula);
                    if (posicaoDisciplina == -1){
                        printf("Disciplina nao encontrada\n");
                    } else {
                        printf("Nome da disciplina\n");
                        fgets(atualizadisciplina.nome_disciplina, TAM_NOME, stdin);

                        printf("Semestre da disciplina");
                        scanf("%d", &atualizadisciplina.semestre_disciplina);
                        AtualizaDisciplina(posicaoMatricula, atualizadisciplina);
                    }
                }
                break;
            }
            case 6://Exclui aluno, professor ou disciplina
            {
                printf("Digite a matricula ou codigo da disciplina: ");
            	scanf("%d", &matricula);
            	
            	posicaoMatricula = Pesquisa(matricula);
                if (posicaoMatricula == -1){
                    printf("Matricula ou codigo da disciplina nao encontrado\n");
                } else {
                    ExcluiAluPro(posicaoMatricula, matricula);
                }            	
                break;
            }
            case 0:
            {
                sair = 1;
            }
            default:
            {
                printf("Menu inexistente\n");
            }
        }
    }
    return 0;
};