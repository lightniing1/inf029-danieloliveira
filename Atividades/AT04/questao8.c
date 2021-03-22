#include <stdio.h>
#define MAX_NOME 50
#define MAX_DATA_N 10
#define MAX_CPF 12
//https://github.com/renatoln/INF029/blob/master/listas/Lista1-Funcoes.pdf

typedef struct
{
    char nome[MAX_NOME];
    char dataNascimento[MAX_DATA_N];
    char cpf[MAX_CPF];
    char sexo;

} DadosCliente;

DadosCliente Cadastro (char nome[], char data[], char cpf[], char sexo){
    DadosCliente Dado;
        for (int i=0; i<MAX_NOME; i++){
            Dado.nome[i] = nome[i];
        };
        for (int i=0; i<MAX_DATA_N; i++){
            Dado.dataNascimento[i] = data[i];
        };
        for (int i=0; i<MAX_CPF; i++){
            Dado.cpf[i] = cpf[i];
        };
        Dado.sexo = sexo;
    return Dado;
}

int main(void) {
    
    char Nome[MAX_NOME];
    char DataNascimento[MAX_DATA_N];
    char Cpf[MAX_CPF];
    char Sexo;

    printf("Digite o nome: ");
    fgets(Nome, MAX_NOME, stdin);
    printf("Digite a data de nascimento: ");
    fgets(DataNascimento, MAX_DATA_N, stdin);
    printf("Digite o CPF: ");
    fgets(Cpf, MAX_CPF, stdin);
    printf("Digite o Sexo: ");
    scanf(" %c", &Sexo);

    DadosCliente D;
    D = Cadastro(Nome, DataNascimento, Cpf, Sexo);
    printf("Nome: %sData de Nascimento: %s\nCPF: %s\nSexo: %c", D.nome, D.dataNascimento, D.cpf, D.sexo);

    return 0;
    
}