#include <iostream>
#include <vector>
using namespace std;

/*

This problem was recently asked by Twitter:

Find the k-th largest number in a sequence of unsorted numbers.

def findKthLargest(arr, k):
  # Fill this in.
  
print(findKthLargest([8, 7, 2, 3, 4, 1, 5, 6, 9, 0], 3))
# 7

Can you do this in linear time?

*/

int partition(vector<int>& nums, int left, int right) {
	for (int i=left; i<right;i++) {
		if (nums[i] < nums[right]) swap(nums[i], nums[left++]);
	}

	swap(nums[left], nums[right]);
	return left;
}

int findKthLargest(vector<int> nums, int k) {
	int i=0, n=nums.size(), j=n-1, target=n-k;
	
	// credit: https://leetcode.com/problems/kth-largest-element-in-an-array/discuss/60328/C%2B%2B-O(nlogn)-and-O(n)-using-partition
	while (i < j) {
		int pivot = partition(nums, i, j);
		if (pivot == target) break;
		if (pivot < target) i = pivot+1;
		else j = pivot-1;
	}
	
	return nums[target];
}

int main(){
	cout << findKthLargest({8, 7, 2, 3, 4, 1, 5, 6, 9, 0}, 3) << "\n"; // 7
	cout << findKthLargest({8, 7, 2, 3, 4, 1, 5, 6, 9, 0}, 4) << "\n"; // 6
	cout << findKthLargest({8, 7, 2, 3, 4, 1, 5, 6, 9, 0}, 6) << "\n"; // 4
	cout << findKthLargest({8, 7, 2, 3, 4, 1, 5, 6, 9, 0}, 2) << "\n"; // 8
	cout << findKthLargest({3,2,3,1,2,4,5,5,6,7,7,8,2,3,1,1,1,10,11,5,6,2,4,7,8,5,6}, 11) << "\n"; //
	cout << findKthLargest({0,0,0,0,0,0, 1,1, 1}, 6) << "\n"; // 4
	return 0;
}