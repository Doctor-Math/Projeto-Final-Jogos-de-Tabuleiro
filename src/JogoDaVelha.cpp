#include <iostream>
#include "JogoDaVelha.hpp"

JogoDaVelha::JogoDaVelha(){
    this->dimensionarTabuleiro(3,3);
}

void JogoDaVelha::validarJogada(int linha, int coluna, int turno){
    if((linha-1)>2 || (coluna-1)>2 || linha<0 || coluna<0){
        std::cout<<"ERRO: formato incorreto"<<std::endl;
    }else if(this->retornarPosicao(linha,coluna)=='\0'){
        if(turno==0){
            this->marcarTabuleiro(linha,coluna,'X');
        }else if(turno==1){
            this->marcarTabuleiro(linha,coluna,'O');
        };
    }else{
        std::cout<<"ERRO: jogada inválida";
    };
}

void JogoDaVelha::imprimirTabuleiro(){
    std::cout<<"|";
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            std::cout<<this->retornarPosicao(i,j)<<"|";
        };
        std::cout<<""<<std::endl;
    };
}