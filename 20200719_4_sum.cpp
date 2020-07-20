#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

/*

This problem was recently asked by Microsoft:

Given a list of numbers, and a target number n, find all unique combinations of a, b, c, d, such that a + b + c + d = n.

Here's some examples and some starting code.

def fourSum(nums, target):
  # Fill this in.

print(fourSum([1, 1, -1, 0, -2, 1, -1], 0))
# print [[-1, -1, 1, 1], [-2, 0, 1, 1]]

print(fourSum([3, 0, 1, -5, 4, 0, -1], 1))
# print [[-5, -1, 3, 4]]

print(fourSum([0, 0, 0, 0, 0], 0))
# print ([0, 0, 0, 0])

*/

typedef vector<int> vi;
typedef set<vi> svi;

svi fourSum(vi nums, int n) {
	sort(nums.begin(), nums.end());
	svi ans;
	int i=0, j=nums.size();
	for (int i=0; i<nums.size(); i++)
		for (int j=i+1; j<nums.size(); j++)
			for (int k=j+1; k<nums.size(); k++)
				for (int l=k+1; l<nums.size(); l++)
					if (n-nums[i]-nums[j]-nums[k]-nums[l]==0) 
						ans.insert(vi{nums[i], nums[j], nums[k], nums[l]});

	return ans;
}

void print(svi ans) {
	cout << "[";
	for (auto it = ans.begin(); it != ans.end();) {
		vi group = (*it);
		cout << "[";
		for (int i=0; i<group.size(); i++) {
			cout << group[i];
			if (i<group.size()-1) cout << ", ";
		}
		cout << "]";
		if (++it != ans.end()) cout << ", ";
	}
	cout << "]\n";
}

int main(){
	print(fourSum({1,1,-1,0,-2,1,-1}, 0)); // [[-2, 0, 1, 1], [-1, -1, 1, 1]]
	print(fourSum({1,0,-1,0,-2,2}, 0)); // [[-2, -1, 1, 2], [-2, 0, 0, 2], [-1, 0, 0, 1]]
	print(fourSum({3,0,1,-5,4,0,-1}, 1)); // [[-5, -1, 3, 4]]
	print(fourSum({0,0,0,0,0}, 0)); // [[0, 0, 0, 0]]
	return 0;
}