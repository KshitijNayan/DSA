#include<stdio.h>
//CS assignment_4 question 1

int check(int a,int n,int an[])
{
    int c=0;
    for(int i=0;i<n;i++)
    {
        if(a==an[i])
        c++;
    }
    return c;
}
int runn(int i,int a,int n)
{
    static int an[100];
    if((a-i)>0 && check((a-i),i,an)==0)
    {
        a=a-i;
    }
    else
    {
        a=a+i;
    }
    an[0]=0;
    an[i]=a;
    printf("%d ",a);
    i++;
    if(i==(n+1))
    return 0;
    else
    runn(i,a,n);
}
int main()
{
    int n;
    printf("Enter value of n<100\n");
    scanf("%d",&n);
    runn(1,0,n);
    return 0;
}