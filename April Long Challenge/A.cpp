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




ll power(ll a,ll b)
{ ll result=1;
 while(b>0)
  {
    if(b%2==1)result*=a;
    a*=a;
    b/=2;
   }return result;}

   float rounder(float var)
{
    // 37.66666 * 100 =3766.66
    // 3766.66 + .5 =3767.16    for rounding off value
    // then type cast to int so value is 3767
    // then divided by 100 so the value converted into 37.67
    float value = (int)(var * 100 + .5);
    return (float)value / 100;
}
int main()
{
    flash;

    
    ll t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll levels=0;

        if(n/4>=2 && n%4==0)
        levels=n/4-1;
        
        if(n/4>=2 && n%4)
        {
            levels=n/4;
        }
        if(n/4==1 && n%4)
        {
            levels=1;
        }
        ll top_level=n%4;
        ll pips=0;
        pips+=levels*44;
        if(top_level==0)
        {
            pips+=60;
        }
        if(top_level==1)
        {
            pips+=20;
            if(levels>=1)
            {
                pips+=12;
            }
        }
        if(top_level==2)
        {
            pips+=36;
            if(levels>=1)
            {
                pips+=8;
            }
        }
        if(top_level==3)
        {
            pips+=51;
            if(levels>=1)
            {
                pips+=4;
            }
        }
        cout<<pips<<ln;
    }
    return 0;
}

        // n=4 =>60;
        // n=3 =>51;
        // n=2 =>36;
        // n=1 => 20;
        //cout<<levels;
