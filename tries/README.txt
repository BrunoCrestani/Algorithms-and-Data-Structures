Trabalho realizado por Nicolas Costa da silva - ncs22 - Grr:20221228
                       Bruno Corrado Crestani - bcc22 - Grr:20221240

	Realizamos este projeto conforme a nosssa interpretação das especificações do trabalho 2 da disciplina de Algoritmos e Estruturas de dados 3. Para isso começamos resolvendo os problemas envolvendo 
arquivos, como especificado era necessário que as palavras encontradas tivessem no minimo 4 letras para serem inseridas, e os acentos deveriam ser ignorados,  portanto fizemos essas funções 
que compuseram nosso folder.c e folder.h, parte dedicada para fins relacionados a arquivos. Importante ressaltar que fizemos tudo usando arquivos .txt, então tanto a base quanto o arquivo lido 
devem ser arquivos.txt.

    As strings utilizadas para leitura foram alocadas de forma estática, possuindo um tamanho fixo de 100.

	A Trie, que tem a struct de seus nodos e as funções que a estruturam presente nos arquivos trie.c e trie.h, funciona da seguinte maneira:

    typedef struct trie {
        struct trie *filho[TAM_ALFABETO];
        char letra;
        char *palavra;
        int fim_palavra;
        char* arquivos[TAM_ARQUIVOS];
        int num_arquivos;
    } trie;

    A trie foi armazenada de forma dinâmica, Porém, o vetor de arquivos não. ele por padrão possui um teto de 100, mas é possível ajustar o #define TAM_ARQUIVOS para uma maior quantidade, se
necessário.

    A struct do nodo tem um vetor de nodos de 26 posições, que representam o alfabeto, e um inteiro que representa se é o fim da palavra ou não.
Se lê a palavra, e se passa letra por letra dela, atribuindo aos nodos na ávore. Cada letra aponta para seu filho, temos um inteiro que fala quando é encontrada a ultima letra (fim da palavra), i
e vemos qual arquivo estamos. 
    A necessidade de saber em qual arquivo estamos se dar por podermos ter a mesma palavra inserida a partir de arquivos diferentes na mesma base, logo devemos armazenar em um vetor presente no nodo 
por meio de quais arquivos a palavra em questão foi inserida. De resto implementamos as funcoes normais de uma trie, para pegar as palavras, inserir na arvore e etc.
com os arquivos resolvidos e conseguindo colocar as palavras deles dentro da trie, passamos para base.

	A base de dados do nosso projeto caminha em torno da serielização da estrutura da trie. Ela se encontra impressa em pré ordem, onde é possível observar a formação
da palavra que foi inserida, pelo acompanhamento dos filhos dos nodos, até chegar no nodo que demarca o fim da palavra.
    A formatação da base consiste em [PALAVRA (ou prefixo se a palavra ainda não finalizou] [FIM_PALAVRA(0 ou 1)] [NUM_ARQUIVOS]. Após encontrar o FIM_PALAVRA com valor 1,
O vetor de arquivos da palavra é impresso na linha debaixo, e para isso se utiliza o NUM_ARQUIVOS impresso na base.

    Na inserção, é feita a verificação da existencia ou não do arquivo base, e no caso da não existencia ele é criado com as informações da inserção realizada.
Dito isso, o processo de inserção é realizado de maneira convencional, e depois impresso na base da maneira descrita no paragrafo acima.

    Já na busca, também é feita a mesma checagem da inserção em relação a existencia da base, porém como na busca é essencial que a base já exista, é impressa uma mensagem de erro na 
saída padrão e o programa acaba. Para realiza a busca o arquivo base é desserializado, retornando para a estrutura da trie e à memoria, Após isso, temos uma função chamada procura_prefixo,
que encontra exatamente o nodo que finaliza o prefixo recebido, e a partir daí se inicia a verificação para saber à quais arquivos as palavras que iniciam com o prefixo recebido pertencem.
para guardar a informação dos arquivos e não os repetir, foi criado um vetor que armazena os já encontrados, e cada arquivo encontrado no vetor de arquivos de um dos nodos de palavras que 
finalizam com o prefixo é comparado com o vetor por completo. Após isso, esse vetor é impresso.

    E finalmente, O main do nosso projeto foi dividido em dois, insere.c (main insere) e procura.c (main procura). 
    O MAKEFILE gera os 2 executaveis, cada um executando uma determinada aplicação.

    A aplicação insere se da por: ./insere [ARQUIVO BASE] [ARQUIVO TEXTO]. 

OBS1: Ambos os arquivos devem ser passados sem o sufixo que determinam seus tipos de arquivos.
OBS2: Na realização do trabalho foi levado em conta que o [ARQUIVO TEXTO] deve ser um arquivo .txt.

    Já a aplicação procura se da por: ./procura [ARQUIVO BASE] [PREFIXO], com o resultado da procura sendo impresso na saída padrão.

