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
const ll row=300;
const ll column=300;

ll changer(vv32& arr,ll x,ll y,ll r,ll c)
{
    ll counter=0;
    if(x+1<r)
    {
        if(abs(arr[x+1][y]-arr[x][y])>1)
        {
            arr[x+1][y]=arr[x][y]-1;
            counter+=(arr[x][y]-1-arr[x+1][y]);
        }
    }
    if(y+1<c)
    {
        if(abs(arr[x][y+1]-arr[x][y])>1)
        {
            arr[x][y+1]=arr[x][y]-1;
            counter+=(arr[x][y]-1-arr[x][y+1]);
        }
    }
    if(x-1>=0)
    {
        if(abs(arr[x-1][y]-arr[x][y])>1)
        {
            arr[x-1][y]=arr[x][y]-1;
            counter+=(arr[x][y]-1-arr[x-1][y]);
        }
    }
    if(y-1>=0)
    {
        if(abs(arr[x][y-1]-arr[x][y])>1)
        {
            arr[x][y-1]=arr[x][y]-1;
            counter+=(arr[x][y]-1-arr[x][y-1]);
        }
    }
    return counter+changer(arr,x+1,y,r,c)+changer(arr,x,y+1,r,c)+changer(arr,x-1,y,r,c)+changer(arr,x,y-1,r,c);
} 

int main()
{
    
    ll t;
    cin >> t;
    for(int z=1;z<=t;z++)
    {
        cout<<"Case #"<<z<<": ";
        ll r,c;
        cin>>r>>c;
        //cout<<"Works till here\n";
        ll max_box=0;
        vv32 arr(r);
        ll max_i,max_j;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                int temp;
                cin>>temp;
                arr[i].push_back(temp);
                if(arr[i][j]>max_box)
                {
                    max_box=arr[i][j];
                    max_i=i;
                    max_j=j;
                }
            }
        }
        ll counter=changer(arr,max_i,max_j,r,c);
        cout<<"yo";
        cout<<counter<<"yoo"<<ln;

    }
    return 0;
}