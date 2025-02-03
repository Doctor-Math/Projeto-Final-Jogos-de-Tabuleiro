<h1 align="center">                                                    Projeto Final - Jogos de Tabuleiro ♟ </h1>

**Aplicar os conceitos de PDS2 em um programa funcional que reflete nosso aprendizado durante as aulas**

- Participantes 🧑‍💻: Guilherme Bueno de Andrade Motta,  Gustavo Cabral Gonçalves, Matheus Soares e Renato Lucas

**Introdução**

Neste projeto, vamos aplicar técnicas aprendidas em sala de aula com o objetivo de criar um programa que reproduz o funcionamento de vários jogos tabuleiro, sendo eles Jogo da Velha, Lig4 e Reversi. Neste programa foram aplicados conceitos de Modularização, Classes, Programação Orientada a Objetos (POO), entre outros. Para realizar o projeto utilizamos das ferramentas do GitHub, VScode, Doxygen e Docteste. Tal programa foi feito com a finalidade para que possamos simular um ambiente de programação em equipe e também nos ambientarmos com as novas técnicas aprendidas.

# Projeto 🏆


**Modularização 🐉**

O programa é dividido em módulos para que ele seja melhor organizado fácilitando a entende-lo e também para ajudar o trabalho em equipe para que vários participantes possam programas em diferentes módulos ao mesmo tempo. 

A modularização foi dividida em pastas. Os arquivos hpp, que estão na pasta include, Definem as classes e funções utilizadas no projeto. Já os arquivos com as implementações, os cpp, estão na pasta src, eles definem as classes e funções utilizadas no projeto para serem utilizadas no arquivo main. Além deles temos o arquivo principal(main) e o Makefile, o primeiro deles é responsável por executar o programa e o segundo é encarregado de compilar o projeto automaticamente.

# Modelagem CRC 📌  

## 🟣 Classe Abstrata: JogoTabuleiro  

| **Classe**       | **Responsabilidades** | **Colaboração** |
|------------------|------------------------|--------------------|
| **JogoTabuleiro** | - Fornecer a estrutura do tabuleiro  | - Nenhuma |
|                  | - Fornecer peças  | |
|                  | - Ler uma jogada  | |
|                  | - Testar a validade da jogada  | |
|                  | - Testar condições de vitória  | |
|                  | - Imprimir tabuleiro  | |

---

## 🟠 Classe Herdeira: JogoDaVelha  

| **Classe**       | **Responsabilidades** | **Colaboração** |
|------------------|------------------------|--------------------|
| **JogoDaVelha**  | - (Herdado) Fornecer a estrutura do tabuleiro  | - `JogoTabuleiro` |
|                  | - (Herdado) Fornecer peças  | |
|                  | - (Herdado) Ler uma jogada  | |
|                  | - (Sobrescreve) `validarJogada()`: Testa a validade da jogada no Jogo da Velha  | |
|                  | - (Sobrescreve) `verificarVitoria()`: Testa as condições de vitória específicas  | |
|                  | - (Sobrescreve) `imprimirTabuleiro()`: Imprime o tabuleiro  | |

---

## 🟠 Classe Herdeira: Lig4  

| **Classe**  | **Responsabilidades** | **Colaboração** |
|-------------|------------------------|--------------------|
| **Lig4**    | - (Herdado) Fornecer a estrutura do tabuleiro  | - `JogoTabuleiro` |
|             | - (Herdado) Fornecer peças  | |
|             | - (Herdado) Ler uma jogada  | |
|             | - (Sobrescreve) `validarJogada()`: Testa a validade da jogada no Lig4  | |
|             | - (Sobrescreve) `verificarVitoria()`: Testa as condições de vitória específicas  | |
|             | - (Sobrescreve) `imprimirTabuleiro()`: Imprime o tabuleiro  | |

---

## 🟠 Classe Herdeira: Reversi  

| **Classe**  | **Responsabilidades** | **Colaboração** |
|-------------|------------------------|--------------------|
| **Reversi** | - (Herdado) Fornecer a estrutura do tabuleiro  | - `JogoTabuleiro` |
|             | - (Herdado) Fornecer peças  | |
|             | - (Herdado) Ler uma jogada  | |
|             | - (Sobrescreve) `validarJogada()`: Testa a validade da jogada no Reversi  | |
|             | - (Sobrescreve) `verificarVitoria()`: Testa as condições de vitória específicas  | |
|             | - (Sobrescreve) `imprimirTabuleiro()`: Imprime o tabuleiro  | |
|             | - **Novo método:** `verificarDirecao(int, int, int, int, int)`: Verifica se há peças alinhadas em uma determinada direção  | |



# Funcionamento Do Programa 🧑‍💻

## Cadastro de jogador
**Entrada:**
```plaintext
CJ
Math
Matheus
```
**Saída:**
```plaintext
Digite o apelido do jogador:
Digite o nome do jogador:
Jogador Math cadastrado com sucesso
```

---

## Remoção de jogador
**Entrada:**
```plaintext
RJ
Math
```
**Saída:**
```plaintext
Digite o apelido do jogador a ser removido:
Jogador Math removido com sucesso!
```

---

## Listar jogadores
**Entrada:**
```plaintext
LJ
```
**Saída:**
```plaintext
RenatoValis Renato
REVERSI - V: 0 D: 0
LIG4 - V: 0 D: 1
VELHA - V: 0 D: 1
--------------------
DoctorMath Matheus
REVERSI - V: 0 D: 0
LIG4 - V: 1 D: 0
VELHA - V: 1 D: 0
--------------------
```

---

## Executar partida
**Entrada:**
```plaintext
EP
V
DoctorMath
RenatoValis
```
**Saída:**
```plaintext
Jogo: 
Apelido do jogador 1:
Apelido do jogador 2:
AGUARDE: Abrindo o tabuleiro, organizando as peças...
Turno do jogador DoctorMath:
```

---

## Finalizar sistema
**Entrada:**
```plaintext
FS
```


No início do programa o usuário pode se cadastrar escolhendo o seu nome e apelido, esses dados vão para um arquivo no qual o usuário pode cadastrar mais jogadores ou remover os já criados. Após o cadastro, o usuário escolhe qual jogo ele quer iniciar a depender das letras que ele digitar, por exemplo R -> Reversi, L ->Lig e V-> Jogo da Velha. Na execução das partidas o usuário deve entrar com os apelidos dos dois jogadores e o sistema mostrar uma partida do jogo selecionado, sendo ela interatica na qual os dois jogadores podem competir entre si. Durante a partida o sistema ele é capaz de checar se uma jogada é válida ou não, atualizar o jogo a cada jogada e testar uma possível vitória de um jogador. No final do jogo, o programa mostra o vencedor e no banco de dados que contém os nomes e apelidos dos jogadores ele atualiza as estatísticas dos indivíduos.



# Dificuldades 😮‍💨

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
 
 - Conseguir fazer a verificação de vitórias no jogo Reversi e Lig4
 - Se ambientar com o GitHub e suas funcionalidades
 - Conseguir que o sistema conseguisse entender e marcar cada jogada
 - Aprender o usar o doxygen
 - Tentar entender a lógica geral do programa
