#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include "Cadastro.hpp"

void cadastrarJogador(){
    std::string nome, apelido, arq_nome="Jogadores.txt";
    std::fstream arquivo(arq_nome,std::ios::in);

    if(!arquivo){
        std::cout<<"ERRO: Arquivo não encontrado!";
        return;
    };
    
    //Leitura do nome e do apelido do jogador:
    std::cin>>apelido>>nome;
    apelido.erase(apelido.find_last_not_of(" \t\n\r") + 1); // Remove espaços
    nome.erase(nome.find_last_not_of(" \t\n\r") + 1); 

    //Verifica se o jogador a ser inserido já existe:
    std::string linha;
    int contador=0;

    while(std::getline(arquivo,linha)){
        if(contador%4==0){
            if(linha.rfind(apelido,0)==0){
                std::cout<<"Erro: jogador repetido"<<std::endl;
                return;
            };
        };
        contador++;
    };

    arquivo.close();

    arquivo.open(arq_nome,std::ios::app);
    if(!arquivo){
        std::cout<<"ERRO: Falha na abertura do arquivo para reescrita"<<std::endl;
        return;
    };

    arquivo<<apelido<<" "<<nome<<std::endl
    <<"REVERSI - V: 0 D: 0"<<std::endl
    <<"LIG4    - V: 0 D: 0"<<std::endl
    <<"VELHA   - V: 0 D: 0"<<std::endl
    <<"--------------------"<<std::endl;

    std::cout<<"Jogador "<<apelido<<" cadastrado com sucesso"<<std::endl;

    arquivo.close();
};

void removerJogador(){
    std::string apelido, arq_nome="Jogadores.txt",temp_nome="Temporario.txt";
    std::ifstream arquivo(arq_nome);
    // Arquivo intermediário:
    std::ofstream arq_temp(temp_nome);
    bool encontrado=false;

    if(!arquivo.is_open() || !arq_temp.is_open()){
        std::cout<<"Erro ao abrir o arquivo!"<<std::endl;
        return;
    };
    
    // Leitura do nome e do apelido do jogador:
    std::cin>>apelido;
    apelido.erase(apelido.find_last_not_of(" \t\n\r") + 1); // Remove espaços

    std::string linha, primeira_palavra;

    // Todas as seções do arquivo são copiadas, exceto as pertencentes ao jogador a ser excluído:
    while(std::getline(arquivo,linha)){
        if(linha.rfind(apelido,0)==0){
            encontrado=true;
            for(int i=0;i<4;i++){
                getline(arquivo,linha);
                };
        }else{
        arq_temp<<linha<<std::endl;
        };
    };

    if(!encontrado){
        std::cout<<"ERRO: Jogador inexistente"<<std::endl;
        return;
    };

    arquivo.close();
    arq_temp.close();

    if(remove(arq_nome.c_str())!=0){
        std::cout<<"Erro ao remover o antigo arquivo de jogadores!"<<std::endl;
        return;
    }
    if(rename(temp_nome.c_str(),arq_nome.c_str())!=0){
        std::cout<<"Erro ao renomear o arquivo temporário!"<<std::endl;
        return;
    };

};

void listarJogadores(){
    std::string apelido, linha, arq_nome="Jogadores.txt",temp_nome="Temporario.txt";
    std::ifstream arquivo(arq_nome);

    if(!arquivo.is_open()){
        std::cout<<"Erro ao abrir o arquivo para impressão."<<std::endl;
        return;
    };

    int vazio=1;

    while(getline(arquivo,linha)){
        vazio=0;
        std::cout<<linha<<std::endl;
    };

    if(vazio){
        std::cout<<"Não há jogadores cadastrados";
    };

    arquivo.close();
};

int verificarCadastro(std::string apelidoJ1, std::string apelidoJ2){
    int encontradoJ1=0, encontradoJ2=0;
    std::string arq_nome="Jogadores.txt", linha;
    std::ifstream arquivo(arq_nome);

    if(!arquivo.is_open()){
        std::cout<<"Erro ao abrir o arquivo para verificação de existência de jogadores."<<std::endl;
        return -1;
    };

    int contador=0;

    while(getline(arquivo,linha)){
        if(contador%4==0){
            if(linha.rfind(apelidoJ1,0)==0){
                encontradoJ1=1;
            }else if(linha.rfind(apelidoJ2,0)==0){
                encontradoJ2=1;
            };
        };
        contador++;
    };

    arquivo.close();

    if(encontradoJ1 && encontradoJ2){
        return 1;
    }else{
        return 0;
    };
};