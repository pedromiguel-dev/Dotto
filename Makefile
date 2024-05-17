CC = gcc
SRCDIR=src
BUILDDIR=build
PROGRAM=Dotto

SOURCES := $(wildcard $(SRCDIR)/*.c)
BUILD := $(SOURCES:$(SRCDIR)/%.c=./$(BUILDDIR)/%.o)

all: dir_folder clean start

dir_folder:
ifeq ($(OS),Windows_NT)
	if not exist "$(BUILDDIR)\" mkdir $(BUILDDIR)
else
	mkdir -p $(BUILDDIR)/
endif

clean:
	rm -f $(BUILDDIR)/*.o

start: $(BUILD)
	$(CC) -o $(PROGRAM) $^

$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	$(CC) -c -o $@ $^ -g -std=gnu99

run:
	./$(PROGRAM)