#include<bits/stdc++.h>
using namespace::std;
int main()
{
    ios_base::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int digit=0;
        int low=0;
        int cap=0;
        int sp=0;
        for(int i=0;i<s.length();i++)
        {
            if(isdigit(s[i]) && i!=0 && i!=s.length()-1)
            {
                digit+=1;
            }
            if(islower(s[i]))
            {
                low+=1;
            }
            if(isupper(s[i]) && i!=0 && i!=s.length()-1)
            {
                cap+=1;
            }
            if(s[i]=='@' || s[i]=='#' || s[i]=='%' || s[i]=='&' || s[i]=='?' )
            {
                if(i!=0 && i!=s.length()-1)
                sp+=1;
            }
        }
        bool check=digit*low*cap*sp;
        if(check && s.length()>=10)
        {
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
}