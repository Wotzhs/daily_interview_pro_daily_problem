#include <iostream>
#include <string>
#include <unordered_map>

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


bool isChainable(std::string words[]) {
	std::unordered_map<char, int> mp;
	for (int i=0; i <= words->size(); i++) {
		mp[words[i].front()]++;
		mp[words[i].back()]++;
	}
	
	for (auto it = mp.begin(); it != mp.end(); ++it) {
		if (it->second&1) return false;
	}
	return true;
}

int main() {
	std::string words1[5] = {"eggs", "karat", "apple", "snack", "tuna"};
	std::cout << isChainable(words1) << "\n"; // 1

	std::string words2[5] = {"eggs", "bacon", "apple", "snack", "tuna"};
	std::cout << isChainable(words2) << "\n"; // 0

	return 0;
}