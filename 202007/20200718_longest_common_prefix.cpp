#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

/*

This problem was recently asked by Microsoft:

Given a list of strings, find the longest common prefix between all strings.

Here's some examples and some starter code.

def longest_common_prefix(strs):
  # Fill this in.
  
print(longest_common_prefix(['helloworld', 'hellokitty', 'hell']))
# hell

print(longest_common_prefix(['daily', 'interview', 'pro']))
# ''

*/

class Trie {
public:
	bool isEnd = false;
	Trie* children[26];
};

string longestCommonPrefix(vector<string> strs) {
	string shortest="", ans;
	int shortestSZ=INT_MAX, skip=0;
	for (int i=0; i<strs.size(); i++) {
		if (strs[i].size() < shortestSZ) {
			shortestSZ = strs[i].size();
			shortest = strs[i];
			skip = i;
		}
	}

	Trie* trie = new Trie;
	Trie* t = trie;
	for (char ch: shortest) {
		if (t->children[ch-'a'] == nullptr) {
			t->children[ch-'a'] = new Trie;
		}
		t = t->children[ch-'a'];
	}
	t->isEnd = true;

	for (int i=0; i<strs.size(); i++) {
		if (i == skip) continue;
		t = trie;
		for (char ch: strs[i]) {
			if (t->children[ch-'a'] == nullptr) {
				t->isEnd = true;
				break;
			}
			t = t->children[ch-'a'];
		}
	}

	t = trie;
	for (char ch: shortest) {
		if (t->isEnd) break;
		else ans += ch;
		t = t->children[ch-'a'];
	}

	return ans;
}

int main(){
	cout << longestCommonPrefix({"helloworld","hellokitty","hell"}) << "\n"; // hell
	cout << longestCommonPrefix({"hell","helloworld","hellokitty"}) << "\n"; // hell
	cout << longestCommonPrefix({"daily","interview","pro"}) << "\n"; // 
	return 0;
}