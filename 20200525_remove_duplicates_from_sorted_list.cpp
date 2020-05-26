#include <iostream>
#include <vector>
using namespace std;

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

int removeDuplicates(vector<int> *nums) {
	vector<int> tmp;
	for (int i=0; i<nums->size()-1; i++)
		if (nums->at(i) != nums->at(i+1)) tmp.emplace_back(nums->at(i));
	tmp.emplace_back(nums->at(nums->size()-1));

	for (int i=0; i<tmp.size(); i++)
		nums->at(i) = tmp[i];

	return tmp.size();
}

int main(){
	vector<int> numsA = {1, 1, 2, 3, 4, 4, 4, 4, 4, 5, 5, 6, 7, 9};
	int ansA = removeDuplicates(&numsA);

	cout << ansA << "\n["; // 8
	for (int i=0; i<ansA; i++) {
		cout << numsA[i];
		if (i < ansA-1) cout << ", ";
	}
	cout << "]\n"; // [1, 2, 3, 4, 5, 6, 7, 9]


	vector<int> numsB = {1, 1, 1, 1, 1, 1};
	int ansB = removeDuplicates(&numsB);

	cout << ansB << "\n["; // 1
	for (int i=0; i<ansB; i++) {
		cout << numsB[i];
		if (i < ansB-1) cout << ", ";
	}
	cout << "]\n"; // [1]

	return 0;
}