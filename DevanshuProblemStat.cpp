using namespace std;
#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>
//code for finding the index of even no. in a given n size array with other elements odd

int main(){
    int n;
    cout<<"Enter size of array and it's elements"<<endl;
    cin>>n;
    cout<<n<<endl;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    for(int i=0;i<n;i++)
    cout<<a[i]<<endl;
    int s=0,m=(n/2),e=n-1;
    cout<<s<<endl<<m<<endl<<e<<endl;
    while(s!=e&&m!=0&&m!=n)
    {
        if(a[m]==a[m-1]){
            if((m-s)%2==0)
            e=m;
            else
            s=m+1;
        }
        else if(a[m]==a[m+1])
        {
            if((m-s)%2==0)
            s=m+2;
            else
            e=m-1;
        }
        else{
        break;}
        m=s+(e-s)/2;   
    }
    cout<<"index = "<<m<<" no. = "<<a[m];
}