#include <stdio.h>
#include <stdlib.h>

void criaVetor (int v[], int tam) 
{

    int i;

    for (i=0; i < tam; i++)
        v[i] = aleat(1, 200);
}

int mergeSort () 
{

}

int main () 
{
    
    int a, m, b, tam;
    tam = b - a + 1;
    int v[tam];

    scanf ("%d %d %d", a, m, b);

    criaVetor(v, a, m);
    criaVetor(v, m+1, b);

    mergeSort()



    

    

} 