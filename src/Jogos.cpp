#include <iostream>
#include "Jogos.hpp"

// Implementação do Jogo da Velha

void JogoTabuleiro::dimensionarTabuleiro(int i, int j){
    tabuleiro.resize(i); // Redimensiona o número de linhas da matriz
    for(int k=0;k<i;k++){ 
        tabuleiro[k].resize(j); // Redimensiona o número de colunas (para cada linha)
    };
}

JogoDaVelha::JogoDaVelha(){
    this->dimensionarTabuleiro(3,3);
}

Reversi::Reversi(){
    this->dimensionarTabuleiro(8,8);
}

Lig4::Lig4(){
    this->dimensionarTabuleiro(6,7);
}