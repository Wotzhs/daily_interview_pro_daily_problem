#include <iostream>
#include <vector>
#include <set>
using namespace std;

/*

This problem was recently asked by Google:

You are given a stream of numbers. Compute the median for each new element .

Eg. Given [2, 1, 4, 7, 2, 0, 5], the algorithm should output [2, 1.5, 2, 3.0, 2, 2, 2]

Here's a starting point:

def running_median(stream):
  # Fill this in.

running_median([2, 1, 4, 7, 2, 0, 5])
# 2 1.5 2 3.0 2 2.0 2

*/

// n - size of stream vector
// TC - o(n)
// SC - o(n)
vector<double> runningMedian(vector<int> stream) {
	multiset<int> streamset;
	vector<double> ans;
	for (int v: stream) {
		streamset.insert(v);
		if (streamset.size()&1) ans.emplace_back(*next(streamset.begin(), streamset.size()/2));
		else {
			auto mid = next(streamset.begin(), streamset.size()/2);
			ans.emplace_back((*mid+*prev(mid))/2.0);
		}
	}
	return ans;
}

void print(vector<double> ans) {
	for (int i=0; i<ans.size(); i++) {
		cout << ans[i];
		if (i < ans.size()-1) cout << ", ";
	}
	cout << "\n";
}

int main() {
	print(runningMedian({2,1,4,7,2,0,5})); // 2 1.5 2 3.0 2 2.0 2
	print(runningMedian({2})); // 2
	print(runningMedian({})); //
	print(runningMedian({0,0,0,0,0,0,0})); // 0, 0, 0, 0, 0, 0, 0

	return 0;
}
