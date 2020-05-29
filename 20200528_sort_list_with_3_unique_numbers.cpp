#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <algorithm>
using namespace std;

/*

This problem was recently asked by Google:

Given a list of numbers with only 3 unique numbers (1, 2, 3), sort the list in O(n) time.

Example 1:
Input: [3, 3, 2, 1, 3, 2, 1]
Output: [1, 1, 2, 2, 3, 3, 3]
def sortNums(nums):
  # Fill this in.

print sortNums([3, 3, 2, 1, 3, 2, 1])
# [1, 1, 2, 2, 3, 3, 3]

Challenge: Try sorting the list using constant space.

*/

/*	Complexity Analysis
	---------------------------
	o(n) time complexity
		list traversal o(n)
		build new list o(n)

	o(1) space complexity
		unordered_map max entries = o(3)
		space used in finding min, mid, max = o(3)
		o(3) ≈ o(1)
*/
vector<int> sortNums(vector<int> v) {
	unordered_map<int, int> mp;
	for (int i: v) {
		if (mp.find(i) == mp.end()) mp[i] = 1;
		else mp[i]++;
	}

	int n1 = mp.begin()->first;
	int n2 = (++mp.begin())->first;
	int n3 = (++(++mp.begin()))->first;

	int hi = max({n1, n2, n3});
	int lo = min({n1, n2, n3});
	int mid = n1+n2+n3-hi-lo;

	vector<int> ans;
	for (int i=0; i<mp[lo];i++) ans.emplace_back(lo);
	for (int i=0; i<mp[mid];i++) ans.emplace_back(mid);
	for (int i=0; i<mp[hi];i++) ans.emplace_back(hi);

	return ans;
}

void print(vector<int> ans) {
	cout << "[";
	for (int i=0; i<ans.size(); i++) {
		cout << ans[i];
		if (i != ans.size()-1) cout << ", ";
	}
	cout << "]\n";
}

int main(){
	print(sortNums({3,3,2,1,3,2,1})); // [1, 1, 2, 2, 3, 3, 3]
	print(sortNums({3,5,0,3,0,0,3,5,5,3})); // [0, 0, 0, 3, 3, 3, 3, 5, 5, 5]

	return 0;
}