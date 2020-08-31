#include <iostream>
#include <vector>
using namespace std;

/*

This problem was recently asked by LinkedIn:

Given a non-empty array where each element represents a digit of a non-negative integer, add one to the integer. The most significant digit is at the front of the array and each element in the array contains only one digit. Furthermore, the integer does not have leading zeros, except in the case of the number '0'.

Example:
Input: [2,3,4]
Output: [2,3,5]
class Solution():
  def plusOne(self, digits):
    # Fill this in.

num = [2, 9, 9]
print(Solution().plusOne(num))
# [3, 0, 0]

*/

// n = length of nums
// TC - o(n);
// SC - o(1);
vector<int> plusOne(vector<int> nums) {
	int i=nums.size()-1;
	for (; i>=0 && nums[i] == 9; i--) nums[i]=0;
	if (i<0) nums.insert(nums.begin(), 1);
	else nums[i]++;

	return nums;
}

void print(vector<int> ans) {
	cout << "[";
	for (int i=0; i<ans.size(); i++) {
		cout << ans[i];
		if (i<ans.size()-1) cout << ", ";
	}
	cout << "]\n";
}

int main() {
	print(plusOne({2,9,9})); // [3, 0, 0]
	print(plusOne({9,9,9})); // [1, 0, 0, 0]
	print(plusOne({9,0,9})); // [9, 1, 0]
	print(plusOne({1,1,1})); // [1, 1, 2]
	print(plusOne({2,3,4})); // [2, 3, 5]

	return 0;
}
