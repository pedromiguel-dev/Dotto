CC = gcc
SRCDIR=src
BUILDDIR=build
PROGRAM=Dotto

SOURCES := $(wildcard $(SRCDIR)/*.c)
BUILD := $(SOURCES:$(SRCDIR)/%.c=./$(BUILDDIR)/%.o)

all: dir_folder clean start

dir_folder:
	mkdir -p $(BUILDDIR)/

clean:
	rm -f $(BUILDDIR)/*.o

start: $(BUILD)
	$(CC) -o $(PROGRAM) $^

$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	$(CC) -c -o $@ $^ -g

run:
	./$(PROGRAM)