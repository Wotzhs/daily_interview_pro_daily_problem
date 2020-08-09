#include <iostream>
#include <vector>
using namespace std;

/*

This problem was recently asked by Apple:

Given an array of numbers, determine whether it can be partitioned into 3 arrays of equal sums.

For instance,
[0, 2, 1, -6, 6, -7, 9, 1, 2, 0, 1] can be partitioned into:
[0, 2, 1], [-6, 6, -7, 9, 1], [2, 0, 1] all of which sum to 3.

class Solution(object):
    def canThreePartsEqualSum(self, A):
          # Fill this in.0

	  print(Solution().canThreePartsEqualSum(
	      [0, 2, 1, -6, 6, -7, 9, 1, 2, 0, 1]))
# True

*/

// TC - o(n);
// SC - o(1)
bool canThreePartsEqualSum2(vector<int> nums) {
	int lo=0, hi=nums.size()-1, sumLeft=nums[lo], sumRight=nums[hi], sumMid=0;

	for (int i=lo+1; i<=hi-1; i++) sumMid += nums[i];

	while(sumLeft != sumRight || sumLeft == sumRight && sumLeft != sumMid) {
		if (sumLeft == sumRight && sumLeft == sumMid) return true;
		if (lo>hi) return false;
		
		if (sumLeft<sumRight) sumLeft += nums[++lo], sumMid -= nums[lo];
		else sumRight += nums[--hi], sumMid -= nums[hi];
	}

	return true;
}

// TC - o(n^2)
// SC - o(1)
bool canThreePartsEqualSum(vector<int> nums) {
	int lo=0, hi=nums.size()-1, sumLeft=nums[lo], sumRight=nums[hi];
	while(lo<hi) {
		while(sumLeft != sumRight && lo<hi) {
			if (sumLeft<sumRight) sumLeft += nums[++lo];
			else sumRight += nums[--hi];
		}

		int sumMid=0;
		
		for (int i=lo+1; i<=hi-1; i++) sumMid += nums[i];
		if (sumMid == sumLeft) return true;

		sumLeft += nums[++lo];
	}
	return false;
}

int main() {
	cout << canThreePartsEqualSum({0,2,1,-6,6,-7,9,1,2,0,1}) << "\n"; // true
	cout << canThreePartsEqualSum({1,1,1,1}) << "\n"; // false
	cout << canThreePartsEqualSum({1,1,1}) << "\n"; // true
	cout << canThreePartsEqualSum({1,1}) << "\n"; // false
	cout << canThreePartsEqualSum({1}) << "\n"; // false

	cout << "\n";
	
	cout << canThreePartsEqualSum2({0,2,1,-6,6,-7,9,1,2,0,1}) << "\n"; // true
	cout << canThreePartsEqualSum2({1,1,1,1}) << "\n"; // false
	cout << canThreePartsEqualSum2({1,1,1}) << "\n"; // true
	cout << canThreePartsEqualSum2({1,1}) << "\n"; // false
	cout << canThreePartsEqualSum2({1}) << "\n"; // false

	return 0;
}
