#include<bits/stdc++.h>
using namespace::std;
vector<int> solve(int n) {
    long long spf[n+100]={0};
    for(long long i=2;i<=n;i++)
    {
        spf[i]=i;
    } 
    for(long long i=2;i<=n;i++)
    {
        if(spf[i]==i)
        {
            for(long long j=i*i;j<=n;j+=i)
            {
                if(spf[j]==j)
                {
                    spf[j]=i;
                }
            }
        }
    }
    vector<int> ans;
    while(n!=1)
    {
        ans.push_back(spf[n]);
        n=n/spf[n];
    }
    return ans;
}
int main()
{
    long long n;
    cin>>n;
    vector<int> prime=solve(n);
    for(int i=0;i<prime.size();i++)
    {
        cout<<prime[i]<<" ";
    }
    return 0;
}