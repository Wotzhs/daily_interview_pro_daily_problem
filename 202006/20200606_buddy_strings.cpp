#include <iostream>
#include <string>
using namespace std;

/*

This problem was recently asked by AirBNB:

Given two strings A and B of lowercase letters, return true if and only if we can swap two letters in A so that the result equals B.

Example 1:
Input: A = "ab", B = "ba"
Output: true
Example 2:

Input: A = "ab", B = "ab"
Output: false
Example 3:
Input: A = "aa", B = "aa"
Output: true
Example 4:
Input: A = "aaaaaaabc", B = "aaaaaaacb"
Output: true
Example 5:
Input: A = "", B = "aa"
Output: false
Here's a starting point:

class Solution:
  def buddyStrings(self, A, B):
    # Fill this in.

print Solution().buddyStrings('aaaaaaabc', 'aaaaaaacb')
# True
print Solution().buddyStrings('aaaaaabbc', 'aaaaaaacb')
# False

*/

bool buddyStrings(string A, string B) {
	if (A.size() != B.size()) return false;
	
	if (A == B && A.size() > 1) {
		char c = A[0];
		for (int i=1; i<A.size(); i++) {
			if (A[i] != c) return false;
		}
		return true;
	}

	int first=-1, second=-1;
	for (int i=0; i<A.size(); i++) {
		if (A[i] == B[i]) continue;
		if (first >= 0 && second > first) {
			return A[first] == B[second] && A[second] == B[first];
		}
		if (first < 0) first = i;
		else second = i;
	}

	return true;
}

int main(){
	// example 1
	cout << buddyStrings("ab", "ba") << "\n"; // true

	// example 2
	cout << buddyStrings("ab", "ab") << "\n"; // false

	// example 3
	cout << buddyStrings("aa", "aa") << "\n"; // true

	// example 4
	cout << buddyStrings("aaaaaaabc", "aaaaaaacb") << "\n"; // true

	// example 5 
	cout << buddyStrings("", "aa") << "\n"; // false

	cout << buddyStrings("aaaaaaabc", "aaaaaaacb") << "\n"; // true
	cout << buddyStrings("aaaaaabbc", "aaaaaaacb") << "\n"; // false

	cout << buddyStrings("algorithm", "mlgoritha") << "\n"; // true

	return 0;
}