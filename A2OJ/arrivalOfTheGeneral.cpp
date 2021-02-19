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
    int shortest=sorted[0];
    int tallest=sorted[n-1];
    int time=0;
    int pos;
    for(int i=n-1;i>=0;i--)
    {
        if(arr[i]==shortest)
        {
            pos=i;
            break;
        }
    }
    for(int i=pos;i<n-1;i++)
    {
        int temp=arr[i+1];
        arr[i+1]=arr[i];
        arr[i]=temp;
        time+=1;

    }
    for(int i=0;i<n;i++)
    {
        if(arr[i]==tallest)
        {
            pos=i;
            break;
        }
    }
    cout<<time+pos;

}