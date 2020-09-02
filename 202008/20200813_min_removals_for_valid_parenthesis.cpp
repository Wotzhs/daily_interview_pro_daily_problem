#include <iostream>
#include <string>
using namespace std;

/*

This problem was recently asked by Uber:

You are given a string of parenthesis. Return the minimum number of parenthesis that would need to be removed in order to make the string valid. "Valid" means that each open parenthesis has a matching closed parenthesis.

Example:

"()())()"

The following input should return 1.

")("

Here's a start:

def count_invalid_parenthesis(string):
  # Fill this in.

print count_invalid_parenthesis("()())()")
# 1

*/

// TC - o(n)
// SC - o(1)
int countInvalidParenthesis(string s) {
	int open=0, invalid=0;
	for (char ch: s) {
		if (ch == '(') open++;
		if (ch == ')' && open>0) open--;
		else if (ch == ')' && open<=0) invalid++;
	}
	return open+invalid;
}

int main() {
	cout << countInvalidParenthesis("()())()") << "\n"; // 1
	cout << countInvalidParenthesis(")))((()") << "\n"; // 5
	cout << countInvalidParenthesis("(((())))") << "\n"; // 0
	cout << countInvalidParenthesis("(()())())") << "\n"; // 1

	return 0;
}
