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

// TC - o(nm)
// SC - o(1)
vector<vector<int>> rotate(vector<vector<int>> mat) {
	if (!mat.size()) return mat;
	int n=mat.size(), m=mat[0].size();

	for (int i=0; i<n; i++)
		for (int j=i; j<m; j++)
			swap(mat[i][j], mat[j][i]);

	for (int i=0; i<n; i++)
		for (int l=0, r=m-1; l<r; l++, r--)
			swap(mat[i][l], mat[i][r]);

	return mat;
}

void print(vector<vector<int>> mat) {
	if (!mat.size()) return;
	int n=mat.size(), m=mat[0].size();

	cout << "[";
	for (int i=0; i<n; i++) {
		cout << "[";
		for (int j=0; j<m; j++) {
			cout << mat[i][j];
			if (j<m-1) cout << ", ";
		}
		cout << "]";
		if (i<n-1) cout << ", ";
	}
	cout << "]\n";
}

int main() {
	print(rotate({{1,2,3}, {4,5,6}, {7,8,9}})); // [[7, 4, 1], [8, 5, 2], [9, 6, 3]]
	return 0;
}
