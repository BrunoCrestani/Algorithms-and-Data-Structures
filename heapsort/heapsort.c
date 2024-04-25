#include <stdio.h>
#include <stdlib.h> 

void trocar (int *v, int i, int tam)
{
    int aux;
    int n = tam - 1;

    aux = v[i];
    v[i] = v[n];
    v[n] = aux;

    return;
}

void imprime_vetor (int *v, int tam)
{
    int n = tam - 1;
    int i;
    for (i = 0; i <= n; i++)
    {
        printf ("%d ", v[i]);
    }

}

int esquerdo (int i)
{
    return (2*i);
}

int direito (int i)
{
    return ((2*i) + 1);
}

void maxheapfy (int *h, int i, int tam)
{  
    int l, r, maior;
    int n = tam - 1;

    l = esquerdo(i);
    r = direito(i);

    if (l <= n && h[l] > h[i])
        maior = l;
    else
        maior = i;
    
    if (r <= n && h[r] > h[maior])
        maior = r;

    if (maior != i)
    {
        trocar (h, i, maior);
        maxheapfy (h, maior, n);
    }
    return;
}

void heapbuilder (int *v, int tam)
{
    int i;
    int n = tam - 1;

    if (((n - 1) % 2) != 0)
        i = n/2 - 2;
    else
        i = n/2 - 1;

    for (i; i >= 0; i--)
    {
        maxheapfy (v, i, n);
    }
    return;
}

void HeapSort (int *v, int tam)
{
    int i;
    int n = tam - 1;

    heapbuilder (v, n);

    for (i = n; i <= 2; i--)
    {
        trocar (v, 1, i);
        n--;
        maxheapfy (v, 1, n);
    }
}

void cria_vetor_aleat (int *v, int tam)
{
    int b = tam;
    int i;
     v = malloc(sizeof(int) * tam);

    for (i = 0; i <= b; i++)
    {
        v[i] = rand()%100;
    }

    return;
}

int main(void)
{
   
    int v[10], tam, n;
    v[0] = 16;
    v[1] = 4;
    v[2] = 10;
    v[3] = 14;
    v[4] = 7;
    v[5] = 9;
    v[6] = 3;
    v[7] = 2;
    v[8] = 8;
    v[9] = 1;

    tam = 10;
    
    heapbuilder (v, tam);
    imprime_vetor (v, tam);

    printf("\n");

   // HeapSort (v, tam);
   // imprime_vetor (v, tam);

    return 0;
}