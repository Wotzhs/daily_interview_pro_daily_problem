#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>
using namespace std;
/*

This problem was recently asked by AirBNB:

Given a non-empty list of words, return the k most frequent words. The output should be sorted from highest to lowest frequency, and if two words have the same frequency, the word with lower alphabetical order comes first. Input will contain only lower-case letters.

Example:
Input: ["daily", "interview", "pro", "pro", 
"for", "daily", "pro", "problems"], k = 2
Output: ["pro", "daily"]
class Solution(object):
  def topKFrequent(self, words, k):
    # Fill this in.

words = ["daily", "interview", "pro", "pro", "for", "daily", "pro", "problems"]
k = 2
print(Solution().topKFrequent(words, k))
# ['pro', 'daily']

*/

vector<pair<string, int>> topKFrequent(vector<string> words, int k) {
	unordered_map<string, int> mp;
	vector<pair<string, int>> ans;

	for (string s: words)
		mp[s]++;

	priority_queue<pair<int, string>> pq;

	for (auto it = mp.begin(); it != mp.end(); it++)
		pq.emplace(make_pair(it->second, it->first));

	for (int i=0; i<k; i++) {
		if (!pq.size()) break;

		auto p = pq.top();
			pq.pop();
			ans.emplace_back(make_pair(p.second, p.first));
		
		while(pq.size() && pq.top().first == p.first) {
			auto next = pq.top();
			pq.pop();
			ans.emplace_back(make_pair(next.second, next.first));
		}
	}

	sort(ans.begin(), ans.end(), [&](auto a, auto b) {
		if (a.second == b.second) 
			return a.first < b.first;
		return a.second > b.second;
	});

	return ans;
}

void print(vector<pair<string, int>> ans) {
	cout << "[";
	for (int i=0; i<ans.size(); i++) {
		cout << ans[i].first;
		if (i<ans.size()-1) cout << ", ";
	}
	cout << "]\n";
}

int main(){
	print(topKFrequent({"daily","interview","pro","pro","for","daily","pro","problems"}, 2)); // ['pro', 'daily']
	print(topKFrequent({"daily","interview","pro","for","daily","pro","problems"}, 2)); // ['pro', 'daily']
	print(topKFrequent({"daily","interview","pro","for","daily","pro","problems"}, 3)); // ['pro', 'daily']
	return 0;

	// {"daily","daily","pro","pro", "problems", "problems", "abc"}
}