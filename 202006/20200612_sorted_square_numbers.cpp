#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

/*

This problem was recently asked by Microsoft:

Given a list of sorted numbers (can be both negative or positive), return the list of numbers squared in sorted order.

Here's an example and some starting code:

def square_numbers(nums):
 # Fill this in.

print(square_numbers([-5, -3, -1, 0, 1, 4, 5]))
# [0, 1, 1, 9, 16, 25, 25]

Solve this problem in O(n) time.

*/

vector<int> squareNumbers(vector<int> &nums) {
	vector<int> negatives;
	vector<int> positives;
	for (int i: nums) {
		if (i < 0) negatives.emplace_back(i*i);
		else positives.emplace_back(i*i);
	}

	// reverse because negatives are sorted ascendingly before square
	reverse(negatives.begin(), negatives.end());

	vector<int> ans(nums.size(), 0);
	int i=0, j=0;
	while(i+j < nums.size()) {
		int a=INT_MAX, b=INT_MAX;
		if (i < negatives.size()) a = negatives[i];
		if (j < positives.size()) b = positives[j];
		if (a < b) ans[(i++) + j] = a;
		else ans[i + (j++)] = b;
	}

	return ans;
}

void print(vector<int> nums) {
	cout << "[";
	for (int i=0; i<nums.size(); i++) {
		cout << nums[i];
		if (i < nums.size()-1) cout << ", ";
	}
	cout << "]\n";
}

int main(){
	vector<int> nums1 = {-5, -3, -1, 0, 1, 4, 5};
	print(squareNumbers(nums1)); // [0, 1, 1, 9, 16, 25, 25]

	vector<int> nums2 = {0, 1, 4, 5};
	print(squareNumbers(nums2)); // [0, 1, 16, 25]

	vector<int> nums3 = {-5, -3, -1, 0};
	print(squareNumbers(nums3)); // [0, 1, 9, 25]
	return 0;
}