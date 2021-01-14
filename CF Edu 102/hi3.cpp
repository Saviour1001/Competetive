#include<bits/stdc++.h>
using namespace::std;
int main()
{
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
            
            string left=s.substr(0,l-1);
            string right=s.substr(r);
        
            string ans=left+right;
           
            for(int j=0;j<ans.length();j++)
            {
                if(ans[j]=='+')
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
            cout<<x.size()<<endl;
        }
        
        
    }
}