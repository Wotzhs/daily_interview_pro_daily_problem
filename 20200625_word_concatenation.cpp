#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*

This problem was recently asked by LinkedIn:

Given a set of words, find all words that are concatenations of other words in the set.

class Solution(object):
  def findAllConcatenatedWords(self, words):
    # Fill this in.


input = ['rat', 'cat', 'cats', 'dog', 'catsdog', 'dogcat', 'dogcatrat']
print(Solution().findAllConcatenatedWords(input))
# ['catsdog', 'dogcat', 'dogcatrat']

*/

class Trie {
public:
	bool isLeaf=false;
	Trie* children[26]={nullptr};
};

bool search(Trie* trie, int idx, int wc, string s) {
	if (idx == s.size()) return wc > 1;
	Trie* t = trie;
	for (int i=idx; i<s.size(); i++) {
		if (t->children[s[i]-'a'] == nullptr) return false;
		t = t->children[s[i]-'a'];
		if (t->isLeaf)
			if (search(trie, i+1, wc+1, s)) return true;
	}
	return false;
}

vector<string> findAllConcatenatedWords(vector<string> input) {
	Trie* trie = new Trie;
	for (string s: input) {
		Trie* t = trie;
		for (char ch: s) {
			if (t->children[ch-'a'] == nullptr) {
				t->children[ch-'a'] = new Trie;
			}
			
			t = t->children[ch-'a'];
		}
		t->isLeaf = true;
	}	

	vector<string> ans;
	for (string s: input) {
		if (search(trie, 0,0, s)) ans.emplace_back(s);
	}

	return ans;
}

void print(vector<string> ans) {
	cout << "[";
	for (int i=0; i<ans.size(); i++) {
		cout << "'" << ans[i] << "'";
		if (i<ans.size()-1) cout << ", ";
	}
	cout << "]\n";
}	

int main(){
	print(findAllConcatenatedWords({"cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"})); // ["catsdogcats","dogcatsdog","ratcatdogcat"]
	print(findAllConcatenatedWords({"rat","cat","cats","dog","catsdog","dogcat","dogcatrat"})); // ['catsdog', 'dogcat', 'dogcatrat']
	print(findAllConcatenatedWords({"a","b","ab","abc"})); // ['ab']
	return 0;
}