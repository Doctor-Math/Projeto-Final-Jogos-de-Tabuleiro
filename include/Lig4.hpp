#include <iostream>
#include <vector>
#include "JogoTabuleiro.hpp"

class Lig4: public JogoTabuleiro{

    public:
    Lig4();
    void validarJogada(int, int,int) override;
    int verificarVitoria(char) override;
    void imprimirTabuleiro() override;
    ~Lig4();
};