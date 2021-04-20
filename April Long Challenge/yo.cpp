#include<bits/stdc++.h>
using namespace::std;
int main()
{
    string a;
    cin>>a;
    bitset<sizeof(int)*8> x(a);
    cout<<x.to_ulong();
    return 0;
}