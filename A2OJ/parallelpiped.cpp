#include<bits/stdc++.h>
using namespace::std;
int main()
{
    int a1,a2,a3;
    cin>>a1>>a2>>a3;
    int side1=sqrt((a1*a3)/a2);
    int side2=sqrt((a2*a1)/a3);
    int side3=sqrt((a3*a2)/a1);
    //cout<<side1<<" "<<side2<<" "<<side3<<"\n";
    int sum=4*(side1+side2+side3);
    cout<<sum<<"\n";
}