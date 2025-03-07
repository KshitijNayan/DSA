#include<stdio.h>
void subarrays(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        int k=1,c=0;
        for(int j=i;j<n;j++)
        {
            if(c==0)
            {
                printf("{");
                j=i;
            }
            printf("%d",a[j]);
            c++;
            if(c!=k)
            {
                printf(",");
            }
            if(c==k)
            {
                printf("}");
                printf("\n");
                c=0;
                k++;
            }
        }
        k=1;
    }
}
int main()
{
    int n;
    printf("Enter the size of array\n");
    scanf("%d",&n);
    int a[50];
    printf("Enter array elements\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    subarrays(a,n);
    return 0;
}