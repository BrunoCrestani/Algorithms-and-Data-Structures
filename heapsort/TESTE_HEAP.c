#include <stdio.h>
#include <stdlib.h>

void imprime_vetor (int *v, int tam)
{
    int i;
    for (i = 0; i < tam; i++)
    {
        printf ("%d ", v[i]);
    }
    printf("\n");
}

int esquerdo (int i)
{
    return (2*i);
}

int direito (int i)
{
    return ((2*i) + 1);
}

void trocar (int *v, int i, int n)
{
    int aux;

    aux = v[i];
    v[i] = v[n];
    v[n] = v[i];

    return;
}

void maxheapfy (int *v, int i, int tam)
{  
    int l, r, maior, n;

    maior = i;
    n = tam-1;

    l = esquerdo(i);
    r = direito(i);

    printf ("%d\n%d\n", l, r);
    imprime_vetor(v, tam);

    if (l <= n && v[l] > v[maior])
        maior = l;
    
    if (r <= n && v[r] > v[maior])
        maior = r;
    
    printf("%d\n", maior);
    
    if (maior != i)
    {
        trocar (v, i, maior);
        maxheapfy (v, maior, n);
    }
    return;
}
void cria_vetor_aleat (int *v, int tam)
{
    int b = tam;
    int i;
    // v = malloc(sizeof(int) * tam);

    for (i = 0; i < b; i++)
    {
        v[i] = rand()%100;
    }

    return;
}

void main ()
{

    int v[10], tam, aux;
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
    imprime_vetor(v, tam);
    
    maxheapfy(v, 4, tam);
    imprime_vetor(v, tam);
    
    return;
}
