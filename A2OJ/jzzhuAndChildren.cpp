#include<bits/stdc++.h>
using namespace::std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> arr(n);
    int turns[n];
    bool check=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        if(arr[i]%m)
        {
            turns[i]=arr[i]/m+1;
        }
        else
        {
            turns[i]=arr[i]/m;
        }
    }
    int ma=0;
    int ans;
    for(int i=0;i<n;i++)
    {
        if(turns[i]>=ma)
        {
            ma=turns[i];
            ans=i;
        }
    }
    cout<<ans+1<<"\n";

}