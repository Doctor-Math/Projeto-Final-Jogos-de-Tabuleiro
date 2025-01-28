#include <iostream>
#include <stdexcept>
#include "Reversi.hpp"

const int TAM_LINHAS = 8, TAM_COL=8;

Reversi::Reversi(){
    this->dimensionarTabuleiro(8,8);
    // Marcação das diagonais:
    this->marcarTabuleiro(3,3,'X');
    this->marcarTabuleiro(3,4,'O');
    this->marcarTabuleiro(4,3,'O');
    this->marcarTabuleiro(4,4,'X');
}


void Reversi::imprimirTabuleiro(){
    for(int i=0;i<TAM_LINHAS;i++){
        std::cout<<"|";
        for(int j=0;j<TAM_COL;j++){
            if(this->retornarPosicao(i,j)=='\0'){
                std::cout<<" "<<"|";
            }else{
            std::cout << this->retornarPosicao(i, j)<<"|";
            };
        };
        std::cout<<std::endl;
    };
};

void Reversi::validarJogada(int linha, int coluna, int turno) {   
    linha--;
    coluna--;

    // Verificar se a posição está dentro dos limites
    if (linha > 7 || linha < 0 || coluna > 7 || coluna < 0) {
        throw std::out_of_range("formato incorreto");
    } else if (this->retornarPosicao(linha, coluna) == '\0') {
        // Verificar nas direções: linhas, colunas e diagonais
        if (verificarDirecao(linha, coluna, turno, -1, 0) ||  // Esquerda
            verificarDirecao(linha, coluna, turno, 1, 0) ||   // Direita
            verificarDirecao(linha, coluna, turno, 0, -1) ||  // Acima
            verificarDirecao(linha, coluna, turno, 0, 1) ||   // Abaixo
            verificarDirecao(linha, coluna, turno, -1, -1) || // Diagonal superior esquerda para inferior direita
            verificarDirecao(linha, coluna, turno, -1, 1) ||  // Diagonal superior direita para inferior esquerda
            verificarDirecao(linha, coluna, turno, 1, -1) ||  // Diagonal inferior esquerda para superior direita
            verificarDirecao(linha, coluna, turno, 1, 1)) {   // Diagonal inferior direita para superior esquerda
            this->marcarTabuleiro(linha, coluna, (turno == 0) ? 'X' : 'O');
        } else {
            std::cout << "ERRO: jogada inválida";
        }
    }
}

// Função auxiliar para verificar uma direção e inverter as peças
bool Reversi::verificarDirecao(int linha, int coluna, int turno, int dLinha, int dColuna) {
    int i = linha + dLinha;
    int j = coluna + dColuna;
    int sucessao = 0;
    bool jogadaValida = false;

    // Laço para verificar a direção especificada
    while (i >= 0 && i < TAM_LINHAS && j >= 0 && j < TAM_COL) {
        char pos = this->retornarPosicao(i, j);
        if (pos != '\0' && pos != ((turno == 0) ? 'X' : 'O')) {
            // Encontrou uma peça adversária
            sucessao++;
        } else if (pos == ((turno == 0) ? 'X' : 'O')) {
            // Encontrou uma peça do jogador
            if (sucessao > 0) {
                // Inverter todas as peças adversárias na direção
                for (int k = 1; k <= sucessao; k++) {
                    int invertLinha = linha + k * dLinha;
                    int invertCol = coluna + k * dColuna;
                    this->marcarTabuleiro(invertLinha, invertCol, (turno == 0) ? 'X' : 'O');
                }
                jogadaValida = true;  // Jogada válida, deve inverter as peças
            }
            break;
        } else {
            break;  // Encontrou uma posição vazia, interrompe
        }

        i += dLinha;  // Avança na direção da linha
        j += dColuna; // Avança na direção da coluna
    }

    return jogadaValida;  // Retorna se a jogada foi válida
}

int Reversi::verificarVitoria(char nulo) {
    int contX = 0; // Contador para as peças do jogador X
    int contO = 0; // Contador para as peças do jogador O
    bool jogadaPossivelX = false; // Verifica se X pode jogar
    bool jogadaPossivelO = false; // Verifica se O pode jogar

    for (int i = 0; i < TAM_LINHAS; i++) {
        for (int j = 0; j < TAM_COL; j++) {
            char pos = this->retornarPosicao(i, j);

            // Conta as peças de cada jogador
            if (pos == 'X') contX++;
            else if (pos == 'O') contO++;

            // Verifica se há jogadas possíveis para X e O
            if (pos == nulo) {
                if (!jogadaPossivelX && 
                    (verificarDirecao(i, j, 0, -1, 0) || verificarDirecao(i, j, 0, 1, 0) ||
                     verificarDirecao(i, j, 0, 0, -1) || verificarDirecao(i, j, 0, 0, 1) ||
                     verificarDirecao(i, j, 0, -1, -1) || verificarDirecao(i, j, 0, -1, 1) ||
                     verificarDirecao(i, j, 0, 1, -1) || verificarDirecao(i, j, 0, 1, 1))) {
                    jogadaPossivelX = true;
                }
                if (!jogadaPossivelO &&
                    (verificarDirecao(i, j, 1, -1, 0) || verificarDirecao(i, j, 1, 1, 0) ||
                     verificarDirecao(i, j, 1, 0, -1) || verificarDirecao(i, j, 1, 0, 1) ||
                     verificarDirecao(i, j, 1, -1, -1) || verificarDirecao(i, j, 1, -1, 1) ||
                     verificarDirecao(i, j, 1, 1, -1) || verificarDirecao(i, j, 1, 1, 1))) {
                    jogadaPossivelO = true;
                }
            }
        }
    }

    // Se nenhum jogador pode jogar, o jogo termina
    if (!jogadaPossivelX && !jogadaPossivelO) {
        if (contX > contO) return 1; // X vence
        else if (contO > contX) return 2; // O vence
        else return 3; // Empate
    }

    // Jogo continua
    return 0;
}


Reversi::~Reversi(){
    std::cout<<"Encerrando o jogo..."<<std::endl;
};