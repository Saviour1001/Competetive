#include<bits/stdc++.h>
using namespace::std;
#define ll long long
ll fact(ll n)
{
    if(n==0 || n==1)
    {
        return 1;
    }
    return n*fact(n-1);
}
string factorial(ll val)
{
    int carry=0;
    vector <int> arr(10000, 0);
    arr[0] = 1; //Initial product = 1

    int k = 0; //Current size of the number stored in arr

    for(int i = 1; i <= val; i++) {
        for(int j = 0;j <= k; j++) {
            arr[j] = arr[j] * i + carry;
            carry = arr[j] / 10;
            arr[j] = arr[j] % 10;
        }
        while(carry) { //Propogate the remaining carry to higher order digits
            k++;
            arr[k] = carry % 10;
            carry /= 10;
        }   
    }
    string s="";
    for(int i = k; i >= 0; i--) {
        s+=to_string(arr[i]);
    }
    return s;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,r;
        cin>>l>>r;
        int n=r-l+1;
        if(n==1)
        {
            cout<<"1\n";
            continue;
        }
        int ans=(n*(n+1))/2;
        cout<<ans<<"\n";
    }
    return 0;
}