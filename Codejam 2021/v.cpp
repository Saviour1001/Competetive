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
 



int checker(v32 nums)
{
    int counter=0;
    int n=nums.size();
        for(int i=0;i<n-1;i++)
        {
            int minNum=nums[i];
            int pos=i;
            for(int j=i;j<n;j++)
            {
                if(minNum>nums[j])
                {
                    minNum=nums[j];
                    pos=j;
                }
            }
            reverse(nums.begin()+i,nums.begin()+pos+1);
            counter+=pos-i+1;
        }
        return counter;
}

void display(v32 a, int n,int c, bool &flag)
{
    if(checker(a)==c && flag==0)
    {
        forn(i,n)cout<<a[i]<<" ";
        cout<<ln;
        flag=1;
    }
}
  
void findPermutations(v32 a, int n,int c,bool &flag)
{
    int count =0;
    if(!flag){
        sort(a.begin(),a.end());
        do {
            display(a, n,c,flag);
            count++;
        } while (next_permutation(a.begin(),a.end()) && flag==0);
    }
}

int main()
{
    flash;
    ll t;
    cin >> t;
    for(int z=1;z<=t;z++)
    {
        int n,c;
        //cout<<"Case #"<<z<<": ";
        //cin>>n>>c;
        n = 10,c=9;
        v32 nums(n);
        forn(i,n)nums[i]=i+1;
        int i=n-1;
        bool flag=0;
        cout<<"cost=> "<<c;
        cout<<"\n";
        findPermutations(nums,nums.size(),c,flag);
        while(flag == 1){
            c++;
            flag=0;
            cout<<"cost=> "<<c;
            cout<<"\n";
            findPermutations(nums,nums.size(),c,flag);
        }
        if(flag==0)
        {
            cout<<"IMPOSSIBLE";
        }
        cout<<ln;
    }
    return 0;
}