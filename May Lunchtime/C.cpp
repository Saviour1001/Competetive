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

vector<bool> segmentedSieve(long long L, long long R) {      //Generates primes between L,R             
 long long lim = sqrt(R);
 vector<bool> mark(lim + 1, false);
vector<long long> primes;
 for (long long i = 2; i <= lim; ++i) {
 if (!mark[i]) {
 primes.emplace_back(i);
for (long long j = i * i; j <= lim; j += i)
mark[j] = true;
}
}
vector<bool> isPrime(R - L + 1, true);
for (long long i : primes)
for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
isPrime[j - L] = false;
if (L == 1)
isPrime[0] = false;
return isPrime;
}

vector<bool> primes=segmentedSieve(0,1e7);


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
    vector<int> dp(1e7);
    dp[0]=0;
    for(int i=1;i<=1e7;i++)
    {
        if(primes[i]==1)
        {
            dp[i]=dp[i-1]+1;
        }
        else
        dp[i]=dp[i-1];
    }
    rep(i,1,t+1){
        int n;
        cin>>n;
        if(n==1)
        {
            cout<<1<<ln;
        }
        else if(n==2)
        {
            cout<<1<<ln;
        }
        else if(n==3)
        {
            cout<<2<<ln;
        }
        else
        cout<<1+dp[n]-dp[n/2]<<ln;
    }
    return 0;
}