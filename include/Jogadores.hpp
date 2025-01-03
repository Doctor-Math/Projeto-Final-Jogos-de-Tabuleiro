#include <iostream>
#include <vector>
#include <string>

class Jogador{
    private:
    std::string nome;
    std::string apelido;
    std::vector<std::string>jogos={"REVERSI","LIG4","VELHA"};
    std::vector<int>vitorias;
    std::vector<int>derrotas;

    public:
    Jogador(std::string, std::string);
    void inserirVitoria();
    void inserirDerrota();

    std::string exibirApelido();
    std::string exibirNome();
    void exibirEstatisticas();

    //Definir o operador "<" para operar pelo apelido:
    bool operator <(const Jogador &outro)const{
        return apelido < outro.apelido;
    };

    ~Jogador();
};