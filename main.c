#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long int contador; ///Contador para o numero de operacoes realizadas
void troca (int A, int B)
{
    int t = A;
    A = B;
    B = t;
    contador++;
}

///Funcao que gera um vetor de 'n' posicoes aleatoriamente.
int *Aleatorio(int n)
{
    int *v = malloc(n*sizeof(int));
    int c;
    for(c=0; c<n; c++)
    {
        v[c] = rand()%1000;
    }
    for(c=0; c<n; c++)
        printf("%d\n",v[c]);
    return v;
}
void insercao(int n, int v[])
{
    int i,j,x;
    for(j=1; j<n; j++)
    {
        x=v[j];
        for(i=j-1; i>=0 && v[i]>x; i--)
        {
            v[i+1]=v[i];
            contador++;
        }
        v[i+1] = x;
    }
    for(i=0; i<n; i++)
        printf("%d\n",v[i]);
}
void selecao(int n, int v[])
{
    int i,j,min,x;
    for(i=0; i<n-1; ++i)
    {
        min = i;
        for(j=i+1; j<n; ++j)
        {
            if(v[j]<v[min])
                min=j;
            contador++;
        }
        x=v[i];
        v[i]=v[min];
        v[min]=x;

    }
    for(i=0; i<n; i++)
        printf("%d\n",v[i]);
}
void intercala(int p,int q, int r, int v[])
{
    int i,j,k,*w;
    w = malloc((r-p)*sizeof(int));
    i = p;
    j=q;
    k=0;

    while(i<q && j<r)
    {
        if(v[i]<=v[j])
        {
            w[k++]=v[i++];
        }
        else
        {
            w[k++]=v[j++];
        }
        contador++;
    }
    while(i<q)
    {
        w[k++]=v[i++];
        contador++;
    }
    while(j<r)
    {
        w[k++]=v[j++];
        contador++;
    }
    for(i=p; i<r; ++i)
    {
        v[i] = w[i-p];
        contador++;
    }
    free (w);
}
void merge(int p, int r, int v[])
{
    int i;
    if(p<r-1)
    {
        int q = (p+r)/2;
        merge(p,q,v);
        merge(q,r,v);
        intercala(p,q,r,v);
        contador++;
    }
    //for(i=0; i<r; i++)
    //     printf("%d\n",v[i]);
}
void constroiHeap (int m, int v[])
{
    int k;
    for (k = 1; k < m; ++k)
    {
        // v[1..k] Ž um heap
        int f = k+1;
        while (f > 1 && v[f/2] < v[f])
        {
            troca (v[f/2], v[f]);
            f = f/2;
            contador++;
        }
        contador++;
    }
}
/*void peneira (int m, int v[])
{
    int f = 2;
    while (f <= m)
    {
        if (f < m && v[f] < v[f+1]){
                ++f;
                contador++;
        }
        // f Ž o filho mais valioso de f/2
        if (v[f/2] >= v[f])
            break;
        troca (v[f/2], v[f]);
        f *= 2;
        contador++;
    }
}*/
void peneira (int m, int v[])
{
   int p = 1, f = 2, t = v[1];
   while (f <= m) {
      if (f < m && v[f] < v[f+1]){
       ++f;
       contador++;
      }
      if (t >= v[f]) break;
      v[p] = v[f];
      p = f, f = 2*p;
      contador++;
   }
   v[p] = t;
}
void heap (int n, int v[])
{
    int m;
    constroiHeap (n, v);
    for (m = n; m >= 2; --m)
    {
        troca (v[1], v[m]);
        peneira (m-1, v);
        contador++;
    }
    //printf("\n\n");
    for(m=0; m<n; m++)
       printf("%d\n",v[m]);
}
int separa (int v[], int p, int r)
{
    int c = v[p], i = p+1, j = r, t;
    while (1)
    {
        while (i <= r && v[i] <= c)
        {
            ++i;
            contador++;
        }
        while (c < v[j])
        {
            --j;
            contador++;
        }
        if (i >= j)
            break;
        t = v[i], v[i] = v[j], v[j] = t;
        ++i;
        --j;
        contador++;
    }
    v[p] = v[j], v[j] = c;
    return j;
}
void quicksort (int v[], int p, int r)
{
   int j;
   if (p < r) {
      j = separa (v, p, r);
      quicksort (v, p, j-1);
      quicksort (v, j+1, r);
      contador++;
   }
}
void menu()
{
    int opc,sub;
    long int n;
    long int *v; //VETOR
    while(1)
    {
        printf("1 - Gerar vetor aleatorio\n");
        printf("2 - Algoritmos de ordenacao\n");
        scanf("%d",&opc);
        while(1)
        {
            if(opc == 1)
            {
                opc = 0;
                printf("Qual o tamanho do vetor que vai ser gerado?\n");
                printf("1) 100 posicoes\n");
                printf("2) 500 posicoes\n");
                printf("3) 1000 posicoes\n");
                printf("4) 10000 posicoes\n");
                printf("5) 25000 posicoes\n");
                printf("6) 50000 posicoes\n");
                printf("7) 100000 posicoes\n");
                scanf("%d",&opc);
                if(opc == 1)
                {
                    v = Aleatorio(100);
                    n = 100;
                    break;
                }
                else if(opc ==2)
                {
                    v = Aleatorio(500);
                    n = 500;
                    break;
                }
                else if(opc == 3)
                {
                    v = Aleatorio(1000);
                    n = 1000;
                    break;
                }
                else if(opc== 4)
                {
                    v = Aleatorio(10000);
                    n = 10000;
                    break;
                }
                else if(opc == 5)
                {
                    v = Aleatorio(25000);
                    n = 25000;
                    break;
                }
                else if(opc == 6)
                {
                    v = Aleatorio(50000);
                    n = 50000;
                    break;
                }
                else if(opc == 7)
                {
                    v = Aleatorio(100000);
                    n = 100000;
                    break;
                }
                else
                    printf("Opcao invalida!\n");

            }
            else if(opc == 2)
            {
                printf("1 - Insercao\n");
                printf("2 - Selecao\n");
                printf("3 - Mergesort\n");
                printf("4 - Heapsort\n");
                printf("5 - Quicksort\n");
                scanf("%d",&opc);
                if(opc==1)
                {
                    contador = 0;
                    system("cls || clear");
                    printf("Contador antes %d\n",contador);
                    insercao(n,v);
                    printf("\nContador final %d\n",contador);
                    break;
                }
                else if(opc==2)
                {
                    contador = 0;
                    system("cls || clear");
                    printf("Contador antes %d\n",contador);
                    selecao(n,v);
                    printf("\nContador final %d\n",contador);
                    break;
                }
                else if(opc==3)
                {
                    contador = 0;
                    system("cls || clear");
                    printf("Contador antes %d\n",contador);
                    merge(0,n,v);
                    printf("\nContador final %d\n",contador);
                    break;
                }
                else if(opc==4)
                {
                    contador = 0;
                    system("cls || clear");
                    printf("Contador antes %d\n",contador);
                    heap(n,v);
                    printf("\nContador final %d\n",contador);
                    break;
                }
                else if(opc==5)
                {
                    system("cls || clear");
                    contador = 0;
                    printf("Contador antes %d\n",contador);
                    quicksort(v,0,n);
                    printf("\nContador final %d\n",contador);
                    break;
                }
                else
                {
                    printf("Opcao invalida!");
                }
            }
            else
            {
                system("cls || clear");
                break;
            }
        }
    }
}

int main()
{
    srand(time(NULL));
    menu();

}
