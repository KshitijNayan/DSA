#include<stdio.h>
int arithmetic(int n, int a[][10],int k)
{
    for(int i=1;i<n-1;i++)
    {
        if(a[k][i]-a[k][i-1]!=a[k][i+1]-a[k][i])
        {
            return 0;
        }
    }
    return 1;
}
void subarray(int a[55][10],int b[10],int pp[55],int n)
{
    int c=0,p=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            for(int k=i;k<=j;k++)
            {
                a[c][p]=b[k];
                p++;
                if(k==j)
                {
                    pp[c]=p;
                    c++;
                    p=0;
                }
            }
        }
    }
}
void checker(int n , int a[55][10], int q[55],int c[55])
{
    for(int i=0;i<n;i++)
    {
        q[i] = arithmetic(c[i],a,i);
    }
}
void max(int n,int c[55],int a[][10],int q[55])
{
    int max=-1,in;
    for(int i=0;i<n;i++)
    {
        if(q[i]==1&&max<c[i])
        {
            max=c[i];
            in=i;
        }
    }
    printf("Largest arithmetic subarray is : \n");
    for(int i=0;i<c[in];i++)
    {
        printf("%d  ",a[in][i]);
    }
}
int main()
{
    int n;
    printf("Enter size of array\n");
    scanf("%d",&n);
    int b[10];
    int a[55][10],c[55];
    printf("Enter elements of the array :\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&b[i]);
    }
    int q[55];
    subarray(a,b,c,n);
    checker(n*(n+1)/2,a,q,c);
    max(n*(n+1)/2,c,a,q);
    return 0;
}