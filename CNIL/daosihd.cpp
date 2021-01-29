#include <bits/stdc++.h>
using namespace std;

vector<long long> rectangularSquare(int n, vector<vector<int>> mat, int q, vector<vector<int>> query)
{
    vector<long long> ans;
 	for(int k=0;k<q;k++)
    {
        int x=query[k][0];
        int y=query[k][1];
        int l=query[k][2];
        int b=query[k][3];
        long long cost=0;
        //cout<<x+l<<"---\n";
        for(int i=0;i<l+x;i++)
        {
            //cout<<"**";
            for(int j=0;j<b+y;j++)
            {
                cost+=mat[i][j];
                //cout<<"yo";
            }
        }
        ans.push_back(cost);
        
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> mat(n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int val;
            cin >> val;

            mat[i].push_back(val);
        }
    }

    int q;
    cin >> q;

    vector<vector<int>> query;

    for (int i = 0; i < q; i++)
    {
        int x, y, l, b;
        cin >> x >> y >> l >> b;

        query.push_back({x, y, l, b});
    }

    vector<long long> ans = rectangularSquare(n, mat, q, query);

    for (auto i : ans)
    {
        cout << i << endl;
    }
}