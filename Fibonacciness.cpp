using namespace std;
#include<stdio.h>
#include<iostream>
// #include<conio.h>
int main()
{
    int t,c=1,a3;
    cin>>t;
    int a[t][5];
    for(int i=0;i<t;i++)
        for(int j=0;j<5;j++)
        {
            if(j==2)
            continue;
            cin>>a[i][j];
        }
    for(int i=0;i<t;i++){
        a3=a[i][0]+a[i][1];
        if(a3+a[i][1]==a[i][3])
            c++;
        if(a3+a[i][3]==a[i][4])
            c++;
        else if(2*a[i][3]-a[i][1]==a[i][4])
        c++;
        cout<<c<<endl;
        c=1;
    }
}