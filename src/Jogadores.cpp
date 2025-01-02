#include <iostream>
#include <string>
#include <map>
#include "Jogadores.hpp"

Jogador::Jogador(std::string apelido, std::string nome){
    for(Jogador* j:usuarios){
        // Verifica se há repetição de jogador
        if((j->apelido==apelido)||(j->nome==nome)){
            std::cout<<"ERRO: jogador repetido";
            break;
        }else{
            this->apelido=apelido;
            this->nome=nome;
            usuarios.push_back(this);
            std::cout<<"Jogador "<<apelido<<" cadastrado com sucesso"<<std::endl;
        }
    }
}

void Jogador::removerJogador(std::string apelido){
    int contador=0;
    for(Jogador* j:usuarios){
        if(j->apelido==apelido){
            delete j; // Destrói o objeto
            usuarios.erase(usuarios.begin()+contador); // Remove o objeto do vetor
            break;
        }
        contador++;
    }
}
