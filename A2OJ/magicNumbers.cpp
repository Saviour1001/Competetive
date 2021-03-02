#include<bits/stdc++.h>
using namespace::std;
int main()
{
    long long n;
    cin>>n;
    stringstream ss;
    ss<<n;
    string s;
    ss>>s;
    int ones=0;
    int fours=0;
    bool check=1;
    for(int i=0;i<s.length();i++)
    {    
        if(s[i]!='1' && s[i]!='4')
        {
            check=0;
            break;
        }
        if(s[i]=='1')
        {
            ones++;
        }
        if(s[i]=='1' && fours>0)
        {
            fours=0;
        }
        if(s[i]=='4' && ones>0)
        {
            fours++;
        }
        if(s[i]=='4' && ones==0)
        {
            check=0;
            break;
        }
        if(fours==2 && ones>0)
        {
            fours=0;
            ones=0;
        }
    }
    
    check ? cout<<"YES\n" : cout<<"NO\n";
}