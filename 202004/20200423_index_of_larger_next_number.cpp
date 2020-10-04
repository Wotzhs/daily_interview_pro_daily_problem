#include <iostream>
#include <vector>
using namespace std;

/*

This problem was recently asked by Google:

Given a list of numbers, for each element find the next element that is larger than the current element. Return the answer as a list of indices. If there are no elements larger than the current element, then use -1 instead.

Here's an example and some starter code:

def larger_number(nums):
  # Fill this in.
  
# print [2, 2, 3, 4, -1, -1]
print(larger_number([3, 2, 5, 6, 9, 8]))

*/

// TC - o(n)
// SC - o(n)
vector<int> largerNumber(vector<int> nums) {
	if (!nums.size()) {
		return nums;
	}

	// outer pair - first tracks the last largest index of the last number
	// inner pair - first tracks the largest number before the last
	// inner pair - second tracks the index of the largest number before the last
	vector<pair<int, pair<int, int>>> track(nums.size());
	track[nums.size()-1] = {-1, {nums[nums.size()-1], nums.size()-1}};
	for (int i=track.size()-2; i>=0; i--) {
		if (nums[i]>=nums[i+1]) {
			if (nums[i]>=track[i+1].second.first) {
				track[i] = {-1, {nums[i], i}};
			}
			else {
				track[i] = {track[i+1].second.second, {track[i+1].second.first, track[i+1].second.second}};
			}
		}
		else {
			track[i] = {i+1, {nums[i+1], i+1}};
		}
	}
	
	vector<int> ans(nums.size());
	for (int i=0; i<track.size(); i++) {
		ans[i] = track[i].first;
	}
	
	return ans;
}

void print(vector<int> ans) {
	cout << "[";
	for (int i=0; i<ans.size(); i++) {
		cout << ans[i];
		if (i<ans.size()-1) {
			cout << ", ";
		}
	}
	cout << "]\n";
}

int main() {
	print(largerNumber({3,2,5,6,9,8})); // [2, 2, 3, 4, -1, -1]
	print(largerNumber({1,1,1,1,1,1})); // [-1, -1, -1, -1 -1, -1]
	return 0;
}
