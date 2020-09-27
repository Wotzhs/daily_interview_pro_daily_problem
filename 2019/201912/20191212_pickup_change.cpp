#include <iostream>
#include <vector>
using namespace std;

/*

This problem was recently asked by Amazon:

Given a 2d n x m matrix where each cell has a certain amount of change on the floor, your goal is to start from the top left corner mat[0][0] and end in the bottom right corner mat[n - 1][m - 1] with the most amount of change. You can only move either left or down.

Here's some starter code:

def max_change(mat):
  # Fill this in.

mat = [
    [0, 3, 0, 2],
    [1, 2, 3, 3],
    [6, 0, 3, 2]
]

print(max_change(mat))
# 13

*/

// TC - o(nm)
// SC - o(nm)
typedef vector<vector<int>> vvi;

int maxChange(vvi mat) {
	if (mat.size() == 0) {
		return 0;
	}
	int n = mat.size(), m = mat[0].size();
	int dp[n][m] = {mat[0][0]};
	for (int i=1; i<m; i++) {
		dp[0][i] = dp[0][i-1] + mat[0][i];
	}

	for (int i=1; i<n; i++) {
		dp[i][0] = dp[i-1][0] + mat[i][0];
	}

	for (int i=1; i<n; i++) {
		for (int j=1; j<m; j++) {
			dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + mat[i][j];
		}
	}
	return dp[n-1][m-1];
}

int main() {
	cout << maxChange({
		{0,3,0,2},
		{1,2,3,3},
		{6,0,3,2},
	}) << "\n"; // 13
	
	cout << maxChange({
		{0,3,0,2},
		{1,2,3,3},
		{8,0,3,3},
	}) << "\n"; // 15
	return 0;
}
