#include <stdio.h>
#include <iostream>
using namespace::std;
int main()
{
    int i;
    cin>>i;
    while(i>0){
        int a,b,c;
        cin>>a>>b>>c;
        if(a+b==c || a+c==b || b+c==a) printf("YES\n");
        else printf("NO\n");
        i--;
    }
    

    return 0;
}