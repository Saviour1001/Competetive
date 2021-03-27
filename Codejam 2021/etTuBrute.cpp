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


int checker(v32 nums)
{
    int counter=0;
    int n=nums.size();
        for(int i=0;i<n-1;i++)
        {
            int minNum=nums[i];
            int pos=i;
            for(int j=i;j<n;j++)
            {
                if(minNum>nums[j])
                {
                    minNum=nums[j];
                    pos=j;
                }
            }
            //cout<<"i= "<<i<<" "<<minNum<<" pos"<<pos<<ln;
            reverse(nums.begin()+i,nums.begin()+pos+1);
            counter+=pos-i+1;
            //forn(k,n)cout<<nums[k];
        }
        return counter;
}

ll power(ll a,ll b)
{ ll result=1;
 while(b>0)
  {
    if(b%2==1)result*=a;
    a*=a;
    b/=2;
   }return result;}

void display(v32 a, int n,int c, bool &flag)
{
    if(checker(a)==c && flag==0)
    {
        forn(i,n)cout<<a[i]<<" ";
        flag=1;
    }
}
  
// Function to find the permutations
void findPermutations(v32 a, int n,int c,bool &flag)
{
  
    // Sort the given array
    //sort(a.begin(),a.end());
    do {
        display(a, n,c,flag);
    } while (next_permutation(a.begin(),a.end()) && flag==0);
}

int main()
{
    flash;
    ll t;
    cin >> t;
    for(int z=1;z<=t;z++)
    {
        int n,c;
        cout<<"Case #"<<z<<": ";
        cin>>n>>c;
        v32 nums(n);
        forn(i,n)nums[i]=i+1;
        int i=0;
        bool flag=0;
        findPermutations(nums,nums.size(),c,flag);
        if(flag==0)
        {
            cout<<"IMPOSSIBLE";
        }
        cout<<ln;
    }
    return 0;
}