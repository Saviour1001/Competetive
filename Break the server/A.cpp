#include<bits/stdc++.h>
using namespace::std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int p=0;int c=0;int m=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='P')p++;
            if(s[i]=='C')c++;
            if(s[i]=='M')m++;
        }
        if(p & c & m)
        {
            cout<<"YES\n";
        }
        else
        {
            cout<<"NO\n";
        }
    }
}