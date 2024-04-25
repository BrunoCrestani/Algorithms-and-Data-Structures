void serializa_trie(trie* raiz, FILE* base, char* base_nome);
trie* le_base(trie *raiz, const char* arquivo_base, int indice);
trie* desserializa_trie(trie* raiz, const char* arquivo_base);
void escreve_base(trie *raiz, FILE* arquivo);
void insere_base(const char *arquivo_base, trie *raiz);
trie* procura_prefixo(trie* raiz, char* prefixo, int indice);
void procura(trie* raiz, char* prefixo);

