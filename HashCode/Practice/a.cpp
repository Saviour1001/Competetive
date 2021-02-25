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


struct Pizza{
    int id;
    vector<string> ings;
    void read(int _id){
    id=_id;
    int cnt;
    cin>>cnt;
    for(int i=0;i<cnt;i++)
    {
        string s;
        cin>>s;
        ings.push_back(s);
    }
    }

};

int main()
{
#ifndef ONLINE_JUDGE
freopen("c_example.txt", "r", stdin);                       //Inputs
freopen("c_output.txt", "w", stdout);
#endif

    flash;
    int m;
    cin>>m;
    int t[5]={0};
    for(int i=2;i<=4;i++)
    {
        cin>>t[i];
    }
    vector<Pizza> pizzas(m);
    for(int i=0;i<m;i++)
    {
        pizzas[i].read(i);
    }
    vv32 output;
    for(int s=4;s>=2;s--)
    {
        if(pizzas.size()>=s){
            v32 delivery;
            for(int rep=0;rep<s;rep++)
            {
                delivery.push_back(pizzas.back().id);
                pizzas.pop_back();
            }
            output.push_back(delivery);
            
        }
    }
    cout<<output.size()<<ln;
    for(v32 delivery : output){
        cout<<delivery.size();
        for(int id:delivery)
        {
            cout<<" "<<id;
        }
        cout<<"\n";
    }
    
    
    return 0;
}