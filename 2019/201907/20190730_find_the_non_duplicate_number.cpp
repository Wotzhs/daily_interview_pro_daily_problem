#include <iostream>
#include <vector>
using namespace std;

/*

This problem was recently asked by Facebook:

Given a list of numbers, where every number shows up twice except for one number, find that one number.

Example:
Input: [4, 3, 2, 4, 1, 3, 2]
Output: 1
Here's the function signature:

def singleNumber(nums):
  # Fill this in.

print singleNumber([4, 3, 2, 4, 1, 3, 2])
# 1

Challenge: Find a way to do this using O(1) memory.

*/

// TC - o(n)
// SC - o(1)
int singleNumber(vector<int> nums) {
	if (!nums.size()) {
		return -1;
	}

	int ans=nums.front();
	for (int i=1; i<nums.size(); i++) {
		ans^=nums[i];
	}

	return ans;
}

int main() {
	cout << singleNumber({4,3,2,4,1,3,2}) << "\n"; // 1
	return 0;
}
