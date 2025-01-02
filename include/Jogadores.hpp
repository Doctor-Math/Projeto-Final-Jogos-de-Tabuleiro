#include <iostream>
#include <vector>
#include <string>

class Jogador{
    private:
    std::string nome;
    std::string apelido;
    int vitorias=0;
    int derrotas=0;
    static std::vector<Jogador *> usuarios;

    public:
    Jogador(std::string, std::string);
    void inserirVitoria();
    void inserirDerrota();
    static Jogador * listarJogadores();
    void removerJogador(std::string);
    ~Jogador();
};