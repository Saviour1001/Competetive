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
#define deb(x) cout << #x << " " << x<<ln;


template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.fr>>a.sc;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.fr<<" "<<a.sc;return out;}
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}
const long long INF=1e18;
const int32_t M=1e9+7;
const int32_t MM=998244353;
const int N=0;


void solve(int test){
    int n,m;
    cin>>n>>m;
    vector<int> trains(n);
    vector<int> pass(m);
    for(auto &x:trains)cin>>x;
    for(auto &x:pass)cin>>x;
    vector<int> ones(n);
    vector<int> twos(n);
    int pos=-1;
    if(trains[0]==1)
    pos=0;
    for(int i=1;i<n;i++)
    {
        if(pos>=0)
        {
            ones[i]=i-pos;
        }
        else
        {
            ones[i]=0;
        }
        if(trains[i]==1)
        {
            pos=i;
            continue;
        }
        
    }
    int pos2=-1;
    if(trains[n-1]==2)
    pos2=n-1;
    for(int i=n-2;i>0;i--)
    {
        if(pos2>=0)
        {
            twos[i]=pos2-i;
        }
        else
        {
            twos[i]=0;
        }
        if(trains[i]==2)
        {
            pos2=i;
            continue;
        }
        
    }
    
    // for(auto x:ones)cout<<x<<" ";cout<<ln;
    // for(auto x:twos)cout<<x<<" ";cout<<ln;
    vector<int> ans(n);
    for(int i=0;i<n;i++)
    {
        if(ones[i]>0 && twos[i]<=0)
        {
            ans[i]=ones[i];
        }
        if(ones[i]<=0 && twos[i]>0)
        {
            ans[i]=twos[i];
        }
        if(ones[i]>0 && twos[i]>0)
        {
            ans[i]=min(ones[i],twos[i]);
        }
    }
    // for(auto x:ans)cout<<x<<" ";cout<<ln;
    for(int i=0;i<m;i++)
    {
        if(pass[i]==1)
        {
            cout<<"0 ";
            continue;
        }
        if(ans[pass[i]-1]==0)
        cout<<"-1 ";
        else
        cout<<ans[pass[i]-1]<<" ";
    }
    cout<<ln;

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
    cin>>t;
    rep(i,1,t+1) solve(i);
    return 0;
}

        // 1 0 0 2 0
        // 0 1 2 3 4
        // 3 2 1 0 4
