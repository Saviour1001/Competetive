#include<bits/stdc++.h>
using namespace::std;
int main()
{
    string s;
    cin>>s;
    int arr[26]={0};
    for(int i=0;i<s.length();i++)
    {
        arr[s[i]-97]+=1;
    }
    int counter=0;
    for(int i=0;i<26;i++)
    {
        if(arr[i]>0)
        {
            counter++;
        }
    }
    if(counter%2)
    {
        cout<<"IGNORE HIM!\n";
    }
    else
    {
        cout<<"CHAT WITH HER!\n";
    }
}