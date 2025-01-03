#include <iostream>
#include <vector>
#include "JogoTabuleiro.hpp"

class Lig4: public JogoTabuleiro{

    public:
    Lig4();
    void validarJogada(int) override;
    void verificarVitoria() override;
    void imprimirTabuleiro() override;
    ~Lig4();
};