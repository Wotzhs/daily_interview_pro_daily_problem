#include <iostream>
#include <vector>
using namespace std;

/*

This problem was recently asked by Microsoft:

A maze is a matrix where each cell can either be a 0 or 1. A 0 represents that the cell is empty, and a 1 represents a wall that cannot be walked through. You can also only travel either right or down.

Given a nxm matrix, find the number of ways someone can go from the top left corner to the bottom right corner. You can assume the two corners will always be 0.

Example:

Input: [[0, 1, 0], [0, 0, 1], [0, 0, 0]]
# 0 1 0
# 0 0 1
# 0 0 0
Output: 2

The two paths that can only be taken in the above example are: down -> right -> down -> right, and down -> down -> right -> right.

Here's some starter code:

def paths_through_maze(maze):
  # Fill this in.

print(paths_through_maze([[0, 1, 0],
                          [0, 0, 1],
                          [0, 0, 0]]))
# 2

*/

int mazePaths(vector<vector<int>> &maze) {
	int ans = 0, rows = maze.size();
	if (rows == 0) return 0;
	int cols = maze[0].size();

	vector<vector<int>> dp(rows, vector<int>(cols));

	for (int row=1; row < rows; row++) {
		if (maze[row-1][0] == 0 && maze[row][0] == 0) dp[row][0] = 1;
	}

	for (int col=1; col < cols; col++) {
		if (maze[0][col-1] == 0 && maze[0][col] == 0) dp[0][col] = 1;
	}

	for (int row = 1; row < rows; row++) {
		for (int col = 1; col < cols; col++) {
			if (maze[row-1][col] == 1 && maze[row][col-1] == 1 || maze[row][col] == 1) {
				dp[row][col] = 0;
				continue;
			}
			if (maze[row-1][col] == 1) {
				dp[row][col] = dp[row][col-1];
				continue;
			}
			if (maze[row][col-1] == 1) {
				dp[row][col] = dp[row-1][col];
				continue;
			}
			dp[row][col] = dp[row-1][col] + dp[row][col-1];
		}
	}

	return dp[rows-1][cols-1];
}

int main() {
	vector<vector<int>> mazeA = {
		{0,1,0},
		{0,0,1},
		{0,0,0}
	};
	cout << mazePaths(mazeA) << "\n"; // 2

	vector<vector<int>> mazeB = {
		{0,1,0},
		{1,0,0},
		{0,0,0}
	};
	cout << mazePaths(mazeB) << "\n"; // 0

	vector<vector<int>> mazeC = {
		{0,0,0},
		{0,0,0},
		{0,0,0}
	};
	cout << mazePaths(mazeC) << "\n"; // 6

	vector<vector<int>> mazeD = {
		{0,0,0},
		{0,0,0},
		{0,0,1}
	};
	cout << mazePaths(mazeD) << "\n"; // 0

	return 0;
}