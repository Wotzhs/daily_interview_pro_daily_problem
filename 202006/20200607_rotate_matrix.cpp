#include <iostream>
#include <vector>
using namespace std;

/*

This problem was recently asked by Uber:

Given a square 2D matrix (n x n), rotate the matrix by 90 degrees clockwise.

Here's an example and some starting code:

def rotate(mat):
  # Fill this in.

mat = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
# Looks like
# 1 2 3
# 4 5 6
# 7 8 9

# Looks like
# 7 4 1
# 8 5 2
# 9 6 3
print(rotate(mat))
# [[7, 4, 1], [8, 5, 2], [9, 6, 3]]

*/

vector<vector<int>> rotate(vector<vector<int>>& matrix) {
	for (int i=0; i<matrix.size(); i++)
		for (int j=i; j<matrix[i].size(); j++)
			swap(matrix[i][j], matrix[j][i]);

	for (int i=0; i<matrix.size(); i++) 
		for (int left=0, right=matrix.size()-1; left < right; left++, right--) 
			swap(matrix[i][left], matrix[i][right]);

	return matrix;
}

void print(vector<vector<int>> matrix) {
	cout << "[";
	for (int i=0; i<matrix.size(); i++) {
		cout << "[";
		for (int j=0; j<matrix[i].size(); j++) {
			cout << matrix[i][j];
			if (j < matrix[i].size()-1) cout << ", ";
		}
		cout << "]";
		if (i < matrix.size()-1) cout << ", ";
	}
	cout << "]\n";
}

int main(){
	vector<vector<int>> matrixA = {
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9},
	};
	print(rotate(matrixA)); // [[7, 4, 1], [8, 5, 2], [9, 6, 3]]

	vector<vector<int>> matrixB = {
		{1, 2},
		{3, 4},
	};
	print(rotate(matrixB)); // [[3, 1], [4, 2]]

	vector<vector<int>> matrixC = {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12},
		{13, 14, 15, 16},
	};

	print(rotate(matrixC)); // [[13, 9, 5, 1], [14, 10, 6, 2], [15, 11, 7, 3], [16, 12, 8, 4]]

	return 0;
}