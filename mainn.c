#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,i=0,j=0;
    int calculo=0, fat=1;
    printf("digite o numero de escadas: ");
    scanf("%d",&n);
    n=n+1;
    for(i=1;i<n;i++)
    {
           fat = fat*i;
           if((i%2) == 0)
           {
            calculo = calculo + fat;
            j++;
           }
    }
    calculo++;

    printf("%d %d maneiras", calculo, j);

}
//6 12
//5 8
//4 5
//3 3
//2 2
//1 1
 //5 
 //4!+3!+1
