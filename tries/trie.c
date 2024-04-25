#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "trie.h"
#define TAM_ALFABETO 26


trie *cria_no(char letra) {

    trie* novo_no = (trie *)malloc(sizeof(trie));

    if(novo_no) {
        novo_no->fim_palavra = 0;
        novo_no->letra = letra;
        novo_no->palavra = NULL;
        novo_no->num_arquivos = 0;

        for(int i = 0; i < TAM_ALFABETO; i++) {
            novo_no->filho[i] = NULL;
        }

        for (int i = 0; i < TAM_ARQUIVOS; i++) {
            novo_no->arquivos[i] = NULL;
        }
    }

    return novo_no;
}

void insere(trie *raiz, char *palavra, const char* nome_arquivo) {
    trie *atual = raiz;

    for(int i = 0; palavra[i] != '\0'; i++) { 

        char letra = tolower(palavra[i]);

        int indice = letra - 'a'; 
        if(!atual->filho[indice]){
          atual->filho[indice] = cria_no(letra);
        }
        atual = atual->filho[indice];
    }


    if (palavra && atual){
        atual->palavra = strdup(palavra);
        atual->fim_palavra = 1;
    
        for (int i = 0; i < atual->num_arquivos; i++) {
            if (strcmp(atual->arquivos[i], nome_arquivo) == 0) 
                return;          
        }
        if (atual->num_arquivos < TAM_ARQUIVOS) {
            atual->arquivos[atual->num_arquivos] = strdup(nome_arquivo);
            atual->num_arquivos++;
        }
    }

}

void imprime_arquivos_trie(trie* raiz, char*  prefixo, int indice, char** arquivos_printados, int *num_arquivos_printados){
        int arquivo_repetido = 0;

        if (raiz == NULL)
        return;

    if(raiz->fim_palavra){
        for(int i = 0; i < raiz->num_arquivos; i++){
            for(int j = 0; j < *num_arquivos_printados; j++){
                if(strcmp(raiz->arquivos[i], arquivos_printados[j]) == 0){
                    arquivo_repetido = 1;
                }
            }
            if (arquivo_repetido == 0){
            arquivos_printados[*num_arquivos_printados] = raiz->arquivos[i];
            (*num_arquivos_printados)++;
            arquivo_repetido = 0;
            }
        }
    }

    for(int i = 0; i < TAM_ALFABETO; i++){
        if (raiz->filho[i] !=  NULL){
            imprime_arquivos_trie(raiz->filho[i], prefixo, indice + 1, arquivos_printados, num_arquivos_printados);
        }
    }
}

void destroi_arvore(trie *raiz) {
    
    if (raiz) {
        free(raiz->palavra);

        for (int i = 0; i < raiz->num_arquivos; i++) {
            free(raiz->arquivos[i]);
        }

        for (int i = 0; i < TAM_ALFABETO; i++) {
            destroi_arvore(raiz->filho[i]);
        }

        free(raiz);
    }
}

