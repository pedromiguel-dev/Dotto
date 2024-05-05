
CC = gcc

all: start

start: ./src/main.o ./src/functions.o
	$(CC) -o main main.o functions.o

%.o: %.c
	$(CC) -c $^

dir_folder:
	mkdir -p ./build/

clean:
	rm -f $(EXEC)