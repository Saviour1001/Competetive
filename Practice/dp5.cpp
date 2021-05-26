#include<bits/stdc++.h>
using namespace::std;

const long long N=101;
const long long W=100005;

long long dp[N][W];
bool visited[N][W];

long long n,c;
long long w[N],v[N];

long long calc(long position,long long capacity)
{
    if(position==n)
    {
        return 0;
    }
    if(visited[position][capacity])
    {
        return dp[position][capacity];
    }
    visited[position][capacity]=1;
    long long ans=0;
    //take
    if(capacity-w[position]>=0)
    ans=max(ans ,calc(position+1, capacity-w[position] ) + v[position]);
    //don't take
    ans=max(ans,calc(position+1,capacity));
    dp[position][capacity]=ans;
    return ans;

}

int main(){
    cin>>n>>c;
    for(int i=0;i<n;i++){
        cin>>w[i]>>v[i];
    }
    cout<<calc(0,c);

}