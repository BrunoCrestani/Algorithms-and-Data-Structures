//aqui estao as funcoes responsaveis por manipular os arquivos e verificar se o texto eh valido para trie ou nao
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include "trie.h"
#include "folder.h"

int arquivo_existe(char* nome_arquivo){
    char* arquivo = nome_arquivo;
    strcat(arquivo, ".txt");
    return access(arquivo, F_OK) != -1;
}

char *remove_pontuacao(const char *palavra) {

    int tam = strlen(palavra);
    char *palavra_sem_pontuacao = (char *)malloc(tam + 1); 

    if (palavra_sem_pontuacao == NULL) {
        fprintf(stderr, "Erro ao alocar memória.\n");
        exit(1);
    }

    int j = 0; 

    for (int i = 0; i < tam; i++) {
        if (!ispunct(palavra[i])) {
            palavra_sem_pontuacao[j] = palavra[i];
            j++;
        }
    }

    palavra_sem_pontuacao[j] = '\0'; 

    return palavra_sem_pontuacao;
    
}


int valida_caractere(const char *palavra) {

    int num_caracteres;
    num_caracteres = strlen(palavra);

    if (num_caracteres < 4)
        return 0;
   
    for(int i = 0; i < num_caracteres; i++){
        if (palavra[i] < 65 || palavra[i] > 122)
            return 0;
    }

        return 1;
}

trie* le_arquivo(const char *arquivo, trie *raiz){

    if(raiz == NULL)
        return raiz;

    char nome_arquivo[100];
    snprintf(nome_arquivo, sizeof(nome_arquivo), "%s.txt", arquivo);

    FILE *arq = fopen(nome_arquivo, "r" );

    if(!arq){
        exit(1);
    }

    char palavra[1000];

    while(fscanf(arq, "%999s", palavra) != EOF){

        char *copia_palavra = remove_pontuacao(palavra);

        if(valida_caractere(copia_palavra)) 
            insere(raiz, copia_palavra, nome_arquivo);

        free(copia_palavra);
    }

    fclose(arq);
    return raiz;
}

