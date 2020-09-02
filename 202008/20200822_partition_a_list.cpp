#include <iostream>
#include <vector>
using namespace std;

/*

This problem was recently asked by LinkedIn:

Given a list of numbers and an integer k, partition/sort the list such that the all numbers less than k occur before k, and all numbers greater than k occur after the number k.

def partition_list(nums, k):
  # Fill this in.

print(partition_list([2, 2, 2, 5, 2, 2, 2, 2, 5], 3))
# [2, 2, 2, 2, 2, 2, 2, 2, 5]

*/

// TC - o(n)
// SC - o(1)
typedef vector<int> vi;

vi partitionList(vi nums, int k) {
	for (int i=0, j=0; i<nums.size(); i++) {
		if (nums[i]<=k) swap(nums[i], nums[j++]);
	}
	return nums;
}

void print(vi ans) {
	cout << "[";
	for (int i=0; i<ans.size(); i++) {
		cout << ans[i];
		if (i<ans.size()-1) cout << ", ";
	}
	cout << "]\n";
}

int main() {
	print(partitionList({2,2,2,5,2,2,2,2,5}, 3)); // [2, 2, 2, 2, 2, 2, 2, 5, 5]
	print(partitionList({2,8,5,1,4,7,6}, 3)); // [2, 1, 5, 8, 4, 7, 6]
	print(partitionList({2,8,5,1,4,7,6}, 1)); // [1, 8, 5, 2, 4, 7, 6]

	return 0;
}
