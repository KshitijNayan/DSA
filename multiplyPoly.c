#include<stdio.h>
#include<stdlib.h>
void prettyPrintPoly(int p[])//function to print a row of polynomial in polyset
{
    for(int j=1;j<p[0]*2+1;j+=2)
    {
        if(j==1&&p[1]>0)
            printf("%dx^%d ",p[j],p[j+1]);
        else{
            if(p[j]>0)
                printf("+ %dx^%d ",p[j],p[j+1]);
            else
                printf("- %dx^%d ",p[j],p[j+1]);
        }
    }
    printf("\n");
}
void leftShift(int a[],int i)
{
    for(;i<=a[0]*2-3;i+=2)
    {
        a[i]=a[i+2];
        a[i+1]=a[i+3];
    }
    a[0]--;
}
void sortPoly(int a[])
{
    for(int i=2;i<=a[0]*2;i+=2)
    {
        for(int j=i+2;j<=a[0]*2;j+=2)
        {
            if(a[i]==a[j])
            {
                a[i-1]+=a[j-1];
                leftShift(a,j-1);
            }
        }
    }
}
void multPoly(int x[],int y[],int z[])
{
    int c=1;
    for(int i=1;i<=x[0]*2;i+=2)
    {
        for(int j=1;j<=y[0]*2;j+=2)
        {
            z[c]=x[i]*y[j];
            z[c+1]=x[i+1]+y[j+1];
            c+=2;
        }
    }
}
int main()
{
    int m,s;//array s is for storing the no. of trems in each row of polyset
    printf("Enter the value of M\n");
    do
    {
        scanf("%d",&m);
    }while(m>19);
    int *polyset[20];
    for(int i=0;i<m;i++)
    {
        printf("Enter the no. of terms in polynomial no. %d\n",i+1);
        scanf("%d",&s);
        polyset[i]=(int *)malloc((s*2+1)*sizeof(int));
        polyset[i][0]=s;
        int c=1;
        for(int j=1;j<polyset[i][0]*2+1;j+=2)
        {
            printf("Enter the coefficient of polynomial no. %d\n",c);
            scanf("%d",&polyset[i][j]);
            printf("Enter the power of polynomial no. %d\n",c);
            scanf("%d",&polyset[i][j+1]);
            c++;
        }
    }
    int x,y;
    printf("Enter the indices of 2 row which are to be multiplied\n");
    scanf("%d%d",&x,&y);
    for(int i=0;i<m;i++)
    {
        prettyPrintPoly(polyset[i]);
    }
    int *res1 = (int*)malloc(sizeof(int)*(polyset[x][0]*polyset[y][0]*2+1));
    res1[0]=polyset[x][0]*polyset[y][0];
    multPoly(polyset[x],polyset[y],res1);
    prettyPrintPoly(res1);
    sortPoly(res1);
    prettyPrintPoly(res1);
}