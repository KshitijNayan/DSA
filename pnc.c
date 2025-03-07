#include<stdio.h>
//Civil Pds test code

int grouping(int g,int n,int a[],int i,int k)
{
    static int c=0;
    if(c==0)
    {
        for(int m=0;m<g;m++)
        a[m]=1;
        a[0]=n-g+1;
    }
    c++;
    if(a[i]==6)
    {
        i++;
        k=i;
    }
    for(int j=0;j<g;j++)
    printf("%d",a[j]);
    if(a[g]==(n-g+1))
    return c;
    else
    {
        for(;k<=i;k--)
        {
            a[k]--;
            a[k+1]++;
            int m=grouping(g,n,a,i,k);
            return c;
        }
    }
}
int main()
{
    int a[100],n,g,ans;
    printf("Enter n and g: ");
    scanf("%d%d",&n,&g);
    ans = grouping(g,n,a,0,0); //function call
    printf("#groupings = %d\n",ans);
    return 0;
}