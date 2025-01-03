#include <iostream>
#include <vector>
#include "JogoTabuleiro.hpp"

class JogoDaVelha: public JogoTabuleiro{

    public:
    JogoDaVelha();
    void validarJogada(int,int) override;
    void verificarVitoria() override;
    void imprimirTabuleiro() override;
    ~JogoDaVelha();
};