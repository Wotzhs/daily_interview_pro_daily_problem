#include <iostream>

/*

This problem was recently asked by Apple:

Given a sorted list of size n, with m unique elements (thus m < n), modify the list such that the first m unique elements in the list will be sorted, ignoring the rest of the list. Your solution should have a space complexity of O(1). Instead of returning the list (since you are just modifying the original list), you should return what m is.

Here's an example and some starter code.

def remove_dups(nums):
  # Fill this in.

nums = [1, 1, 2, 3, 4, 4, 4, 4, 4, 5, 5, 6, 7, 9]
print(remove_dups(nums))
# 8
print(nums)
# [1, 2, 3, 4, 5, 6, 7, 9]

nums = [1, 1, 1, 1, 1, 1]
print(remove_dups(nums))
print(nums)
# 1
# [1]

*/

// credits: https://www.geeksforgeeks.org/remove-duplicates-sorted-array/
int removeDuplicates(int *arr, int n) {
	int j=0, tmp[n]={0};
	for (int i=0; i < n-1; i++)
		if (arr[i] != arr[i+1]) tmp[j++] = arr[i];
	tmp[j++] = arr[n-1];

	for (int i=0; i < j; i++)
		arr[i] = tmp[i];

	return j;
}

int main(){
	int a[] = {1, 1, 2, 3, 4, 4, 4, 4, 4, 5, 5, 6, 7, 9}, asz = sizeof(a)/sizeof(a[0]);
	int ans = removeDuplicates(a, asz);
	std::cout << ans << "\n["; // 8
	for (int i=0; i < ans; i++) {
		std:: cout << a[i];
		if (i < ans-1) std::cout << ", ";
	}
	std::cout << "]\n"; // [1, 2, 3, 4, 5, 6, 7, 9]


	int b[] = {1, 1, 1, 1, 1, 1}, bsz = sizeof(b)/sizeof(b[0]);
	ans = removeDuplicates(b, bsz);
	std::cout << ans << "\n["; // 1
	for (int i=0; i < ans; i++) {
		std:: cout << a[i];
		if (i < ans-1) std::cout << ", ";
	}
	std::cout << "]\n"; // [1]
	return 0;
}