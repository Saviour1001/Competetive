#include<bits/stdc++.h>
using namespace::std;
int main()
{
    long long x;
    cin>>x;
    string s=to_string(x);
    long long counter=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='4' || s[i]=='7')
        counter++;
    }
    counter==4 || counter==7 ? cout<<"YES\n" : cout<<"NO\n";


}