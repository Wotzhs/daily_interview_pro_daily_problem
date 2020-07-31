#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/*

This problem was recently asked by Google:

Given a list of numbers and a target number n, find 3 numbers in the list that sums closest to the target number n. There may be multiple ways of creating the sum closest to the target number, you can return any combination in any order.

Here's an example and some starter code.

def closest_3sum(nums, target):
  # Fill this in.
  
print(closest_3sum([2, 1, -5, 4], -1))
# Closest sum is -5+1+2 = -2 OR -5+1+4 = 0
# print [-5, 1, 2]

*/

// TC = o(n^2)
// SC = o(1)
vector<int> closest3Sum(vector<int> nums, int target) {
	int n=nums.size(), diff=INT_MAX, idx=-1;

	for (int i=0; i<n; i++) {
		int sum=0, absSum;
		for (int j=0; j<n; j++)
			if (i!=j) sum += nums[j];

		absSum = abs(sum-target);
		
		if (absSum<diff) {
			diff = absSum;
			idx = i;
		}
	}

	vector<int> ans;
	for (int i=0; i<n; i++)
		if (idx != i) ans.emplace_back(nums[i]);

	return ans;
}

void print(vector<int> ans) {
	cout << "[";
	for (int i=0; i<ans.size(); i++) {
		cout << ans[i];
		if (i<ans.size()-1)cout << ", ";
	}
	cout << "]\n";
}

int main(){
	print(closest3Sum({2,1,-5,4},-1)); // [1, -5, 4]
	print(closest3Sum({2,1,-5,4},-2)); // [2, 1, -5]
	print(closest3Sum({2,1,-5,4},-3)); // [2, 1, -5]
	print(closest3Sum({2,1,-5,4},1)); // [2, -5, 4]
	print(closest3Sum({2,1,-5,4},7)); // [2, 1, 4]
	print(closest3Sum({2,1,-5,4},10)); // [2, 1, 4]
	return 0;
}