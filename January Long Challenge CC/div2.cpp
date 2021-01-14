#include<bits/stdc++.h>
using namespace::std;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    int n;
    string s;
    cin>>t;
    string alphabets="abcdefghijklmnop";
    while(t--)
    {
        cin>>n>>s;
        int characters=n/4;
        
        for(int i=0;i<characters;i++)
        {
            string answer="";
            string alphabets="abcdefghijklmnop";
            for(int j=i*4;j<(i+1)*4;j++)
            {
                if(s[j]=='0')
                {
                    alphabets=alphabets.substr(0,alphabets.length()/2);
                }
                else
                {
                    alphabets=alphabets.substr(alphabets.length()/2);
                }
                
            }
            cout<<alphabets;

        }
        cout<<"\n";
    }
}