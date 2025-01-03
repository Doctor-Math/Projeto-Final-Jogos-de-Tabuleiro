#include <iostream>
#include <vector>
#include "Jogadores.hpp"

void Cadastro(){
    std::string nome, apelido;
    int quantJogadores, flag=1;
    std::vector<Jogador*> Jogadores;

    std::cout<<"Quantos jogadores deseja cadastrar?"<<std::endl;
    std::cin>>quantJogadores;

    for(int i=0;i<quantJogadores;i++){
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
};