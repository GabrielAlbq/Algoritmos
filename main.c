#include<stdio.h>
#include<stdlib.h>
#include <time.h>

int Maxvetor()
{
    srand(time(NULL));
    int random = rand()%10;
    int v[random];
    int n = 0;
    int j;
    int aleat = 50;
    for(n=0; n<random; n++)
    {
        v[n] = rand()%50;
        printf("%d\n",v[n]);
    }
    int maior =0;
    if(random == 1)
    {
        return v[0];
    }
    else
    {
        for(n=0; n<random; n++)
        {
            for(j=random; j>=0; j--)
            {
                printf("nmr aleat eh %d\n",aleat);
                if(v[n] > v[j] || v[j] >v[n])
                {
                    if(v[n] > maior)
                    {
                        maior = v[n];
                        //printf("O maximo eh %d\n",maior);
                    }
                    else
                     break;
                }
                else
                {
                    break;
                    aleat--;
                }
            }
        }
        printf("O maximo eh %d\n",maior);
    }
}

int main()
{
    srand(time(NULL));
    Maxvetor();
}
