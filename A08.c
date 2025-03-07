/*Kshitij Nayan
Roll no. 24IM10040
PC no. 34
*/
#include<stdio.h>
int equal_submat(int n,int x[][10],int y[][10],int m,int s,int p,int q, int qq,int rr,int ss,int tt);
int symmetric_check(int n,int x[][10]);
void row_col_sum(int n,int x[][10]);//this function is calculating and displaying the sum of each elements of separate rows and columns in a matrix
void transpose(int n,int x[][10]);//this functions finds and returns the transpose of a matrix
void difference(int n,int x[][10],int y[][10],int t[][10])//this function is calculating the difference between two matrices
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            t[i][j]=x[i][j]-y[i][j];
        }
    }
}
int symmetric_check(int n,int x[][10])//this function is checking whether a matrix is symmetric or not
{
    int t[n][10];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            t[i][j]=x[i][j];
        }
    }
    transpose(n,t);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(t[i][j]!=x[i][j])
                return 0;
        }
    }
    return 1;
}
void row_col_sum(int n,int x[][10])//this function is calculating and displaying the sum of each elements of separate rows and columns in a matrix
{
    int s=0;
    printf("Sum of element in a row :\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            s+=x[i][j];
        }
        printf("Sum of all element of row %d = %d\n",i+1,s);
        s=0;
    }
    printf("Sum of element in a column :\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            s+=x[j][i];
        }
        printf("Sum of all element of column %d = %d\n",i+1,s);
        s=0;
    }
}
void transpose(int n,int x[][10])//this functions finds and returns the transpose of a matrix
{
    int t;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            t=x[i][j];
            x[i][j]=x[j][i];
            x[j][i]=t;
        }
    }
}
int main()//main function
{
    int A[10][10],B[10][10],P[10][10],Q[10][10],R[10][10],S[10][10],n;//declaring all arrays
    printf("Enter value of n less than 10\n");
    do
    {
        scanf("%d",&n);
    }while(n>9);
    printf("n = %d\n",n);
    printf("Enter elements of matrix A\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("Enter value at row %d and column %d\n",i+1,j+1);
            scanf("%d",&A[i][j]);
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            B[i][j]=A[i][j];
        }
    }
    transpose(n,B);//calling transpose function
    printf("Transpose of Matrix A :\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",B[i][j]);
        }
        printf("\n");
    }
    printf("For matrix A :\n");
    row_col_sum(n,A);//calling row_col_sum function for matrix A
    printf("For matrix B :\n");
    row_col_sum(n,B);//calling row_col_sum function for matrix B
    int checksym=symmetric_check(n,A);//calling and storing the return value from symmetric_check function
    if(checksym==0)
        printf("A is not symmetric\n");
    else
        printf("A is symmetric\n");
    printf("Enter elements of matrix P\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("Enter value at row %d and column %d\n",i+1,j+1);
            scanf("%d",&P[i][j]);
        }
    }printf("Enter elements of matrix Q\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("Enter value at row %d and column %d\n",i+1,j+1);
            scanf("%d",&Q[i][j]);
        }
    }
    difference(n,P,Q,R);//calling difference function
    printf("Matrix R containing A-B : \n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",R[i][j]);
        }
        printf("\n");
    }
    int m;
    printf("Enter value of m\n");
    scanf("%d",&m);
    int size=0,f,g,ff,gg;
    int res=equal_submat(n,A,B,m,size,f,g,0,0,0,0);
    if(res==1)
    {
        printf("Size of common submatrix in A and B matrix = %d\nCommon submatrix :\n",size*size);
        for(int i=f;i<size;i++)
        {
            for(int j=g;j<size;j++)
            {
                printf("%d ",R[i][j]);
            }
            printf("\n");
        }
        printf("Position of submatrix is column %d and row %d\n",f,g);
    }
    else
    {
        printf("No common submatrix in A and B\n");
    }
    res=equal_submat(n,A,B,m,size,f,g,0,0,0,0);
    if(res==1)
    {
        int kq=0,jq=0;
        printf("Size of common submatrix in P and Q matrix = %d\nCommon submatrix :\n",size*size);
        for(int i=f;i<size;i++)
        {
            for(int j=g;j<size;j++)
            {
                S[kq][jq]=R[i][j];
                printf("%d ",R[i][j]);
                jq++;
            }
            jq=0;
            kq++;
            printf("\n");
        }
        printf("position of submatrix is column %d and row %d\n",f,g);
    }
    else
    {
        printf("No common submatrix in P and Q\n");
    }
    return 0;
}
int equal(int n,int a[][10],int b[][10])//function for checking whether two matrices are equal
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i][j]!=b[i][j])
                return 0;
        }
    }
    return 1;
}
int equal_submat(int n,int x[][10],int y[][10],int &m,int &s,int &p,int &q, int qq,int rr,int ss,int tt)
/*function for calculating submatrix of highest order and storing it'S POSITION
m -> minimum order of submatrix
n->size of matrix
s -> order
p -> row location of largest submatrix in matrix x
q -> column location of smallest submatrix in matrix x
qq -> current row location of matrtix x
rr -> current column location of matrix x
ss -> current row location of matrix y
tt -> current column loaction of matrix y 
*/
{
    int a[n][10],b[n][10],ia=0,ja=0;
    for(int i=0;i<n-m;i++)
    {
        for(int j=0;j<n-m;j++)
        {
            if(ia<m&&ja<m)
            {
       
                a[ia][ja]=x[i][j];
                ia++;
            }
        }
        ia=0;
        ja++;
    }
    for(int i=0;i<n-m;i++)
    {
        for(int j=0;j<n-m;j++)
        {
            if(ia<m&&ja<m)
            {
                b[ia][ja]=y[i][j];
                ia++;
            }
        }
        ia=0;
        ja++;
    }
    int res=equal(n,a,b);
    if(res==1)
    {
        if(s<m)
        {
            s==m;
            p=qq;
            q=rr;
        }
        if(ss==n-m-1)
        {
            tt++;
            ss=0;
        }
        else
            ss++;
        if(ss==n-m-1&&tt==n-m-1)
        {
            if(qq==n-m-1)
            {
                rr++;
                qq=0;
            }
            else
                qq++;
        }
        if(n>=m+1)
        {
            m++;
            equal_submat(n,x,y,m,s,p,q,qq,rr,ss,tt);
        }
        else{
            if(s>0)
                return 1;
            else
                return 0;
        }
    }
    else
    {
        equal_submat(n,x,y,m,s,p,q,qq,rr,ss,tt);
        if(rr==n-m-1&&qq==n-m-1)
            return 0;
        if(ss==n-m-1)
        {
            tt++;
            ss=0;
        }
        else
            ss++;
        if(ss==n-m-1&&tt==n-m-1)
        {
            if(qq==n-m-1)
            {
                rr++;
                qq=0;
            }
            else
                qq++;
        }
    }
}
