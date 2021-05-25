// C program to count total number of special sequences
// of length N where
#include <stdio.h>
#include<bits/stdc++.h>
using namespace::std;
// DP based function to find the number of special
// sequences
int getTotalNumberOfSequences(int m, int n)
{
		// define T and build in bottom manner to store
		// number of special sequences of length n and
		// maximum value m
		int T[m+1][n+1];
		for (int i=0; i<m+1; i++)
		{
			for (int j=0; j<n+1; j++)
			{
				// Base case : If length of sequence is 0
				// or maximum value is 0, there cannot
				// exist any special sequence
				if (i == 0 || j == 0)
					T[i][j] = 0;

				// if length of sequence is more than
				// the maximum value, special sequence
				// cannot exist
				else if (i < j)
					T[i][j] = 0;

				// If length of sequence is 1 then the
				// number of special sequences is equal
				// to the maximum value
				// For example with maximum value 2 and
				// length 1, there can be 2 special
				// sequences {1}, {2}
				else if (j == 1)
					T[i][j] = i;

				// otherwise calculate
				else
					T[i][j] = T[i-1][j] + T[i/2][j-1];
			}
		}
        for (int i=0; i<m+1; i++)
		{
			for (int j=0; j<n+1; j++)
			{
                cout<<T[i][j]<<" ";
			}
            cout<<"\n";
		}
		return T[m][n];
}

// Driver Code
int main()
{
	int m = 2;
	int n = 2;
	printf("Total number of possible sequences %d",
				getTotalNumberOfSequences(m, n));
	return 0;
}
