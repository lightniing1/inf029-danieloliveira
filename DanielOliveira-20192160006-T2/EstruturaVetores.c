#include <stdio.h>
#include <stdlib.h>
#define TAM 10

#include "EstruturaVetores.h"

int *vetor_principal[TAM];

void dobrar(int *x)
{

    *x = *x * 2;
}

// se posição é um valor válido {entre 1 e 10}
int ehPosicaoValida(int posicao)
{
    int retorno = 0;
    if (posicao < 1 || posicao > 10)
    {
        retorno = POSICAO_INVALIDA;
    }
    else
        retorno = SUCESSO;

    return retorno;
}

//Copia itens do array principal para qualquer vetor auxiliar
void copia_array_principal (int posicao, int *vetor_destino){
    
    //vetor_fonte é o vetor principal
    int i, j;
    int tamanho_do_array = *(vetor_principal[posicao]); //índice 0 do array principal contem o tamanho dele mesmo
    int qtd_elementos = *(vetor_principal[posicao]+1); // índice 1 do array a ser copiado tem a quantidade de elementos

    for (i = 0; i < qtd_elementos; i++){
        vetor_destino[i] = *(vetor_principal[posicao]+(2+i));
    };

}

void ordena_array (int vetor[], int tamanho_do_array){

    int i, j;
    int aux;

    for (i = 0; i < tamanho_do_array-1; i++){
        for (j = i+1; j < tamanho_do_array; j++){
            if (vetor[i] > vetor[j] ){
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
        }
    }

}

/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'

Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho tem inteiro maior ou igual a 1
*/


int criarEstruturaAuxiliar(int posicao, int tamanho)
{
    int retorno = 0;

    if (vetor_principal[posicao] == NULL){

        if (ehPosicaoValida(posicao) == POSICAO_INVALIDA){
            
            retorno = ehPosicaoValida(posicao);

        } else if (tamanho < 1){

            retorno = TAMANHO_INVALIDO;

        } else {

            int *vetor_aux = (int *) malloc ( (tamanho+2) * sizeof (int) ); //Tamanho + 2 para guarda o tamanho do array no index 0 dele e a qtd de elemntos no index 1
            vetor_principal[posicao] = vetor_aux;

            vetor_aux[0] = tamanho; //Guarda o tamanho do array na posicao 0
            vetor_aux[1] = 0; //Quantidade de elementos na estrutura

            retorno = SUCESSO;
        }
    }  else  {

        retorno = JA_TEM_ESTRUTURA_AUXILIAR;
    }

    return retorno;
}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/

int inserirNumeroEmEstrutura(int posicao, int valor)
{
    int retorno = 0;

    int i;
    int tamanho_do_array;
    int qtd_elementos;

    if (ehPosicaoValida(posicao) == POSICAO_INVALIDA){
        retorno = ehPosicaoValida(posicao);
    }
    else
    {
        if (vetor_principal[posicao] != NULL) //Se ja tiver estrutura
        {
            tamanho_do_array = *(vetor_principal[posicao]);
            qtd_elementos = *(vetor_principal[posicao]+1);

            if (qtd_elementos == tamanho_do_array){
                retorno = SEM_ESPACO;
            }
            else 
            {
                //Coloca o valor no espaço disponivel. Valor +2 na frente pois os dois primeiros estao reservados
                *(vetor_principal[posicao]+(2+qtd_elementos)) = valor;
                *(vetor_principal[posicao]+1) += 1;
                retorno = SUCESSO;

            }
        }
        else
        {
            retorno = SEM_ESTRUTURA_AUXILIAR;
        }
    }

    return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica

Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar 
*/
int excluirNumeroDoFinaldaEstrutura(int posicao)
{
    int retorno;
    int tamanho_do_array, qtd_elementos;
    int i;
    int array_vazio = 0;

    if (ehPosicaoValida(posicao) == POSICAO_INVALIDA){
        retorno = ehPosicaoValida(posicao);
    } 
    else if (vetor_principal[posicao] != NULL) //Se existir estrutura na posicao
    {   
        tamanho_do_array = *(vetor_principal[posicao]);
        qtd_elementos = *(vetor_principal[posicao]+1);
        

        if (qtd_elementos == 0){

            retorno = ESTRUTURA_AUXILIAR_VAZIA;

        } else {

            //*(vetor_principal[posicao]+(2+qtd_elementos)) = '\0'; //Coloca null no ultimo numero
            *(vetor_principal[posicao]+1) -= 1;

            retorno = SUCESSO;
        }


    } else {
        retorno = SEM_ESTRUTURA_AUXILIAR;
    }


    return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar

*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor)
{
    int retorno;
    int tamanho_do_array;
    int qtd_elementos;
    int i, j;

    if (ehPosicaoValida(posicao) == POSICAO_INVALIDA){
        retorno = ehPosicaoValida(posicao);
    }
    else if (vetor_principal[posicao] != NULL)
    {
        tamanho_do_array = *(vetor_principal[posicao]);
        qtd_elementos = *(vetor_principal[posicao]+1);
        
        if (qtd_elementos == 0){
            retorno = ESTRUTURA_AUXILIAR_VAZIA;
        }
        else 
        {
            //Faz busca sequencial e elimina o valor sobrepondo com o proximo item que tem no array
            for (i = 2; i <= tamanho_do_array; i++){
                if (*(vetor_principal[posicao]+i) == valor){
                    for (j = i; j <= tamanho_do_array-1; j++){ //Pode precisar de -1
                        *(vetor_principal[posicao]+j) = *(vetor_principal[posicao]+(j+1));
                        *(vetor_principal[posicao]+1) -= 1;
                        //if (j == tamanho_do_array){
                        ///    *(vetor_principal[posicao]+j) = '\0'; //coloca null o ultimo array
                            //Sinto que vai dar erro
                        //}
                    }
                    retorno = SUCESSO;
                } else {
                    retorno = NUMERO_INEXISTENTE;
                }
                break;
            }      
        }
    } 
    else 
    {
        retorno = SEM_ESTRUTURA_AUXILIAR;
    }
    
    return retorno;
}

/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
    int retorno = 0;
    int tamanho_do_array;
    int i, j;

    if (ehPosicaoValida(posicao) == POSICAO_INVALIDA){
        retorno = ehPosicaoValida(posicao);
    }
    else if (vetor_principal[posicao] != NULL)
    {
        tamanho_do_array = *(vetor_principal[posicao]);

        copia_array_principal(posicao, vetorAux);

        retorno = SUCESSO;

    } else {
        retorno = SEM_ESTRUTURA_AUXILIAR;
    }

    return retorno;
}

/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
    int retorno = 0;
    int tamanho_do_array;
    int qtd_elementos;
    int i, j;

    if (ehPosicaoValida(posicao) == POSICAO_INVALIDA){
        retorno = ehPosicaoValida(posicao);
    }
    else if (vetor_principal[posicao] != NULL)
    {
        tamanho_do_array = *(vetor_principal[posicao]);
        qtd_elementos = *(vetor_principal[posicao]+1);
        
        copia_array_principal(posicao, vetorAux);
        ordena_array(vetorAux, qtd_elementos);

        retorno = SUCESSO;

    } else {
        retorno = SEM_ESTRUTURA_AUXILIAR;
    }

    return retorno;
}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
    int i,j;
    int retorno = 0;
    int todas_estruturas_auxiliares_vazias = 0;
    int posicao_ultimo_numero = 0;
    int qtd_elementos, tamanho_do_array;

    for (i=0; i<TAM; i++){

        if (vetor_principal[i] != NULL){

            qtd_elementos = *(vetor_principal[i]+1);
            tamanho_do_array = *(vetor_principal[i]);
            
            if (qtd_elementos == 0){ //

                todas_estruturas_auxiliares_vazias = todas_estruturas_auxiliares_vazias + 1;

            } 
            else 
            {
                for (j = 0; j < qtd_elementos; j++ ){

                    vetorAux[posicao_ultimo_numero] = *(vetor_principal[i]+(2+j) );
                    posicao_ultimo_numero += 1;

                }

                retorno = SUCESSO;
            }
        }
        else {
            todas_estruturas_auxiliares_vazias = todas_estruturas_auxiliares_vazias + 1;
            //retorno = SEM_ESTRUTURA_AUXILIAR;
        }
    }

    if (todas_estruturas_auxiliares_vazias == TAM){
        retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    }


    return retorno;
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
    int i,j;
    int retorno = 0;
    int todas_estruturas_auxiliares_vazias = 0;
    int posicao_ultimo_numero = 0;
    int qtd_elementos, tamanho_do_array;

    for (i=0; i<TAM; i++){

        if (vetor_principal[i] != NULL){

            qtd_elementos = *(vetor_principal[i]+1);
            tamanho_do_array = *(vetor_principal[i]);
            
            if (qtd_elementos == 0){ //

                todas_estruturas_auxiliares_vazias = todas_estruturas_auxiliares_vazias + 1;

            } 
            else 
            {
                for (j = 0; j < qtd_elementos; j++ ){

                    vetorAux[posicao_ultimo_numero] = *(vetor_principal[i]+(2+j) );
                    posicao_ultimo_numero += 1;

                }

                retorno = SUCESSO;
            }
        }
        else {
            todas_estruturas_auxiliares_vazias = todas_estruturas_auxiliares_vazias + 1;
            //retorno = SEM_ESTRUTURA_AUXILIAR;
        }
    }

    if (todas_estruturas_auxiliares_vazias == TAM){
        retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    }

    ordena_array(vetorAux, posicao_ultimo_numero);

    return retorno;
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1

Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho)
{
    int retorno = 0;
    int tamanho_antigo, qtd_elementos;

    /*
    printf("Tamanho %d\n", *(vetor_principal[posicao]) );
    printf("Quantidade %d\n", *(vetor_principal[posicao]+1) );

    printf("Elemento %d\n", *(vetor_principal[posicao]+2) );
    printf("Elemento %d\n", *(vetor_principal[posicao]+3) );
    printf("Elemento %d\n", *(vetor_principal[posicao]+4) );
    printf("Elemento %d\n", *(vetor_principal[posicao]+5
    ) );
    */

    //printf("Novo tamanho: %d\n", *(vetor_principal[posicao])+(novoTamanho) );

    if (ehPosicaoValida(posicao) == POSICAO_INVALIDA){

        retorno = ehPosicaoValida(posicao);
    }

    else if (vetor_principal[posicao] == NULL){

        retorno = SEM_ESTRUTURA_AUXILIAR;

    } 
    
    else if ( *(vetor_principal[posicao])+novoTamanho < 1){ //Verificar se for igual

        retorno = NOVO_TAMANHO_INVALIDO;

    } 
    
    else {
            tamanho_antigo = *(vetor_principal[posicao]);
            qtd_elementos = *(vetor_principal[posicao]+1);

            if (novoTamanho < tamanho_antigo){ // Diminui o tamanho do array original, retira a quantidade de elementos

                novoTamanho = tamanho_antigo + novoTamanho; //Jogo de sinal quando o novonumero for negativo
            
                int *vetor_aux = (int *) realloc ( vetor_principal[posicao], (novoTamanho+2) * sizeof (int) ); //Coloca +2 para preservar os dois primeiros indices

                vetor_principal[posicao] = vetor_aux;

                vetor_aux[0] = novoTamanho; //Guarda o novo tamanho no index 0

                if (qtd_elementos > novoTamanho){
                    *(vetor_principal[posicao]+1) = novoTamanho; //Diminui a quantidade de elementos de se não tiver espaço no array
                }

            } else {

                novoTamanho = tamanho_antigo + novoTamanho; //Aumenta o tamanho do array original

                int *vetor_aux = (int *) realloc ( vetor_principal[posicao], (novoTamanho) * sizeof (int) );
                vetor_principal[posicao] = vetor_aux;
                vetor_aux[0] = novoTamanho; //Guarda o novo tamanho no index 0

                for (int i = tamanho_antigo+2; i < novoTamanho; i++){
                    vetor_aux[i] = 0; //Coloca nulo nos novos tamanho
                }

            }
        
        retorno = SUCESSO;
    }

    return retorno;
}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.

Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao)
{
    int retorno = 0;
    int tamanho;
    int array_vazio = 0;
    int i;
    int qtd_elementos = 0;

    if (ehPosicaoValida(posicao) == POSICAO_INVALIDA){

        retorno = ehPosicaoValida(posicao);
    }
    else if (vetor_principal[posicao] != NULL)
    {
       qtd_elementos = *(vetor_principal[posicao]+1);

        if (qtd_elementos == 0){
            retorno = ESTRUTURA_AUXILIAR_VAZIA;
        }
        else 
        {
            retorno = qtd_elementos;

        }
    }
    else {
        retorno = SEM_ESTRUTURA_AUXILIAR;
    }


    return retorno;
}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.

Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/
No *montarListaEncadeadaComCabecote()
{

    return NULL;
}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[])
{
}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.

Retorno 
    void.
*/
void destruirListaEncadeadaComCabecote(No **inicio)
{
}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa 

*/

void inicializar()
{
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa 
para poder liberar todos os espaços de memória das estruturas auxiliares.

*/

void finalizar()
{
}
