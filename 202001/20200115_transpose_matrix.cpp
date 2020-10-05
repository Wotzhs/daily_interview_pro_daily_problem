#include <iostream>
#include <vector>
using namespace std;

/*

This problem was recently asked by Twitter:

Given a matrix, transpose it. Transposing a matrix means the rows are now the column and vice-versa.

Here's an example:

def transpose(mat):
  # Fill this in.

mat = [
    [1, 2, 3],
    [4, 5, 6],
]

print(transpose(mat))
# [[1, 4],
#  [2, 5], 
#  [3, 6]]

*/

// TC - o(n*m)
// SC - o(n*m)
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

vvi transpose(vvi &mat) {
	int n=mat.size(), m=mat[0].size();
	vvi transposed(m, vi(n));
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			transposed[j][i] = mat[i][j];
		}
	}
	return transposed;
}

void print(vvi ans) {
	cout << "[";
	for (int i=0; i<ans.size(); i++) {
		cout << "[";
		for (int j=0; j<ans[i].size(); j++) {
			cout << ans[i][j];
			if (j<ans[i].size()-1) {
				cout << ", ";
			}
		}
		if (i<ans.size()-1) {
			cout << ",\n";
		}
	}
	cout << "]\n";
}

int main() {
	vector<vector<int>> mat = {
		{1,2,3},
		{4,5,6},
	};
	print(transpose(mat));
	// [[1, 4],
	// [2, 5],
	// [3, 6]]
	return 0;
}
