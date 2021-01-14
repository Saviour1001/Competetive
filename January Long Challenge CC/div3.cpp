#include<bits/stdc++.h>
using namespace::std;
int main()
{
    int t;
    int n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        int arr1[n],arr2[m];
        int john=0;int jack=0;
        int swaps=0;
        for(int i=0;i<n;i++)
        {
            cin>>arr1[i];
            john+=arr1[i];
        }
        for(int i=0;i<m;i++)
        {
            cin>>arr2[i];
            jack+=arr2[i];
        }
        if(john>jack)
        {
            cout<<"0\n";
            continue;
        }
        sort(arr1,arr1+n);
        sort(arr2,arr2+m,greater<int>());
        int i=0;
        while(john<=jack && i<n && i<m)
        {
            john+=arr2[i]-arr1[i];
            jack+=arr1[i]-arr2[i];
            i++;
            swaps++;
        }
        if(i==n && john<=jack)
        {
            cout<<"-1\n";
        }
        else
        {
            cout<<swaps<<"\n";
        }
        
    }
    return 0;
}