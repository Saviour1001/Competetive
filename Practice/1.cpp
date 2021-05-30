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
const int N=0;


void solve(int test){
    int n,m;
    string s;
    cin>>n>>m>>s;
    string t=s;
    int a = min(n,m);
    // cout<<a<<ln;
    for(int i=0;i<a;i++)
    {
        // cout<<t<<ln;
        for(int j=1;j<s.length()-1;j++)
        {
            if(s[j]=='0' && s[j+1]=='1' && s[j-1]!='1')
            {
                t[j]='1';
                continue;
            }
            if(s[j]=='0' && s[j-1]=='1' && s[j+1]!='1')
            {
                t[j]='1';
        
                continue;
            }
        }
        if(s[0]=='0' && s[1]=='1')
        {
            t[0]='1';
        }
        if(s[s.length()-1]=='0' && s[s.length()-2]=='1')
        {
            t[n-1]='1';
        }
        s=t;
    }
    cout<<t<<ln;
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