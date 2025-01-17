# Compilador e flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11

# Diretórios
SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = obj

# Arquivos fonte e objetos
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SOURCES))

# Executável
EXEC = main

# Regra padrão
all: $(EXEC)

# Regra para criar o executável
$(EXEC): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Regra para compilar os arquivos .cpp em .o
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# Limpeza dos arquivos gerados
clean:
	rm -f $(BUILD_DIR)/*.o $(EXEC)
