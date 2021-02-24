#include<bits/stdc++.h>
using namespace::std;
int main()
{
    string a,b,c;
    cin>>a>>b>>c;
    if(c.length()!=a.length()+b.length())
    {
        cout<<"NO\n";
        return 0;
    }
    int arr[26]={0};
    for(int i=0;i<a.length();i++)
    {
        arr[a[i]-'A']++;
    }
    for(int i=0;i<b.length();i++)
    {
        arr[b[i]-'A']++;
    }
    for(int i=0;i<c.length();i++)
    {
        arr[c[i]-'A']-=1;
    }
    bool check=1;
    for(int i=0;i<26;i++)
    {
        if(arr[i]>0)
        {
            check=0;
            break;
        }
    }
    if(check)
    {
        cout<<"YES\n";
    }
    else
    {
        cout<<"NO\n";
    }
}