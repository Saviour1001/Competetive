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
    int n;
    cin>>n;
    vector<int> nums(n);
    int one=0;
    int two=0;
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
        if(nums[i]==1)
        {
            one++;
        }
        if(nums[i]==2)
        {
            two++;
        }
    }
    if((one*1+two*2)%2==1)
    {
        cout<<"NO\n";
        return;
    }
    if(one%2==0 && two%2==0)
    {
        cout<<"YES\n";return;
    }
    if(one%2==1 && two%2==1)
    {
        cout<<"NO\n";return;
    }
    if(one==0 && two%2==1)
    {
        cout<<"NO\n";return;
    }
    if(two==0 && one%2==0)
    {
        cout<<"NO\n";return;
    }
    if(one/2==two%2)
    {
        cout<<"YES\n";
        return;
    }
    cout<<"NO\n";
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