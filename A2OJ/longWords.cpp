#include<bits/stdc++.h>
using namespace::std;
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        string s;
        cin>>s;
        if(s.length()>10)
        {
            string ans="";
            char a=s[0];
            char b=s[s.length()-1];
            stringstream length;
            length<<s.length()-2;
            string c;
            length>>c;
            ans=a+c+b;
            cout<<ans<<"\n";
        }
        else
        {
            cout<<s<<"\n";
        }
    }
}