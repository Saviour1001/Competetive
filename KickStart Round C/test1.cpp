#include "bits/stdc++.h"
using namespace std;
#define int               long long
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define sz(x)             (int)((x).size())
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount
#define ppcll             __builtin_popcountll

template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.fr>>a.sc;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.fr<<" "<<a.sc;return out;}
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}

const long long INF=1e18;
const int32_t M=1e9+7;
const int32_t MM=998244353;

const int N=60;

int f(int a,int b,int rand_num){
	// hash the pair non-commutatively
	a += 489;
	a ^= 2309480;
	a *= 25;
	a += 123;
	a %= MM;
	a *= 34563;
	a %= M;
	return 17 + (rand_num * a + b) + a * a % M * b % MM + a * a % MM * a % M * (b + 23) % MM;
}

int evaluate(string s,int MOD,int rand_num){
	vector<pii> v;
	for(char c:s){
		if(c == '('){
			continue;
		}
		if(c == ')'){
			int b = v.back().sc;
			v.ppb();
			char o = v.back().sc;
			v.ppb();
			int a = v.back().sc;
			v.ppb();
			int res;
			if(o == '+'){
				res = (a + b) % MOD;
			}
			else if(o == '*'){
				res = (a * b) % MOD;
			}
			else{
				res = f(a,b,rand_num) % MOD;
			}
			v.pb({0,res});
			continue;
		}
		if(c >= '0' && c <= '9'){
			if(v.empty() || v.back().fr != 0){
				v.pb({0,0});
			}
			v.back().sc = (10 * v.back().sc + c - '0') % MOD;
			continue;
		}
		v.pb({1,c});
	}
	return v.back().sc;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
auto dist=uniform_int_distribution<int>(50,12433284);
auto dist2=uniform_int_distribution<int>(5e8,1e9);

void solve(int test){
	cout << "Case #" << test << ": ";
	int n;
	cin >> n;
	string s[n];
	rep(i,0,n){
		cin >> s[i];
	}
	array<int,20> val[n];
	vector<int> cls(n,0);
	rep(turn,0,20){
		int rand_num = dist(rng);
		int MOD = dist2(rng);
		rep(i,0,n){
			val[i][turn] = evaluate(s[i],MOD,rand_num);
		}
	}
	
	int cnt = 1;
	rep(i,0,n){
		if(!cls[i]){
			cls[i] = cnt++;
			rep(j,i+1,n){
				if(val[i] == val[j]){
					cls[j] = cls[i];
				}
			}
		}
		cout << cls[i] << " ";
	}
	
	
	cout << "\n";
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#ifdef SIEVE
		sieve();
	#endif
	#ifdef NCR
		init();
	#endif
	int t=1;
	cin>>t;
	rep(i,1,t+1) solve(i);
	return 0;
}
