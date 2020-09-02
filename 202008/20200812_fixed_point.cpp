#include <iostream>
#include <vector>
using namespace std;

/*

This problem was recently asked by Apple:

A fixed point in a list is where the value is equal to its index. So for example the list [-5, 1, 3, 4], 1 is a fixed point in the list since the index and value is the same. Find a fixed point (there can be many, just return 1) in a sorted list of distinct elements, or return None if it doesn't exist.

Here is a starting point:

def find_fixed_point(nums):
  # Fill this in.

print find_fixed_point([-5, 1, 3, 4])
# 1

Can you do this in sublinear time?

*/

// TC - o(log n)
// SC - o(1)
int findFixedPoint(vector<int> nums) {
	if (nums.front() == 0) return 0;
	if (nums.back() == nums.size()-1) return nums.back();
	int lo=1, hi=nums.size()-2;
	while(lo<hi) {
		int mid = lo+(hi-lo)/2;
		if (nums[mid]==mid) return mid;
		if (nums[mid]>mid) hi=mid-1;
		else lo=mid+1;
	}
	return -1;
}

int main() {
	cout << findFixedPoint({-5,1,3,4}) << "\n"; // 1
	cout << findFixedPoint({-5,-4,-3,-2,-1,0,1,7}) << "\n"; // 7
	cout << findFixedPoint({1,2,3,3,4,5,7}) << "\n"; // 3
	cout << findFixedPoint({-5,-2,-1}) << "\n"; // -1
	return 0;
}
