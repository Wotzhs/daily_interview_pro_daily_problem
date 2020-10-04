#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

/*

This problem was recently asked by Apple:

Given a list of strings, find the list of characters that appear in all strings.

Here's an example and some starter code:

def common_characters(strs):
  # Fill this in.

print(common_characters(['google', 'facebook', 'youtube']))
# ['e', 'o']

*/

// n - sum of all the str in strs
// TC - o(n)
// SC - o(n)
vector<char> commonCharacters(vector<string> strs) {
	vector<char> ans;
	if (!strs.size()) {
		return ans;
	}

	unordered_map<char, int> freq;
	for (string s: strs) {
		unordered_map<char, bool> tmpFreq;
		for (char ch: s) {
			tmpFreq[ch] = true;
		}
		for (auto it=tmpFreq.begin(); it!=tmpFreq.end(); it++) {
			freq[it->first]++;
		}
	}
	
	for (auto it=freq.begin(); it!=freq.end(); it++) {
		if (it->second == strs.size()) {
			ans.emplace_back(it->first);
		}
	}

	return ans;
}

void print(vector<char> ans) {
	cout << "[";
	for (int i=0; i<ans.size(); i++) {
		cout << "'" << ans[i] << "'";
		if (i<ans.size()-1) {
			cout << ", ";
		}
	}
	cout << "]\n";
}

int main() {
	print(commonCharacters({"google", "facebook", "youtube"})); // ['e', 'o']
	return 0;
}
