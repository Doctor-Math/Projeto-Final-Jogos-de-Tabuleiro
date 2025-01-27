CC=g++
CFLAGS=-std=c++11 -Wall
SRC_DIR=src
INCLUDE_DIR=include
OBJ_DIR=obj

# Alvo padrão
all: $(OBJ_DIR)/Jogo_Tabuleiro

# Criação do diretório build, se não existir
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Compilação do arquivo JogoTabuleiro.o
$(OBJ_DIR)/JogoTabuleiro.o: $(SRC_DIR)/JogoTabuleiro.cpp $(INCLUDE_DIR)/JogoTabuleiro.hpp | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/JogoTabuleiro.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/JogoTabuleiro.o

# Compilação do arquivo JogoDaVelha.o
$(OBJ_DIR)/JogoDaVelha.o: $(SRC_DIR)/JogoDaVelha.cpp $(INCLUDE_DIR)/JogoDaVelha.hpp | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/JogoDaVelha.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/JogoDaVelha.o

# Compilação do arquivo Lig4.o
$(OBJ_DIR)/Lig4.o: $(SRC_DIR)/Lig4.cpp $(INCLUDE_DIR)/Lig4.hpp | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/Lig4.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/Lig4.o

# Compilação do arquivo Reversi.o
$(OBJ_DIR)/Reversi.o: $(SRC_DIR)/Reversi.cpp $(INCLUDE_DIR)/Reversi.hpp | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/Reversi.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/Reversi.o

# Compilação do arquivo Cadastro.o
$(OBJ_DIR)/Cadastro.o: $(SRC_DIR)/Cadastro.cpp $(INCLUDE_DIR)/Cadastro.hpp | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/Cadastro.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/Cadastro.o

# Compilação do arquivo ExecucaoPartidas.o
$(OBJ_DIR)/ExecucaoPartidas.o: $(SRC_DIR)/ExecucaoPartidas.cpp $(INCLUDE_DIR)/ExecucaoPartidas.hpp | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/ExecucaoPartidas.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/ExecucaoPartidas.o

# Compilação do arquivo main.o
$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp $(INCLUDE_DIR)/Cadastro.hpp $(INCLUDE_DIR)/ExecucaoPartidas.hpp | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/main.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/main.o

# Criação do executável
$(OBJ_DIR)/Jogo_Tabuleiro: $(OBJ_DIR)/main.o $(OBJ_DIR)/JogoTabuleiro.o $(OBJ_DIR)/JogoDaVelha.o $(OBJ_DIR)/Lig4.o $(OBJ_DIR)/Reversi.o $(OBJ_DIR)/Cadastro.o $(OBJ_DIR)/ExecucaoPartidas.o
	$(CC) $(CFLAGS) $(OBJ_DIR)/main.o $(OBJ_DIR)/JogoTabuleiro.o $(OBJ_DIR)/JogoDaVelha.o $(OBJ_DIR)/Lig4.o $(OBJ_DIR)/Reversi.o $(OBJ_DIR)/Cadastro.o $(OBJ_DIR)/ExecucaoPartidas.o -o $(OBJ_DIR)/Jogo_Tabuleiro

# Limpeza de arquivos gerados
clean:
	del /f /q obj\*.o obj\Jogo_Tabuleiro.exe
