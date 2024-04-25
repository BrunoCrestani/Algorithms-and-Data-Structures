int arquivo_existe(char* nome_arquivo);
char *remove_pontuacao(const char *palavra); 
int eh_letra_acentuada(char c);
int valida_caractere(const char *palavra);     
trie* le_arquivo(const char *arquivo, trie *raiz); //recebe como parametro o nome do arquivo, le todos os caracteres do arquivo

