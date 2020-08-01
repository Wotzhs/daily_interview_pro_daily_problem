#include <iostream>
#include <vector>
#include <string.h>
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

int pathsThroughMaze(vector<vector<int>> maze) {
	int n=maze.size();
	if (n<1) return 0;
	int m=maze[0].size();
	int dp[n][m];
	memset(dp, 0, sizeof dp);

	for (int i=0; i<n; i++)
		if (maze[i][0] == 1) break;
		else dp[i][0] = 1;

	for (int i=0; i<m; i++)
		if (maze[0][i] == 1) break;
		else dp[0][i] = 1;

	for (int i=1; i<n; i++)
		for (int j=1; j<n; j++)
			if (maze[i][j] != 1) dp[i][j] = dp[i-1][j] + dp[i][j-1];

	return dp[n-1][m-1];
}

int main(){
	cout << pathsThroughMaze({
		{0,1,0},
		{0,0,1},
		{0,0,0},
	}) << "\n"; // 2

	cout << pathsThroughMaze({
		{0,0,0},
		{0,0,1},
		{0,0,0},
	}) << "\n"; // 3

	cout << pathsThroughMaze({
		{1,0,0},
		{0,0,0},
		{0,0,0},
	}) << "\n"; // 0

	cout << pathsThroughMaze({
		{0,0,0},
		{0,0,0},
		{0,0,1},
	}) << "\n"; // 0

	cout << pathsThroughMaze({
		{0,0,0},
		{0,0,1},
		{0,1,0},
	}) << "\n"; // 0

	cout << pathsThroughMaze({
		{0,1,0},
		{0,1,0},
		{0,1,0},
	}) << "\n"; // 0

	cout << pathsThroughMaze({
		{0,1,0,0},
		{0,1,0,0},
		{0,1,1,1},
		{0,0,0,0},
	}) << "\n"; // 1

	return 0;
}