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
 

void solve(){
    
}
int main()
{
//#ifndef ONLINE_JUDGE
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
//#endif
    flash;
    const int N=1000001;
    bool sieve[N];
    memset(sieve,true,sizeof(sieve));
    for(int i=2;i*i<=N;i++)
    {
        if(sieve[i])
        {
            for(int j=i*i;j<=N;j+=i)
            {
                sieve[j]=0;
            }
        }
    }
    int counter=0;
    int ans[N]={0};
    for(int i=5;i<N;i++)
    {
        if(sieve[i] && sieve[i-2])
        {
            counter++;
        }
        ans[i]=counter;
    }
    ll t;
    cin >> t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<ans[n]<<ln;
    }
    return 0;
}