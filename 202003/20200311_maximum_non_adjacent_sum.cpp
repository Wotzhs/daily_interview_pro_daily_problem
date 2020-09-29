#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/*

This problem was recently asked by Google:

Given a list of positive numbers, find the largest possible set such that no elements are adjacent numbers of each other.

Here's some example and some starter code

def maxNonAdjacentSum(nums):
  # Fill this in.
  
print(maxNonAdjacentSum([3, 4, 1, 1]))
# 5
# max sum is 4 (index 1) + 1 (index 3)

print(maxNonAdjacentSum([2, 1, 2, 7, 3]))
# 9
# max sum is 2 (index 0) + 7 (index 3)

*/

// TC - o(n)
// SC - o(i)
int maxNonAdjacentSum(vector<int> nums) {
	int mxi=INT_MIN, ans, idx;
	for (int i=0; i<nums.size(); i++) {
		if (nums[i]>mxi) {
			mxi = nums[i];
			idx = i;
		}
	}

	nums[idx] = 0;
	if (idx+1<nums.size())	{
		nums[idx+1] = 0;
	}
	
	if (idx-1>=0)	{
		nums[idx-1] = 0;
	}
	
	ans = mxi;
	mxi = INT_MIN;

	for (int i=0; i<nums.size(); i++) {
		if (nums[i]>mxi) {
			mxi = nums[i];
		}
	}
	return ans+mxi;
}

int main() {
	cout << maxNonAdjacentSum({3,4,1,1}) << "\n"; // 5
	cout << maxNonAdjacentSum({2,1,2,7,3}) << "\n"; // 9
	return 0;
}
