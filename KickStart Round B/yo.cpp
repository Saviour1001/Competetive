#include<bits/stdc++.h>
using namespace::std;
int main()
{
	
        int a=0;
        int b=0;
		string s;
		cin>>s;
		for(int i=0;i<s.length();i++)
		{
			if(s[i]=='(')
			{
				a+=1;
			}
			if(s[i]==')')
			{
                if(a>0)
                {a--;
                b+=2;
                }
			}
		}
		cout<<b<<"\n";
	
}