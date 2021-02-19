#include<bits/stdc++.h>
using namespace::std;
int main()
{
    int n;
    cin>>n;
    float arr[n];
    float counter=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        counter+=(arr[i]/100);
    }
    cout<<setprecision(6)<<100*(counter/n);
}