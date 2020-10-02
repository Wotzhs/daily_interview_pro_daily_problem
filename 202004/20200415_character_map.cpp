#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

/*

This problem was recently asked by Google:

Given two strings, find if there is a one-to-one mapping of characters between the two strings.

Example
Input: abc, def
Output: True # a -> d, b -> e, c -> f

Input: aab, def
Ouput: False # a can't map to d and e 
Here's some starter code:

def has_character_map(str1, str2):
  # Fill this in.

print(has_character_map('abc', 'def'))
# True
print(has_character_map('aac', 'def'))
# False

*/

// n - length of string 1 or string 2
// TC - o(n)
// SC - o(n)
bool hasCharacterMap(string str1, string str2) {
	if (str1.size() != str2.size()) {
		return false;
	}
	
	unordered_map<char, char> mp;
	for (int i=0; i<str1.size(); i++) {
		char a=str1[i], b=str2[i];
		if (mp.count(a) && mp[a] != b) {
			return false;
		}
		mp[a] = b;
	}
	return true;
}

int main() {
	cout << hasCharacterMap("abc", "def") << "\n"; // true
	cout << hasCharacterMap("aac", "def") << "\n"; // false
	cout << hasCharacterMap("aac", "ddf") << "\n"; // true

	return 0;
}
