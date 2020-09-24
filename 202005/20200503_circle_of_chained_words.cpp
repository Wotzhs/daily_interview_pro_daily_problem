#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

/*

This problem was recently asked by Facebook:

Two words can be 'chained' if the last character of the first word is the same as the first character of the second word.

Given a list of words, determine if there is a way to 'chain' all the words in a circle.

Example:
Input: ['eggs', 'karat', 'apple', 'snack', 'tuna']
Output: True
Explanation:
The words in the order of ['apple', 'eggs', 'snack', 'karat', 'tuna'] creates a circle of chained words.

Here's a start:

from collections import defaultdict

def chainedWords(words):
  # Fill this in.

print chainedWords(['apple', 'eggs', 'snack', 'karat', 'tuna'])
# True

*/

// TC - o(n)
// SC - o(n) 
bool chainedWords(vector<string> words) {
	unordered_map<char, int> freq;
	for (string word: words) {
		if (freq[word[0]] == 0) freq[word[0]]++;
		else freq[word[0]]--;

		if (freq[word[word.size()-1]] == 0) freq[word[word.size()-1]]++;
		else freq[word[word.size()-1]]--;
	}
	for (auto it = freq.begin(); it != freq.end(); it++) {
		if (it->second != 0) {
			return false;
		}
	}
	return true;
}

int main() {
	cout << chainedWords({"apple", "eggs", "snack", "karat", "tuna"}) << "\n"; // true
	cout << chainedWords({"epple", "eggs", "snack", "karat", "tuna"}) << "\n"; // false
	return 0;
}
