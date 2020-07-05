#include <iostream>
using namespace std;

/*

This problem was recently asked by Microsoft:

You 2 integers n and m representing an n by m grid, determine the number of ways you can get from the top-left to the bottom-right of the matrix y going only right or down.

Example:
n = 2, m = 2

This should return 2, since the only possible routes are:
Right, down
Down, right.

Here's the signature:

def num_ways(n, m):
  # Fill this in.

print num_ways(2, 2)
# 2

*/

int numWays(int n, int m) {
	int dp[n][m];
	for (int i=0; i<n; i++)
		dp[0][i] = 1;
	for (int i=0; i<m; i++)
		dp[i][0] = 1;
	for (int i=1; i<n; i++)
		for (int j=1; j<m; j++)
			dp[i][j] = dp[i-1][j] + dp[i][j-1];

	return dp[n-1][m-1];
}

int main(){
	cout << numWays(2,2) << "\n"; // 2
	cout << numWays(3,3) << "\n"; // 5
	cout << numWays(4,4) << "\n"; // 20
	
	return 0;
}