#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
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
	sort(nums.begin(), nums.end());
	int a, b, c;
	for (int i=0, diff=INT_MAX; i<nums.size() && diff != 0; i++) {
		int lo=i+1, hi=nums.size()-1;
		while (lo<hi) {
			int currSum = nums[i]+nums[lo]+nums[hi];
			if (abs(currSum-target) < diff) {
				diff = abs(currSum-target);
				a=nums[i], b=nums[lo], c=nums[hi];
			}
			if (currSum < target) lo++;
			else hi--;
		}
	}
	
	return {a, b, c};
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
	print(closest3Sum({-1,2,1,-4},1)); // [-1, 2, 1]
	print(closest3Sum({-1,2,1,-4,1,2,3},1)); // [-4,2,3]
	return 0;
}