#ifndef LIG4_HPP
#define LIG4_HPP

#include <iostream>
#include <vector>
#include "JogoTabuleiro.hpp"

class Lig4 : public JogoTabuleiro
{

public:
    Lig4();
    int retornaLinha(int);
    void validarJogada(int, int, int) override;
    int verificarVitoria(char, int, int) override;
    void imprimirTabuleiro() override;
    ~Lig4();
};

#endif
