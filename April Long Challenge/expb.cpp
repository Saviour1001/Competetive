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

int main()
{
    flash;
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m, k;
        cin >> n >> m >> k;
        int N = n;
        int M = m;
        int arr[n][m] = {0};
        int counter = 0;
        forn(i, n)
        {
            forn(j, m)
            {
                cin >> arr[i][j];
                if (arr[i][j] >= k)
                    counter++;
            }
        }
        int pref[N][M];
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                pref[i][j] = arr[i][j];
                if (i > 0)
                    pref[i][j] += pref[i - 1][j];
                if (j > 0)
                    pref[i][j] += pref[i][j - 1];
                if (i > 0 && j > 0)
                    pref[i][j] -= pref[i - 1][j - 1];
            }
        }
        int l = 1;
        while (l < n && l < m)
        {
            int i = 0;
            int j = 0;
            while (i + l < n)
            {
                while (j + l < m)
                {
                    //cout << i << " " << j << ln;
                    ll sum = pref[i + l][j + l];
                    if (j > 0)
                        sum -= pref[i + l][j - 1];
                    if (i > 0)
                        sum -= pref[i - 1][j + l];
                    if (i > 0 && j > 0)
                        sum += pref[i - 1][j - 1];
                    //cout << "sum=> " << sum << ln;
                    if (sum / ((l+1) * (l+1)) >= k)
                        counter++;
                    j++;
                }
                i++;
                j=0;
            }
            l++;
        }
        cout<<counter<<ln;
    }
    return 0;
}