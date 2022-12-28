CC = gcc
CFLAGS = -Wall -I. -fopenmp -lm -pthread
SRC = $(wildcard ./src/*.c)
OBJFILES = $(SRC:.c=.o)
DEPS = $(wildcard ./include/*.h)
EXEC = ./bin/wordsearch
DEBUG = 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(EXEC): $(OBJFILES)
	@echo "\nOptimizing build. Run \"make debug\" for GGDB debugging.\n"
	$(CC) -o $(EXEC) $(OBJFILES) $(CFLAGS) -O3

.PHONY: debug
debug: $(OBJFILES)
	$(CC) -o $(EXEC) $(OBJFILES) $(CFLAGS) -ggdb

build: $(OBJFILES)
	@make $(EXEC)
	@make build-dicts

.PHONY: clean
clean:
	rm -f $(OBJFILES)
	rm -rf $(wildcard *.o)
	rm -f $(wildcard ./wordsrc/dict_*.txt)

.PHONY: build-dicts
build-dicts:
	python3 randomize.py 40

.PHONY: time
time:
	@make -s clean
	@make -s $(EXEC)
	python3 randomize.py 400
	@./$(EXEC) -t aaaaaaa

