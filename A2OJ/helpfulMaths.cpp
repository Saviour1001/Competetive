#include<bits/stdc++.h>
using namespace::std;
int main()
{
    string s;
    cin>>s;
    int count1=0;
    int count2=0;
    int count3=0;
    string ones="";
    string twoes="";
    string threes="";
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='1')
        {
            count1++;
            ones+="1+";
        }
        if(s[i]=='2')
        {
            count2++;
            twoes+="2+";
        }
        if(s[i]=='3')
        {
            count3++;
            threes+="3+";
        }
    }
    string ans=ones+twoes+threes;
    ans.pop_back();
    cout<<ans<<"\n";

}