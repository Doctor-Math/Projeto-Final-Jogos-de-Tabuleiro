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

class JogoDaVelha: public JogoTabuleiro{

    public:
    JogoDaVelha();
    void validarJogada(int,int) override;
    void verificarVitoria() override;
    void imprimirTabuleiro() override;
    ~JogoDaVelha();
};

class Lig4: public JogoTabuleiro{

    public:
    Lig4();
    void validarJogada(int) override;
    void verificarVitoria() override;
    void imprimirTabuleiro() override;
    ~Lig4();
};

class Reversi: public JogoTabuleiro{

    public:
    Reversi();
    void validarJogada(int,int) override;
    void verificarVitoria() override;
    void imprimirTabuleiro() override;
    ~Reversi();
};