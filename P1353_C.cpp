using namespace::std;
#include<stdio.h>
#include<vector>
#include<iostream>
#include<math.h>
int main(){
    int t;
    cin>>t;
    long long int a[t],c=0,b=1;
     int n[t];
    for(int i=0;i<t;i++){
        cin>>n[i];
        a[i]=0;
        for(int j=n[i]/2;j>=0;j--){
            a[i]+=c*b;
            c++;
            b=8*c;
            if(j==0)
            b=1;
        }
        c=0;
    }
    for(int i=0;i<t;i++){
        cout<<a[i]<<endl;
    }
}