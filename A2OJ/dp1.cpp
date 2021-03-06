#include<bits/stdc++.h>
using namespace::std;

const int N=100005;

int dp[N];
bool visited[N];

int n;
int heights[N];

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
    visited[position]=1;
    long long ans=INT_MAX;
    if(position+1<=n-1)
    {
        int a=heights[position]-heights[position+1];
        ans=min(ans,calc(position+1)+abs(a));
        //cout<<position<<" "<<ans<<"\n";
    }
    if(position+2<=n-1)
    {
        int a=heights[position]-heights[position+2];
        ans=min(ans,calc(position+2)+abs(a));
        //cout<<position<<" "<<ans<<"\n";
    }
    dp[position]=ans;
    return ans;
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>heights[i];
    }
    cout<<calc(0);
}
