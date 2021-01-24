#include<bits/stdc++.h>
using namespace::std;
#define ll long long 
vector<ll> primeSeive(ll n=1000000)
{
    vector<ll> s(n,0);
    for(ll i=2;i<=n;i++)
    {
        if(s[i]==0)
        {
            for(ll j=i*i;j<=n;j+=i)
            {
                s[j]=1;
            }
        }
    }
    vector<ll> prime;
    for(ll i=2;i<=n;i++)
    {
        if(s[i]==0)
        {
            prime.push_back(i);
        }
    }
    return prime;
}
int main()
{
    
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        vector<ll> ans=primeSeive();
        //cout<<ans.size();
        /*if(ans.size()<3)
        {
            cout<<"0\n";
            continue;
        }
        if(ans.size()==3)
        {
            cout<<"1\n";
            continue;
        }
        int counter=0;
        cout<<ans.size();*/
        for(int i=0;i<ans.size();i++)
        {
            cout<<ans[i]<<" ";
            /*for(int j=i+1;j<ans.size();j++)
            {
                
                int sum=ans[i]+ans[j];
                if(binary_search(ans.begin(),ans.end(),sum))
                {
                    counter+=1;
                }
            }
            cout<<"yo"<<endl;*/
        }
        //cout<<counter<<"\n";
    }
    return 0;
}