#include <stdio.h>
#define MAX_NOME 30
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

/*
int validaNome (char nome[]){

    for(int i = 0; i < 22; i++){
        if (nome[20] != '\0'){
            return 1;
        }
    }

    return 0;
}

int validaSexo (char sexo){

    if (sexo == 'M' || sexo == 'm' || sexo == 'F' || sexo == 'f' || sexo == 'O' || sexo == 'o'){
        return 0;
    } else {
        return 1;
    }
}
*/
int validaCPF (char CPF[]){

    char vCPF[15];
    
    int i, j = 0;

    for(i = 0; i < 15; i++){
        vCPF[i] = CPF[j];
        j++;
        if (CPF[j] == '.' || CPF[j] == '-'){
            j = j + 1;
        }
    }
    
    return 0;
}

int validaNascimento (char nasc[]){
    return 0;
}

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
    
    char Nome[] = "testetestetesteteste";
    char DataNascimento[MAX_DATA_N];
    char Cpf[] = "068.343.445-43";
    char Sexo;

    //printf("Digite o nome: ");
    //fgets(Nome, MAX_NOME, stdin);
    //printf("Digite a data de nascimento: ");
    //fgets(DataNascimento, MAX_DATA_N, stdin);
    //printf("Digite o CPF: ");
    //fgets(Cpf, MAX_CPF, stdin);
    //printf("Digite o Sexo: ");
    //scanf(" %c", &Sexo);

    validaCPF(Cpf);

    //DadosCliente D;
    //D = Cadastro(Nome, DataNascimento, Cpf, Sexo);
    //printf("Nome: %sData de Nascimento: %s\nCPF: %s\nSexo: %c", D.nome, D.dataNascimento, D.cpf, D.sexo);

    return 0;
    
}