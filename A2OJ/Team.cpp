#include<bits/stdc++.h>
using namespace::std;
int main()
{
    int n;
    cin>>n;
    int counter=0;
    while(n--)
    {
        int pa=0;
        int a,b,c;
        cin>>a>>b>>c;
        if(a==1)
        {
            pa++;
        }
        if(b==1)
        {
            pa++;
        }
        if(c==1)
        {
            pa++;
        }
        if(pa>=2)
        {
            counter++;
        }
    }
    cout<<counter<<"\n";
}