#include <iostream>
#include <stdexcept>
#include "Reversi.hpp"

// Constantes que definem o número de linhas e colunas do tabuleiro.
const int TAM_LINHAS = 8, TAM_COL=8;

/**
 * @brief Construtor da classe Reversi.
 * 
 * Inicializa o tabuleiro do jogo Reversi com dimensões 8x8 e configura
 * as peças iniciais nas posições padrão para começar o jogo.
 */
Reversi::Reversi(){
    this->dimensionarTabuleiro(8,8);
    // Marcação das diagonais:
    this->marcarTabuleiro(3,3,'X');
    this->marcarTabuleiro(3,4,'O');
    this->marcarTabuleiro(4,3,'O');
    this->marcarTabuleiro(4,4,'X');
}


/**
 * @brief Imprime o tabuleiro do jogo Reversi no console.
 * 
 * Este método exibe o tabuleiro atual do jogo, mostrando as posições
 * ocupadas por 'X', 'O' e espaços vazios representados por ' '.
 */
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

/**
 * @brief Valida a jogada de um jogador.
 * 
 * Verifica se a jogada realizada na posição especificada (linha, coluna) 
 * é válida com base no turno atual do jogador e, se for válida, marca a posição 
 * e realiza as alterações necessárias no tabuleiro.
 * 
 * @param linha Linha onde o jogador quer realizar a jogada (1 a 8).
 * @param coluna Coluna onde o jogador quer realizar a jogada (1 a 8).
 * @param turno Indica o turno atual do jogador (0 para 'X', 1 para 'O').
 * 
 * @throws std::out_of_range Caso a posição esteja fora dos limites do tabuleiro.
 */
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

/**
 * @brief Verifica a validade de uma jogada em uma direção específica.
 * 
 * Este método verifica se uma jogada na direção especificada (dLinha, dColuna)
 * é válida. Caso seja válida, as peças adversárias na direção são invertidas.
 * 
 * @param linha Linha da posição onde a jogada foi realizada.
 * @param coluna Coluna da posição onde a jogada foi realizada.
 * @param turno Turno do jogador atual (0 para 'X', 1 para 'O').
 * @param dLinha Direção da linha (-1, 0 ou 1).
 * @param dColuna Direção da coluna (-1, 0 ou 1).
 * @return true Se a jogada for válida na direção especificada.
 * @return false Se a jogada for inválida na direção especificada.
 */
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

/**
 * @brief Verifica se há um vencedor no jogo.
 * 
 * Analisa o estado atual do tabuleiro para determinar se o jogo terminou
 * e qual jogador venceu. Se nenhum jogador pode realizar jogadas, o jogo 
 * termina e a contagem de peças decide o vencedor.
 * 
 * @param nulo Caractere representando posições vazias no tabuleiro ('\0').
 * @return int Retorna:
 * - 1 se o jogador 'X' venceu,
 * - 2 se o jogador 'O' venceu,
 * - 3 se houve empate,
 * - 0 se o jogo ainda não terminou.
 */
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

/**
 * @brief Destrutor da classe Reversi.
 * Exibe uma mensagem indicando que o jogo está sendo encerrado.
 */
Reversi::~Reversi(){
    std::cout<<"Encerrando o jogo..."<<std::endl;
};