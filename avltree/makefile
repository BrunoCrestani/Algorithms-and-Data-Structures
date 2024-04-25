# Makefile de exemplo (Manual do GNU Make
CC = gcc
CFLAGS = -Wall # flags de compilacao

# arquivos-objeto
	objects = busca.o avl-tree.o 
     
busca: busca.o avl-tree.o 
	$(CC) -o busca busca.o avl-tree.o $(LDFLAGS)

avl-tree.o: avl-tree.c
	$(CC) -c $(CFLAGS) avl-tree.c

busca.o: busca.c
	$(CC) -c $(CFLAGS) busca.c

clean:
	rm -f $(objects) busca

