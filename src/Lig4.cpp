#include <iostream>
#include "Lig4.hpp"
#include "doctest.h"



// Constantes que definem o número de linhas e colunas do tabuleiro.
const int TAM_LINHAS=6, TAM_COL=7;

/**
* @brief Construtor da classe Lig4.
*Inicializa o tabuleiro com as dimensões padrão (6x7).
*/
Lig4::Lig4()
{
    this->dimensionarTabuleiro(6, 7);
}

int Lig4::retornaLinha(int coluna)
{
    coluna--;
    for (int i = (TAM_LINHAS - 1); i >= 0; i--)
    {
        if (this->retornarPosicao(i, coluna) == '\0')
        {
            return i;
        };
    };
    return -1;
};

/**
 * @brief Valida a jogada de um jogador e atualiza o tabuleiro.
 * 
 * @param nulo Parâmetro sem uso (incluso para compatibilidade).
 * @param coluna Coluna escolhida para a jogada.
 * @param turno Determina o jogador atual (0 para 'X' e 1 para 'O').
 * @throws Exibe mensagem de erro se a jogada for inválida.
 */
void Lig4::validarJogada(int nulo, int coluna, int turno)
{
    if (coluna > 1 || coluna < 7)
    {
        int linha = this->retornaLinha(coluna);
        if (linha == -1)
        {
            std::cout << "ERRO: jogada inválida";
        }
        else
        {
            this->marcarTabuleiro(linha, coluna - 1, (turno == 0) ? 'X' : 'O');
        }
    }
    else
    {
        std::cout << "ERRO: jogada inválida";
    }
};

void Lig4::imprimirTabuleiro()
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

int menorNum(int a, int b)
{
    if (a < b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

/**
 * @brief Verifica se um jogador venceu o jogo.
 * 
 * @param marcacao Caractere do jogador ('X' ou 'O').
 * @return int Retorna 1 se houver vitória; 0 caso contrário.
 */
int Lig4::verificarVitoria(char marcacao, int linha, int coluna)
{
    coluna--;
    int flag = 0;
    int i, j;
    linha++;

    // Verifica a linha:
    j = 0;
    while (j < TAM_COL)
    {
        if (this->retornarPosicao(linha, j) == marcacao)
        {
            flag++;
            if (flag == 4)
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
            if (flag == 4)
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

    // Diagonal da direita para a esquerda:
    int dist = menorNum(linha, (TAM_COL - 1) - coluna);

    // Verifica a diagonal da esquerda pra direita descendo:
    i = linha - dist, j = coluna + dist;
    while (i < TAM_LINHAS && j >= 0)
    {
        if (this->retornarPosicao(i, j) == marcacao)
        {
            flag++;
            if (flag == 4)
            {
                return 1;
            };
        }
        else
        {
            flag = 0;
        };
        i++, j--;
    }

    // Diagonal da esquerda para a direita:
    dist = menorNum(linha, coluna);

    // Verifica a diagonal da jogada pra direita descendo:
    i = linha - dist, j = coluna - dist;
    while (i < TAM_LINHAS && j < TAM_COL)
    {
        if (this->retornarPosicao(i, j) == marcacao)
        {
            flag++;
            if (flag == 4)
            {
                return 1;
            };
        }
        else
        {
            flag = 0;
        };
        i++, j++;
    }

    return 0;
}

/**
 * @brief Destrutor da classe Lig4.
 * Exibe mensagem de encerramento do jogo.
 */
Lig4::~Lig4()
{
    std::cout << "Encerrando o jogo..." << std::endl;
};
