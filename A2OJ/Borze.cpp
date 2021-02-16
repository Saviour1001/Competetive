#include<bits/stdc++.h>
using namespace::std;
int main()
{
    string s;
    cin>>s;
    int zeroes=0;
    string ans="";
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='.')
        {
            ans+="0";
            continue;
        }
        if(s[i]=='-' && s[i+1]=='.')
        {
            ans+="1";
            i++;
            continue;
        }
        if(s[i]=='-' && s[i+1]=='-')
        {
            ans+="2";
            i++;
            continue;
        }
    }
cout<<ans;
}