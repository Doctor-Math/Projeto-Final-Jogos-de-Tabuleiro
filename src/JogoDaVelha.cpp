#include <iostream>
#include <stdexcept>
#include "JogoDaVelha.hpp"

//Tamanho do tabuleiro do jogo da velha
const int TAM_LINHAS = 3, TAM_COL = 3;


/**
 * @brief Construtor da classe JogoDaVelha.
 * Inicializa o tabuleiro com as dimensões 3x3.
 */

JogoDaVelha::JogoDaVelha()
{
    this->dimensionarTabuleiro(TAM_LINHAS, TAM_COL);
};


/**
 * @brief Valida a jogada do jogador.
 * 
 * @param linha Linha escolhida pelo jogador (1 a 3).
 * @param coluna Coluna escolhida pelo jogador (1 a 3).
 * @param turno Identifica o turno do jogador (0 para 'X', 1 para 'O').
 * 
 * @throws std::out_of_range Se a linha ou coluna estiverem fora do intervalo permitido.
 */


void JogoDaVelha::validarJogada(int linha, int coluna, int turno)
{
    linha--;
    coluna--;
    if (linha > 2 || linha < 0 || coluna > 2 || coluna < 0)
    {
        throw std::out_of_range("formato incorreto");
    }
    else if (this->retornarPosicao(linha, coluna) == '\0')
    {
        this->marcarTabuleiro(linha, coluna, (turno == 0) ? 'X' : 'O');
    }
    else
    {
        std::cout << "ERRO: jogada inválida"<<std::endl;
    };
};


/**
 * @brief Imprime o estado atual do tabuleiro no console.
 */


void JogoDaVelha::imprimirTabuleiro()
{
    for (int i = 0; i < TAM_LINHAS; i++)
    {
        std::cout << "|";
        for (int j = 0; j < TAM_COL; j++)
        {
            if (this->retornarPosicao(i, j) == '\0')
            {
                std::cout << " " << "|";
            }
            else
            {
                std::cout << this->retornarPosicao(i, j) << "|";
            };
        };
        std::cout << std::endl;
    };
};


/**
 * @brief Verifica se um jogador venceu a partida.
 * 
 * @param marcacao Caractere do jogador ('X' ou 'O').
 * 
 * @return int Retorna 1 se o jogador venceu, ou 0 caso contrário.
 */

    
int JogoDaVelha::verificarVitoria(char marcacao, int linha, int coluna)
{
    int flag = 0;
    int i, j;
    linha--;
    coluna--;

    // Verifica a linha:
    j = 0;
    while (j < TAM_COL)
    {
        if (this->retornarPosicao(linha, j) == marcacao)
        {
            flag++;
            if (flag == 3)
            {
                return 1;
            };
        }
        else
        {
            flag = 0;
        };
        j++;
    };

    // Verifica a coluna:
    i = 0;
    while (i < TAM_LINHAS)
    {
        if (this->retornarPosicao(i, coluna) == marcacao)
        {
            flag++;
            if (flag == 3)
            {
                return 1;
            };
        }
        else
        {
            flag = 0;
        };
        i++;
    };

    // Verifica a diagonal principal:
    for (i = 0; i < TAM_LINHAS; i++)
    {
        j = i;

        if (this->retornarPosicao(i, j) == marcacao)
        {
            flag = 1;
            if (i == 2)
            {
                return flag;
            };
        }
        else
        {
            flag = 0;
            break;
        };
    };

    // Verifica a diagonal secundária:
    for (i = 0, j = 2; i < TAM_LINHAS; i++)
    {
        if (this->retornarPosicao(i, j) == marcacao)
        {
            flag = 1;
            if (i == 2)
            {
                return flag;
            };
        }
        else
        {
            flag = 0;
            break;
        };
        j--;
    };

    return flag;
};

/**
 * @brief Destrutor da classe JogoDaVelha.
 * Imprime uma mensagem ao encerrar o jogo.
 */


JogoDaVelha::~JogoDaVelha()
{
    std::cout << "Encerrando o jogo..." << std::endl;
};
