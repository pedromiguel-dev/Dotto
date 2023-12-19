
CC = gcc
BUILD = ./build/
SRC = ./src/main.c

EXEC = $(BUILD)main

all: dir_folder clean $(EXEC)

$(EXEC): $(SRC)
	$(CC) -o $@ $^

dir_folder:
	mkdir -p ./build/

clean:
	rm -f $(EXEC)

run:
	$(EXEC)