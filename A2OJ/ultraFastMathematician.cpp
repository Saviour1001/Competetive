#include<bits/stdc++.h>
using namespace::std;
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    string ans="";
    //cout<<s1<<"--\n";
    for(int i=0;i<s1.length();i++)
    {
        if(s1[i]=='1' && s2[i]=='1')
        {
            ans+="0";
        }
        else if(s1[i]=='0' && s2[i]=='0')
        {
            ans+="0";
        }
        else
        {
            ans+="1";
        }
    }
    cout<<ans;

}