#include "ordenacao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getNome(char nome[])
{
	strncpy(nome, "Bruno Corrado Crestani", MAX_CHAR_NOME);
	nome[MAX_CHAR_NOME-1] = '\0';
}

unsigned int getGRR()
{
	return 20221240;
}
//-------------------------------------------------------------Funcoes de uso geral--------------------------------------------------------------
void trocar(int *i, int *j)
{
    int aux;

    aux = *i;
    *i = *j;
    *j = aux;

    return;
}

int *insereVetor(int vetor[], int tam, int *numComparacoes)
{
	int x = vetor[tam];
	int j = tam - 1;
	while (j >= 0 && vetor[j] > x)
	{
		vetor[j + 1] = vetor[j];
		j = j - 1;
		(*numComparacoes)++;
	}
	vetor[j + 1] = x;
	return numComparacoes;
}
// ---------------------------------------------------------------Inicio das Funcoes da Busca sequencial-----------------------------------------------
int minhaBuscaSequencial(int vetor[], int a, int b, int valor, int *numComparacoes)
{
    if (a > b) 
        return -1;

    (*numComparacoes)++;
    if (valor == vetor[b])
    {
        return b;
    }
    return minhaBuscaSequencial(vetor, a, b - 1, valor, numComparacoes);
}

int buscaSequencial(int vetor[], int tam, int valor, int* numComparacoes)
{
	return minhaBuscaSequencial(vetor, 0, tam-1, valor, numComparacoes);
}
// ----------------------------------------------------------------Inicio das Funcoes da Busca Binaria--------------------------------------------------------------
int minhaBuscaBinaria(int vetor[], int a, int b, int valor, int *numComparacoes)
{
    if (b >= a) {
        int meio = a + (b - a) / 2;

		(*numComparacoes)++;
        if (vetor[meio] == valor)
            return meio;

		(*numComparacoes)++;
		if (vetor[meio] > valor)
            return minhaBuscaBinaria(vetor, a, meio - 1, valor, numComparacoes);
 
        return minhaBuscaBinaria(vetor, meio + 1, b, valor, numComparacoes);
    }
 
    return -1;
}

int buscaBinaria(int vetor[], int tam, int valor, int* numComparacoes)
{
	return minhaBuscaBinaria(vetor, 0, tam-1, valor, numComparacoes);
}
// --------------------------------------------------------------Inicio das Funcoes do Insertion Sort-----------------------------------------------------------
void meuInsertionSort(int vetor[], int tam, int *numComparacoes)
{
	if (0 < tam)
	{
		meuInsertionSort(vetor, tam - 1, numComparacoes);
		insereVetor(vetor, tam - 1, numComparacoes);
	}
	return;
}

int insertionSort(int vetor[], int tam)
{
	int numComparacoes = 0;
    meuInsertionSort(vetor, tam, &numComparacoes);
	return numComparacoes;
}
// --------------------------------------------------------------Inicio das Funcoes do Selection Sort-----------------------------------------------------------
void meuSelectionSort(int vetor[], int n, int indice, int *numComparacoes)
{
	if (indice == n)
		return;

	int menor = indice;
	for (int i = indice + 1; i < n; i++)
	{
		(*numComparacoes)++;
		if (vetor[i] < vetor[menor])
			menor = i;
	}
	trocar(&vetor[menor], &vetor[indice]);
	meuSelectionSort(vetor, n, indice + 1, numComparacoes);
    
    return;
}

int selectionSort(int vetor[], int tam)
{
	int numComparacoes = 0;
	meuSelectionSort(vetor, tam, 0, &numComparacoes);
	return numComparacoes;
}
// ---------------------------------------------------------------Inicio das Funcoes do Merge Sort--------------------------------------------------------------
void merge(int vetor[], int a, int meio, int b, int *numComparacoes)
{
	int i, j, k;

	int x = meio - a + 1;
	int y = b - meio;

	int vetorA[x], vetorB[y];

	for (i = 0; i < x; i++)
		vetorA[i] = vetor[a + i];

	for (j = 0; j < y; j++)
	 vetorB[j] = vetor[meio + 1 + j];

	i = 0;
	j = 0;
	k = a;

	while (i < x && j < y)
	{
		if (vetorA[i] <= vetorB[j])
		{
			(*numComparacoes)++;
			vetor[k] = vetorA[i];
			i++;
		}
		else
		{
			(*numComparacoes)++;
			vetor[k] = vetorB[j];
			j++;
		}
		k++;
	}

	while (i < x)
	{
		vetor[k] = vetorA[i];
		i++;
		k++;
	}
	while (j < y)
	{
		vetor[k] = vetorB[j];
		j++;
		k++;
	}
	return;
}

    void meuMergeSort(int vetor[], int a, int b, int *numComparacoes)
{
	int meio = a + (b - a) / 2;
	if (a < b)
	{
		meuMergeSort(vetor, a, meio, numComparacoes);
		meuMergeSort(vetor, meio + 1, b, numComparacoes);
		merge(vetor, a, meio, b, numComparacoes);
	}

	return;
}

int mergeSort(int vetor[], int tam)
{
	int numComparacoes = 0;
	meuMergeSort(vetor, 0, tam - 1, &numComparacoes);
	return numComparacoes;
}
// ---------------------------------------------------------------Inicio das Funcoes do Quick Sort--------------------------------------------------------------
int parcionamento(int vetor[], int a, int b, int *numComparacoes)
{
	int x = vetor[b]; //pivo
	int m = (a - 1);

	for (int i = a; i <= b - 1; i++)
	{
        (*numComparacoes)++;
		if (vetor[i] <= x)
		{
            m++;
			trocar(&vetor[m], &vetor[i]);
		}
	}
	trocar(&vetor[m + 1], &vetor[b]);

	return (m + 1);
}

void meuQuickSort(int vetor[], int a, int b, int *numComparacoes)
{
	if (a < b)
	{
		int m = parcionamento(vetor, a, b, numComparacoes);

		meuQuickSort(vetor, a, m - 1, numComparacoes);
		meuQuickSort(vetor, m + 1, b, numComparacoes);
	}
}

int quickSort(int vetor[], int tam)
{
	int numComparacoes = 0;
	meuQuickSort(vetor, 0, tam, &numComparacoes);
	return numComparacoes;
}
// -----------------------------------------------------------------Inicio das Funcoes do HeapSort----------------------------------------------------------------
int esquerdo(int i)
{
    return (2*i + 1);
}

int direito(int i)
{
    return ((2*i) + 2);
}

void maxHeapfy(int *h, int i, int tam, int *numComparacoes)
{  
    int l, r, maior;
    int n = tam - 1;
    maior = i;

    l = esquerdo(i);
    r = direito(i);

    (*numComparacoes)++;
    if (l <= n && h[l] > h[maior])
        maior = l;
	    
    (*numComparacoes)++;
    if (r <= n && h[r] > h[maior])
        maior = r;
		
    
    if (maior != i)
    {
        trocar(&h[i], &h[maior]);
        maxHeapfy(h, maior, tam, numComparacoes);
    }
    return;
}

void heapBuilder(int *h, int tam, int *numComparacoes)
{

    for (int i = tam/2 - 1; i >= 0; i--)
    {
        maxHeapfy(h, i, tam, numComparacoes);
    }
}

void meuHeapSort(int *h, int tam, int *numComparacoes)
{
    int n = tam - 1;

    heapBuilder (h, tam, numComparacoes);
    for (int i = n; i >= 0; i--)
    {
        trocar(&h[0], &h[i]);
        maxHeapfy(h, 0, i, numComparacoes);
    }
}

int heapSort(int vetor[], int tam)
{
	int numComparacoes = 0;
	meuHeapSort(vetor, tam, &numComparacoes);
	return numComparacoes;
}
