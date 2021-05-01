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


int isConsecutive(string str)
{
    // variable to store starting number
    int start;
  
    // length of the input string
    int length = str.size();
  
    // find the number till half of the string
    for (int i = 0; i < length / 2; i++) {
  
        // new string containing the starting
        // substring of input string
        string new_str = str.substr(0, i + 1);
  
        // converting starting substring into number
        int num = atoi(new_str.c_str());
  
        // backing up the starting number in start
        start = num;
  
        // while loop until the new_string is 
        // smaller than input string
        while (new_str.size() < length) {
  
            // next number
            num++;
  
            // concatenate the next number
            new_str = new_str + to_string(num);
        }
  
        // check if new string becomes equal to
        // input string
        if (new_str == str) 
           return start;
    }
  
    // if string doesn't contains consecutive numbers
    return -1;
}

ll power(ll a,ll b)
{ ll result=1;
 while(b>0)
  {
    if(b%2==1)result*=a;
    a*=a;
    b/=2;
   }return result;}
int main()
{
    flash;
    ll t;
    cin >> t;
    for(int z=1;z<=t;z++)
    {
        cout<<"Case #"<<z<<": ";
        ll y;
        cin>>y;

        while(true)
        {
            y++;
            string s = to_string(y);
            if(isConsecutive(s)!=-1)
            {
                cout<<y<<ln;
                break;
            }
        }

        
    }
    return 0;
}
