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

vector<float> runningMedian(vector<int> stream) {
	multiset<int> s;
	vector<float> ans;
	for (int i=0; i<stream.size(); i++) {
		s.insert(stream[i]);
		if (s.size()&1) {
			ans.emplace_back(*next(s.begin(), s.size()/2));
		}
		else {
			auto a= next(s.begin(), s.size()/2);
			ans.emplace_back((*a+*prev(a))/2.0);
		}
	}

	return ans;
}

void print(vector<float> ans) {
	for (float i: ans)
		cout << i << " ";
	cout << "\n";
}

int main(){
	print(runningMedian({2,1,4,7,2,0,5})); // 2 1.5 2 3.0 2 2.0 2

	return 0;
}