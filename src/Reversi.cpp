#include <iostream>
#include "Reversi.hpp"

const int TAM_LINHAS = 8, TAM_COL=8;

Reversi::Reversi(){
    this->dimensionarTabuleiro(8,8);
}

void Reversi::imprimirTabuleiro(){
    for(int i=0;i<TAM_LINHAS;i++){
        std::cout<<"|";
        for(int j=0;j<TAM_COL;j++){
            std::cout<<this->retornarPosicao(i,j)<<"|";
        };
        std::cout<<std::endl;
    };
};