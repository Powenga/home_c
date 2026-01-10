# gcc
СС = gcc
CFLAGS = -Wall -Wextra -g -Iinclude

# Folders
SRC = src
OBJ = obj
BIN = bin
INCLUDE = include

# exe file name
TARGET = $(BIN)/app

all: create_dirs $(BIN)/app

create_dirs:
	if not exist obj mkdir obj
	if not exist bin mkdir bin

$(BIN)/app: $(OBJ)/main.o $(OBJ)/utils.o $(OBJ)/temp_api.o
	if not exist $(OBJ) mkdir $(OBJ)
	if not exist $(BIN) mkdir $(BIN)
	$(CC) $(CFLAGS) $(OBJ)/main.o $(OBJ)/utils.o $(OBJ)/temp_api.o -o $(BIN)/app

$(OBJ)/main.o: $(SRC)/main.c $(INCLUDE)/temp_api.h $(INCLUDE)/temperature_record.h
	$(CC) $(CFLAGS) -c $(SRC)/main.c -o $(OBJ)/main.o

$(OBJ)/utils.o: $(SRC)/utils.c $(INCLUDE)/utils.h $(INCLUDE)/temperature_record.h
	$(CC) $(CFLAGS) -c $(SRC)/utils.c -o $(OBJ)/utils.o

$(OBJ)/temp_api.o: $(SRC)/temp_api.c $(INCLUDE)/temp_api.h $(INCLUDE)/temperature_record.h
	$(CC) $(CFLAGS) -c $(SRC)/temp_api.c -o $(OBJ)/temp_api.o

clean:
	if exist obj rmdir /s /q obj
	if exist bin rmdir /s /q bin
