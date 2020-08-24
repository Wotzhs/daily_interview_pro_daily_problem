#include <iostream>
#include <vector>
#include <algorithm>
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
typedef pair<int, int> pii;

pii minWindowToSort(vector<int> nums) {
	int lo=-1, hi=0;
	vector<int> nums2 = nums;
	sort(nums2.begin(), nums2.end());
	for (int i=0; i<nums.size(); i++) {
		if (nums[i] != nums2[i]) {
			if (lo==-1) lo=i;
			else hi=i;
		}
	}
	return {max(lo,0),hi};
}

void print(pii ans) {
	cout << "(" << ans.first << ", " << ans.second << ")\n";
}

int main() {
	print(minWindowToSort({2,4,7,5,6,8,9})); // (2, 4)
	print(minWindowToSort({7,6,5,4,3,2,1})); // (0, 6)
	print(minWindowToSort({2,4,7,5,6,9,1})); // (0, 6)
	print(minWindowToSort({1,2,3,4,5,6,7})); // (0, 0)

	return 0;
}
