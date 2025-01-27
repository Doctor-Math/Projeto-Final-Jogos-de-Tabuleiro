#include <iostream>
#include "JogoDaVelha.hpp"

const int TAMANHO=3;

JogoDaVelha::JogoDaVelha(){
    this->dimensionarTabuleiro(TAMANHO,TAMANHO);
};

void JogoDaVelha::validarJogada(int linha, int coluna, int turno){
    linha--;
    coluna--;
    if(linha>2 || linha<0 || coluna>2 || coluna<0){
        std::cout<<"ERRO: formato incorreto"<<std::endl;
    }else if(this->retornarPosicao(linha,coluna)=='\0'){
        this->marcarTabuleiro(linha,coluna,(turno==0)? 'X':'O');
    }else{
        std::cout<<"ERRO: jogada inválida";
    };
};

void JogoDaVelha::imprimirTabuleiro(){
    for(int i=0;i<TAMANHO;i++){
        std::cout<<"|";
        for(int j=0;j<TAMANHO;j++){
            std::cout<<this->retornarPosicao(i,j)<<"|";
        };
        std::cout<<std::endl;
    };
};

int JogoDaVelha::verificarVitoria(char marcacao){
    int flag=0;

    //Verifica a diagonal principal:
    for(int i=0;i<TAMANHO;i++){
        int j=i;

        if(this->retornarPosicao(i,j)==marcacao){
            flag=1;
            if(i==2){
                return flag;
            };
        }else{
            flag=0;
            break;
        };
    };

    //Verifica a diagonal secundária:
    int j=2;
    for(int i=0;i<TAMANHO;i++){
        if(this->retornarPosicao(i,j)==marcacao){
            flag=1;
            if(i==2){
                return flag;
            };
        }else{
            flag=0;
            break;
        };
        j--;
    };

    //Verifica as linhas:
    for(int i=0;i<TAMANHO;i++){
        for(int j=0;j<TAMANHO;j++){
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

    //Verifica as colunas:
    for(int j=0;j<TAMANHO;j++){
        for(int i=0;i<TAMANHO;i++){
            if(this->retornarPosicao(i,j)==marcacao){
                flag=1;
                if(i==2){
                    return flag;
                }
            }else{
                flag=0;
                break;
            };
        };
    };

    return flag;
};

JogoDaVelha::~JogoDaVelha(){
    std::cout<<"Encerrando o jogo..."<<std::endl;
};