#include<bits/stdc++.h>
using namespace::std;
int main()
{
    string a,b;
    cin>>a>>b;
    bool check=0;
    for(int i=0;i<a.length();i++){
        a[i]=tolower(a[i]);
        b[i]=tolower(b[i]);
        if(a[i]==b[i] && i!=a.length()-1)
        {
            continue;
        }
        if(a[i]<b[i])
        {
            cout<<-1;
            check=1;
            break;
        }
        if(a[i]>b[i])
        {
            cout<<1;
            check=1;
            break;
        }
    }
    if(check==0)
    {
        cout<<0;
    }
}