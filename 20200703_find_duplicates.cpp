#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*

This problem was recently asked by Amazon:

Given an array of size n, and all values in the array are in the range 1 to n, find all the duplicates.

class Solution(object):
  def findDuplicates(self, nums):
    # Fill this in.

print(Solution().findDuplicates([4,3,2,7,8,2,3,1]))
# [2, 3]

*/

vector<int> findDuplicates(vector<int> nums) {
	vector<int> ans;
	unordered_map<int, int> mp;
	for (int i: nums)
		if(++mp[i]>1) ans.emplace_back(i);

	return ans;
}

void print(vector<int> ans) {
	cout<<"[";
	for (int i=0;i<ans.size();i++) {
		cout<<ans[i];
		if(i<ans.size()-1) cout<<", ";
	}
	cout<<"]\n";
}

int main(){
	print(findDuplicates({4,3,2,7,8,2,3,1})); // [2, 3]
	return 0;
}