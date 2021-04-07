#ifndef CADASTRO_H_INCLUDED
#define CADASTRO_H_INCLUDED

#define TAM_LISTA 200
//Coloca apenas os títulos da função ali

//Structs

typedef struct {
    char nome[22];
    char sexo;
    char dataNascimento[12];
    char CPF[15];
    int matricula;
    int cod_disciplina;
} CadastroAluPro; //Stuct para cadastro de alunos e professores

typedef struct
{
    char nome_disciplina[20];
    int cod_disciplina;
    int semestre_disciplina;
    //int matricula_professor;
    //int matriculas_alunos[40];
} Disciplinas;

CadastroAluPro listaAlunos[TAM_LISTA];
CadastroAluPro listaProfs[TAM_LISTA];
Disciplinas listaDisciplinas[TAM_LISTA];

//char nome[] = "00000000000000000000";

int mainCadastro();
int selecaoCadastro();
int RegistraAluno(CadastroAluPro aluno);
int RegistraProfessor(CadastroAluPro professor);
int RegistroDisciplina(Disciplinas disciplina);
int Pesquisa(int matricula);
int AtualizaAluPro(int posicao, int tipo, CadastroAluPro alunoprofessor);
int AtualizaDisciplina (int posicao, Disciplinas disciplina);
int registra_aluno_professor_disciplina(int posicao, int cod_disciplina, int tipo);


#endif