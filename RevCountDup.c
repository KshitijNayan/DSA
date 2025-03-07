#include<stdio.h>
//code for counting duplicates in an array using recursion

int revCountDup(int n,int a[],int b,int c)
{
    for(int i=0;i<b;i++)
    {
        if(a[i]==a[b])
        {
            c++;
            break;
        }
    }
    if(b==(n-1))
    return c;
    else
    {
        b++;
        revCountDup(n,a,b,c);
    }
}
int main()
{
    int n=5;
    int a[5]={1,2,1,3,1};
    printf("Digits of array seperated by spaces are\n",n);
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("Duplicates = %d\n",revCountDup(n,a,0,0));
}