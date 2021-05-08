#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 2e18;
int T;
ll n, ans;
int m, a[100];

ll pwl(ll k) {
	ll ans = 1;
	while (k) {
		k /= 10; ans *= 10;
	}
	return ans;
}

ll calc(ll v, int d) {
	ll ans = 0;
	for (int i = 1; i <= d; ++i) {
		ll w = pwl(v);
		if (ans > inf / w) return inf;
		ans = ans * pwl(v) + v;
		ans = min(ans, inf);
		++v;
	}
	return ans;
}

void solve(int d) {
	ll l = 0, r = 1e9;
	while (l != r) {
		ll mid = (l + r) >> 1;
		if (calc(mid, d) > n) r = mid;
		else l = mid + 1;
	}
	ans = min(ans, calc(l, d));
}

int main() {
	scanf("%d", &T);
	for (int cas = 1; cas <= T; ++cas) {
		scanf("%lld", &n); 
		m = 0; ans = 2e18;
		for (ll i = n; i; i /= 10)
			a[++m] = i % 10;
		for (int i = 2; i <= 18; ++i)
			solve(i);
		printf("Case #%d: %lld\n", cas, ans);
	}
}
