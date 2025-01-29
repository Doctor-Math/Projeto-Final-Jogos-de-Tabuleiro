#ifndef CADASTRO_HPP
#define CADASTRO_HPP

#include <string>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>

void cadastrarJogador();
void removerJogador();
void listarJogadores();
int verificarCadastro(std::string apelidoJ1, std::string apelidoJ2);

#endif

