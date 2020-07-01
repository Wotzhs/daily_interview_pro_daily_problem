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

char firstRecurringChar(string s) {
	unordered_map<char, int> mp;
	for (char ch: s) {
		if (mp.find(ch) == mp.end()) mp[ch]++;
		else return ch;
	}
	return '\0'; // https://stackoverflow.com/a/18410258/6568632
}

void print(char ch) {
	if (ch == '\0') cout << "None\n";
	else cout << ch << "\n";
}

int main(){
	print(firstRecurringChar("qwertty")); // t
	print(firstRecurringChar("qwerty")); // None
	return 0;
}