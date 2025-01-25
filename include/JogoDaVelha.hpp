#include <iostream>
#include <vector>
#include "JogoTabuleiro.hpp"

class JogoDaVelha: public JogoTabuleiro{

    public:
    JogoDaVelha();
    void validarJogada(int,int,int) override;
    int verificarVitoria(char) override;
    void imprimirTabuleiro() override;
    ~JogoDaVelha();
};