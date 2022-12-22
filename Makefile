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