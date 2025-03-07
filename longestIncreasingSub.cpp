using namespace std;
#include<stdio.h>
#include<iostream>
void display(int a[],int s,int e)
{
    cout<<"Elements of longest increasing subarray :"<<endl;
    while(s<=e)
    {
        cout<<a[s]<<'\t';
        s++;
    }
}
void processor(int a[],int n)
{
    int c=0,m=0,s,ms,me;
    for(int i=1;i<n;i++)
    {
        if(a[i]>a[i-1])
        {
            if(c==0)
            s=i-1;
            c++;
            if(m<c)
            {
                m=c;
                me=i;
                ms=s;
            }
        }
        else
        {
            c=0;
            s=0;
        }
    }
    if(m>0)
    display(a,ms,me);
    else
    cout<<"No increasing subaaray";
}
void getdata(int a[],int n)
{
    cout<<"Enter "<<n<<" numbers"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
}
int main()
{
    cout<<"Enter the length of array"<<endl;
    int n;
    cin>>n;
    int a[n];
    getdata(a,n);
    processor(a,n);
}