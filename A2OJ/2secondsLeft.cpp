#include<iostream>
#include<iomanip>
using namespace::std;
int main()
{
    int n;
    cin>>n;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        sum+=x;
    }
    float ans=float(sum/n);
    //cout<<fixed<<setprecision(9)<<sum/n<<"\n";
    cout<<fixed<<setprecision(9)<<ans<<"\n";
}