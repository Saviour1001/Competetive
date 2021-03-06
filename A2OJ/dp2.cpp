#include<bits/stdc++.h>
using namespace::std;

const int N=100005;
const int K=101;

int k;

long long dp[N];
bool visited[N];
long long heights[N];
int n;

long long calc(int position)
{
    if(position==n-1)
    {
        return 0;
    }
    if(visited[position])
    {
        return dp[position];
    }
    long long ans=INT_MAX;
    visited[position]=1;
    for(int i=1;i<=k;i++)
    {
        if(position+i<=n-1)
        {
            ans=min(ans,calc(position+i)+abs(heights[position]-heights[position+i]));
        }
    }
    dp[position]=ans;
    return ans;
}

int main()
{
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>heights[i];
    }
    cout<<calc(0);
}