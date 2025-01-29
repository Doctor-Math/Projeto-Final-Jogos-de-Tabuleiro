#ifndef JOGOTABULEIRO_HPP
#define JOGOTABULEIRO_HPP

#include <iostream>
#include <vector>

class JogoTabuleiro
{
private:
    std::vector<std::vector<char>> tabuleiro;

public:
    JogoTabuleiro();
    void dimensionarTabuleiro(int, int);
    void marcarTabuleiro(int, int, char);
    char retornarPosicao(int, int);
    virtual void validarJogada(int, int, int) = 0;

    virtual int verificarVitoria(char);
    virtual int verificarVitoria(char, int, int);

    virtual void imprimirTabuleiro() = 0;
    virtual ~JogoTabuleiro();
};

#endif
