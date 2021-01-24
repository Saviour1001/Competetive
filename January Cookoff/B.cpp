#include<bits/stdc++.h>
using namespace::std;
int factorial(int n) 
{ 
    return (n==1 || n==0) ? 1: n * factorial(n - 1);  
} 
int fact(int n)
{
    if(n==1 || n==0)
    {
        return 1;
    }
    return n*fact(n-1);
}
int main()
{
    int t;
    cin>>t;
    int l,r;
    cout<<fact(5)<<endl;
    while(t--)
    {
        
        cin>>l>>r;
        int n=l-r;
        if(n==0)
        {
            cout<<"1\n";
            continue;
        }
        else{
            cout<<"---";
        }
        int ans;
        ans=fact(n+2-1)/(2*fact(n-1));
        cout<<ans<<"\n";
    }
    return 0;

}