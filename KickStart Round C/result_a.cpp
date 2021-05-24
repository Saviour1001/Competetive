#include <bits/stdc++.h>  
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
double eps = 1e-12;
const int32_t M=1e9+7;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define flash ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
 

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




long long binpow(long long a, long long b,int MOD=M) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % MOD;
        a = a * a% MOD;
        b >>= 1;
    }
    return res;
}
int main()
{
    flash;
    ll t;
    cin >> t;
    for(int z=1;z<=t;z++)
    {
        // cout<<"Case #"<<z<<": ";
        int n,k;
        string s;
        cin>>n>>k>>s;

        int m=(n+1)/2;
        int ans=0;
        for(int i=0;i<m;i++)
        {
            char c=s[i];
            int d=(c-'a');
            ans = (ans+ d* binpow(k,m-1-i))% M;
            cout<<ans<<ln;
        }
        string t;
        forn(i,m)t.push_back(s[i]);
        forn(i,n-m)
        {
            t.push_back(s[n-m-i-1]);
        }
        if(t<s)ans++;
        ans = ans%M;
        cout<<ans<<ln;


    }
    return 0;
}