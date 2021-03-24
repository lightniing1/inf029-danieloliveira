#include <stdio.h>

#define MAX_NOME 50
#define MAX_DATA_N 12
#define MAX_CPF 15

//https://github.com/renatoln/INF029/blob/master/listas/Lista1-Funcoes.pdf


typedef struct
{
    char nome[MAX_NOME];
    char dataNascimento[MAX_DATA_N];
    char cpf[MAX_CPF];
    char sexo;
    char erro[MAX_NOME];

} DadosCliente;


int validaNome (char nome[]){
	
	int i;
	
    for(i = 0; i < 22; i++){
        if (nome[20] != '\0'){
            return 1;
        } else {
            return 0;
        }
    }
}

int validaSexo (char sexo){

    if (sexo == 'M' || sexo == 'm' || sexo == 'F' || sexo == 'f' || sexo == 'O' || sexo == 'o'){
        return 0;
    } else {
        return 1;
    }
}

int validaCPF (char CPF[]){

    int vCPF[11];
    int digito_1 = 0;
    int digito_2 = 0;
    
    int i, j = 0;

    for(i = 0; i < 11; i++){
        vCPF[i] = CPF[j] - '0';
        j++;
        if (CPF[j] == '.' || CPF[j] == '-'){
            j = j + 1;
        }
    }

    //Colocar aqui função para validar o CPF
    
    j = 10;
    for (i = 0; i < 9; i++){
        digito_1 += vCPF[i] * j;
        j--;
    }

    if (digito_1 % 11 < 2){
        digito_1 = 0;
    } else {
        digito_1 = 11 - (digito_1 % 11);
    }

    if (vCPF[9] != digito_1){
        return 1;
    } else {
        j = 11;
        for (i = 0; i < 10; i++){
            digito_2 += vCPF[i] * j;
            j--;
        }
        if (digito_2 % 11 < 0){
            digito_2 = 0;
        } else {
            digito_2 = 11 - (digito_2 % 11);
            if (vCPF[10] =! digito_2){
                return 1;
            } else {
                return 0;
            }
        }
    }
}


int validaNascimento (char nasc[]){

    char vNasc[] = "00000000";
    char data[] = "00";
    char mes[] = "00";
    char ano[] = "0000";

    int i, j = 0;

    // Separa o dia, mes e ano em diferentes arrays
    for(i = 0; i < 12; i++){
        vNasc[i] = nasc[j];
        j++;
        if (nasc[j] == '.' || nasc[j] == '-' || nasc[j] == '/'){
            j = j + 1;
        }
    }    

    for (i = 0; i < 3; i++){
        if (i==2){
            break;
        } else {
        	data[i] = vNasc[i];
		}

    }

	j = 0;
    for (; i < 5; i++){
        if (i==4){
            break;
        } else {
        	mes[j] = vNasc[i];
        	j++;
		}
    }
    
    j = 0;
    for (; i < 9; i++){
        if (i==8){
            break;
        } else {
        	ano[j] = vNasc[i];
        	j++;
		}
	}
    
    //Converte os arrays de string para int. Tem jeito melhor mas agora não da.

    int i_ano, i_mes, i_dia;

    sscanf(ano,"%d", &i_ano);
    sscanf(mes,"%d", &i_mes);
    sscanf(data,"%d", &i_dia);

    //Verifica se é ano bissexto
    int bissexto;

    if ((i_ano % 4 == 0) && (i_ano % 100 != 0) || (i_ano % 400 == 0)) {
        bissexto = 1;
    } else { 
        bissexto = 0;
    };

    //Verifica se o dia, mes e ano | Um switch seria melhor aqui

    if ( (i_mes == 1 || i_mes == 3 || i_mes == 5 || i_mes == 7 || i_mes == 8 || i_mes == 10 || i_mes == 12) && i_dia > 0 && i_dia <= 31 ){
        ///printf("Mes Valida (1)");
        return 0;
    } else if (i_mes == 4 || i_mes == 6 || i_mes == 9 || i_mes == 11 && i_dia > 0 && i_dia <= 30){
        //printf("Mes Valida (2)");
        return 0;
    } else if (i_mes == 2){
        if ( (bissexto == 1) && (i_dia > 0 && i_dia <= 29) ){
            //printf("Data Valida (3)");
            return 0;
        } else if ((bissexto == 0) && (i_dia > 0 && i_dia <= 28)){
            //printf("Data Valida (3)");
            return 0;
        } else {
            //printf("Data invalida (3)");
            return 1;
        };
    }
}


DadosCliente Cadastro (char nome[], char data[], char cpf[], char sexo){
    DadosCliente Dado;

    char Erro_nome[] = "Erro: Nome com mais de 20 caracteres";
    char Erro_cpf[] = "Erro: CPF Invalido";
    char Erro_data[] = "Erro: Data invalida";
    char Erro_sexo[] = "Erro: Sexo invalido";
	
	int i;
	
    if (validaNome(nome) != 0){
        for (i=0; i<MAX_NOME; i++){
            Dado.erro[i] = Erro_nome[i];
        }
    } else {
        for (i=0; i<21; i++){
            Dado.nome[i] = nome[i];
        }
        //Dado.erro[0] = '\0';
    };
        
    if (validaCPF(cpf) != 0){
        for (i=0; i<MAX_NOME; i++){
            Dado.erro[i] = Erro_cpf[i];
        }
    } else {
        for (i=0; i<MAX_CPF; i++){
            Dado.cpf[i] = cpf[i];
        }
        //Dado.erro[0] = '\0';
    };

    if (validaNascimento(data) != 0){
        for (i=0; i<MAX_NOME; i++){
            Dado.erro[i] = Erro_data[i];
        }
    } else {
        for (i=0; i<MAX_DATA_N; i++){
            Dado.dataNascimento[i] = data[i];
        }
        //Dado.erro[0] = '\0';
    };

    if (validaSexo(sexo) != 0){
        for (i=0; i<MAX_NOME; i++){
            Dado.erro[i] = Erro_sexo[i];
        }
    } else {
        Dado.sexo = sexo;
       // Dado.erro[0] = '\0';
    };    

    return Dado;

   /*
    for (int i=0; i<MAX_NOME; i++){
        Dado.nome[i] = nome[i];
        if (nome[i] = '\0'){
            break;
        }
    };
    for (int i=0; i<MAX_DATA_N; i++){
        Dado.dataNascimento[i] = data[i];
        if (data[i] = '\0'){
            break;
        }
    };
    for (int i=0; i<MAX_CPF; i++){
        Dado.cpf[i] = cpf[i];
        if (cpf[i] = '\0'){
            break;
        }
    };
    
    Dado.sexo = sexo;

    return Dado;
    */
}

void Stdin(void)
{
    int c = 0;
    while ((c = getchar()) != '\n' && c != EOF) {}
    return;
}

int main(void) {
    
    char Nome[MAX_NOME];
    char DataNascimento[MAX_DATA_N];
    char Cpf[MAX_CPF];
    char Sexo;
    
    printf("Digite o nome: ");
    fgets(Nome, MAX_NOME, stdin);
    Stdin(); 
    printf("Digite a data de nascimento: ");
    fgets(DataNascimento, MAX_DATA_N, stdin);
    Stdin();
    printf("Digite o CPF: ");
    fgets(Cpf, MAX_CPF, stdin);
    Stdin();
    printf("Digite o Sexo: ");
    scanf(" %c", &Sexo);
    

    DadosCliente D;
    D = Cadastro(Nome, DataNascimento, Cpf, Sexo);

    //printf("%s\n", D.erro);

    printf("Nome: %s\nData de Nascimento: %s\nCPF: %s\nSexo: %c", D.nome, D.dataNascimento, D.cpf, D.sexo);

    return 0;
    
}