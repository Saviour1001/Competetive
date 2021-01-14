#include<bits/stdc++.h>
using namespace::std;
#define ll long long 
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t,n;
    cin>>t;
    while(t--)
    {
        ll k,d;
        cin>>n>>k>>d;
        ll arr[n];
        ll sum=0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            sum+=arr[i];
        }
        ll days=sum/k;
        ll answer=min(days,d);
        cout<<answer<<"\n";

    }
    return 0;
}