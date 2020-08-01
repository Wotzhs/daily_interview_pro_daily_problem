#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*

This problem was recently asked by Microsoft:

You are given an array of intervals - that is, an array of tuples (start, end). The array may not be sorted, and could contain overlapping intervals. Return another array where the overlapping intervals are merged.

For example:
[(1, 3), (5, 8), (4, 10), (20, 25)]

This input should return [(1, 3), (4, 10), (20, 25)] since (5, 8) and (4, 10) can be merged into (4, 10).

Here's a starting point:

def merge(intervals):
  # Fill this in.
  
print merge([(1, 3), (5, 8), (4, 10), (20, 25)])
# [(1, 3), (4, 10), (20, 25)]

*/

typedef pair<int, int> pii;
typedef vector<pii> vpii;

vpii merge(vpii intervals) {
	sort(intervals.begin(), intervals.end(), [&](pii const a, pii const b){
		return a.first < b.first;
	});
	vpii merged={intervals[0]};
	for (int i=1; i<intervals.size(); i++) {
		pii curr = intervals[i], prev = merged[merged.size()-1];
		
		if (curr.first > prev.second)
			merged.emplace_back(make_pair(curr.first, curr.second));
		if (curr.first <= prev.second && curr.second > prev.second)
			merged.back().second = curr.second;
	}
	return merged;
}

void print(vpii ans) {
	cout << "[";
	for (int i=0; i<ans.size(); i++) {
		cout << "(" << ans[i].first << ", " << ans[i].second << ")";
		if (i<ans.size()-1) cout << ", ";
	}
	cout << "]\n";
}

int main(){
	print(merge({{1,3},{5,8},{4,10},{20,25}})); // [(1, 3), (4, 10), (20, 25)]
	print(merge({{1,3},{2,8},{4,10},{20,25}})); // [(1, 10), (4, 8), (9, 10), (20, 25)]
	print(merge({{1,3},{2,8},{7,10},{20,25}})); // [(1, 3), (4, 8), (9, 10), (20, 25)]
	print(merge({{1,4},{0,2},{3,5}})); // [(0,5)]
	print(merge({{1,4},{0,4}})); // [(0, 4)]
	print(merge({{1,4},{1,4}})); // [(1, 4)]
	print(merge({{1,3},{2,6},{8,10},{15,18}})); // [(1, 6), (8, 10), (15, 18)]
	print(merge({{1,3}})); // [(1, 3)]
	print(merge({{}})); // [(0, 0)]
	print(merge({{1,4},{4,5}})); // [(1, 5)]

	return 0;
}