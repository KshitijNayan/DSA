#include<stdio.h>
#include<math.h>
int search(int A[],int n,int r);
int countDup(int A[],int n,int i);
int remDup(int A[],int B[],int n);
int main()
{
    int n;
    do
    {
        printf("Enter a positive no. less than 11\n");
        scanf("%d",&n);//taking n as input
        printf("\n");
    }while(n>10);
    printf("Value of n = %d\n",n);
    printf("Enter %d integer values separated by space to be stored in the array\n",n);
    int A[10];//Declaring array 'A'
    for(int i=0;i<n;i++)//for taking input to be stored in the array
    {
        scanf("%d",&A[i]);
    }
    printf("\n");
    printf("Enter r to be searched in the array\n");
    int r;
    scanf("%d",&r);//taking r as input
    int c0=search(A,n,r);
    if(c0==-1)
        printf("r not found\n");
    else
        printf("r found at position : %d\n",(c0+1));
    int cx=1,An[10],Ann[10];
    for(int i=0;i<n;i++)
    {
        An[i]=A[i];
        Ann[i]=A[i];
    }
    int yh=0;
    for(int i=0;i<n;i++)
    {
        if(An[i]!=-1)
        {
            cx=countDup(An,n,i);//for counting the no. of copies of each element in the array
            printf("%d is present %d times\n",A[i],cx);
            yh++;
        }
    }
    int B[10];
    remDup(Ann,B,n);
    printf("The elements in the array B are:\n");
    for(int i=0;i<yh;i++)//for printing the array
    {
        printf("%d\n",B[i]);
    }
    return 0;
}
int search(int A[],int n,int r)
{
    int co=-1;
    for(int i=0;i<n;i++)
    {
        if(A[i]==r)
        {
            co=i;
            break;
        }
    }
    return co;
}
int countDup(int A[],int n,int i)
{
    int y=A[i];
    int x=0;
    int c=0;
    while(c!=-1)
    {
        c=search(A,n,y);
        x++;
        A[c]=-1;
    }
    x--;
    return x;
}
int remDup(int A[],int B[],int n)
{
    int ab=0;
    for(int i=0;i<n;i++)
    {
        if(A[i]!=-1)
        {
            int y=A[i];
            B=A[i];
            int c=0;
            while(c!=-1)
            {
                c=search(A,n,y);
                A[c]=-1;
            }
            ab++;
        }
    }
}
