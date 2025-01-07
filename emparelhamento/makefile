# Variáveis
CC = g++
CFLAGS = -Wall
LIB_NAME = grafo
OBJ_FILES = $(OBJ_DIR)/grafo.o $(OBJ_DIR)/algoritmo-simples.o $(OBJ_DIR)/hopcroft-karp.o

# Diretórios
OBJ_DIR = obj

all: $(OBJ_DIR)/grafo.o $(OBJ_DIR)/algoritmo-simples.o $(OBJ_DIR)/hopcroft-karp.o

$(OBJ_DIR)/grafo.o:
	$(CC) -c grafo.cpp -o $(OBJ_DIR)/grafo.o

$(OBJ_DIR)/hopcroft-karp.o:
	$(CC) -c hopcroft-karp.cpp -o $(OBJ_DIR)/hopcroft-karp.o

$(OBJ_DIR)/algoritmo-simples.o:
	$(CC) -c algoritmo-simples.cpp -o $(OBJ_DIR)/algoritmo-simples.o
# Alvo 'compile' - compilar as bibliotecas
compile: all $(NAME).cpp
	$(CC) $(CFLAGS) $(OBJ_DIR)/*.o $(NAME).cpp -o $(NAME)

# Alvo 'run' - executar o programa compilado
run: $(NAME)
	./$(NAME)

# Alvo 'clean' - remover arquivos gerados
clean:
	rm -f $(OBJ_DIR)/*.o $(NAME)

# Definir o alvo default para 'run'
.DEFAULT_GOAL := run