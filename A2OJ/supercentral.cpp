#include<bits/stdc++.h>
using namespace::std;
int main()
{
    int n;
    cin>>n;
    vector<pair<int,int>> points(n);
    for(int i=0;i<n;i++)
    {
        cin>>points[i].first>>points[i].second;
    }
    int counter=0;
    for(int i=0;i<n;i++)
    {
        bool left=0;
            bool right=0;
            bool up=0;
            bool down=0;
        for(int j=0;j<n;j++)
        {
            if(j==i)
            {
                continue;
            }
            
            if(points[i].first==points[j].first && points[i].second>points[j].second)
            {
                down=1;
            }
            if(points[i].first==points[j].first && points[i].second<points[j].second)
            {
                up=1;
            }
            if(points[i].first>points[j].first && points[i].second==points[j].second)
            {
                left=1;
            }
            if(points[i].first<points[j].first && points[i].second==points[j].second)
            {
                right=1;
            }
        }
        if(down && up && right && left )
        {
            counter++;
        }
    }
    cout<<counter<<"\n";
}