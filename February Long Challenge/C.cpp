//This Code killed me but it works !! 


#include <bits/stdc++.h>  
#include <string> 
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
//#ifndef ONLINE_JUDGE
//freopen("input.txt", "r", stdin);                       //Inputs
//freopen("output.txt", "w", stdout);
//#endif


/*const int N=1000001;
bool sieve[N];
memset(sieve,true,sizeof(sieve));                             //Sieve
for(int i=2;i*i<=N;i++)
{
   if(sieve[i])
    {
        for(int j=i*i;j<=N;j+=i)
        {
            sieve[j]=0;
        }
    }
}*/
    flash;
    ll t;
    cin >> t;
    ll b=t;
    while(t--)
    {
        string p;
        char input[8];
        if(t==b-1)
        cin.ignore();
        getline(cin,p);
        //cout<<p<<"---"<<ln;
        string hour=p.substr(0,2);
        stringstream inte(hour);
        int h,m;
        inte>>h;
        if(h==12)
        {
            h=0;
        }
        string min=p.substr(3,4);
        stringstream intm(min);
        intm>>m;
        if(p[6]=='P')
        {
            h+=12;
        }
        m=h*60+m;
        //cout<<m<<ln;
        int n;
        cin>>n;
        string ans="";
        
        for(int i=0;i<n;i++)
        {
            string l;
            if(i==0)
            cin.ignore();
            getline(cin,l);
            int hl,ml;
            //cout<<l<<"---"<<ln;
            
            string lh=l.substr(0,3);
            stringstream lhour(lh);
            lhour>>hl;
            if(hl==12)
            {
                hl=0;
            }
            if(l[6]=='P')
            {
                hl+=12;
            }
            //cout<<hl<<endl;
            string lm=l.substr(3,4);
            stringstream lmin(lm);
            lmin>>ml;
            ml=hl*60+ml;
            //cout<<ml<<ln;
            int hr,mr;
            //cout<<l[12]<<ln;
            string rh=l.substr(9,2);
            stringstream rhour(rh);
            rhour>>hr;
            if(hr==12)
            {
                hr=0;
            }
            if(l[15]=='P')
            {
                hr+=12;
            }
            string rm=l.substr(12,2);
            stringstream rmin(rm);
            rmin>>mr;
            mr=hr*60+mr;
            //cout<<mr<<ln;
            if(m>=ml && m<=mr)
            {
                ans=ans+"1";
            }
            else
            {
                ans+="0";
            }


        }
        cout<<ans<<ln;
    }
    return 0;
}