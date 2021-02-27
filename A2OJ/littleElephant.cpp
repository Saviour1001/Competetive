#include<bits/stdc++.h>
using namespace::std;
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    vector<int> sorted=arr;
    sort(sorted.begin(),sorted.end());
    if(sorted[0]==sorted[1])
    {cout<<"Still Rozdil";return 0;}
    for(int i=0;i<n;i++)
    {
        if(arr[i]==sorted[0])
        {cout<<i+1;break;}

    }
}