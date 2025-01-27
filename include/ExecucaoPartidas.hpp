#ifndef EXECUCAOPARTIDAS_HPP
#define EXECUCAOPARTIDAS_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "JogoDaVelha.hpp"
#include "Lig4.hpp"
#include "Reversi.hpp"

void escreverJogo(std::ofstream &arq_temp, int i, int vitorias, int derrotas);
void pontuarJogadores(std::string vencedor, std::string perdedor, int linha_modificar);
void partidaVelha(std::string apelidoJ1, std::string apelidoJ2, JogoDaVelha* &tabuleiro);
void partidaLig4(std::string apelidoJ1, std::string apelidoJ2,Lig4* &tabuleiro);
void partidaReversi(std::string apelidoJ1, std::string apelidoJ2,Reversi* &tabuleiro);
void executarPartida(char tipoJogo,std::string apelidoJ1,std::string apelidoJ2);

#endif