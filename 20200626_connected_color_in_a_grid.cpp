#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

/*

This problem was recently asked by Uber:

Find the maximum number of connected colors in a grid.

class Grid:
  def __init__(self, grid):
    self.grid = grid

  def max_connected_colors(self):
    # Fill this in.

grid = [[1, 0, 0, 1],
        [1, 1, 1, 1],
        [0, 1, 0, 0]]

print(Grid(grid).max_connected_colors())
# 7

Can you solve this both recursively and iteratively?

*/

class Grid {
	vector<vector<int>> grid;
	vector<int> offsets = {1,0,-1,0,1};
	vector<vector<bool>> visited;
	int m;
	int n;
public:
	Grid(vector<vector<int>> g): grid(g) {};
	int maxConnectedColors() {
		m = grid.size();
		
		if (m == 0) return 0;
		
		n = grid[0].size();
		
		visited = vector<vector<bool>>(m, vector<bool>(n, false));

		unordered_map<int, int> mp;

		for (int i=0; i<m; i++) {
			for (int j=0; j<n; j++) {
				if (visited[i][j]) continue;

				int count = dfs(i, j);

				mp[grid[i][j]] = max({mp[grid[i][j]], count, 1});
			}
		}


		int maxCount = -1;
		for (auto it = mp.begin(); it != mp.end(); it++) {
			maxCount = max(maxCount, it->second);
		}

		return maxCount;
	}

	int dfs(int r, int c) {
		int count = 0;
		for (int i=0; i<offsets.size()-1; i++) {
			int row = r+offsets[i], col = c+offsets[i+1];

			if (row < 0 || row >= m || col < 0 || col >= n)
				continue;

			if (grid[row][col] == grid[r][c] && !visited[row][col]) {
				visited[row][col] = true;
				count += dfs(row, col) + 1;
			}
		}
		return count;
	}
};

int main() {
	cout << Grid({ 
        {1, 0, 0, 1},
        {1, 1, 1, 1},
        {0, 1, 0, 0},
    }).maxConnectedColors() << "\n"; // 7

    cout << Grid({ 
        {1, 0, 0, 1},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
    }).maxConnectedColors() << "\n"; // 5

	cout << Grid({ 
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {1, 0, 1, 0},
    }).maxConnectedColors() << "\n"; // 1

    cout << Grid({ 
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 1, 1},
    }).maxConnectedColors() << "\n"; // 12

    cout << Grid({ 
        {1, 0, 4, 2},
        {4, 4, 4, 2},
        {6, 3, 5, 2},
    }).maxConnectedColors() << "\n"; // 4
	return 0;
}