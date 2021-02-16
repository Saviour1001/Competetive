#include<iostream>
using namespace::std;
int main()
{
    int n;int t;
    cin>>n>>t;
    string s;
    cin>>s;
    bool check=1;
    
    for(int i=0;i<t;i++)
    {
        int j=0;
        while(j<s.length())
        {
            if(s[j]=='B' && s[j+1]=='G')
            {
                s[j]='G';
                s[j+1]='B';
                j++;
            }
            j++;
        }
    }
    cout<<s;
}