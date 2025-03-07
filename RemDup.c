#include<stdio.h>
//function to remove duplicates in an array using  recursion

void revRemDup(int n, int a[],int k,int b[],int c)
{
    int kp=0;
    for(int i=0;i<k;i++)
    {
        if(a[k]==a[i])
        {
            kp=1;
            break;
        }
    }
    if(kp==0)
    {
        b[c]=a[k];
        c++;
    }
    if(k<n)
    {
        k++;
        revRemDup(n,a,k,b,c);
    }
}
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
    int a[n],b[n];
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
    printf("\n");
    revRemDup(n,a,0,b,0);
    printf("Array after removing duplicates\n",n);
    for(int i=0;i<n-revCountDup(n,a,0,0);i++)
    {
        printf("%d ",b[i]);
    }
}