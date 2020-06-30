#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

/*

This problem was recently asked by AirBNB:

Implement auto-completion. Given a large set of words (for instance 1,000,000 words) and then a single word prefix, find all words that it can complete to.

class Solution:
  def build(self):
    # Fill this in.
    
  def autocomplete(self, word):
    # Fill this in.

s = Solution()
s.build(['dog', 'dark', 'cat', 'door', 'dodge'])
print(s.autocomplete('do'))
# ['dog', 'door', 'dodge']

Can you solve this optimally (in linear time with regards to the result set)?

*/

class Trie {
public:
	bool isWord=false;
	Trie* children[26]={nullptr};
};

class Solution {
	Trie* trie;
public:
	Solution(): trie(new Trie) {};
	void build(vector<string> words) {
		for (string s: words) {
			Trie* t = trie;
			for (char ch: s) {
				if (t->children[ch-'a'] == nullptr) {
					t->children[ch-'a'] = new Trie;
				}
				t = t->children[ch-'a'];
			}
			t->isWord = true;
		}
	}

	vector<string> autocomplete(string s) {
		vector<string> ans;
		Trie* t = trie;
		for (char ch: s) {
			if (t->children[ch-'a'] == nullptr) return ans;
			t = t->children[ch-'a'];
		}
		
		dfs(t, s, &ans);
		return ans;
	}

	void dfs(Trie* trie, string s, vector<string>* ans) {
		if (trie->isWord) ans->emplace_back(s);
		
		for (int i=0; i<26; i++) {
			if (trie->children[i] != nullptr) {
				s += (i+'a');
				dfs(trie->children[i], s, ans);
				s.pop_back();
			}
		}
	}
};

void print(vector<string> ans) {
	cout << "[";
	for (int i=0; i<ans.size(); i++) {
		cout << "'" << ans[i] << "'";
		if (i<ans.size()-1) cout << ", ";
	}
	cout << "]\n";
}

int main(){
	Solution s;
	s.build({"dog","dark","cat","door","dodge"});
	print(s.autocomplete("do")); // ['dodge', 'dog', 'door']
	print(s.autocomplete("dod")); // ['dodge']
	print(s.autocomplete("d")); // ['dark', 'dodge', 'dog', 'door']
	print(s.autocomplete("a")); // []

	return 0;
}