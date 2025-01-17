#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include "Jogadores.hpp"

void cadastrarJogador(){
    std::string nome, apelido;
    int quantJogadores;
    std::fstream arquivo;

    arquivo.open("Jogadores.txt",std::ios::out | std::ios::in);
    if(!arquivo){
        std::cout<<"ERRO: Arquivo não criado!";
        return;
    };
    
    //Leitura do nome e do apelido do jogador:
    std::cin>>apelido>>nome;

    //Verifica se o jogador a ser inserido já existe:
    std::string linha, apelido_jogador;
    int contador=0;
    while(std::getline(arquivo,linha)){
        std::istringstream lineStream(linha);
        if(contador%4==0){
            lineStream>>apelido_jogador; //Extração da primeira palavra da linha
            if(apelido_jogador==apelido){
                std::cout<<"Erro: jogador repetido"<<std::endl;
                return;
            };
        };
        contador++;
    };
        
        arquivo<<apelido<<" "<<nome<<std::endl
        <<"REVERSI - V: 0 D: 0"<<std::endl
        <<"LIG4    - V: 0 D: 0"<<std::endl
        <<"VELHA   - V: 0 D: 0"<<std::endl
        <<"--------------------"<<std::endl;

        std::cout<<"Jogador "<<apelido<<" cadastrado com sucesso"<<std::endl;

    arquivo.close();
};

void removerJogador(std::vector<Jogador*> &Jogadores){
    int contador=0, flag=0;
    std::string apelido;
    std::cin>>apelido;
    
    //Verifica se o jogador está cadastrado:
    for(Jogador* j:Jogadores){
        if(j->exibirApelido()==apelido){
            delete j; // Destrói o objeto
            Jogadores.erase(Jogadores.begin()+contador); // Remove o objeto do vetor
            flag=1;
            break;
        }
        contador++;
    };

    if(flag){
        std::cout<<"Jogador "<<apelido<<" removido com sucesso"<<std::endl;
    }else{
        std::cout<<"ERRO: jogador inexistente";
    };

};

void listarJogadores(std::vector<Jogador *> Jogadores){
    std::sort(Jogadores.begin(),Jogadores.end());

    for(Jogador *j:Jogadores){
        std::cout<<j->exibirApelido()<<" "<<j->exibirNome()<<std::endl;
        j->exibirEstatisticas();
    }
};
