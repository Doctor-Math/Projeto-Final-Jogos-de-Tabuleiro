#ifndef JOGODAVELHA_HPP
#define JOGODAVELHA_HPP

#include <iostream>
#include <vector>
#include "JogoTabuleiro.hpp"

class JogoDaVelha : public JogoTabuleiro
{

public:
    JogoDaVelha();
    void validarJogada(int, int, int) override;
    int verificarVitoria(char, int, int) override;
    void imprimirTabuleiro() override;
    ~JogoDaVelha();
};

#endif
