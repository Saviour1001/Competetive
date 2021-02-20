#include<bits/stdc++.h>
using namespace::std;
int main()
{
    int n;
    cin>>n;
    int counter=0;
    while(n--)
    {
        string s;
        cin>>s;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='+')
            {
                i++;
                counter++;
            }
            if(s[i]=='-')
            {
                i++;
                counter--;
            }
        }

    }
    cout<<counter<<"\n";
}