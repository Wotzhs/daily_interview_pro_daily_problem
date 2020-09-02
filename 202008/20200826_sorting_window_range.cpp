#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

/*

This problem was recently asked by Twitter:

Given a list of numbers, find the smallest window to sort such that the whole list will be sorted. If the list is already sorted return (0, 0). You can assume there will be no duplicate numbers.

Example:
Input: [2, 4, 7, 5, 6, 8, 9]
Output: (2, 4)
Explanation: Sorting the window (2, 4) which is [7, 5, 6] will also means that the whole list is sorted.

def min_window_to_sort(nums):
  # Fill this in.
    
print(min_window_to_sort([2, 4, 7, 5, 6, 8, 9]))
# (2, 4)

*/

// TC - o(nlogn)
// SC - o(n)
pair<int, int> minWindowToSort(vector<int> nums) {
	int lo=-1, hi=0;
	vector<int> nums2 = nums;
	sort(nums.begin(), nums.end());
	for (int i=0; i<nums.size(); i++) 
		if (nums[i] != nums2[i]){
			if(lo == -1) lo = i;
			else hi = i;
		}

	return {max(lo, 0), hi};
}

void print(pair<int, int> p) {
	cout << "(" << p.first << ", " << p.second << ")\n";
}

int main() {
	print(minWindowToSort({2,4,7,5,6,8,9})); // (2, 4)
	return 0;
}
