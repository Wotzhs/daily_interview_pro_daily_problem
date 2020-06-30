#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

/*

This problem was recently asked by Google:

A criminal is constructing a ransom note. In order to disguise his handwriting, he is cutting out letters from a magazine.

Given a magazine of letters and the note he wants to write, determine whether he can construct the word.

class Solution(object):
  def canSpell(self, magazine, note):
    # Fill this in.
    
print(Solution().canSpell(['a', 'b', 'c', 'd', 'e', 'f'], 'bed'))
# True

print(Solution().canSpell(['a', 'b', 'c', 'd', 'e', 'f'], 'cat'))
# False

Can you do this in linear time?

*/

bool canSpell(vector<char> letters, string word) {
	unordered_map<char, int> mp;
	for (char ch: letters)
		mp[ch]++;
	for (char ch: word)
		if (--mp[ch] < 0) return false;
	return true;
}

int main() {
	cout << canSpell({'a','b','c','d','e','f'}, "bed") << "\n"; // true
	cout << canSpell({'a','b','c','d','e','f'}, "cat") << "\n"; // false
	return 0;
}