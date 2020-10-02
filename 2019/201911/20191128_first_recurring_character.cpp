#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

/*

This problem was recently asked by Amazon:

Given a string, return the first recurring letter that appears. If there are no recurring letters, return None.

Example:
Input: qwertty
Output: t

Input: qwerty
Output: None
Here's some starter code:

def first_recurring_char(s):
  # Fill this in.
  
print(first_recurring_char('qwertty'))
# t

print(first_recurring_char('qwerty'))
# None

*/

// n - length of string
// TC - o(n)
// SC - o(n)
char firstRecurringChar(string s) {
	unordered_map<char, bool> mp;
	for (char ch: s) {
		if (mp.count(ch)) {
			return ch;
		}
		mp[ch] = true;
	}
	return '\0';
}

int main() {
	cout << firstRecurringChar("qwertty") << "\n"; // t
	cout << firstRecurringChar("qwerty") << "\n"; //
	return 0;
}
