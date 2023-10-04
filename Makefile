# I'll use `gcc`:
CC = gcc

# Directories and stuff:
SRC_DIR = .
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)

# Object files directory:
OBJ_DIR = ./build

# Object files (per source file):
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))
# `patsubst` is basically find-and-replace (tokens are seperated by whitespace).

all: $(OBJ_FILES)

# Compiles all object files into a C one:
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) -c $< -o $@

# Compiles the [currently, the] only file in the `scanf()`-security wrapper API:
$(OBJ_DIR)/IoUtilsByBrahvim.o: ./scan-api-impls/IoUtilsByBrahvim.c
	$(CC) -c $< -o $@

# Clean rule to remove object files:
clean:
	rm -rf $(OBJ_DIR)

.PHONY: all clean
