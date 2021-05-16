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

bool checker(string a)
{
    int xcounter = 0;
    int ocounter = 0;
    for (int i = 0; i < 3; i++)
    {
        if (a[i] == 'X')
        {
            xcounter++;
        }
        if (a[i] == 'O')
        {
            ocounter++;
        }
    }
    return xcounter == 3 || ocounter == 3;
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
int main()
{
    flash;
    ll t;
    cin >> t;
    while (t--)
    {

        string vertical[3];
        string horizontal[3];
        bool winner = 0;
        int x = 0;
        int o = 0;
        for (int i = 0; i < 3; i++)
        {
            cin >> horizontal[i];
            for (int j = 0; j < 3; j++)
            {
                if (horizontal[i][j] == 'X')
                {
                    x++;
                }
                if (horizontal[i][j] == 'O')
                {
                    o++;
                }
            }
            vertical[i] = horizontal[i];
        }
        string diagonals[2];
        diagonals[0] = "OOO";
        diagonals[1] = "OOO";
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                vertical[j][i] = horizontal[i][j];
            }
        }
        diagonals[0] = string(1, horizontal[0][0]) + string(1, horizontal[1][1]) + string(1, horizontal[2][2]);
        diagonals[1] = string(1, horizontal[0][2]) + string(1, horizontal[1][1]) + string(1, horizontal[2][0]);
        int count_wins=0;
        for (int i = 0; i < 3; i++)
        {
            if(checker(horizontal[i]))count_wins++;
            if(checker(vertical[i]))count_wins++;
        }
        if (checker(diagonals[0]))
        {
            count_wins++;
        }
        if (checker(diagonals[1]))
        {
            count_wins++;
        }
        if(count_wins==1 && abs(x-o)<=1)
        {
            cout<<"1\n";
        }
        if(count_wins==0 && x+o==9 && abs(x-o)==1)
        {
            cout<<"1\n";
        }
        if(count_wins==0 && x+o<9 && abs(x-o)<=1)
        {
            cout<<"2\n";
        }
        if(count_wins>1 || abs(x-o)>1)
        {
            cout<<"3\n";
        }
    }
    return 0;
}