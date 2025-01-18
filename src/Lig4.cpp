#include <iostream>
#include "Lig4.hpp"

const int TAM_LINHAS = 6, TAM_COL=7;

Lig4::Lig4(){
    this->dimensionarTabuleiro(6,7);
}

void Lig4::validarJogada(int coluna, int turno){
    int flag=0;
    coluna--;
    for(int i=(TAM_LINHAS-1);i>=0;i--){
        if(this->retornarPosicao(i,coluna)=='\0'){
            this->marcarTabuleiro(i,coluna,(turno==0)? 'X':'O');
            flag=1;
            break;
        };
    };
    if(!flag){
        std::cout<<"ERRO: jogada inválida";
    };
};

void Lig4::imprimirTabuleiro(){
    for(int i=0;i<TAM_LINHAS;i++){
        std::cout<<"|";
        for(int j=0;j<TAM_COL;j++){
            std::cout<<this->retornarPosicao(i,j)<<"|";
        };
        std::cout<<std::endl;
    };
};

int Lig4::verificarVitoria(char marcacao){
    int flag = 0;

    //Verificar nas linhas 
    for(int i=0;i<TAMANHO;i++){
       int j = (TAM_COL - 1)/2 
            if(this->retornarPosicao(i,j)==marcacao){
                flag=1;
                if(j==2){
                    return flag;
                }
            }else{
                flag=0;
                break;
            };
        };
    };





    