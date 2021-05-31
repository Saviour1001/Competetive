#include "bits/stdc++.h"
using namespace std;
#define int long long
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define all(x) (x).begin(), (x).end()
#define uniq(v) (v).erase(unique(all(v)), (v).end())
#define sz(x) (int)((x).size())
#define fr first
#define sc second
#define pii pair<int, int>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define mem1(a) memset(a, -1, sizeof(a))
#define mem0(a) memset(a, 0, sizeof(a))
#define ppc __builtin_popcount
#define ppcll __builtin_popcountll
#define ln "\n"

template <typename T1, typename T2>
istream &operator>>(istream &in, pair<T1, T2> &a)
{
    in >> a.fr >> a.sc;
    return in;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &out, pair<T1, T2> a)
{
    out << a.fr << " " << a.sc;
    return out;
}
template <typename T, typename T1>
T amax(T &a, T1 b)
{
    if (b > a)
        a = b;
    return a;
}
template <typename T, typename T1>
T amin(T &a, T1 b)
{
    if (b < a)
        a = b;
    return a;
}
const long long INF = 1e18;
const int32_t M = 1e9 + 7;
const int32_t MM = 998244353;
const int N = 0;

void solve(int test)
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int ch[k];
    for (auto &x : ch)
        cin >> x;
    int dist = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == s[i + 1])
        {
            dist += 2;
        }
        else
        {
            dist += 1;
        }
    }
    // cout<<dist<<ln;

    for (int i = 0; i < k; i++)
    {
        int a = ch[i] - 1;
        // cout<<a<<" ";
        if (a == 0 && a + 1 < n && s[a] != s[a + 1])
        {
            dist += 1;
            s[a] = s[a + 1];
            goto start;
        }
        else if (a == 0 && a + 1 < n && s[a] == s[a + 1])
        {
            dist -= 1;
            if (s[a] == '0')
                s[a] = '1';
            else if (s[a] == '1')
                s[a] = '0';
            goto start;
        }
        else if (a == n - 1 && a - 1 >= 0 && s[a] != s[a - 1])
        {
            dist += 1;
            s[a] = s[a - 1];
            goto start;
        }
        else if (a == n - 1 && a - 1 >= 0 && s[a] == s[a - 1])
        {
            dist -= 1;
            if (s[a] == '0')
                s[a] = '1';
            else if (s[a] == '1')
                s[a] = '0';
            goto start;
        }
        else if (a + 1 < n && a - 1 >= 0)
        {
            if (s[a] == s[a - 1] && s[a] == s[a + 1] )
            {
                dist -= 2;
                // cout << "yo\n";
                if (s[a] == '0')
                    s[a] = '1';
                else if (s[a] == '1')
                    s[a] = '0';
                goto start;
            }

            if (s[a] != s[a - 1] && s[a] != s[a + 1])
            {
                dist += 2;
                if (s[a] == '0')
                    s[a] = '1';
                else if (s[a] == '1')
                    s[a] = '0';
                goto start;
            }
            if (s[a] != s[a - 1] && s[a] == s[a + 1] )
            {
                if (s[a] == '0')
                    s[a] = '1';
                else if (s[a] == '1')
                    s[a] = '0';
                goto start;
            }
            if (s[a] == s[a - 1] && s[a] != s[a + 1] )
            {
                if (s[a] == '0')
                    s[a] = '1';
                else if (s[a] == '1')
                    s[a] = '0';
                goto start;
            }
        }
    start:
        // cout<<s<<ln;
        cout << dist << ln;
    }
    // cout<<s;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
#ifdef SIEVE
    sieve();
#endif
#ifdef NCR
    init();
#endif
    int t = 1;
    cin >> t;
    rep(i, 1, t + 1) solve(i);
    return 0;
}