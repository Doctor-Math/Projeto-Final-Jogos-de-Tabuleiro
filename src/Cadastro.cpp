#include <iostream>
#include <vector>
#include <fstream>
#include "Jogadores.hpp"
#include "Cadastro.hpp"

void cadastrarJogador(std::vector<Jogador*> &Jogadores){
    std::string nome, apelido;
    int quantJogadores, flag=1;
    std::ofstream arquivo;
    
    //Leitura do nome e do apelido do jogador:
    std::cin>>nome>>apelido;

    for(Jogador* j:Jogadores){
        if((j->mostrarApelido()==apelido)||(j->mostrarApelido()==nome)){
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

void removerJogador(std::string apelido){

}