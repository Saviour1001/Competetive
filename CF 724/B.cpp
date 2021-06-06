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
#define ln "\n"
#define deb(x) cout << #x << " " << x<<ln;


template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.fr>>a.sc;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.fr<<" "<<a.sc;return out;}
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}
const long long INF=1e18;
const int32_t M=1e9+7;
const int32_t MM=998244353;
const int N=0;

int isSubstring(string s1, string s2)
{
    int M = s1.length();
    int N = s2.length();
 
    /* A loop to slide pat[] one by one */
    for (int i = 0; i <= N - M; i++) {
        int j;
 
        /* For current index i, check for
 pattern match */
        for (j = 0; j < M; j++)
            if (s2[i + j] != s1[j])
                break;
 
        if (j == M)
            return i;
    }
 
    return -1;
}

void solve(int test){
    int n;
    cin>>n;
    string s;
    cin>>s;
    string alpha = "abcdefghijklmnopqrstuvwxyz";
    string ch="a";
    int x=1;
    int y=0;
    int i=1;
    while(true)
    {
        // if(isSubstring(ch,s)!=-1)
        {
            ch.pop_back();
            ch+=alpha[i];
            i++;
            if(i==27)
            {
                i=0;
                x++;
                ch="";
                // for(int i=0;i<y;i++)
                    if(y==0 && x>=3){y=0;}
                    for(int j=0;j<x;j++)
                    ch+=alpha[y];
                    if(y==25)
                    {
                        y=0;
                        ch=ch.substr(26);
                    }
                    else
                    {y++;
                    ch = ch.substr(y);}
                ch+="a";
            }
        }
        // else
        {
            cout<<ch<<ln;
            // break;
        }
        if(x==1000)break;
    }
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