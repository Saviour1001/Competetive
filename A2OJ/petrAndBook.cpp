#include<bits/stdc++.h>
using namespace::std;
int main()
{
    int pages;
    cin>>pages;
    int arr[7]={0};
    int pages_sum[7]={0};
    int sum=0;
    for(int i=0;i<7;i++)
    {
        cin>>arr[i];
        sum+=arr[i];
        pages_sum[i]=sum;
    }
    int i=0;
    int counter=0;
    while(pages>0)
    {
        pages-=arr[i];
        i++;
        if(i==7)
        {
            i=0;
        }
    

    }
    if(i==0)
    {
        cout<<7<<"\n";
    }
    else
    {
        cout<<i<<"\n";
    }
}