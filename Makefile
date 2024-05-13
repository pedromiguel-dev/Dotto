CC = gcc
SRCDIR=src
BUILDDIR=build
PROGRAM=Dotto

SOURCES := $(wildcard $(SRCDIR)/*.c)
BUILD := $(SOURCES:$(SRCDIR)/%.c=./$(BUILDDIR)/%.o)

all: dir_folder clean start run

dir_folder:
	mkdir -p ./build/

clean:
	rm -f ./build/*.o

start: $(BUILD)
	$(CC) -o $(PROGRAM) $^

$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	$(CC) -c -o $@ $^

run:
	./$(PROGRAM)