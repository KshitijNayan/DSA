#include<stdio.h>
#include<math.h>
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
    printf("Enter 10 integer values separated by space to be stored in the array\n");
    int A[10];//Declaring array 'A'
    for(int i=0;i<10;i++)//for taking input to be stored in the array
    {
        scanf("%d",&A[i]);
    }
    printf("\n");
    printf("The elements in the array are:\n");
    for(int i=0;i<10;i++)//for printing the array
    {
        printf("%d\n",A[i]);
    }
    int sO=0,sE=0;//Declaring and initializing sO=0 for storing sum of odd values in array and sE=0 for the sum of the even no. in the array
    for(int i=0;i<10;i++)//for printing the array
    {
        if(A[i]%2==0)//checking condition whether the element at (i+1)th position of array is even
            sE+=A[i];//if the element is even adding it to sE
        else
            sO+=A[i];//else adding it to sO
    }
    printf("Sum of odd elements of array = %d\n",sO);//printing the sum of odd nos. in the array
    printf("Sum of even elements of array = %d\n",sE);//printing the sum of even nos. in the array
    int flag=0;//Declaring and initializing flag=0 as flag variable
    for(int i=0;i<10;i++)//for printing the array
    {
        if(A[i]==A[9-i])//checking condition whether the element at (i+1)th position of array is the same as the (i+1)th element from the ending of array
            {}
        else
            flag=1;//else turning the value of flag variable from 0 to 1
    }
    if(flag==0)//checking whether flag variable is 0 or not
        printf("Palindrome array\n");
    else
        printf("Not a palindrome array\n");
    int ch=A[0],ch1=0;
    for(int i=0;i<10;i++)//for circular right shift of array
    {
        if(i==9)
            A[0]=ch;
        else
            ch1=ch;
            ch=A[i+1];
            A[i+1]=ch1;
    }
    printf("The elements in the array A after circular right shift are:\n");
    for(int i=0;i<10;i++)//for printing the array
    {
        printf("%d\n",A[i]);
    }
    int B[10];//Declaring array 'B'
    printf("Enter 10 integer values separated by space to be stored in the array B\n");
    for(int i=0;i<10;i++)//for taking input to be stored in the array
    {
        scanf("%d",&B[i]);
    }
    printf("\n");
    printf("The elements in the array A are:\n");
    for(int i=0;i<10;i++)//for printing the array 'A'
    {
        printf("%d\n",A[i]);
    }
    printf("The elements in the array B are:\n");
    for(int i=0;i<10;i++)//for printing the array 'B'
    {
        printf("%d\n",B[i]);
    }
    printf("The positions where value in A is greater than that in B :\n");
    int counter=0;//declaring and initializing a counter=0 for counting no. of positions where value in A is greater than that in B
    for(int i=0;i<10;i++)
    {
        if(A[i]>B[i])
        {
            printf("%d\n",i);
            counter++;
        }
    }
    if(counter==0)
        printf("none \n");
    int counter1=0;//declaring and initializing a counter1=0 for counting no. of positions where value in A is equal to that in B
    int im=10;
    for(int i=0;i<10;i++)
    {
        if(A[i]==B[i])
        {
            counter1++;
        }
    }
    int C[20-counter1];
    for(int i=0;i<10;i++)
    {
        C[i]=A[i];
    }
    for(int i=0;i<(20-counter1);i++)
    {
        if(A[i]==B[i])
        {
            continue;
        }
        else
            C[im]=B[i];
        im++;
    }
    printf("The elements in the array C are:\n");
    for(int i=0;i<10;i++)//for printing the array
    {
        printf("%d\n",C[i]);
    }
}