#include <stdio.h>
void shiftRight(int n, int a[], int k)
{
    int b=a[n-1],c;
    for (int j = 1; j <= k; j++)
    {
        for (int i = 0; i < n; i++)
        {
            c=a[i];
            a[i]=b;
            b=c;
        }
        b=a[n-1];
    }
}
int main()
{
    int n;
    printf("Enter size of array\n");
    scanf("%d", &n);
    int a[n];
    printf("Enter %d no. to be input in array separated by spaces\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d ", &a[i]);
    }
    printf("Enter how many times array is to be circular shifted in right direction");
    int k;
    scanf("%d", &k);
    shiftRight(n, a, k);
    printf("New array after circular right shift by %d times :",k);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}