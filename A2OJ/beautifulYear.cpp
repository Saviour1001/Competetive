#include<bits/stdc++.h>
using namespace::std;
int main()
{
    int n;
    cin>>n;
    for(int i=n+1;i<10000;i++)
    {
        string s=to_string(i);
        set<int> unique(s.begin(),s.end());
        if(unique.size()==s.size())
        {
            cout<<s;
            break;
        }
    }
    return 0;
}