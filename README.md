<h1 align="center"> Projeto Final - Jogos de Tabuleiro </h1>

**Aplicar os conceitos de PDS2 em um programa funcional que reflete nosso aprendizado durante as aulas**

- Participantes: Guilherme Bueno de Andrade Motta,  Gustavo Cabral Gonçalves, Matheus Soares e Renato Lucas

**Introdução**

Neste projeto, vamos aplicar técnicas aprendidas em sala de aula com o objetivo de criar um programa que reproduz o funcionamento de vários jogos tabuleiro, sendo eles Jogo da Velha, Lig4 e Reversi. Neste programa foram aplicados conceitos de Modularização, Classes, Programação Orientada a Objetos (POO), entre outros. Para realizar o projeto utilizamos das ferramentas do GitHub, VScode, Doxygen e Docteste. Tal programa foi feito com a finalidade para que possamos simular um ambiente de programação em equipe e também nos ambientarmos com as novas técnicas aprendidas.

# Projeto

**Modularização**

O programa é dividido em módulos para que ele seja melhor organizado fácilitando a entende-lo e também para ajudar o trabalho em equipe para que vários participantes possam programas em diferentes módulos ao mesmo tempo. 

A modularização foi dividida em pastas. Os arquivos hpp, que estão na pasta include, Definem as classes e funções utilizadas no projeto. Já os arquivos com as implementações, os cpp, estão na pasta src, eles definem as classes e funções utilizadas no projeto para serem utilizadas no arquivo main. Além deles temos o arquivo principal(main) e o Makefile, o primeiro deles é responsável por executar o programa e o segundo é encarregado de compilar o projeto automaticamente.

******Classes*********

**🟣Classe Abstrata**: JogoTabuleiro 

Responsabilidades: 

Fornecer a estrutura do tabuleiro; 

Fornecer peças;

Ler uma jogada; 

Testar a validade da jogada; 

Testar condições de vitória; 

Imprimir tabuleiro.

Colaboração:

Nenhuma.  


**🟣Classe Herdeira**: JogoDaVelha

Responsabilidades:

(Herdada de JogoTabuleiro) Fornecer a estrutura do tabuleiro; 

(Herdada de JogoTabuleiro) Fornecer peças; 

(Herdada de JogoTabuleiro) Ler uma jogada; 

(Herdada de JogoTabuleiro) Sobrescreve o método validade() para testar a validade da jogada; 

(Herdada de JogoTabuleiro) Sobrescreve o método condicoesVitoria() para testar as condições de vitória; 

(Herdada de JogoTabuleiro) Sobrescreve o método imprime() para imprimir o tabuleiro. 

Colaboração: JogoTabuleiro.

