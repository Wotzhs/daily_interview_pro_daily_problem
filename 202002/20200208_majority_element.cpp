#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*

This problem was recently asked by AirBNB:

A majority element is an element that appears more than half the time. Given a list with a majority element, find the majority element.

Here's an example and some starting code.

def majority_element(nums):
  # Fill this in.

print(majority_element([3, 5, 3, 3, 2, 4, 3]))
# 3

*/

// TC - o(n)
// SC - o(n)
int majorityElement(vector<int> nums) {
	unordered_map<int, int> freq;
	for (int i: nums) {
		freq[i]++;
	}
	
	for (auto it = freq.begin(); it != freq.end(); it++) {
		if (it->second > nums.size() / 2) {
			return it->first;
		}
	}
	return -1;
}

int main() {
	cout << majorityElement({3,5,3,3,2,4,3}) << "\n"; // 3
	cout << majorityElement({1,1,2}) << "\n"; // 1
	return 0;
}
