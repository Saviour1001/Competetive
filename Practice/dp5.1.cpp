#include "bits/stdc++.h"
using namespace std;
#define int               long long
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define sz(x)             (int)((x).size())
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount
#define ppcll             __builtin_popcountll
#define ln "\n"


template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.fr>>a.sc;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.fr<<" "<<a.sc;return out;}
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}
const long long INF=1e18;
const int32_t M=1e9+7;
const int32_t MM=998244353;
const int N=101;
const long long W=100005;

int dp[N][W];
bool visited[N][W];

int n,c;
int w[N],v[N];

int calc(int position,int capacity)
{
    if(position==n)
    {
        return 0;
    }
    if(visited[position][capacity])
    return dp[position][capacity];
    
    visited[position][capacity]=1;
    int ans=0;
    if(capacity-w[position]>=0)
    {
        ans=max(ans,calc(position+1,capacity-w[position])+v[position]);
    }
    ans=max(ans,calc(position+1,capacity));
    dp[position][capacity]=ans;
    return ans;
}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #ifdef SIEVE
    sieve();
    #endif
    #ifdef NCR
    init();
    #endif
    int t=1;
    cin>>n>>c;
    for(int i=0;i<n;i++){
        cin>>w[i]>>v[i];
    }
    cout<<calc(0,c);
    return 0;
}