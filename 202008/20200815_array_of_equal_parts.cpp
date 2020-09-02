#include <iostream>
#include <vector>
using namespace std;

/*

This problem was recently asked by Twitter:

Given an array containing only positive integers, return if you can pick two integers from the array which cuts the array into three pieces such that the sum of elements in all pieces is equal.

Example 1:
Input: array = [2, 4, 5, 3, 3, 9, 2, 2, 2]

Output: true
Explanation: choosing the number 5 and 9 results in three pieces [2, 4], [3, 3] and [2, 2, 2]. Sum = 6.

Example 2:
Input: array =[1, 1, 1, 1],

Output: false
Here's a starting point:

class Solution(object):
  def canPick2(self, arr):
      # Fill this in.

print(Solution().canPick2([2, 4, 5, 3, 3, 9, 2, 2, 2]))
# True

print(Solution().canPick2([1, 2, 3, 4, 5]))
# False

*/

// TC - o(n^2) ?? 
// SC - o(1)
bool canPick2(vector<int> nums) {
	if (nums.size()<5) return false;
	int sumFromLeft=0, sumFromRight=0;
	for (int l=0, r=nums.size(); l<r;) {
		sumFromLeft += nums[l];
		sumFromRight += nums[r];
		while(sumFromLeft!=sumFromRight) {
			if (l>r) return false;
			else if (sumFromLeft<sumFromRight) sumFromLeft += nums[l++];
			else sumFromRight += nums[r--];
		}
		int pick1=l+1, pick2=r-1, sumMid=0;
		for (int i=pick1+1; i<=pick2; i++) {
			sumMid += nums[i];
			if (sumMid == sumFromLeft) {
				return true;
			}
		}
		l++; r--;
	}
	return false;
}

int main() {
	cout << canPick2({2,4,5,3,3,9,2,2,2}) << "\n"; // true
	cout << canPick2({1,2,3,4,5}) << "\n"; // false
	cout << canPick2({1,1,1,1,1}) << "\n"; // true
	cout << canPick2({1,1,1,1,1,1}) << "\n"; // false
	cout << canPick2({1,1,1}) << "\n"; // false
	cout << canPick2({1,1,1,1}) << "\n"; // false
	cout << canPick2({1,1,1,2,1,1,1}) << "\n"; // true
	return 0;
}
