#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

/*

This problem was recently asked by Amazon:

You are given a 2D array of integers. Print out the clockwise spiral traversal of the matrix.

Example:

grid = [[1,  2,  3,  4,  5],
        [6,  7,  8,  9,  10],
        [11, 12, 13, 14, 15],
        [16, 17, 18, 19, 20]]

The clockwise spiral traversal of this array is:

1, 2, 3, 4, 5, 10, 15, 20, 19, 18, 17, 16, 11, 6, 7, 8, 9, 14, 13, 12

Here is a starting point:

def matrix_spiral_print(M):
  # Fill this in.

grid = [[1,  2,  3,  4,  5],
        [6,  7,  8,  9,  10],
        [11, 12, 13, 14, 15],
        [16, 17, 18, 19, 20]]

matrix_spiral_print(grid)
# 1 2 3 4 5 10 15 20 19 18 17 16 11 6 7 8 9 14 13 12

*/

// n = number of rows, m = number of columns
// TC - o(nm) 
// SC - o(nm)
void matrixSpiralPrint(vector<vector<int>> matrix) {
	if (!matrix.size()) return;
	
	int n=matrix.size(), m=matrix[0].size(), i=0, j=0, k=0, visited[n][m];
	memset(visited, 0, sizeof visited);

	vector<int> dir = {0,1,0,-1,0}; // right [0,1], down [1,0], left [0, -1], up [-1, 0]

	while(!visited[i][j]) {
		visited[i][j]=1;
		cout << matrix[i][j] << " ";

		if (i+dir[k]<0 || i+dir[k]>n-1 || j+dir[k+1]<0 || j+dir[k+1]>m-1 || visited[i+dir[k]][j+dir[k+1]])
			++k%=dir.size()-1;

		i+=dir[k], j+=dir[k+1];
	}
	cout << "\n";
}

int main() {
	matrixSpiralPrint({
		{1,2,3,4,5},
		{6,7,8,9,10},
		{11,12,13,14,15},
		{16,17,18,19,20},
	}); // 1 2 3 4 5 10 15 20 19 18 17 16 11 6 7 8 9 14 13 12
	
	matrixSpiralPrint({
		{1,2,},
		{4,3},
	}); // 1 2 3 4

	matrixSpiralPrint({}); // 

	return 0;
}
