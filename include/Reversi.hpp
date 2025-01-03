#include <iostream>
#include <vector>
#include "JogoTabuleiro.hpp"

class Reversi: public JogoTabuleiro{

    public:
    Reversi();
    void validarJogada(int,int) override;
    void verificarVitoria() override;
    void imprimirTabuleiro() override;
    ~Reversi();
};