#include<bits/stdc++.h>
using namespace::std;
int main()
{
    int n;
    int sum=0;
    cin>>n;
    vector<int> hands(n);
    int total=n+1;
    for(int i=0;i<n;i++)
    {
        cin>>hands[i];
        sum+=hands[i];
    }
    int counter=0;
    for(int i=1;i<=5;i++)
    {
        if((sum+i)%total!=1)
        {
            counter++;
        }
    }
    cout<<counter<<"\n";

    
    
}