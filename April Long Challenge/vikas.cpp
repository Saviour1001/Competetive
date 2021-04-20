#include <bits/stdc++.h>
#include <string.h>
using namespace std;
#define N 10000000;
int i = 0;

// Find all subsequences
string decimalToBinary(int n)
{
    //finding the binary form of the number and
    //coneverting it to string.
    string s = bitset<64>(n).to_string();

    //Finding the first occurance of "1"
    //to strip off the leading zeroes.
    const auto loc1 = s.find('1');

    if (loc1 != string::npos)
        return s.substr(loc1);

    return "0";
}
void printSubsequence(string input, string output, string a[10000])
{
    // Base Case
    // if the input is empty print the output string
    //string a[10000000];
    if (input.empty())
    {
        //cout << output << endl;

        a[i] = output;
        i++;
        return;
    }
    //cout<<a;

    // output is passed with including
    // the Ist characther of
    // Input string
    printSubsequence(input.substr(1), output + input[0], a);

    // output is passed without
    // including the Ist character
    // of Input string
    printSubsequence(input.substr(1), output, a);
}

// Driver code
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        // output is set to null before passing in as a
        // parameter
        vector<int> b;
        string output = "";
        string input;
        cin >> input;
        string a[10000];

        printSubsequence(input, output, a);
        i = 0;
        for (int j = 0; j <= pow(2, input.length()); j++)
        {
            if (a[j].length())
            {
                bitset<sizeof(int) * 8> x(a[j]);
                b.push_back(x.to_ulong());
            }
        }
        sort(b.begin(), b.end());
        b.erase(unique(b.begin(), b.end()), b.end());

        for (int l = 0; l < b.size(); l++)
        {
            if (b[l] != l)
            {
                cout << decimalToBinary(l) << "\n";
                break;
            }
        }
    }

    return 0;
}