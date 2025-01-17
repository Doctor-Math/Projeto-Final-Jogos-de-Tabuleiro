#include <iostream>
#include <algorithm>
#include <fstream>
#include "Jogadores.hpp"

void cadastrarJogador(std::vector<Jogador*> &Jogadores){
    std::string nome, apelido;
    int quantJogadores, flag=1;
    std::ofstream arquivo;
    
    //Leitura do nome e do apelido do jogador:
    std::cin>>nome>>apelido;

    //Verifica se o jogador a ser inserido já existe:
    for(Jogador* j:Jogadores){
        if((j->exibirApelido()==apelido)||(j->exibirNome()==nome)){
            std::cout<<"ERRO: jogador repetido";
            flag=0;
            break;
        };
    };
        
    if(flag){
        Jogadores.push_back(new Jogador(nome,apelido));
        std::cout<<"Jogador "<<apelido<<" cadastrado com sucesso"<<std::endl;
    };

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
