#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> p32;
typedef pair<ll, ll> p64;
typedef pair<double, double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int>> vv32;
typedef vector<vector<ll>> vv64;
typedef vector<vector<p64>> vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i, e) for (ll i = 0; i < e; i++)
#define forsn(i, s, e) for (ll i = s; i < e; i++)
#define rforn(i, s) for (ll i = s; i >= 0; i--)
#define rforsn(i, s, e) for (ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout << #x << " = " << x << ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define flash                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

vector<bool> segmentedSieve(long long L, long long R)
{ //Generates primes between L,R
    long long lim = sqrt(R);
    vector<bool> mark(lim + 1, false);
    vector<long long> primes;
    for (long long i = 2; i <= lim; ++i)
    {
        if (!mark[i])
        {
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

long long binpow(long long a, long long b)
{
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
bool pal_checker(string s)
{
    bool flag = 1;
    int lhs = 0;
    int rhs = s.length() - 1;
    while (lhs < rhs)
    {
        if (s[lhs] != s[rhs])
        {
            flag = 0;
            break;
        }
        lhs++;
        rhs--;
    }
    return flag;
}
string pal_maker(string s, ll a, ll b, ll q)
{
    // cout<<q<<ln;

    int lhs = 0;
    int rhs = s.length() - 1;
    while (lhs <= rhs)
    {
        if (s[lhs] == '0' && s[rhs] == '?' && a > 0 && q > 0)
        {
            s[rhs] = '0';
            a--;
            q--;
            continue;
        }
        if (s[rhs] == '0' && s[lhs] == '?' && a > 0 && q > 0)
        {
            s[lhs] = '0';
            a--;
            q--;
            continue;
        }
        if (s[lhs] == '1' && s[rhs] == '?' && b > 0 && q > 0)
        {
            s[rhs] = '1';
            b--;
            q--;
            continue;
        }
        if (s[rhs] == '1' && s[lhs] == '?' && b > 0 && q > 0)
        {

            s[lhs] = '1';
            b--;
            q--;

            continue;
        }
        if (lhs == rhs && q > 0 && s[lhs]=='?')
        {
            if (a > 0)
            {
            // cout<<"="<<q<<ln;
                s[lhs] = '0';
                a--;
                q--;
            // cout<<"="<<q<<ln;
                continue;
            }
            else if (b > 0)
            {
                s[lhs] = '1';
                b--;
                q--;
                continue;
            }
        }
        if (s[rhs] == '?' && s[lhs] == '?' && q >= 2)
        {
            if (a >= 2)
            {
                s[rhs] = '0';
                s[lhs] = '0';
                a -= 2;
                q -= 2;
                continue;
            }
            if (b >= 2)
            {
                s[rhs] = '1';
                s[lhs] = '1';
                b -= 2;
                q -= 2;
            }
        }
        lhs++;
        rhs--;
    }
    // cout<<"a"<<a<<" b"<<b<<ln;
    if (a == 0 && b == 0 && q == 0)
    {
        return s;
    }
    else
        return "-1";
}
int main()
{
    flash;
    ll t;
    cin >> t;
    while (t--)
    {
        ll a, b;
        cin >> a >> b;
        string s;
        cin >> s;
        ll zero = 0;
        ll one = 0;
        ll q = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '0')
                zero++;
            if (s[i] == '1')
                one++;
            if (s[i] == '?')
                q++;
        }
        if (a == zero && b == one && q == 0)
        {
            if (pal_checker(s))
            {
                cout << s << ln;
            }
            else
            {
                cout << "-1\n";
            }
        }
        else
        {
            int a_diff = a - zero;
            int b_diff = b - one;
            // cout<<b_diff;
            // cout<<b_diff<<ln;
            // if(a_diff==0)
            // {
            //     for(int i=0;i<s.length();i++)
            //     {
            //         if(s[i]=='?')
            //         {
            //             s[i]='0';
            //         }
            //     }
            //     if(pal_checker(s))
            //     {
            //         cout<<s;
            //     }else
            //     cout<<"-1\n";
            //     continue;
            // }
            // if(b_diff==0)
            // {
            //     for(int i=0;i<s.length();i++)
            //     {
            //         if(s[i]=='?')
            //         {
            //             s[i]='1';
            //         }
            //     }
            //     if(pal_checker(s))
            //     {
            //         cout<<s;
            //     }else
            //     cout<<"-1\n";
            //     continue;
            // }
            string ans = pal_maker(s, a_diff, b_diff, q);
            cout << ans << ln;
        }
    }
    return 0;
}