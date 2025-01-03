#include <iostream>
#include <vector>
#include <string>

class Jogador{
    private:
    std::string nome;
    std::string apelido;
    int vitorias=0;
    int derrotas=0;

    public:
    Jogador(std::string, std::string);
    std::string mostrarApelido();
    std::string mostrarNome();
    void removerJogador(std::string);
    ~Jogador();
};