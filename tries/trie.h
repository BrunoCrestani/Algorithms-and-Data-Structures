#ifndef TRIE_H
#define TRIE_H
#define TAM_ALFABETO 26
#define TAM_ARQUIVOS 100

typedef struct trie {
    struct trie *filho[TAM_ALFABETO];
    char letra;
    char *palavra;
    int fim_palavra;
    char* arquivos[TAM_ARQUIVOS];
    int num_arquivos;
} trie;

trie *cria_no(char letra);
void insere(trie *raiz, char *palavra, const char *nome_arquivo);
void imprime_arquivos_trie(trie* raiz, char* prefixo, int indice, char** arquivos_printados, int* num_arquivos_printados);
void destroi_arvore(trie *raiz);

#endif
