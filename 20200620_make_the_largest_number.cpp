#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

/*

This problem was recently asked by Uber:

Given a number of integers, combine them so it would create the largest number.

Example:
Input:  [17, 7, 2, 45, 72]
Output:  77245217
def largestNum(nums):
  # Fill this in.

print largestNum([17, 7, 2, 45, 72])
# 77245217

*/

#define ll long long

// credit: https://www.geeksforgeeks.org/given-an-array-of-numbers-arrange-the-numbers-to-form-the-biggest-number/
int largestNum(vector<int> nums) {
	sort(nums.begin(),nums.end(), [](int a, int b) {
		string stra = to_string(a), strb = to_string(b);
		string ab = stra.append(strb), ba = strb.append(stra);
		return ab > ba;
	});

	stringstream ss;
	for (int i: nums)
		ss << i;

	ll ans;
	ss >> ans;
	return ans;
}

int main(){
	cout << largestNum({17, 7, 2, 45, 72}) << "\n"; // 77245217
	cout << largestNum({123, 1, 9, 7, 8}) << "\n"; // 9871231
	cout << largestNum({451, 4, 6, 7, 8}) << "\n"; // 8764514
	cout << largestNum({3,30,34,5,9}) << "\n"; // 9534330
	cout << largestNum({128,12}) << "\n"; // 12812
	cout << largestNum({0, 0, 0}) << "\n"; // 0
	cout << largestNum({10,2}) << "\n"; // 210
	return 0;
}