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
        if(s[0]=='1')
        {
            cout<<"10";
            cout<<s.substr(1)<<"\n";
        }
        else
        {
            cout<<"1"<<s<<"\n";
        }
    }
}

