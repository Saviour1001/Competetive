#include<bits/stdc++.h>
using namespace::std;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        string s;
        cin>>s;
        
        
        for(int i=0;i<m;i++)
        {
            int yo=0;
            int l,r;
            set<int> x;
            x.insert(yo);
            cin>>l>>r;
            for(int i=0;i<n;i++)
            {
                if(i<l-1 || i>=r)
                {
                    if(s[i]=='+')
                {
                    yo+=1;
                   
                    x.insert(yo);
                }
                else
                {
                    yo-=1;
                   
                    x.insert(yo);
                }
                }
            }
            cout<<x.size()<<endl;
        }
        
        
    }
}