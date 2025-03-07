using namespace std;
#include<stdio.h>
#include<iostream>
int larger(int n,int v[], int *i)
{
    int max=0;
    for(;*i<n;*i++)
    {
        if(v[*i]>max)
        {
            max=v[*i];
            return 1;
        }
    }
    return 0;
}
int checker(int n,int v[])
{
    int count=0, max=0;
    if(v[0]>v[1])
    {
        cout<<"Day 1 is a record breaking day"<<endl;
        count++;
        max=v[0];
    }
    int i=0,f=0;
    while(i<n)
    {
        i++;
        f=larger(n,v,&i);
        if(f==1&&v[i]>v[i+1]&&i<n-1&&v[i]>max)
        {
            cout<<"Day "<<i+1<<" is a record breaking day"<<endl;
            count++;
            f=0;
            max=v[i];
        }
        else if(f==1&&i==n-1&&v[i]>max)
        {
            cout<<"Day "<<i+1<<" is a record breaking day"<<endl;
            count++;
            break;
        }
        else if(f==0&&count==0&&i==n-1)
        {
            cout<<"There is no record breaking day"<<endl;
        }
    }
    return count;
}
int main()
{
    int n;
    cout<<"Enter no. of days"<<endl;
    cin>>n;
    int v[100];
    cout<<"Enter the no. of visitors on each day "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    cout<<"Total no. of record breaking days = "<<checker(n,v)<<endl;
}