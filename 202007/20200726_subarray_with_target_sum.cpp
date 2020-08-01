#include <iostream>
#include <vector>
using namespace std;

/*

This problem was recently asked by Amazon:

You are given an array of integers, and an integer K. Return the subarray which sums to K. You can assume that a solution will always exist.

def find_continuous_k(list, k):
  # Fill this in.

print find_continuous_k([1, 3, 2, 5, 7, 2], 14)
# [2, 5, 7]

Can you do this in linear time?

*/

vector<int> findContinuousK(vector<int> list, int k) {
	vector<int> ans;
	int l=0, r=0, sum=0;
	while(r<list.size()) {
		sum += list[r++];
		while (sum>k) sum -= list[l++];

		if (sum == k) {
			ans = vector<int>(list.begin()+l, list.begin()+r);
			break;
		}
	}
	return ans;	
}

void print(vector<int> ans) {
	cout << "[";
	for (int i=0; i<ans.size(); i++) {
		cout << ans[i];
		if (i<ans.size()-1) cout << ", ";
	}
	cout << "]\n";
}

int main(){
	print(findContinuousK({1,3,2,5,7,2}, 14)); // [2, 5, 7]
	return 0;
}