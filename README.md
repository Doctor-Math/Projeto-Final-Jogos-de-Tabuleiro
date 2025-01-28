<h1 align="center"> Projeto Final - Jogos de Tabuleiro </h1>

**Aplicar os conceitos de PDS2 em um programa funcional que reflete nosso aprendizado durante as aulas**

- Participantes: Guilherme Bueno de Andrade Motta,  Gustavo Cabral Gonçalves, Matheus Soares e Renato Lucas

**Introdução**

Neste projeto, vamos aplicar técnicas aprendidas em sala de aula com o objetivo de criar um programa que reproduz o funcionamento de vários jogos tabuleiro, sendo eles Jogo da Velha, Lig4 e Reversi. Neste programa foram aplicados conceitos de Modularização, Classes, Programação Orientada a Objetos (POO), entre outros. Para realizar o projeto utilizamos das ferramentas do GitHub, VScode, Doxygen e Docteste. Tal programa foi feito com a finalidade para que possamos simular um ambiente de programação em equipe e também nos ambientarmos com as novas técnicas aprendidas.

# Projeto

**Modularização**

O programa é dividido em módulos para que ele seja melhor organizado fácilitando a entende-lo e também para ajudar o trabalho em equipe para que vários participantes possam programas em diferentes módulos ao mesmo tempo. 

A modularização foi dividida em pastas. Os arquivos hpp, que estão na pasta include, Definem as classes e funções utilizadas no projeto. Já os arquivos com as implementações, os cpp, estão na pasta src, eles definem as classes e funções utilizadas no projeto para serem utilizadas no arquivo main. Além deles temos o arquivo principal(main) e o Makefile, o primeiro deles é responsável por executar o programa e o segundo é encarregado de compilar o projeto automaticamente.

***CLASSES***

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

(Herdada de JogoTabuleiro) Sobrescreve o método validarJogada() para testar a validade da jogada no jogo da velha; 

(Herdada de JogoTabuleiro) Sobrescreve o método verificarVitoria() para testar as condições de vitória específicas do jogo da velha; 

(Herdada de JogoTabuleiro) Sobrescreve o método imprimirTabuleiro() para imprimir o tabuleiro. 

Colaboração: JogoTabuleiro.


**🟣Classe Herdeira**: Lig4

Responsabilidades:

(Herdada de JogoTabuleiro) Fornecer a estrutura do tabuleiro; 

(Herdada de JogoTabuleiro) Fornecer peças; 

(Herdada de JogoTabuleiro) Ler uma jogada; 

(Herdada de JogoTabuleiro) Sobrescreve o método validarJogada() para testar a validade da jogada no jogo lig4; 

(Herdada de JogoTabuleiro) Sobrescreve o método verificarVitoria() para testar as condições de vitória específicas do lig4; 

(Herdada de JogoTabuleiro) Sobrescreve o método imprimirTabuleiro() para imprimir o tabuleiro. 

Colaboração: JogoTabuleiro.


**🟣Classe Herdeira**: Reversi

(Herdado de JogoTabuleiro) Fornecer a estrutura do tabuleiro.

(Herdado de JogoTabuleiro) Fornecer peças.

(Herdado de JogoTabuleiro) Ler uma jogada.

(Herdado de JogoTabuleiro) Sobrescreve o método validarJogada() para testar a validade da jogada no jogo Reversi.

(Herdado de JogoTabuleiro) Sobrescreve o método verificarVitoria() para verificar as condições de vitória específicas do Reversi.

(Herdado de JogoTabuleiro) Sobrescreve o método imprimirTabuleiro() para imprimir o tabuleiro

Novo método verificarDirecao(int, int, int, int, int): Método que verifica se há peças alinhadas em uma determinada direção (útil para capturar peças no Reversi).


# Funcionamento Do Programa

No início do programa o usuário pode se cadastrar escolhendo o seu nome e apelido, esses dados vão para um arquivo no qual o usuário pode cadastrar mais jogadores ou remover os já criados. Após o cadastro, o usuário escolhe qual jogo ele quer iniciar a depender das letras que ele digitar, por exemplo R -> Reversi, L ->Lig e V-> Jogo da Velha. Na execução das partidas o usuário deve entrar com os apelidos dos dois jogadores e o sistema mostrar uma partida do jogo selecionado, sendo ela interatica na qual os dois jogadores podem competir entre si. Durante a partida o sistema ele é capaz de checar se uma jogada é válida ou não, atualizar o jogo a cada jogada e testar uma possível vitória de um jogador. No final do jogo, o programa mostra o vencedor e no banco de dados que contém os nomes e apelidos dos jogadores ele atualiza as estatísticas dos indivíduos.



# Dificuldades

 A criação desse algoritmo foi um processo ao mesmo tempo muito divertido, foi também
 custoso. A liberdade de poder criar um código da nossa maneira, poder usar todos
 os nossos conhecimentos e quando não sabiamos o que fazer, pesquisar na internet,
 conversar entre nós e com outros colegas sobre alguma solução para o problema, foram
 situações satisfatórias.

 Em muitos momentos, pensavamos que o código estava funcionando da maneira
 correta e ao prosseguir por outro teste e ele dar totalmente errado era bem
 desagradável, mas sempre uma oportunidade de procurar o erro e resolve-lo da
 melhor maneira possível.

 😡Nossas principais dificuldades foram:
