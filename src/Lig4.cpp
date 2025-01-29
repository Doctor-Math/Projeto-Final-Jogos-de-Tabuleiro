#include <iostream>
#include "Lig4.hpp"
#include "doctest.h"



// Constantes que definem o número de linhas e colunas do tabuleiro.
const int TAM_LINHAS=6, TAM_COL=7;

/**
* @brief Construtor da classe Lig4.
*Inicializa o tabuleiro com as dimensões padrão (6x7).
*/
Lig4::Lig4(){
    this->dimensionarTabuleiro(TAM_LINHAS, TAM_COL);
};

/**
 * @brief Valida a jogada de um jogador e atualiza o tabuleiro.
 * 
 * @param nulo Parâmetro sem uso (incluso para compatibilidade).
 * @param coluna Coluna escolhida para a jogada.
 * @param turno Determina o jogador atual (0 para 'X' e 1 para 'O').
 * @throws Exibe mensagem de erro se a jogada for inválida.
 */
void Lig4::validarJogada(int nulo, int coluna, int turno){
    int valido=0;
    coluna--;
    for (int i=(TAM_LINHAS-1);i>=0;i--){
        if (this->retornarPosicao(i,coluna)=='\0'){
            this->marcarTabuleiro(i,coluna,(turno==0)? 'X':'O');
            valido=1;
            break;
        };
    };
    if(!valido){
        std::cout<<"ERRO: jogada inválida";
    };
};

/**
 * @brief Exibe o estado atual do tabuleiro no console.
 */
void Lig4::imprimirTabuleiro(){
    for (int i=0;i<TAM_LINHAS;i++){
        std::cout<<"|";
        for(int j=0;j<TAM_COL;j++){
            if(this->retornarPosicao(i,j)=='\0'){
                std::cout<<" "<<"|";
            }else{
            std::cout << this->retornarPosicao(i, j)<<"|";
            };
        };
        std::cout<<std::endl;
    };
};

/**
 * @brief Verifica se um jogador venceu o jogo.
 * 
 * @param marcacao Caractere do jogador ('X' ou 'O').
 * @return int Retorna 1 se houver vitória; 0 caso contrário.
 */
int Lig4::verificarVitoria(char marcacao)
{
    int flag=0;
    int i,j;
    // Verifica as linhas:
    for (i=0;i<TAM_LINHAS;i++){
        for (j=0;j<TAM_COL;j++){
            if (this->retornarPosicao(i,j)==marcacao){
                flag++;
                if(flag==4){
                    return 1;
                };
            }else{
                flag=0;
            };
        };
    };

    // Verifica as colunas:
    for (j=0;j<TAM_COL;j++){
        for (i=0;i<TAM_LINHAS;i++){
            if (this->retornarPosicao(i,j)==marcacao){
                flag++;
                if (flag == 4){
                    return 1;
                };
            }else{
                flag=0;
            };
        };
    };

    // Verifica a diagonal da esquerda pra direita subindo:
    i=1, j=0;
    while (i<TAM_COL-3 && j<=TAM_LINHAS-i){
        if (this->retornarPosicao(i,j)==marcacao){
            flag++;
            if (flag==4){
                return 1;
            };
        }else{
            flag=0;
        };
        i++, j++;
    };

    // Verifica a diagonal da esquerda pra direita subindo:
    i=TAM_COL-2, j=0;
    while (i>TAM_COL-5 && j<=TAM_LINHAS-i){
        if (this->retornarPosicao(i,j)==marcacao){
            flag++;
            if (flag==4){
                return 1;
            };
        }else{
            flag=0;
        };
        i--, j++;
    };

    // Verifica a diagonal da esquerda pra direita descendo:
    i=1, j=TAM_LINHAS-1;
    while (i<TAM_COL && j>i-1){
        if (this->retornarPosicao(i, j)==marcacao){
            flag++;
            if(flag==4){
                return 1;
            };
        }else{
            flag=0;
        };
        i++, j--;
    };

    // Verifica a diagonal da direita pra esquerda descendo:
    i=TAM_COL-2, j=TAM_LINHAS-1;
    while(i>TAM_COL-5 && j>(TAM_LINHAS-1)-i){
        if(this->retornarPosicao(i,j)==marcacao){
            flag++;
            if(flag==4){
                return 1;
            };
        }else{
            flag=0;
        };
        i--, j--;
    };

    return flag;
};

/**
 * @brief Destrutor da classe Lig4.
 * Exibe mensagem de encerramento do jogo.
 */
Lig4::~Lig4(){
    std::cout<<"Encerrando o jogo..."<<std::endl;
};
