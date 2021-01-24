#include<bits/stdc++.h>
using namespace::std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,r;
        cin>>l>>r;
        set<int> s;
        vector<int> v;
        vector<int>::iterator ip;
        for(int i=l;i<=r;i++)
        {
            for(int j=l;j<=r;j++)
            {
                v.push_back(i+j);
            }
        }
        ip = std::unique(v.begin(), v.end() ); 
    // Now v becomes {1 3 10 1 3 7 8 * * * * *} 
    // * means undefined 
  
    // Resizing the vector so as to remove the undefined terms 
    v.resize(distance(v.begin(), ip)); 
        cout<<v.size()<<"\n";
    }
}