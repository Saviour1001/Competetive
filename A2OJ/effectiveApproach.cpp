#include<bits/stdc++.h>
using namespace::std;
int main()
{
    int n;
    cin>>n;
    vector<int> array(n);
    for(int i=0;i<n;i++)
    {
        cin>>array[i];
    }
    vector<int> sorted=array;
    sort(sorted.begin(),sorted.end());
    bool wow=0;
    if(sorted==array)
    {
        wow=1;
    }
    int m;
    cin>>m;
    vector<int> query(m);
    for(int i=0;i<m;i++)
    {
        cin>>query[i];
    }
    int vasya=0;
    int petya=0;
    for(int i=0;i<m;i++)
    {
        if(wow==1)
        {
            vasya+=query[i];
            petya+=(n-query[i]+1);
            continue;
        }
        for(int j=0;j<n;j++)
        {
            if(array[j]==query[i])
            {
                vasya+=j+1;
                break;
            }
        }
        int counter=0;
        for(int j=n-1;j>=0;j--)
        {
            counter++;
            if(array[j]==query[i])
            {
                petya+=counter;
                break;
            }
        }
    }
    cout<<vasya<<" "<<petya<<"\n";

}