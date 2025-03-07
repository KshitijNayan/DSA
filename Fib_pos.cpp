#include<stdio.h>
//code to calculate fibonacci no. at a given position

int fib(int a)
{
    int n;
    if(a==1)
    {
        n = 0;
    }
    else if(a==2)
    {
        n = 1;
    }
    else
    {
        n = fib(a-1)+fib(a-2);
    }
    return n;
}
int main()
{
    int n;
    printf("Enter no.\n");
    scanf("Enter no. %d",&n);
    int r = fib(n);
    printf("fibonacci number at given position is %d",r);
    return 0;
}
