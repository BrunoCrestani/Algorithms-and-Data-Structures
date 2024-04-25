# Makefile de exemplo (Manual do GNU Make
CC = gcc
CFLAGS = -Wall # flags de compilacao

# arquivos-objeto
	objects = main.o lib.o 
     
main: main.o lib.o 
	$(CC) -o main main.o lib.o $(LDFLAGS)

lib.o: lib.c
	$(CC) -c $(CFLAGS) lib.c

main.o: main.c
	$(CC) -c $(CFLAGS) main.c

clean:
	rm -f $(objects) main


