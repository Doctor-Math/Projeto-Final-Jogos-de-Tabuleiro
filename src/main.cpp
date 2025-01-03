#include <iostream>
#include "Jogadores.hpp"
#include "Cadastro.hpp"


int main(){
    std::vector<Jogador*> Jogadores;
    std::string resp=" ";
    
    std::cout<<"---------Jogos-de-tabuleiro--------"<<std::endl;
    
    std::cout<<"Comandos:"<<std::endl;
    std::cout<<"CJ - Cadastrar jogador"<<std::endl;
    std::cout<<"RJ - Remover jogador"<<std::endl;
    std::cout<<"LJ - Listar jogadores"<<std::endl;
    std::cout<<"EP - Executar partida"<<std::endl;
    std::cout<<" .Opções de jogo:"<<std::endl;
    std::cout<<" ..R - Reversi"<<std::endl;
    std::cout<<" ..L - Lig4"<<std::endl;
    std::cout<<" ..V - Jogo da Velha"<<std::endl;
    std::cout<<"FS - Finalizar Sistema"<<std::endl;

    while(resp!="FS"){
        std::cin>>resp;
        if(resp=="CJ"){
            cadastrarJogador(Jogadores);
        }else if(resp=="RJ"){
            removerJogador(Jogadores);
        }else if(resp=="LJ"){
            listarJogadores(Jogadores);
        }else if(resp=="EP"){

        }else if(resp!="FS"){
            std::cout<<"Comando inválido"<<std::endl;
        }
    };
}