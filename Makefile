CC = gcc
CFLAGS = -Wall -I. -ggdb
SRC = $(wildcard *.c)
OBJFILES = $(SRC:.c=.o)
DEPS = $(wildcard *.h)
EXEC = wordsearch

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(EXEC): $(OBJFILES)
	$(CC) -o $(EXEC) $(OBJFILES) $(CFLAGS)

.PHONY: clean
clean:
	rm -f $(OBJFILES)
	rm -f $(wildcard dict_*.txt)

.PHONY: build-dicts
build-dicts:
	python3 randomize.py 10
