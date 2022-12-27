CC = gcc
CFLAGS = -Wall -I. -ggdb -fopenmp -lm -pthread
SRC = $(wildcard *.c)
OBJFILES = $(SRC:.c=.o)
DEPS = $(wildcard ./include/*.h)
EXEC = ./bin/wordsearch

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(EXEC): $(OBJFILES)
	$(CC) -o $(EXEC) $(OBJFILES) $(CFLAGS)

build: $(OBJFILES)
	@make $(EXEC)
	@make build-dicts

.PHONY: clean
clean:
	rm -f $(OBJFILES)
	rm -f $(wildcard ./wordsrc/dict_*.txt)

.PHONY: build-dicts
build-dicts:
	python3 randomize.py 40

.PHONY: time
time:
	@make -s clean
	@make -s $(EXEC)
	python3 randomize.py 400
	@./$(EXEC) aaaaaaa

.PHONY: test
test:
	@make -s clean
	@make -s $(EXEC)
	python3 randomize.py 10
	@python3 test.py
