#include<stdio.h>
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
    int n;
    printf("Enter size of array\n");
    scanf("%d",&n);
    int a[n];
    printf("Enter %d digits of array seperated by spaces\n",n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Digits of array seperated by spaces are\n",n);
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("Duplicates = %d\n",revCountDup(n,a,0,0));
}