#ifndef REVERSI_HPP
#define REVERSI_HPP

#include <iostream>
#include <vector>
#include "JogoTabuleiro.hpp"

class Reversi: public JogoTabuleiro{

    public:
    Reversi();
    void validarJogada(int,int,int) override;
    int verificarVitoria(char) override;
    void imprimirTabuleiro() override;
    bool verificarDirecao(int,int,int,int,int);
    ~Reversi();
};

#endif