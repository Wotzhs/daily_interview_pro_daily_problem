#include <iostream>
#include <algorithm>
#include <vector>

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

std::vector<int> plusOne(std::vector<int> nums) {
	if (nums.back()+1 < 9) {
		nums[nums.size()-1] += 1;
		return nums;
	}

	std::reverse(nums.begin(), nums.end());
	bool carryOver = false;
	for (int i=0; i < nums.size(); i++) {
		if (nums[i]+1 > 9) {
			nums[i] = 0;
			carryOver = true;
			continue;
		}
		if (carryOver && nums[i]+1>9) {
			nums[i] = 0;
			continue;
		}
		nums[i] += 1;
		carryOver = false;
		break;
	}

	if (carryOver) nums.emplace_back(1);

	std::reverse(nums.begin(), nums.end());
	return nums;
}

void printResult(std::vector<int> ans) {
	for (int i: ans) 
		std::cout << i << " ";
	std::cout << "\n";
}

int main () {
	printResult(plusOne({2, 9, 9})); // 3 0 0
	printResult(plusOne({9, 9, 9})); // 1 0 0 0
	printResult(plusOne({2, 3, 4})); // 2 3 5
	printResult(plusOne({1, 8, 9})); // 1 9 0
	printResult(plusOne({1, 0, 9, 9})); // 1 1 0 0

	return 0;
}

