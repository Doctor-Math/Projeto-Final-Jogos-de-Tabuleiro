#include <iostream>
#include <string>
#include <map>
#include "Jogadores.hpp"

Jogador::Jogador(std::string apelido, std::string nome){
    this->apelido=apelido;
    this->nome=nome;
}

void Jogador::removerJogador(std::string apelido){
    Jogador::~Jogador();
}

std::string Jogador::mostrarApelido(){
    return this->apelido;
}

std::string Jogador::mostrarNome(){
    return this->nome;
}
