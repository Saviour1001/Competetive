#include <bits/stdc++.h>
using namespace ::std;
string longDivision(string number, int divisor)
{
    // As result can be very large store it in string
    string ans;
 
    // Find prefix of number that is larger
    // than divisor.
    int idx = 0;
    int temp = number[idx] - '0';
    while (temp < divisor)
        temp = temp * 10 + (number[++idx] - '0');
 
    // Repeatedly divide divisor with temp. After
    // every division, update temp to include one
    // more digit.
    while (number.size() > idx) {
        // Store result in answer i.e. temp / divisor
        ans += (temp / divisor) + '0';
 
        // Take next digit of number
        temp = (temp % divisor) * 10 + number[++idx] - '0';
        // cout<<temp<<"--\n";
    }

    // If divisor is greater than number
    if (ans.length() == 0)
        return "0";
 
    if(temp==-48)
    return ans;
    return "-1";
}
int main()
{

    int a, b, n;
    cin>>a>>b>>n;
    
    string s = to_string(a);
    if(b==10)
    {
        for(int i=0;i<n;i++)
        {
            s+="0";
        }   
        cout<<s;
        return 0;
    }
    bool flag=0;
    bool zeros=0;
    for (int i = 0; i < n;i++)
    {
        if(zeros==1)
        {
            s+="0";
            continue;
        }
        for(int j=0;j<=9;j++)
        {
            string x = s;
            string y = to_string(j);
            x+=y;
            if(longDivision(x,b)!="-1" && longDivision(x,b)!="0")
            {
                s = x;
                if(j==0)
                {
                    zeros=1;
                }
                break;

            }
            if(j==9)
            {
                flag=1;
                break;
            }
        }
        if(flag && zeros==0)
        {
            break;
        }
    }
    // cout<<n;
    if(flag)
    {
        cout<<"-1";
    }
    else
    {
        cout<<s;
    }
}