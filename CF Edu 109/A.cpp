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



int main()
{
    int arr[100];
    arr[0]=1;
    arr[100]=1
    flash;
    ll t;
    cin >> t;
    while(t--)
    {
        float k;
        cin>>k;
        float e=1;
        float w=1;
        if(k==100 || k==0)
        {
            cout<<"1\n";
            continue;
        }
        if(k==50)
        {
            cout<<"2\n";
            continue;
        }
        float ratio =(float)(e/(e+w))*100;
        ll counter=2;
        // cout<<k<<ln;
        while(ratio!=k)
        {
            // cout<<ratio<<" "<<counter<<ln;
            // if(counter==100)
            // {
            //     break;
            // }
            if(ratio>k)
            {
                w++;
                counter++;
                ratio = (float)(e/(e+w))*100;
                continue;
            }
            if(ratio<k)
            {
                e++;
                counter++;
                ratio = (float)(e/(e+w))*100;
            }
            
        }
        float water =  (float)(w/(e+w))*100;
        // cout<<setprecision(10)<<ratio<<" "<<water<<ln;
        cout<<counter<<ln;

    }
    return 0;
}