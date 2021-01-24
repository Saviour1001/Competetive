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
    return s;
}
int main()
{
    const int N=1000001;
    int counter=0;
    vector<ll> ans=primeSeive();
    int count[N]={0};
    for(int i=5;i<N;i++)
    {
        if(ans[i]==0 && ans[i-2]==0)
        {
            counter++;
        }count[i]=counter;

    }
    ll t;

    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        cout<<count[n]<<"\n";
    }
    
    return 0;
}