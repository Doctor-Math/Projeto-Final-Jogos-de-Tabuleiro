#include <iostream>
#include <string>
#include <map>
#include "Jogadores.hpp"

Jogador::Jogador(std::string apelido, std::string nome){
    this->apelido=apelido;
    this->nome=nome;
}

std::string Jogador::exibirApelido(){
    return this->apelido;
}

std::string Jogador::exibirNome(){
    return this->nome;
}

void Jogador::exibirEstatisticas(){
    for(int i=0;i<3;i++){
        std::cout<<this->jogos[i]<<" - V: "<<this->vitorias[i]<<" D: "<<this->derrotas[i]<<std::endl;
    };
}

