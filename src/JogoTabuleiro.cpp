#include <iostream>
#include "JogoTabuleiro.hpp"

JogoTabuleiro::JogoTabuleiro(){
    std::cout<<"AGUARDE: Abrindo o tabuleiro, organizando as peças..."<<std::endl;
};

void JogoTabuleiro::dimensionarTabuleiro(int i, int j){
    tabuleiro.resize(i); // Redimensiona o número de linhas da matriz
    for(int k=0;k<i;k++){ 
        tabuleiro[k].resize(j); // Redimensiona o número de colunas (para cada linha)
    };
}

void JogoTabuleiro::marcarTabuleiro(int linha, int coluna, char marcacao){
    this->tabuleiro[linha][coluna]=marcacao;
};

char JogoTabuleiro::retornarPosicao(int linha, int coluna){
        return this->tabuleiro[linha][coluna];
};

JogoTabuleiro::~JogoTabuleiro(){
    std::cout<<"AGUARDE: Fechando o tabuleiro, guardando as peças..."<<std::endl;
};