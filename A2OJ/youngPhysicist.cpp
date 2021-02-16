#include<bits/stdc++.h>
using namespace::std;
int main()
{
    int n;
    cin>>n;
    int arr[n][3];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>arr[i][j];
        }
    }
    
    bool check=0;
    for(int j=0;j<3;j++)
    {int counter=0;
        for(int i=0;i<n;i++)
    {
        counter+= arr[i][j];
    }
    //cout<<counter;
    if(counter!=0)
    {
        check=1;
        break;
    }
    }
    if(check)
    {
        cout<<"NO\n";
    }
    else
    {
        cout<<"YES\n";
    }
}