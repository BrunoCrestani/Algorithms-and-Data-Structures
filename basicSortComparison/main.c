#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "ordenacao.h"

void trocarMain(int *i, int *j)
{
    int aux;

    aux = *i;
    *i = *j;
    *j = aux;

    return;
}

void imprimeVetor(int *vetor, int tamVetor)
{
	for(int i=0; i < tamVetor; i++)
	{
		printf("%d ", vetor[i]);
	}
}

int *criaVetorAleat(int *vetor, int tamVetor)
{
	for (int i = 0; i < tamVetor; i++)
	{
		vetor[i] = rand() % tamVetor;
	}
	return vetor;
}

int *criaVetorQuaseOrdenado(int *vetor, int tamVetor)
{
	int m;

	m = ((tamVetor - 1) / 2);

	vetor = criaVetorAleat(vetor, tamVetor);
	quickSort(vetor, tamVetor);

	trocarMain(&vetor[m], &vetor[0]);

	return vetor;
}


int *criaVetorAoContrario(int *vetor, int tamVetor)
{
	vetor = criaVetorAleat(vetor, tamVetor);
	quickSort(vetor, tamVetor);

    int aux[tamVetor];
 
    for (int i = 0; i < tamVetor; i++) {
        aux[tamVetor - 1 - i] = vetor[i];
    }
 
    for (int i = 0; i < tamVetor; i++) 
	{
        vetor[i] = aux[i];
    }
	return vetor;
}

int main(){
	char nome[MAX_CHAR_NOME];
	int idxBusca;
	int numComp, tamVetor;

	clock_t start, end;
    double total;

	getNome(nome);
	printf("\nTrabalho de %s\n", nome);
	printf("GRR %u\n\n", getGRR());

	tamVetor = 50000;
	

	int *vetorAleatorio = malloc(tamVetor * sizeof(int));
	if(vetorAleatorio == NULL)
	{
		printf("Falha fatal. Impossível alocar memoria.");
		return 1;
	}

	int *vetorAoContrario = malloc(tamVetor * sizeof(int));
	if(vetorAoContrario == NULL)
	{
		printf("Falha fatal. Impossível alocar memoria.");
		return 1;
	}

	int *vetorQuaseOrdenado = malloc(tamVetor * sizeof(int));
	if(vetorQuaseOrdenado == NULL)
	{
		printf("Falha fatal. Impossível alocar memoria.");
		return 1;
	}

	int *vetorOrdenado = malloc(tamVetor * sizeof(int));
	if(vetorOrdenado == NULL)
	{
		printf("Falha fatal. Impossível alocar memoria.");
		return 1;
	}

//-------------------------------------------------------------------------Comparacoes para Busca Sequencial-------------------------------------------------------------------------------
	printf ("Busca sequencial em vetor Aleatorio de %d posicoes\n", tamVetor);
	numComp = 0;

	vetorAleatorio = criaVetorAleat(vetorAleatorio, tamVetor);

	start = clock();
	idxBusca = buscaSequencial(vetorAleatorio, tamVetor, 2023, &numComp);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Tempo total: %f\n", total);

	printf("Numero de Comparacoes:%d\n indice de busca:%d\n\n", idxBusca, numComp);
	//imprimeVetor(vetorAleatorio, tamVetor);

//-------------------------------------------------------------------------------Vetor ao Contrario-----------------------------------------------------------------------------------

	printf ("Busca sequencial em vetor Ao Contrario de %d posicoes\n", tamVetor);
	numComp = 0;

	vetorAoContrario = criaVetorAoContrario(vetorAoContrario, tamVetor);

	start = clock();
	idxBusca = buscaSequencial(vetorAoContrario, tamVetor, 2023, &numComp);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Tempo total: %f\n", total);

	printf("Numero de Comparacoes:%d\n indice de busca:%d\n\n", idxBusca, numComp);
	//imprimeVetor(vetorAoContrario, tamVetor);

//-----------------------------------------------------------------------------------Vetor Ordenado-----------------------------------------------------------------------------------

	printf ("Busca sequencial em vetor Ordenado de %d posicoes\n", tamVetor);
	numComp = 0;

	vetorAleatorio = criaVetorAleat(vetorAleatorio, tamVetor);
	quickSort(vetorAleatorio, tamVetor);

	start = clock();
	idxBusca = buscaSequencial(vetorAleatorio, tamVetor, 2023, &numComp);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Tempo total: %f\n", total);

	printf("Numero de Comparacoes:%d\n indice de busca:%d\n\n\n", idxBusca, numComp);
	//imprimeVetor(vetorAleatorio, tamVetor);

//-------------------------------------------------------------------------------Comparacoes para Busca Binaria-----------------------------------------------------------------------
	//tamVetor = 100;
	printf ("Busca Binaria em vetor Ordenado de %d posicoes:\n", tamVetor);
	numComp = 0;

	vetorAleatorio = criaVetorAleat(vetorAleatorio, tamVetor);
	quickSort(vetorAleatorio, tamVetor);

	start = clock();
	idxBusca = buscaBinaria(vetorAleatorio, tamVetor, 2023, &numComp);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Tempo total: %f\n", total);

	printf("Numero de Comparacoes:%d\nindice de busca:%d\n\n\n", numComp, idxBusca);
	//imprimeVetor(vetorAleatorio, tamVetor);

//---------------------------------------------------------------------------Comparacoes para Insertion Sort-----------------------------------------------------------------------
	//tamVetor = 100;
	numComp = 0;
	printf ("Insertion Sort em vetor Aleatorio de %d posicoes:\n", tamVetor);

	vetorAleatorio = criaVetorAleat(vetorAleatorio, tamVetor);

	start = clock();
	numComp = insertionSort(vetorAleatorio, tamVetor);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Tempo total: %f\n", total);

	printf("Numero de Comparacoes: %d\n\n", numComp);
	//imprimeVetor(vetorAleatorio, tamVetor);

//-------------------------------------------------------------------------------Vetor ao Contrario-----------------------------------------------------------------------------------

	printf ("Insertion Sort em vetor Ao Contrario de %d posicoes\n", tamVetor);
	numComp = 0;

	vetorAoContrario = criaVetorAoContrario(vetorAoContrario, tamVetor);

	start = clock();
	numComp = insertionSort(vetorAoContrario, tamVetor);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Tempo total: %f\n", total);

	printf("Numero de Comparacoes: %d\n\n", numComp);
	//imprimeVetor(vetorAoContrario, tamVetor);

//-------------------------------------------------------------------------------Vetor Quase Ordenado-----------------------------------------------------------------------------------
	printf ("Insertion Sort em vetor Quase Ordenado de %d posicoes\n", tamVetor);
	numComp = 0;

	vetorQuaseOrdenado= criaVetorQuaseOrdenado(vetorQuaseOrdenado, tamVetor);

	start = clock();
	numComp = insertionSort(vetorQuaseOrdenado, tamVetor);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Tempo total: %f\n", total);

	printf("Numero de Comparacoes: %d\n\n\n", numComp);
	//imprimeVetor(vetorQuaseOrdenado, tamVetor);

//---------------------------------------------------------------------------Comparacoes para Selection Sort-----------------------------------------------------------------------
	//tamVetor = 100;
	numComp = 0;
	printf ("Selection Sort em vetor Aleatorio de %d posicoes:\n", tamVetor);

	vetorAleatorio = criaVetorAleat(vetorAleatorio, tamVetor);

	start = clock();
	numComp = selectionSort(vetorAleatorio, tamVetor);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Tempo total: %f\n", total);

	printf("Numero de Comparacoes: %d\n\n", numComp);
	//imprimeVetor(vetorAleatorio, tamVetor)

//-------------------------------------------------------------------------------Vetor ao Contrario-----------------------------------------------------------------------------------
	printf ("Selection Sort em vetor Ao Contrario de %d posicoes\n", tamVetor);
	numComp = 0;

	vetorAoContrario = criaVetorAoContrario(vetorAoContrario, tamVetor);

	start = clock();
	numComp = selectionSort(vetorAoContrario, tamVetor);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Tempo total: %f\n", total);

	printf("Numero de Comparacoes: %d\n\n", numComp);
	//imprimeVetor(vetorAoContrario, tamVetor);
	//---------------------------------------------------------------------------Vetor Quase Ordenado-----------------------------------------------------------------------------------
	printf ("Selection Sort em vetor Quase Ordenado de %d posicoes\n", tamVetor);
	numComp = 0;

	vetorQuaseOrdenado= criaVetorQuaseOrdenado(vetorQuaseOrdenado, tamVetor);

	start = clock();
	numComp = selectionSort(vetorQuaseOrdenado, tamVetor);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Tempo total: %f\n", total);

	printf("Numero de Comparacoes: %d\n\n\n", numComp);
	//imprimeVetor(vetorQuaseOrdenado, tamVetor);

//-----------------------------------------------------------------------------Comparacoes para Merge Sort--------------------------------------------------------------------------
	//tamVetor = 100;
	numComp = 0;
	printf ("Merge Sort em vetor Aleatorio de %d posicoes:\n", tamVetor);

	vetorAleatorio = criaVetorAleat(vetorAleatorio, tamVetor);
	
	start = clock();
	numComp = mergeSort(vetorAleatorio, tamVetor);
	end = clock();

	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Tempo total: %f\n", total);

	printf("Numero de Comparacoes: %d\n\n", numComp);
	//imprimeVetor(vetorAleatorio, tamVetor);

//-------------------------------------------------------------------------------Vetor ao Contrario-----------------------------------------------------------------------------------
	printf ("Merge Sort em vetor Ao Contrario de %d posicoes\n", tamVetor);
	numComp = 0;

	vetorAoContrario = criaVetorAoContrario(vetorAoContrario, tamVetor);

	start = clock();
	numComp = mergeSort(vetorAoContrario, tamVetor);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Tempo total: %f\n", total);

	printf("Numero de Comparacoes: %d\n\n", numComp);
	//imprimeVetor(vetorAoContrario, tamVetor);
	//----------------------------------------------------------------------------Vetor Quase Ordenado-----------------------------------------------------------------------------------
	printf ("Merge Sort em vetor Quase Ordenado de %d posicoes\n", tamVetor);
	numComp = 0;

	vetorQuaseOrdenado= criaVetorQuaseOrdenado(vetorQuaseOrdenado, tamVetor);

	start = clock();
	numComp = mergeSort(vetorQuaseOrdenado, tamVetor);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Tempo total: %f\n", total);

	printf("Numero de Comparacoes: %d\n\n\n", numComp);
	//imprimeVetor(vetorQuaseOrdenado, tamVetor);

//---------------------------------------------------------------------------------Comparacoes para Quick Sort-------------------------------------------------------------------------
	//tamVetor = 100;
	numComp = 0;
	printf ("Quick Sort em vetor Aleatorio de %d posicoes:\n", tamVetor);

	vetorAleatorio = criaVetorAleat(vetorAleatorio, tamVetor);
	
	start = clock();
	numComp = quickSort(vetorAleatorio, tamVetor);
	end = clock();

	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Tempo total: %f\n", total);

	printf("Numero de Comparacoes: %d\n\n", numComp);

	//imprimeVetor(vetorAleatorio, tamVetor);

//-------------------------------------------------------------------------------Vetor ao Contrario-----------------------------------------------------------------------------------
	printf ("Quick Sort em vetor Ao Contrario de %d posicoes\n", tamVetor);
	numComp = 0;

	vetorAoContrario = criaVetorAoContrario(vetorAoContrario, tamVetor);

	start = clock();
	numComp = quickSort(vetorAoContrario, tamVetor);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Tempo total: %f\n", total);

	printf("Numero de Comparacoes: %d\n\n", numComp);
	//imprimeVetor(vetorAoContrario, tamVetor);
	//-------------------------------------------------------------------------------Vetor Quase Ordenado-----------------------------------------------------------------------------------
	printf ("Quick Sort em vetor Quase Ordenado de %d posicoes\n", tamVetor);
	numComp = 0;

	vetorQuaseOrdenado= criaVetorQuaseOrdenado(vetorQuaseOrdenado, tamVetor);

	start = clock();
	numComp = quickSort(vetorQuaseOrdenado, tamVetor);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Tempo total: %f\n", total);

	printf("Numero de Comparacoes: %d\n\n\n", numComp);
	//imprimeVetor(vetorQuaseOrdenado, tamVetor);

//----------------------------------------------------------------------------------Comparacoes para Heap Sort--------------------------------------------------------------------------
	//tamVetor = 65000;
	numComp = 0;
	printf ("Heap Sort em vetor Aleatorio de %d posicoes:\n", tamVetor);

	vetorAleatorio = criaVetorAleat(vetorAleatorio, tamVetor);

	start = clock();
	numComp = heapSort(vetorAleatorio, tamVetor);
	end = clock();

	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Tempo total: %f\n", total);

	printf("Numero de Comparacoes: %d\n\n", numComp);

	//imprimeVetor(vetorAleatorio, tamVetor);
	//-------------------------------------------------------------------------------Vetor ao Contrario-----------------------------------------------------------------------------------
	printf ("Heap Sort em vetor Ao Contrario de %d posicoes\n", tamVetor);
	numComp = 0;

	vetorAoContrario = criaVetorAoContrario(vetorAoContrario, tamVetor);

	start = clock();
	numComp = heapSort(vetorAoContrario, tamVetor);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Tempo total: %f\n", total);

	printf("Numero de Comparacoes: %d\n\n", numComp);
	//imprimeVetor(vetorAoContrario, tamVetor);
	//-------------------------------------------------------------------------------Vetor Quase Ordenado-----------------------------------------------------------------------------------
	printf ("Heap Sort em vetor Quase Ordenado de %d posicoes\n", tamVetor);
	numComp = 0;

	vetorQuaseOrdenado= criaVetorQuaseOrdenado(vetorQuaseOrdenado, tamVetor);

	start = clock();
	numComp = heapSort(vetorQuaseOrdenado, tamVetor);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Tempo total: %f\n", total);

	printf("Numero de Comparacoes: %d\n\n", numComp);
	//imprimeVetor(vetorQuaseOrdenado, tamVetor);

	free(vetorAleatorio);
	free(vetorAoContrario);
	free(vetorQuaseOrdenado);
	
	return 0;
}
