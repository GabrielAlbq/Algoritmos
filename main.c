#include <stdio.h>
#include <stdlib.h>
#include <time.h>
///Funcao que gera um vetor de 'n' posiçoes aleatoriamente.
int *Aleatorio(int n){
    //int n;
    //n = rand()%1000;
    int *v = malloc(n*sizeof(int));
    int c;
    for(c=0;c<n;c++){
        v[c] = rand()%1000000;
    }
    for(c=0;c<n;c++)
        printf("%d\n",v[c]);
    return v;
}
void insercao(int n, int v[]){
    int i,j,x;
    for(j=1;j<n;j++){
        x=v[j];
        for(i=j-1;i>=0 && v[i]>x;i--){
            v[i+1]=v[i];
        }
            v[i+1] = x;
    }
    for(i=0;i<n;i++)
        printf("%d\n",v[i]);
}
void selecao(int n, int v[]){
    int i,j,min,x;
    for(i=0;i<n-1;i++){
        min = i;
        for(j=i+1;j<n;j++){
            if(v[j]<v[min])
                min=j;
            x=v[i];v[i]=v[min];v[min]=x;
        }
    }
    for(i=0;i<n;i++)
        printf("%d\n",v[i]);
}
void intercala(int p,int q, int r, int v[]){
    int i,j,k,*w;
    w = malloc((r-p)*sizeof(int));
    i = p;j=q;k=0;

    while(i<q && j<r){
        if(v[i]<=v[j])
            w[k++]=v[i++];
        else w[k++]=v[j++];
    }
    while(i<q) w[k++]=v[i++];
    while(j<r) w[k++]=v[j++];
    for(i=p;i<r;i++) v[i] =w[i-p];
    free (w);
}
void mergesorts(int p, int r, int v[]){
    int i;
    if(p<r-1){
        int q = (p+r)/2;
        mergesorts(p,q,v);
        mergesorts(q,r,v);
        intercala(p,q,r,v);
    }
    for(i=0;i<r;i++)
        printf("%d\n",v[i]);
}
void menu(){
    int opc,sub;
    long int n;
    printf("1 - Insercao\n");
    printf("2 - Selecao\n");
    printf("3 - Mergesort\n");
    printf("4 - Heapsort\n");
    printf("5 - Quicksort\n");
    scanf("%d",&opc);
    if(opc==1)
    {
        system("cls || clear");
        printf("Digite o numero de posicoes do vetor aleatorio: ");
        scanf("%i",&n);
        insercao(n,Aleatorio(n));
    }
    else if(opc==2)
    {
        system("cls || clear");
        printf("Digite o numero de posicoes do vetor aleatorio: ");
        scanf("%i",&n);
        selecao(n,Aleatorio(n));
    }
    else if(opc==3)
    {
        system("cls || clear");
        printf("Digite o numero de posicoes do vetor aleatorio: ");
        scanf("%i",&n);
        mergesorts(1,n,Aleatorio(n));
    }
    /*else if(opc==4)
    {
        system("cls || clear");
        float x;
        printf("Digite um valor para a potencia");
        scanf("%d",&sub);
        system("cls || clear");
        x=CalcPotRecursivo(sub);
        printf("2 elevado a %d eh igual a %f",sub,x);
    }
    else if(opc==5)
    {
        system("cls || clear");
        printf("Digite o tamanho do vetor: ");
        scanf("%d",&sub);
        printf("Digite os valores do vetor: ");
        int c, v[sub];
        for(c=0; c<sub; c++)
        {
        scanf("%d",&v[c]);
        }
        int
        x = OrdenacaoIterativo(sub,v);
        if(x==1)
        printf("Esta ordenado");
        else
            printf("Nao esta ordenado");
    }*/
    else
    {
        system("cls || clear");
        menu();
    }
}

int main()
{
    srand(time(NULL));
    //Aleatorio(1000);
    int *w;
    w = malloc(10*sizeof(int));
   // w = Aleatorio(10);
    int c;
    menu();
    //insercao(10,Aleatorio(10));
    //for(c=0;c<10;c++)
    //    printf("%d\n",w[c]);
    //return 0;
   // free(w);
    //for(c=0;c<10;c++)
   //     printf("%d\n",w[c]);
}
