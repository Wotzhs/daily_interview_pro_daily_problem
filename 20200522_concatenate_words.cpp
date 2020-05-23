#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

/*

This problem was recently asked by Twitter:

Find all words that are concatenations of a list.

Input:
["tech", "lead", "techlead", "cat", "cats", "dog", "catsdog"]

Output:
['techlead', 'catsdog']

class Solution(object):
  def findAllConcatenatedWordsInADict(self, words):
    # Fill this in.
    
input = ["tech", "lead", "techlead", "cat", "cats", "dog", "catsdog"]

print(Solution().findAllConcatenatedWordsInADict(input))


Note: This question is classified as "hard."
HINT: Start with a brute-force solution.

*/


// credit: https://leetcode.com/problems/concatenated-words/discuss/176805/Trie-with-Explanations
class Trie {
	bool isLeaf = false;
	Trie* children[26] = {nullptr};

public:
	void insert(string word) {
		Trie* curr = this;
		for (char ch: word) {
			if (curr->children[ch-'a'] == nullptr) curr->children[ch-'a'] = new Trie();
			curr = curr->children[ch-'a'];
		}
		curr->isLeaf = true;
	}

	bool search(string word, int idx, int wordUsed) {
		if (idx == word.size()) return wordUsed >= 2;

		Trie* curr = this;
		for (int i=idx; i<word.size();i++) {
			if (curr->children[word[i]-'a'] == nullptr) return false;
			curr = curr->children[word[i]-'a'];
			if (curr->isLeaf) {
				if (search(word, i+1, wordUsed+1)) return true;
			}
		}
		return false;
	}
};

vector<string> findAllConcactenatedWords(vector<string>& words) {
	vector<string> ans;
	if (words.size() < 1) return ans;

	Trie* trie = new Trie();

	for (string word: words)
		trie->insert(word);

	for (string word: words)
		if (trie->search(word, 0, 0)) ans.emplace_back(word);

	return ans;
}

int main(){
	vector<string> wordsA = {"tech", "lead", "techlead", "cat", "cats", "dog", "catsdog"};
	auto ans = findAllConcactenatedWords(wordsA);

	cout << "[";
	for (int i=0; i<ans.size(); i++) {
		cout << "'" << ans[i] << "'";
		if (i!=ans.size()-1) cout << ", ";
	}
	cout << "]\n"; // ['techlead', 'catsdog']

	vector<string> wordsB = {"cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"};
	ans = findAllConcactenatedWords(wordsB);

	cout << "[";
	for (int i=0; i<ans.size(); i++) {
		cout << "'" << ans[i] << "'";
		if (i!=ans.size()-1) cout << ", ";
	}
	cout << "]\n"; // ['catsdogcats', 'dogcatsdog', 'ratcatdogcat']

	return 0;
}