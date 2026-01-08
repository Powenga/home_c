# gcc
СС = gcc

# Folders
SRC = src
OBJ = obj
BIN = bin
INCLUDE = include

# exe file name
TARGET = $(BIN)/app

# folders
$(shell mkdir $(OBJ) $(BIN))

all: $(BIN)/app

$(BIN)/app: $(OBJ)/main.o $(OBJ)/utils.o $(OBJ)/temp_api.o
	$(CC) $(OBJ)/main.o $(OBJ)/utils.o $(OBJ)/temp_api.o -o $(BIN)/app

$(OBJ)/main.o: $(SRC)/main.c $(INCLUDE)/temp_api.h $(INCLUDE)/temperature_record.h
	$(CC) -Wall -Iinclude -c $(SRC)/main.c -o $(OBJ)/main.o

$(OBJ)/utils.o: $(SRC)/utils.c $(INCLUDE)/utils.h $(INCLUDE)/temperature_record.h
	$(CC) -Wall -Iinclude -c $(SRC)/utils.c -o $(OBJ)/utils.o

$(OBJ)/temp_api.o: $(SRC)/temp_api.c $(INCLUDE)/temp_api.h $(INCLUDE)/temperature_record.h
	$(CC) -Wall -Iinclude -c $(SRC)/temp_api.c -o $(OBJ)/temp_api.o

clean:
	if exist obj rmdir /s /q obj
	if exist bin rmdir /s /q bin