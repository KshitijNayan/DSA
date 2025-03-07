using namespace std;
#include<stdio.h>
#include<iostream>
#include<vector>
int main(){
    int c0=0,c1=0,t;
    cin>>t;
    vector<vector <char>> a;
    int s[t];
    for(int i=0;i<t;i++)
    {
        cin>>s[i];
        char arr;
        vector<char> ar;
        for(int j=0;j<s[i];j++)
        {
            cin>>arr;
            ar.push_back(arr);
        }
        a.push_back(ar);
    }
  
    for(int i=0;i<a.size();i++)
    {
        for(int j=0;j<a[i].size();j++)
        {
            if(a[i][j]=='(')
            c0++;
            if(c0==0&&a[i][j]==')'){
                c1++;
            }
            else if(a[i][j]==')')
            c0--;
        }
        cout<<c1<<endl;
        c0=0;
        c1=0;
    }
}