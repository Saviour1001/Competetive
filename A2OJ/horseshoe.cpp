#include<bits/stdc++.h>
using namespace::std;
int main()
{
    vector<int> a(4);
    for(int i=0;i<4;i++)
    {
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    a.erase(unique(a.begin(),a.end() ),a.end() );
    cout<<4-a.size();
}