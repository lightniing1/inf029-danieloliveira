#ifndef CADASTRO_H_INCLUDED
#define CADASTRO_H_INCLUDED

#define TAM_LISTA 200
//Coloca apenas os títulos da função ali

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
    char nome_disciplina[20];
    int cod_disciplina;
    int semestre_disciplina;
    int matricula_professor;
} Disciplinas;

CadastroAluPro listaAlunos[TAM_LISTA];
CadastroAluPro listaProfs[TAM_LISTA];
Disciplinas listaDisciplinas[TAM_LISTA];

int mainCadastro();
int selecaoCadastro();
void RegistraAluno(CadastroAluPro aluno);
void RegistraProfessor(CadastroAluPro professor);
void RegistroDisciplina(Disciplinas disciplina);
int Pesquisa(int matricula);
int AtualizaAluPro(int posicao, int tipo, CadastroAluPro alunoprofessor);
int AtualizaDisciplina (int posicao, Disciplinas disciplina);


#endif