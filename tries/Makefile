CC=gcc
CFLAGS=-Wall

all: procura insere

procura: procura.c folder.c base.c trie.c
	$(CC) $(CFLAGS) $^ -o $@

insere: insere.c folder.c base.c trie.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f procura insere
