#include<bits/stdc++.h>
#include<numeric> 
using namespace::std;
int gcd(int a,int b){
    if(b==0)return a;
    else return gcd(b,a%b);
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s,t,s1,t1;
        cin>>s1>>t1;
        s=s1;
        t=t1;
        string answer="";
        int slen=s1.length();
        int tlen=t1.length();
        int lcm;
        if(slen>tlen)
        lcm = slen;
        else
        lcm = tlen;
        while(1) {
            if( lcm%slen==0 && lcm%tlen==0 ) {
         break;
      }lcm++;
   }
   while(slen<lcm)
   {
       if(slen==lcm)
       {
           break;
       }
      
       s+=s1;
       slen+=s1.length();
   }
   
   while (tlen<lcm)
   {
       
       t+=t1;
       tlen+=t1.length();
   }

   if(s==t)
   {
       cout<<s<<"\n";
   }
   else
   {
       cout<<"-1\n";   }
   
   
        
        /*if(slen>tlen)
        {
            while(answer!=s && answer.length()<=slen)
            {
                answer+=t;
            }
            if(answer==s)
            {
                cout<<answer<<"\n";
            }
            else
            {
                cout<<"-1\n";
            }
            
        }
        if(slen<tlen)
        {
            while(answer!=s && answer.length()<=tlen)
            {
                answer+=s;
            }
            if(answer==t)
            {
                cout<<answer<<"\n";
            }
            else
            {
                cout<<"-1\n";
            }
        }*/
        
    }
    return 0;
}