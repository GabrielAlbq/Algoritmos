///Gabriel Albuquerque de Oliveira
///EP0, 18/05/2017
///DISCIPLINA: ALGORITMOS E ESTRUTURA DE DADOS BC3

#include<stdio.h>
#include<stdlib.h>
#include <time.h>
///A funcao abaixo recebe valores aleatorios para o vetor e verifica se ele tem apenas uma posiçao ou nao, caso nao, ela percorre o vetor
///e verifica se o valor da posiçao atual é maior que a variavel que guarda valor da posiçao 0, se sim, essa variavel recebe o valor da
///posiçao atual até chegar ao fim do vetor, e retorna o valor maximo encontrado.
int ContUniv;
int MaxvetorIterativo()
{
    ContUniv = 0;
    int random = 1 + (rand()%10);
    int v[random];
    int n = 0;
    for(n=0; n<random; n++)
    {
        v[n] = rand()%50;
        printf("%d\n",v[n]);
    }
    int maximo = v[0];
    if(random == 1)
    {
        return v[0];
    }
    else
    {
        for(n=1; n<random; n++)
        {
            ContUniv++;
            if(v[n] > maximo)
            {
                maximo = v[n];
            }
        }
    }
    printf("rodou %d\n",ContUniv);
    return maximo;
}
///
int MaxvetorRecursivo(int n,int v[]) //
{
    if(n==1)
        return v[0];
    else
    {
        int x;
        x = MaxvetorRecursivo(n-1,v);
        if(x > v[n-1])
            return x;
        else
            return v[n-1];
    }
}
///A funcao abaixo recebe um inteiro o qual vai servir parar calcular a potencia de 2, e usa um contador para multiplicar o 2, n vezes e com isso devolve essa multiplicaçao
int CalcPotIterativo(int n)
{
    int c;
    float pot=2;
    if(n==0)
        return 1;
    else
    {
            for(c=1; c<n; c++)
            {
                pot = pot*2;
            }
    }
    return pot;
}
///A funcao abaixo verifica se n é igual a 1 ou 0, caso sim, retorna o valor que seria a potencia de 2 com esses numeros, caso nao, devolve a multiplicacao de 2 por ele mesmo
///N vezes
int CalcPotRecursivo(int n)
{
    if(n==1)
        return 2;
    else if(n==0)
        return 1;
    else
        return 2*CalcPotRecursivo(n-1);
}
///A funcao abaixo pede do usuario tamanho e valores do vetor, e o verifica se está em ordem crescente comparando uma posiçao N com todas as posiçoes até verificar se o N
///é maior que o próximo valor do vetor caso sim retorna 0 como falso e 1 como verdadeiro
int OrdenacaoIterativo(int n,int v[])
{
    int e;
    int c,j;
    for(c=1; c<n; c++)
    {
        for(j=c; j<n; j++)
        {
            if(v[c] > v[j])
            {
                return 0;
            }
        }
    }
    return 1;
}
int OrdenacaoRecursivo(int n,int v[])
{
    int x=n-1;
    if(n==1)
        return 0;
    else
    {
        if(v[x] > v[x-1])
        {
            return OrdenacaoRecursivo(x-1,v);
        }
        else
            return 0;
    }
}
void menu()
{
    int opc,sub;
    printf("1 - Maximo de um vetor iterativo\n");
    printf("2 - Maximo de um vetor recursivo\n");
    printf("3 - Calcular potencia iterativo\n");
    printf("4 - Calcular potencia recursivo\n");
    printf("5 - Verificar ordenacao iterativo\n");
    printf("6 - Verificar ordenacao recursivo\n");
    printf("7 - Localizar posicao iterativo\n");
    printf("8 - Localizar posicao recursivo\n");
    scanf("%d",&opc);
    if(opc==1)
    {
        system("cls || clear");
        sub = MaxvetorIterativo();
        printf("O maior eh %d",sub);
    }
    else if(opc==2)
    {
        system("cls || clear");
        int x;
        printf("Digite o tamanho do vetor: ");
    scanf("%d",&sub);
        printf("Digite os valores do vetor: ");
        int c, v[sub];
        for(c=0; c<sub; c++)
        {
        scanf("%d",&v[c]);
        }
        x= MaxvetorRecursivo(sub,v);
        printf("O maior eh %d",x);
    }
    else if(opc==3)
    {
        system("cls || clear");
        float x;
        printf("Digite um valor para a potencia");
        scanf("%d",&sub);
        x=CalcPotIterativo(sub);
        printf("2 elevado a %d eh igual a %f",sub,x);
    }
    else if(opc==4)
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
    }
    else
    {
        system("cls || clear");
        menu();
    }
}
int main()
{
    srand(time(NULL));
    menu();
}
