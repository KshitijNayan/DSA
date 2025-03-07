/*
Assignment : A_09
Name : Kshitij Nayan
Roll : 24IM10040
PC no. : 34*/
#include<stdio.h>
#include<stdlib.h>
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
void orderPoly(int p[])//function for sorting a row of polyset containing polynomials
{
    int min,q,qq;
    for(int j=2;j<p[0]*2+1;j+=2)
    {
        min=p[j];
        qq=j;
        for(int k=j+2;k<p[0]*2+1;k+=2)
        {
            if(min>p[k])
            {
                min=p[k];
                qq=k;
            }
        }
        q=p[qq-1];
        p[qq-1]=p[j-1];
        p[j-1]=q;
        p[qq]=p[j];
        p[j]=min;
    }
}
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
void addPoly(int p[],int q[],int r[])//function to add 2 rows of polyset
{
    int c=1,i;
    for(i=1;i<=p[0]*2;i+=2)
    {
        r[c]=p[i];
        r[c+1]=p[i+1];
        c+=2;
    }
    for(i=1;i<=q[0]*2;i+=2)
    {
        r[c]=q[i];
        r[c+1]=q[i+1];
        c+=2;
    }
    r[0]=p[0]+q[0];
    sortPoly(r);
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
int main()//main function
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
        polyset[i]=(int *)malloc((1+s*2)*sizeof(int));
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
    for(int i=0;i<m;i++)
    {
        printf("polynomial no. %d = ",i+1);
        for(int j=1;j<polyset[i][0]*2+1;j+=2)
        {
            if(j==1&&polyset[i][1]>0)
            printf("%dx^%d ",polyset[i][j],polyset[i][j+1]);
            else{
                if(polyset[i][j]>0)
                    printf("+ %dx^%d ",polyset[i][j],polyset[i][j+1]);
                else
                    printf("- %dx^%d ",polyset[i][j],polyset[i][j+1]);
            }
        }
        printf("\n");
    }
    for(int i=0;i<m;i++)
    {
        orderPoly(polyset[i]);
    }
    printf("Polyset After sorting =\n");
    for(int i=0;i<m;i++)
    {
        for(int j=1;j<polyset[i][0]*2+1;j++)
        {
            printf("%d ",polyset[i][j]);
        }
        printf("\n");
    }
    printf("Sorted polynomial =\n");
    for(int i=0;i<m;i++)
    {
        prettyPrintPoly(polyset[i]);
    }
    int y,z;
    printf("Enter 2 rows to be added\n");
    scanf("%d%d",&y,&z);
    int *Result1 = (int*)malloc(sizeof(int)*(polyset[z][0]+polyset[y][0]*2+1));
    addPoly(polyset[y],polyset[z],Result1);
    orderPoly(Result1);
    prettyPrintPoly(Result1);
    printf("Enter 2 rows to be multiplied\n");
    scanf("%d%d",&y,&z);
    int *Result2 = (int*)malloc(sizeof(int)*(polyset[z][0]*polyset[y][0]*2+1));
    if(Result2==NULL)
    {
        printf("memory adrress not allocated");
    }
    else
    {
        printf("memory adrress allocated");
    }
    Result2[0]=polyset[z][0]*polyset[y][0];
    multPoly(polyset[y],polyset[z],Result2);
    prettyPrintPoly(Result2);
    sortPoly(Result2);
    prettyPrintPoly(Result2);
    orderPoly(Result2);
    prettyPrintPoly(Result2);
    return 0;
}
