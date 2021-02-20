#include<bits/stdc++.h>
using namespace::std;
int main()
{
    int n;
    cin>>n;
    int ma=0;
    int tram=0;
    while(n--)
    {
        int a,b;
        cin>>a>>b;
        tram-=a;
        tram+=b;
        ma=max(ma,tram);
    }
    cout<<ma<<"\n";
}