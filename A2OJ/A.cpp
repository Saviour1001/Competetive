#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int gcd(int a, int b)
{
    if (!a || !b)
        return a | b;
    unsigned shift = __builtin_ctz(a | b);
    a >>= __builtin_ctz(a);
    do
    {
        b >>= __builtin_ctz(b);
        if (a > b)
            swap(a, b);
        b -= a;
    } while (b);
    return a << shift;
}

int main()
{
    long long int t;
    t=1;
    while (t--)
    {
        // ans = 14
        long long int p;
        vector<long long> ans;
        for (int k = 1; k <= 10000; k++)
        {
            p=k;
            long long int count = 0;
            for (int i = 1; i <= 2 * p; i++)
            {
                long long a = p + (i * i);
                long long b = p + (i + 1) * (i + 1);
                // cout<<a<<" "<<b<<"\n";
                long long int ans = gcd(a, b);
                count += ans;
                // cout<<"=>"<<ans<<"\n";
            }
            ans.push_back(count);
        }
        p=1;
        cout<<ans[p-1]<<"\n";
        // long long x =count;
        // count+=(2*p+p)+x;
    }
}