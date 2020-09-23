#include <iostream>
#include <string>
#include <sstream>
using namespace std;

/*

This problem was recently asked by LinkedIn:

Given a string, convert it to an integer without using the builtin str function. You are allowed to use ord to convert a character to ASCII code.

Consider all possible cases of an integer. In the case where the string is not a valid integer, return None.

Here's some starting code:

def convert_to_int(s):
  # Fill this in.

print(convert_to_int('-105') + 1)
# -104

*/

// TC - o(n)
// SC - o(n)
int convertToInt(string s) {
	if (!s.size()) return 0;
	if (s.size() == 1 && s[0] == '-') return 0;
	stringstream ss;
	if (s[0] == '-') {
		for (int i=1; i<s.size(); i++) {
			ss << s[i];
		}
	} else {
		for (char ch: s) {
			ss << ch;
		}
	}
	int val;
	ss >> val;
	return s[0] == '-' ? -1*val : val;
}

int main() {
	cout << convertToInt("-105") + 1 << "\n"; // -104
	cout << convertToInt("105") + 1 << "\n"; // 106
	cout << convertToInt("-") + 1 << "\n"; // 1
	cout << convertToInt("0") + 1 << "\n"; // 1
	return 0;
}
