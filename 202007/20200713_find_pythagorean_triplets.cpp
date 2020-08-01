#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool findPythagoreanTriplets(vector<int> nums) {
	unordered_map<int, bool> mp;
	for (int i=0; i<nums.size(); i++) {
		nums[i] = nums[i]*nums[i];
		mp[nums[i]] = true;
	}
	for (int i=0; i<nums.size(); i++)
		for (int j=i+1; j<nums.size(); j++)
			if (mp.find(nums[i]+nums[j]) != mp.end()) return true;
	
	return false;
}

int main(){
	cout << findPythagoreanTriplets({3,12,5,13}) << "\n"; // true
	cout << findPythagoreanTriplets({13,5,12,3}) << "\n"; // true
	cout << findPythagoreanTriplets({13,11,5,3}) << "\n"; // false
	return 0;
}