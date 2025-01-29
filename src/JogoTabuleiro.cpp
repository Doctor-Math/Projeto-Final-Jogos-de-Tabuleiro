#include <iostream>
#include "JogoTabuleiro.hpp"

/**
 * @brief Construtor da classe JogoTabuleiro.
 * 
 * Exibe uma mensagem indicando que o tabuleiro está sendo aberto e as peças estão sendo organizadas.
 */
JogoTabuleiro::JogoTabuleiro(){
    std::cout<<"AGUARDE: Abrindo o tabuleiro, organizando as peças..."<<std::endl;
};

/**
 * @brief Redimensiona o tabuleiro para o tamanho especificado.
 * 
 * @param i Número de linhas do tabuleiro.
 * @param j Número de colunas do tabuleiro.
 */
void JogoTabuleiro::dimensionarTabuleiro(int i, int j){
    tabuleiro.resize(i); // Redimensiona o número de linhas da matriz
    for(int k=0;k<i;k++){ 
        tabuleiro[k].resize(j); // Redimensiona o número de colunas (para cada linha)
    };
}

/**
 * @brief Marca uma posição do tabuleiro com a jogada do jogador.
 * 
 * @param linha Linha do tabuleiro a ser marcada.
 * @param coluna Coluna do tabuleiro a ser marcada.
 * @param marcacao Símbolo a ser inserido na posição (por exemplo, 'X' ou 'O').
 */
void JogoTabuleiro::marcarTabuleiro(int linha, int coluna, char marcacao){
    this->tabuleiro[linha][coluna]=marcacao;
};

/**
 * @brief Retorna o símbolo presente em uma posição do tabuleiro.
 * 
 * @param linha Linha da posição desejada.
 * @param coluna Coluna da posição desejada.
 * 
 * @return char Símbolo presente na posição especificada (por exemplo, 'X', 'O').
 */
char JogoTabuleiro::retornarPosicao(int linha, int coluna){
        return this->tabuleiro[linha][coluna];
};

/**
 * @brief Destrutor da classe JogoTabuleiro.
 * 
 * Exibe uma mensagem indicando que o tabuleiro está sendo fechado e as peças estão sendo guardadas.
 */
JogoTabuleiro::~JogoTabuleiro(){
    std::cout<<"AGUARDE: Fechando o tabuleiro, guardando as peças..."<<std::endl;
};