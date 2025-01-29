#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <iostream>
#include "Cadastro.hpp"
#include "ExecucaoPartidas.hpp"
#include "doctest.h"


/**
 * @brief Função principal do sistema de jogos de tabuleiro.
 * 
 * @details
 * O programa permite o cadastro, remoção e listagem de jogadores, além de executar partidas 
 * de jogos como Reversi, Lig4 e Jogo da Velha. O usuário interage através de comandos específicos.
 * 
 * Comandos disponíveis:
 * - CJ: Cadastrar jogador
 * - RJ: Remover jogador
 * - LJ: Listar jogadores
 * - EP: Executar partida
 *   - R: Reversi
 *   - L: Lig4
 *   - V: Jogo da Velha
 * - FS: Finalizar sistema
 * 
 *O programa exive um menu com comandos e solicita entradas do usuário para executar as opereações desejadas
 *
 * @return int Retorna 0 ao finalizar o programa com sucesso.
 */
int main(){
    std::string resp=" ", apelidoJ1, apelidoJ2;
    char tipoJogo;
    std::cout<<"---------Jogos-de-tabuleiro--------"<<std::endl;
    
    /**
     * @brief Exibe o menu inicial do sistema.
     */
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

    /**
     * @brief Loop principal para processar comandos do usuário.
     * 
     * @details
     * O loop continua até que o comando "FS" (Finalizar Sistema) seja recebido. Em cada iteração, o programa:
     * - Lê o comando inserido pelo usuário.
     * - Executa a operação correspondente (como cadastrar, remover ou listar jogadores, ou iniciar uma partida).
     * - Exibe uma mensagem de erro para comandos inválidos.
     */
    while(resp!="FS"){
        std::cin>>resp;
        if(resp=="CJ"){ 
            /**
             * @brief Comando para cadastrar um novo jogador.
             * @details Chama a função cadastrarJogador() do módulo Cadastro.
             */
            cadastrarJogador();
        }else if(resp=="RJ"){
            /**
             * @brief Comando para remover um jogador existente.
             * @details Chama a função removerJogador() do módulo Cadastro.
             */
            removerJogador();
        }else if(resp=="LJ"){
            /**
             * @brief Comando para listar os jogadores cadastrados.
             * @details Chama a função listarJogadores() do módulo Cadastro.
             */
            listarJogadores();
        }else if(resp=="EP"){

             /**
             * @brief Comando para executar uma partida entre dois jogadores.
             * 
             * @details Solicita o tipo de jogo e os apelidos dos dois jogadores. 
             * Valida se ambos os jogadores estão cadastrados antes de iniciar a partida.
             * 
             * @param tipoJogo Tipo de jogo escolhido (R: Reversi, L: Lig4, V: Jogo da Velha).
             * @param apelidoJ1 Apelido do jogador 1.
             * @param apelidoJ2 Apelido do jogador 2.
             * @throws Exibe mensagem de erro caso um ou ambos os jogadores não estejam cadastrados.
             */
            std::cout<<"Jogo: ";
            std::cin>>tipoJogo;
            std::cout<<"Apelido do jogador 1:";
            std::cin>>apelidoJ1;
            std::cout<<"Apelido do jogador 2:";
            std::cin>>apelidoJ2;

            int verificado=0;

            /**
             * @brief Verifica o cadastro dos jogadores e executa a partida, se possível.
             * 
             * @details 
             * A função verificarCadastro é chamada para verificar se os jogadores fornecidos 
             * (apelidoJ1 e apelidoJ2) estão cadastrados no sistema. Caso estejam, a função 
             * executarPartida é chamada para iniciar o jogo entre os dois jogadores, com o tipo 
             * de jogo selecionado. Caso contrário, uma mensagem de erro é exibida.
             * 
             * @param tipoJogo Tipo de jogo escolhido (R: Reversi, L: Lig4, V: Jogo da Velha).
             * @param apelidoJ1 Apelido do jogador 1.
             * @param apelidoJ2 Apelido do jogador 2.
             * 
             * @return void
             * @throws Exibe uma mensagem de erro se um ou ambos os jogadores não estiverem cadastrados.
             */
            verificado=verificarCadastro(apelidoJ1,apelidoJ2);

            if(verificado){
                executarPartida(tipoJogo,apelidoJ1,apelidoJ2);
            }else{
                std::cout<<"ERRO: Jogador(es) inexistente(s)"<<std::endl;
            };
            
        }else if(resp!="FS"){
            /**
             * @brief Tratamento para comandos inválidos.
             * @details Exibe mensagem de erro caso o comando digitado seja diferente de "FS" e não esteja listado.
             */
            std::cout<<"Comando inválido"<<std::endl;
        }
    };
};