#include<bits/stdc++.h>
using namespace::std;
int main()
{
    int k,l,m,n,d;
    cin>>k>>l>>m>>n>>d;
    vector<int> arr(d+1,0);
    int counter=0;
    for(int i=1;i<d+1;i++)
    {
        if(arr[i]==0)
        {
            if(i%k==0)
            {
                arr[i]=1;
                //cout<<"YO\n";
                counter++;
                continue;
            }
            if(i%l==0)
            {
                arr[i]=1;
                counter++;
                continue;
            }
            if(i%m==0)
            {
                arr[i]=1;
                counter++;
                continue;
            }
            if(i%n==0)
            {
                arr[i]=1;
                counter++;
                continue;
            }
            
        }
    }
    cout<<counter<<"\n";

}