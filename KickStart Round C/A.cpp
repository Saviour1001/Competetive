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

bool palidrome(string s)
{
    bool flag=1;
    ll lhs=0;
    ll rhs=s.length()-1;
    while(lhs<rhs)
    {
        if(s[lhs]!=s[rhs])
        {
            flag=0;
            break;
        }
        lhs++;
        rhs--;
    }
    return flag;
}

void printAllKLengthRec(string set, string prefix,int n, int k,string s,ll &counter)
{
     
    // Base case: k is 0,
    // print prefix
    if (k == 0)
    {
        if(prefix<s && palidrome(prefix))
        {
            // cout<<prefix<<ln;
            counter++;
        }
        return;
    }
 
    // One by one add all characters
    // from set and recursively
    // call for k equals to k-1
    for (int i = 0; i < n; i++)
    {
        string newPrefix;
         
        // Next character of input added
        newPrefix = prefix + set[i];
         
        // k is decreased, because
        // we have added a new character
        printAllKLengthRec(set, newPrefix, n, k - 1,s,counter);
    }
 
}

long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
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
        cout<<"Case #"<<z<<": ";
        string s;
        ll n,k;
        cin>>n>>k>>s;
        string alpha="abcdefghijklmnopqrstuvwxyz";
        ll counter=0;
        printAllKLengthRec(alpha,"",k,n,s,counter);
        cout<<counter<<ln;
    }
    return 0;
}