#include <iostream>
#include "Lig4.hpp"

const int TAM_LINHAS = 6, TAM_COL = 7;

Lig4::Lig4()
{
    this->dimensionarTabuleiro(6, 7);
}

void Lig4::validarJogada(int nulo, int coluna, int turno)
{
    int flag = 0;
    coluna--;
    for (int i = (TAM_LINHAS - 1); i >= 0; i--)
    {
        if (this->retornarPosicao(i, coluna) == '\0')
        {
            this->marcarTabuleiro(i, coluna, (turno == 0) ? 'X' : 'O');
            flag = 1;
            break;
        };
    };
    if (!flag)
    {
        std::cout << "ERRO: jogada inválida";
    };
};

void Lig4::imprimirTabuleiro()
{
    for (int i = 0; i < TAM_LINHAS; i++)
    {
        std::cout << "|";
        for (int j = 0; j < TAM_COL; j++)
        {
            std::cout << this->retornarPosicao(i, j) << "|";
        };
        std::cout << std::endl;
    };
};

int verificarVitoria(char marcacao)
{
    int flag = 0;
    int i, j;
    // Verifica as linhas:
    for (i = 0; i++; i < TAM_LINHAS)
    {
        for (j = 0; j++; j < TAM_COL)
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
        };
    };

    // Verifica as colunas:
    for (j = 0; j++; j < TAM_COL)
    {
        for (i = 0; i++; i < TAM_LINHAS)
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
        };
    };
}

/*
Verifica se o meio corresponde:
    se sim:
        verifica se meio + 1, meio+2 e meio são iguais:
            se sim:
                verifica se


verifica se o meio corresponde:
    se sim:
        verifica se meio + 2 corresponde:
            se sim:
                verifica se meio+1 e meio+3 corespondem:
                    se sim:
                        retorna vitória
                    se não:
                        retorna 0
            se não:
                retona 0
    se não:
        retorna 0



*/
