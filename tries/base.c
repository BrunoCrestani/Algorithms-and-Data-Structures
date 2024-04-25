#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "trie.h"
#include "folder.h"
#include "base.h"

void serializa_trie(trie* raiz, FILE* base, char* base_nome) {
    if (raiz == NULL) {
        return;
    }

    fprintf(base, "%s %d %d\n", base_nome, raiz->fim_palavra, raiz->num_arquivos);

    if(raiz->fim_palavra){
        for(int i = 0; i < raiz->num_arquivos; i++){
            fprintf(base, "%s ", raiz->arquivos[i]);
            //printf("%s ", raiz->arquivos[i]);
        }
        fprintf(base, "\n");
    }


    for (int i = 0; i < TAM_ALFABETO; i++) {
        char filho[100]; // ajuste conforme necessário
        snprintf(filho, sizeof(filho), "%s%c", base_nome, 'a' + i);
        serializa_trie(raiz->filho[i], base, filho);
    }
}

trie* desserializa_trie(trie* raiz, const char* arquivo_base) {

    if (raiz == NULL)
        return raiz;
    
    char nome_arquivo[100];
    strcpy(nome_arquivo, arquivo_base);

    FILE *arq = fopen(nome_arquivo, "r" );

    if(!arq){
        exit(1);
    }

    char palavra[100]; // ajuste conforme necessário
    int fim_palavra; 
    int num_arquivos;
    char arquivo[100];

    while (fscanf(arq, "%99s %d %d", palavra, &fim_palavra, &num_arquivos) != EOF) {
        trie* atual = raiz;

        for (size_t i = 0; i < strlen(palavra); i++) {
            int indice = palavra[i] - 'a';

            if (!atual->filho[indice]){
                atual->filho[indice] = cria_no(palavra[i]);
            }
            
            atual = atual->filho[indice];
        }

        atual->palavra = strdup(palavra);
        atual->fim_palavra = fim_palavra;
        atual->num_arquivos = num_arquivos;
   
        if (fim_palavra){
            for(int i = 0; i < num_arquivos; i++){
                fscanf(arq, "%99s", arquivo);
                atual->arquivos[i] = strdup(arquivo);
            }
        }
    }

    fclose(arq);
    return raiz;
}

void insere_base(const char *arquivo_base, trie *raiz){

    if(raiz == NULL)
        return;
    
    char nome_arquivo[100];
    strcpy(nome_arquivo, arquivo_base);

    FILE *arq_base = fopen(nome_arquivo, "w");

    if (!arq_base) {
        exit(1);
    }

    serializa_trie(raiz, arq_base, "");

    fclose(arq_base);
}

trie* procura_prefixo(trie* raiz, char* prefixo, int indice){

    if (raiz == NULL || prefixo[indice] == '\0')
        return raiz;

    char letra = prefixo[indice];
    
    for(int i = 0; i < TAM_ALFABETO; i++){
        if (raiz->filho[i] && letra == raiz->filho[i]->letra){
            return procura_prefixo(raiz->filho[i], prefixo, indice + 1);
        }
    }
    return NULL;
}
 
void procura(trie* raiz, char* prefixo){
    
    if (raiz == NULL)
        return;
    
    char* arquivos_printados[TAM_ARQUIVOS];
    for(int i = 0; i < TAM_ARQUIVOS; i++){
        arquivos_printados[i] = NULL;
    }
    int num_arquivos_printados = 0;


    trie* subtrie;
    subtrie = procura_prefixo(raiz, prefixo, 0);
    imprime_arquivos_trie(subtrie, prefixo, 0, arquivos_printados, &num_arquivos_printados);

    for(int i = 0; i < num_arquivos_printados; i++){
        printf("%s %s\n", prefixo, arquivos_printados[i]);
    }

}
