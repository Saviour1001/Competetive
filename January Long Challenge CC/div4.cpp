#include<bits/stdc++.h>
using namespace::std;
#define ll long long
int main()
{
    int t;
    ll n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>n>>k>>x>>y;
        if(x==y)
        {
            cout<<n<<" "<<n;
            cout<<"\n";
            continue;
        }
        int location_x,location_y;
        int collision=k%4;
        if(x>y)
        {
            switch(collision)
            {
                case 0:location_x=x-y;location_y=0;break;
                case 1:location_x=n;location_y=(n-x)+y;break;
                case 2:location_x=(n-x)+y;location_y=n;break;
                case 3:location_x=0;location_y=x-y;break;

            }
        }
        if(y>x)
        {
            switch(collision)
            {
                case 0:location_x=0;location_y=y-x;break;
                case 1:location_x=(n-y)+x;location_y=n;break;
                case 2:location_x=n;location_y=(n-y)+x;break;
                case 3:location_x=y-x;location_y=0;break;

            }
        }
        cout<<location_x<<" "<<location_y<<"\n";
    }

}