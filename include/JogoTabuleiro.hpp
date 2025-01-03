#include <iostream>
#include <vector>

class JogoTabuleiro{
    private:
    std::vector<std::vector<char>> tabuleiro;

    public:
    JogoTabuleiro();
    void dimensionarTabuleiro(int, int);
    virtual void validarJogada(int)=0;
    virtual void validarJogada(int,int)=0;
    virtual void verificarVitoria()=0;
    virtual void imprimirTabuleiro()=0;
    ~JogoTabuleiro();
};