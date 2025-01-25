#include <iostream>
#include "Cadastro.hpp"
#include "ExecucaoPartidas.hpp"

int main(){
    std::string resp=" ", apelidoJ1, apelidoJ2;
    char tipoJogo;
    
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
            cadastrarJogador();
        }else if(resp=="RJ"){
            removerJogador();
        }else if(resp=="LJ"){
            listarJogadores();
        }else if(resp=="EP"){
            std::cout<<"Jogo: ";
            std::cin>>tipoJogo;
            std::cout<<"Apelido do jogador 1:";
            std::cin>>apelidoJ1;
            std::cout<<"Apelido do jogador 2:";
            std::cin>>apelidoJ2;

            int verificado=0;

            verificado=verificarCadastro(apelidoJ1,apelidoJ2);

            if(verificado){
                executarPartida(tipoJogo,apelidoJ1,apelidoJ2);
            }else{
                std::cout<<"ERRO: Jogador(es) inexistente(s)"<<std::endl;
            };
            
        }else if(resp!="FS"){
            std::cout<<"Comando inválido"<<std::endl;
        }
    };
};