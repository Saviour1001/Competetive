#include<bits/stdc++.h>
using namespace::std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int d,c;
        cin>>d>>c;
        int a1,a2,a3;
        cin>>a1>>a2>>a3;
        int atotal=a1+a2+a3;
        int b1,b2,b3;
        cin>>b1>>b2>>b3;
        int btotal=b1+b2+b3;
        if(atotal>=150 && btotal>=150)
        {
            if(2*d<=c)
            {
                cout<<"NO\n";
            }
            else
            {
                cout<<"YES\n";
            }
        }
        if(atotal>=150 && btotal<150)
        {
            if(c+d>=2*d)
            {
                cout<<"NO\n";
            }
            else
            {
                cout<<"YES\n";
            }
        }
        if(btotal>=150 && atotal<150)
        {
            if(c+d>=2*d)
            {
                cout<<"NO\n";
            }
            else
            {
                cout<<"YES\n";
            }
        }
        if(atotal<150 && btotal<150)
        {
            cout<<"NO\n";
        }
        
    }
}