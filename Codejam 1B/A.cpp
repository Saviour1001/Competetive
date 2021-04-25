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


float possible(float hour, float minutes) {
    if (hour >= 12) {
        hour -= 12;
    }
    float aph = 360.0 / 12.0;
    float apm = aph / 60.0;
    float lh = apm * minutes + aph * hour;
    apm = 360.0 / 60.0;
    float sm = apm * minutes;
    return min(abs(lh - sm), 360 - abs(lh - sm));
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
        //cout<<"Case #"<<z<<": ";
        ld a,b,c;
        cin>>a>>b>>c;
        ld angle_a = a /(10000000000 *12);
        ld angle_b = b /(10000000000 *12);
        ld angle_c = c /(10000000000 *12);

        float hand_a,hand_b,hand_c;
        cout<<angle_a<<" "<<angle_b<<" "<<angle_c<<ln;

        hand_a = (angle_a/6)/5;
        hand_b = (angle_b/6)/5;
        hand_c = (angle_c/6)/5;
        cout<<hand_a<<" "<<hand_b<<" "<<hand_c<<ln;

        float h[6];
        float m[6];
        float s[6];
        h[0] = hand_a;
        m[0] = hand_b*5;
        s[0] = hand_c/6;

        h[1] = hand_a;
        m[1] = hand_c*5;
        s[1] = hand_b/6;

        h[2] = hand_b;
        m[2] = hand_a*5;
        s[2] = hand_c/6;

        h[3] = hand_b;
        m[3] = hand_c*5;
        s[3] = hand_a/6;

        h[4] = hand_c;
        m[4] = hand_a*5;
        s[4] = hand_b/6;

        h[5] = hand_c;
        m[5] = hand_b*5;
        s[5] = hand_a/6;

        float diff_1 = abs(angle_a-angle_b);
        float diff_2 = abs(angle_a-angle_c);
        float diff_3 = abs(angle_b-angle_c);

        cout<<diff_1<<" "<<diff_2<<" "<<diff_3<<ln;
        bool flag= 0;
        for(int i=0;i<6;i++)
        {
            //cout<<possible(h[i],m[i])<<ln;
            //cout<<h[i]<<" "<<m[i]<<ln;
            if(possible(h[i],m[i])==diff_1 || possible(h[i],m[i])==diff_2 || possible(h[i],m[i])==diff_3)
            {
                cout<<h[i]<<" "<<m[i]<<" "<<s[i]<<" 0"<<ln;
                flag =1;
                break;

            }
        }
        // if(flag==0)
        // {
        //     cout<<"yo";
        // }
        //cout<<"The angle "<<possible(6,30)<<ln;
    }
    return 0;
}