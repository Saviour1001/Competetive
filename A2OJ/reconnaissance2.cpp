#include<bits/stdc++.h>
using namespace::std;
int main()
{
    int n;
    cin>>n;
    int arr[n+1];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    arr[n]=arr[0];
    int diff=abs(arr[0]-arr[1]);
    int x=0,y=1;
    for(int i=0;i<n;i++)
    {
        int a=abs(arr[i]-arr[i+1]);
        if(a<diff)
        {
            diff=a;
            x=i;
            y=i+1;
        }
    }
    if(y==n)
    {
        cout<<y<<" "<<1;
    }
    else
    {
        cout<<x+1<<" "<<y+1;
    }
}