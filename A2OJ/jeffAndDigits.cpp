#include<bits/stdc++.h>
using namespace::std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    int zeros=0;
    int fives=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        if(arr[i]==5)
        {
            fives++;
        }
        else
        zeros++;
    }
    
}