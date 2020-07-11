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

bool canThreePartsEqualSum(vector<int> nums) {
	int lo=0, hi=nums.size()-1, p1=0, p2=0;
	while(lo<hi) {
		p1 += nums[lo++];
		p2 += nums[hi--];
		if (p1 == p2) {
			int p3=0;
			for (int i=lo; i<=hi; i++) {
				p3+=nums[i];
			}
			if (p3 == p1) return true;
		}
	}

	return false;
}

int main(){
	cout << canThreePartsEqualSum({0,2,1,-6,6,-7,9,1,2,0,1}) << "\n"; // true
	return 0;
}