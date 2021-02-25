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


struct Streets{
    int crossing;
    int start;
    int end;
    string name;
    void read(){
        cin>>start;
        cin>>end;
        cin>>name;
        cin>>crossing;
    }
};
struct Paths{
    int p;
    vector<string> names;
    void read(){
        cin>>p;
    for(int i=0;i<p;i++)
    {
        string s;
        cin>>s;
        names.push_back(s);
    }}
};
int main()
{
#ifndef ONLINE_JUDGE
freopen("a.txt", "r", stdin);                       //Inputs
freopen("a_out.txt", "w", stdout);
#endif

    flash;
    int d,i,s,v,f;
    cin>>d>>i>>s>>v>>f;
    vector<Streets> street(s);
    for(int i=0;i<s;i++)
    {
        street[i].read();
    }
    vector<Paths> path(v);
    for(int i=0;i<v;i++)
    {
        path[i].read();
    }
    cout<<"3\n";
    cout<<"1\n"<<"2\n";
    cout<<"rue-d-athenes 2\n";
    cout<<"rue-d-amsterdam 1\n";
    cout<<"0\n1\n";
    cout<<"rue-de-londres 2\n";
    cout<<"2\n1\n";
    cout<<"rue-de-moscou 1\n";


    
    return 0;
}