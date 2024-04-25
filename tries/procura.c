#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include "trie.h"
#include "base.h"
#include "folder.h"

int main(int argc, char* argv[]){

    if (argc > 1){
        trie *raiz = cria_no('\0');
        char base[100];    
        char prefixo[100]; 

        strcpy(base, argv[1]);
        strcpy(prefixo ,argv[2]);

        if(arquivo_existe(base))
            raiz = desserializa_trie(raiz, base);

        procura(raiz, prefixo);

        destroi_arvore(raiz);
    }
    return 1;
}
