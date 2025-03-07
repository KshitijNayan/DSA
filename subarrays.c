#include<stdio.h>
void max(int b[],int c)
{
    int max=b[0];
    for(int i=0;i<c;i++)
    {
        if(b[i]>max)
        max=b[i];
    }
    printf("Maximum sum of subarray = %d",max);
}
int subarrays(int a[],int b[],int n)
{
    int c=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            for(int k=i;k<=j;k++)
            {
                if(k==i)
                printf("{");
                printf("%d",a[k]);
                b[c]+=a[k];
                if(k!=j)
                printf(",");
                if(k==j)
                {
                    printf("}");
                    c++;
                }
            }
            printf("\n");
        }
    }
    return c;
}
int main()
{
    int n,c;
    printf("Enter the size of array\n");
    scanf("%d",&n);
    int a[50],b[100];
    printf("Enter array elements\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<100;i++)
    {
        b[i]=0;
    }
    c=subarrays(a,b,n);
    printf("c= %d\nSum of each subarray in previous order :\n",c);
    for(int i=0;i<c;i++)
    {
        printf("%d ",b[i]);
    }
    printf("\n");
    max(b,c);
    return 0;
}