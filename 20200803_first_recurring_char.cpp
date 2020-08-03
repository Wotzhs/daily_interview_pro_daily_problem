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

// n - size of s
// TC - o(n)
// SC - o(n
char firstRecurringChar(string s) {
	unordered_map<char, int> freq;
	for (char ch: s) 
		if (++freq[ch]>1) return ch;

	return '\0';
}

int main() {
	cout << firstRecurringChar("qwertty") << "\n"; // t
	cout << firstRecurringChar("qwerty") << "\n"; //
	cout << firstRecurringChar("qwewtyq") << "\n"; // w
	return 0;
}
