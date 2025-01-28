#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "ExecucaoPartidas.hpp"

void escreverJogo(std::ofstream &arq_temp, int i, int vitorias, int derrotas){
    if(i==0){
        arq_temp<<"REVERSI - V: "<<vitorias<<" D: "<<derrotas<<std::endl;
    }else if(i==1){
        arq_temp<<"LIG4 - V: "<<vitorias<<" D: "<<derrotas<<std::endl;
    }else if(i==2){
        arq_temp<<"VELHA - V: "<<vitorias<<" D: "<<derrotas<<std::endl;
    };
};

void pontuarJogadores(std::string vencedor, std::string perdedor, int linha_modificar){
    std::string arq_nome="Jogadores.txt",temp_nome="Temporario.txt";
    std::ifstream arquivo(arq_nome);
    std::ofstream arq_temp(temp_nome);

    if(!arquivo.is_open()||!arq_temp.is_open()){
        std::cout<<"Erro ao abrir o arquivo!"<<std::endl;
        return;
    };

    std::string linha;
    int vitoria_vencedor=0,derrota_vencedor=0,vitoria_perdedor=0,derrota_perdedor=0;

    // Extração do número de vitórias e derrotas
    while (getline(arquivo, linha)){
        if(linha.rfind(vencedor,0)==0){ // Se a linha começa com o apelido do vencedor
            for(int i=0;i<3;i++) {
                getline(arquivo, linha);
                if(i==linha_modificar){
                    std::stringstream leitura(linha);
                    leitura >>vitoria_vencedor>>derrota_vencedor;
                    break;
                };
            };
        } else if(linha.rfind(perdedor,0)==0){ // Se a linha começa com o apelido do derrotado
            for(int i=0;i<3;i++) {
                getline(arquivo, linha);
                if(i==linha_modificar) {
                    std::stringstream leitura(linha);
                    leitura>>vitoria_perdedor>>derrota_perdedor;
                    break;
                };
            };
        };
    };

    // Incrementa vitórias e derrotas
    vitoria_vencedor++;
    derrota_perdedor++;

    // Volta ao início do arquivo
    arquivo.clear();
    arquivo.seekg(0, std::ios::beg);

    // Reescreve o arquivo com as alterações
    while(getline(arquivo,linha)){
        arq_temp<<linha<<std::endl;
        if(linha.rfind(vencedor, 0)==0){ // Atualiza o vencedor
            for (int i=0;i<3;i++){
                getline(arquivo,linha);
                if (i==linha_modificar){
                    escreverJogo(arq_temp,i,vitoria_vencedor,derrota_vencedor);
                }else{
                    arq_temp<<linha<<std::endl;
                };
            };
        }else if(linha.rfind(perdedor,0)==0){ // Atualiza o perdedor
            for(int i=0;i<3;i++){
                getline(arquivo,linha);
                if(i==linha_modificar){
                    escreverJogo(arq_temp,i,vitoria_perdedor,derrota_perdedor);
                }else{
                    arq_temp<<linha<<std::endl;
                };
            };
        };
    };

    arquivo.close();
    arq_temp.close();

    // Substitui o arquivo antigo pelo novo
    if(remove(arq_nome.c_str())!=0) {
        std::cout<<"Erro ao remover o antigo arquivo de jogadores!"<<std::endl;
        return;
    };
    if(rename(temp_nome.c_str(),arq_nome.c_str())!=0) {
        std::cout<<"Erro ao renomear o arquivo temporário!"<<std::endl;
        return;
    };
};

void rodadaVelha(int turno, int &vitoria, std::string apelido1, std::string apelido2, JogoDaVelha* &tabuleiro){
    int linha, coluna;
    std::cout<<"Turno do jogador "<<apelido1<<":"<<std::endl;

        try{
        std::cout<<"Linha:";
        std::cin>>linha;
        std::cout<<""<<std::endl;
        std::cout<<"Coluna:";
        std::cin>>coluna;
        std::cout<<""<<std::endl;
        tabuleiro->validarJogada(linha,coluna,turno);
        }

        catch(const std::out_of_range& e){ // Captura exceção de linha/coluna fora dos limites do tabuleiro
        std::cout<<"Erro: "<<e.what()<<std::endl; // Exibe a mensagem de erro
        }

        tabuleiro->imprimirTabuleiro();
        vitoria=tabuleiro->verificarVitoria('X');
        if(vitoria){
            std::cout<<"Vitória de "<<apelido1<<"!"<<std::endl;
            pontuarJogadores(apelido1,apelido2,2);
        };
};


void partidaVelha(std::string apelidoJ1, std::string apelidoJ2, JogoDaVelha* &tabuleiro){
    int turno=0, vitoria=0,linha,coluna;
    while(!vitoria){
        if(turno==0){
            rodadaVelha(turno,vitoria,apelidoJ1,apelidoJ2,tabuleiro);
            turno++;
        }else if(turno==1){
            rodadaVelha(turno,vitoria,apelidoJ2,apelidoJ1,tabuleiro);
            turno--;
        };

    };
};

void rodadaLig4(int turno, int &vitoria, std::string apelido1, std::string apelido2, Lig4* &tabuleiro){
    int linha, coluna;

    std::cout<<"Turno do jogador "<<apelido1<<":"<<std::endl;

        std::cout<<"Coluna:";
        std::cin>>coluna;
        std::cout<<""<<std::endl;

        
        try{
            tabuleiro->validarJogada(0,coluna,turno);
        }

        catch(const std::out_of_range& e){
            std::cout<<"Erro: "<<e.what()<<std::endl; 
        }

        tabuleiro->imprimirTabuleiro();
        vitoria=tabuleiro->verificarVitoria('X');
        if(vitoria){
            std::cout<<"Vitória de "<<apelido1<<"!"<<std::endl;
            pontuarJogadores(apelido1,apelido2,1);
        };
};


void partidaLig4(std::string apelidoJ1, std::string apelidoJ2,Lig4* &tabuleiro){
    int turno=0, vitoria=0, coluna;
    while(!vitoria){
      if(turno==0){
        rodadaLig4(turno,vitoria,apelidoJ1,apelidoJ2,tabuleiro);
        turno++;
    }else if(turno==1){
        rodadaLig4(turno,vitoria,apelidoJ2,apelidoJ1,tabuleiro);
        turno--;
    };
    };

};

void rodadaReversi(int turno, int &vitoria, std::string apelido1, std::string apelido2, Reversi* &tabuleiro){
    int linha, coluna, invalidade=0;

    tabuleiro->imprimirTabuleiro();
    int i=0;

    std::cout << "Turno do jogador " << apelido1 << ":" << std::endl;

        std::cout << "Linha:";
        std::cin >> linha;
        std::cout << "" << std::endl;
        std::cout << "Coluna:";
        std::cin >> coluna;
        std::cout << "" << std::endl;

        tabuleiro->validarJogada(linha,coluna,turno);
        tabuleiro->imprimirTabuleiro();
    

};


void partidaReversi(std::string apelidoJ1, std::string apelidoJ2,Reversi* &tabuleiro){
    int turno=0, vitoria=0,i=0;
    while(i<6){
        if(turno==0){
            rodadaReversi(turno,vitoria,apelidoJ1,apelidoJ2,tabuleiro);
            turno++;
        }else if(turno==1){
            rodadaReversi(turno,vitoria,apelidoJ2,apelidoJ1,tabuleiro);
            turno--;
        };
        i++;
    };
};

void executarPartida(char tipoJogo,std::string apelidoJ1,std::string apelidoJ2){
    int linha, coluna;
    switch(tipoJogo){
        case 'R':
        {
            Reversi* tabuleiro=new Reversi();
        
            partidaReversi(apelidoJ1,apelidoJ2,tabuleiro);
        
            delete tabuleiro;
        
        };
        break;

        case 'L':
        {
            Lig4* tabuleiro=new Lig4();
        
            partidaLig4(apelidoJ1,apelidoJ2,tabuleiro);
        
            delete tabuleiro;
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
        std::cout<<"ERRO: Tipo de jogo não disponível"<<std::endl;
    };
};