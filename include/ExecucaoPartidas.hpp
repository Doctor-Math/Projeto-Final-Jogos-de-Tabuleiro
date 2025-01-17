#include <iostream>
#include "JogoDaVelha.hpp"

void partidaVelha(std::string apelidoJ1, std::string apelidoJ2, JogoDaVelha* &tabuleiro){
    int turno=0, vitoria=0, linha,coluna;
    while(vitoria==0){
    if(turno==0){
        std::cout<<"Turno do jogador "<<apelidoJ1<<":"<<std::endl;

        std::cout<<"Linha:";
        std::cin>>linha;
        std::cout<<""<<std::endl;

        std::cout<<"Coluna:";
        std::cin>>coluna;
        std::cout<<""<<std::endl;

        tabuleiro->validarJogada(linha,coluna,turno);
        tabuleiro->imprimirTabuleiro();
        vitoria=tabuleiro->verificarVitoria('X');
        if(vitoria){
            break;
        };
        turno++;
    }else if(turno==1){
        std::cout<<"Turno do jogador "<<apelidoJ2<<":"<<std::endl;

        std::cout<<"Linha:";
        std::cin>>linha;
        std::cout<<""<<std::endl;

        std::cout<<"Coluna:";
        std::cin>>coluna;
        std::cout<<""<<std::endl;

        tabuleiro->validarJogada(linha,coluna,turno);
        tabuleiro->imprimirTabuleiro();
        vitoria=tabuleiro->verificarVitoria('O');
        if(vitoria){
            break;
        };
        turno--;
    };
    };
};



void partidaLig4(std::string apelidoJ1, std::string apelidoJ2){
    int turno=1;
};

void partidaReversi(std::string apelidoJ1, std::string apelidoJ2){
    int turno=1;
};

void executarPartida(char tipoJogo,std::string apelidoJ1,std::string apelidoJ2){
    int linha, coluna;
    switch(tipoJogo){
        case 'R':
        {
        };
        break;

        case 'L':
        {
            Lig4* tabuleiro=new Lig4();
        };
        break;

        case 'V':
        {
            JogoDaVelha* tabuleiro=new JogoDaVelha();

            partidaVelha(apelidoJ1,apelidoJ2,tabuleiro);

            delete tabuleiro;
        };
        break;
        default:
        std::cout<<"ERRO: dados incorretos"<<std::endl;
    };
};