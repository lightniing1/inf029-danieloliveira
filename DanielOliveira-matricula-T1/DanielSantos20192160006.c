// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Daniel Oliveira dos Santos
//  email: dan-@Outlook.com
//  Matrícula: 20192160006
//  Semestre: 2

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 20/06/2018 - 19/08/2016

// #################################################

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "DanielSantos20192160006.h"

void remove_acentos(char *letra_modificada){
    
    int i;

    for (i = 0; letra_modificada[i] != '\0'; i++){
        if (letra_modificada[i] == 0xC3A1){
            letra_modificada[i] =  'a';
        }
    }
};

/*
## função utilizada para testes  ##

 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y)
{
    int soma = 0;
    soma = x + y;
    return soma;
}

/*
## função utilizada para testes  ##

 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x)
{ //função utilizada para testes
    int fat = 1;
    return fat;
}

/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)   
    pode utilizar strlen para pegar o tamanho da string
 */
int q1(char *nasc)
{
    //quebrar a string data em strings sDia, sMes, sAno

    //converter sDia, sMes e sAno em inteiros (ex: atoi)

    //criar as variáveis iDia, iMes, iAno

    //printf("%s\n", data);

    char sDia[3];
    char sMes[3];
    char sAno[5];
    int i = 0;
    int j;

    int iDia, iMes, iAno = 0;
    int bissexto;
    int datavalida = 0;

    for (i = 0; nasc[i] != '\0'; i++){
        if (nasc[i] != '/'){
            sDia[i] = nasc[i];
        } else {
            sDia[i] = '\0';
            i++;
            break;
        }
    }
    
    j = 0;
    for (; nasc[i] != '\0'; i++){
        if (nasc[i] != '/'){
            sMes[j] = nasc[i];
            j++;
        } else {
            sMes[j] = '\0';
            i++;
            break;
        }
    }
    
    j = 0;
    for (; nasc[i] != '\0'; i++){
        if (nasc[i] != '/'){
            sAno[j] = nasc[i];
            j++;
        } else {
            sAno[j] = '\0';
            break;
        }
    }

    iDia = atoi(sDia);
    iMes = atoi(sMes);
    iAno = atoi(sAno);
    
    
    //printf("Dia: %d\n", iDia);
    //printf("Mes: %d\n", iMes);
    //printf("Ano: %d\n", iAno);
    
   
    if ( (iAno % 4 == 0 && iAno % 100 != 0) || (iAno % 400 == 0)) {
        bissexto = 1;
    } else { 
        bissexto = 0;
    };
    
    if ( (iAno > 0 && iAno < 99) || (iAno > 1800 && iAno < 9999) )
    {
        if (iMes == 2)
        {
            if (iDia == 29 && bissexto == 1)
            {
                datavalida = 1;
            }
            
            else if (iDia >= 1 && iDia <= 28)
            {
                datavalida = 1;
            }
        }
        else if (iMes == 1 || iMes == 3 || iMes == 5 || iMes == 7 || iMes == 8 || iMes == 10 || iMes == 12)
        {
            if (iDia >= 1 && iDia <= 31)
            {
                datavalida = 1;
            }
        }
        else if (iMes == 4 || iMes == 6 || iMes == 9 || iMes == 11)
        {
            if (iDia >= 1 && iDia <= 30)
            {
                datavalida = 1;
            }
        }
        else
        {
            datavalida = 0;
        }
    }
    
    return datavalida;
}

/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. Além disso, a função tem três parâmetros qtdDias, qtdMeses e qtdAnos. 
    Esses três parâmetros devem ser utilizados para guardar os resultados dos cálculos. Na chamada da função deve passar o valor -1 para os três
 @saida
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
 */
int q2(char *datainicial, char *datafinal, int *qtdDias, int *qtdMeses, int *qtdAnos)
{
    //calcule os dados e armazene nas três variáveis a seguir
    int nDias, nMeses, nAnos;

    char sDia[3];
    char sMes[3];
    char sAno[5];

    int i, j = 0;

    int data_inicial_dia, data_inicial_mes, data_inicial_ano = 0;
    int data_final_dia, data_final_mes, data_final_ano = 0;

    //Separa data inicial
    for (i = 0; datainicial[i] != '\0'; i++){
        if (datainicial[i] != '/'){
            sDia[i] = datainicial[i];
        } else {
            sDia[i] = '\0';
            i++;
            break;
        }
    }
    
    j = 0;
    for (; datainicial[i] != '\0'; i++){
        if (datainicial[i] != '/'){
            sMes[j] = datainicial[i];
            j++;
        } else {
            sMes[j] = '\0';
            i++;
            break;
        }
    }
    
    j = 0;
    for (; datainicial[i] != '\0'; i++){
        if (datainicial[i] != '/'){
            sAno[j] = datainicial[i];
            j++;
        } else {
            sAno[j] = '\0';
            break;
        }
    }

    data_inicial_dia = atoi(sDia);
    data_inicial_mes = atoi(sMes);
    data_inicial_ano = atoi(sAno);

    //Separa data final
    for (i = 0; datafinal[i] != '\0'; i++){
        if (datafinal[i] != '/'){
            sDia[i] = datafinal[i];
        } else {
            sDia[i] = '\0';
            i++;
            break;
        }
    }
    
    j = 0;
    for (; datafinal[i] != '\0'; i++){
        if (datafinal[i] != '/'){
            sMes[j] = datafinal[i];
            j++;
        } else {
            sMes[j] = '\0';
            i++;
            break;
        }
    }
    
    j = 0;
    for (; datafinal[i] != '\0'; i++){
        if (datafinal[i] != '/'){
            sAno[j] = datafinal[i];
            j++;
        } else {
            sAno[j] = '\0';
            break;
        }
    }

    data_final_dia = atoi(sDia);
    data_final_mes = atoi(sMes);
    data_final_ano = atoi(sAno);

    /*mantenha o código abaixo, para salvar os dados em 
    nos parâmetros da funcao
    */

    //Faz os calculos
    if (q1(datainicial) == 0)
    {
        return 2;
    }
    else 
    {
        if (q1(datafinal) == 0)
        {
            return 3;
        }
        else
        {
            if ( (data_inicial_ano > data_final_ano) || ( (data_inicial_ano == data_final_ano) && (data_inicial_mes > data_final_mes) ) || ( (data_inicial_ano == data_final_ano) && (data_inicial_mes == data_final_mes) && (data_inicial_dia > data_final_dia) ) )
            {
                return 4;
            }
            else
            {
                //Corrigir aqui!!! Considerar quando os anos são de dois digitos e fazer a subtração das datas corretamente
                nAnos = data_final_ano - data_inicial_ano;
                nDias = data_final_dia - data_inicial_dia;
                nMeses = data_final_mes - data_inicial_mes;
                
                *qtdDias = nDias;
    			*qtdAnos = nAnos;
    			*qtdMeses = nMeses;
                
                return 1;
            }
        }
    }

    //coloque o retorno correto
}


/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive)
{

    //Corrigir: Remover os acentos do texto e da letra busca!!

    int qtdOcorrencias = 0;
    int i;

    //remove_acentos(texto);

    for (i=0; texto[i] != '\0'; i++){
        if (isCaseSensitive == 0) {
            if (c >= 'a' && c <= 'z'){
                if ( (texto[i] == c) || (texto[i] == c - 32) ){
                    qtdOcorrencias += 1;
                }
            } else {
                if (texto[i] == c || texto[i] == c + 32){
                    qtdOcorrencias += 1;
                }
            }
        } else {
            if (texto[i] == c){
                qtdOcorrencias += 1;
            }
        }
    }

    return qtdOcorrencias;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com 
    o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. 
    Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;

 */
int q4(char *strTexto, char *strBusca, int posicoes[30])

//Corrigir: Se o texto/palavra tiver acento, ele considera o acento e a contagem fica errada!
//letras acentuadas não faz parte da ascii e tem dois bytes.

{
    int qtdOcorrencias = 0;
    int i, j, k = 0;
    int inicio, fim;
    int tamanho_string_busca;

    //remove_acentos(strTexto);
    //remove_acentos(strBusca);

    for (i=0; strTexto[i] != '\0'; i++){
         if (strTexto[i] == strBusca[0]){
            inicio = i;
            while (strTexto[i] == strBusca[j]){
                i++;
                j++;
                fim = i;
            }
        }

        //fim = i;
        j = 0;
        tamanho_string_busca = fim - inicio;

        if (strlen(strBusca) == (fim-inicio) ){
            posicoes[k] = inicio+1;
            k++;
            posicoes[k] = fim;
            k++;
            qtdOcorrencias += 1;
            tamanho_string_busca = 0;
            inicio = 0;
        }
    }

    return qtdOcorrencias;
}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num)
{

    char num_string[50];
    char num_string_invertido[50];
    int tamanho;
    int i;

    //itoa(num, num_string, 10);
    sprintf(num_string, "%d", num);
    tamanho = strlen(num_string);

    for (i=0; tamanho>=0; tamanho--, i++){
        if (num_string[tamanho] == '\0'){
            i--;
        } else {
            num_string_invertido[i] = num_string[tamanho];
        }
    }

    num = atoi(num_string_invertido);

    return num;
}

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca)
{

    char num_base_string[50];
    char num_busca_string[50];

    //itoa(numerobase, num_base_string, 10);
    //itoa(numerobusca, num_busca_string, 10);

    sprintf(num_base_string, "%d", numerobase);
    sprintf(num_busca_string, "%d", numerobusca);

    int qtdOcorrencias = 0;
    int i, j, k = 0;
    int inicio, fim;
    int tamanho_string_busca;

    tamanho_string_busca = strlen(num_busca_string);

    for (i=0; num_base_string[i] != '\0'; i++){
        if (num_base_string[i] == num_busca_string[0]){
            while (num_base_string[i] == num_busca_string[j]){
                i++;
                j++;
                if (j == tamanho_string_busca){
                    qtdOcorrencias = qtdOcorrencias + 1;
                    j = 0;
                }
            }
        }
        j = 0;
    }

    return qtdOcorrencias;
}
