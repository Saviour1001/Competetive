
// C++ program for the above approach
 
#include <bits/stdc++.h>
using namespace std;
 
// Function to find the count of
// substrings having an equal number
// of uppercase and lowercase characters
int countSubstring(string& S, int N)
{
    // Stores the count of prefixes
    // having sum S considering uppercase
    // and lowercase characters as 1 and -1
    unordered_map<int, int> prevSum;
 
    // Stores the count of substrings
    // having equal number of lowercase
    // and uppercase characters
    int res = 0;
 
    // Stores the sum obtained so far
    int currentSum = 0;
 
    for (int i = 0; i < N; i++) {
 
        // If the character is uppercase
        if (S[i] >= 'A' and S[i] <= 'Z') {
            currentSum++;
        }
 
        // Otherwise
        else
            currentSum--;
 
        // If currsum is o
        if (currentSum == 0)
            res++;
 
        // If the current sum exists in
        // the HashMap prevSum
        if (prevSum.find(currentSum)
            != prevSum.end()) {
 
            // Increment the resultant
            // count by 1
            res += (prevSum[currentSum]);
        }
 
        // Update the frequency of the
        // current sum by 1
        prevSum[currentSum]++;
    }
 
    // Return the resultant count of
    // the subarrays
    return res;
}
 
// Driver Code
int main()
{
    string S = "gEEk";
    cout << countSubstring(S, S.length());
 
    return 0;
}