#include <iostream>
#include <string>
#include <stack>
using namespace std;

/*

This problem was recently asked by Uber:

Imagine you are building a compiler. Before running any code, the compiler must check that the parentheses in the program are balanced. Every opening bracket must have a corresponding closing bracket. We can approximate this using strings.

Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
An input string is valid if:
- Open brackets are closed by the same type of brackets.
- Open brackets are closed in the correct order.
- Note that an empty string is also considered valid.

Example:
Input: "((()))"
Output: True

Input: "[()]{}"
Output: True

Input: "({[)]"
Output: False
class Solution:
  def isValid(self, s):
    # Fill this in.

# Test Program
s = "()(){(())" 
# should return False
print(Solution().isValid(s))

s = ""
# should return True
print(Solution().isValid(s))

s = "([{}])()"
# should return True
print(Solution().isValid(s))

*/

// TC - o(n)
// SC - o(n)
bool isValid(string s) {
	stack<char> st;
	for (char ch: s) {
		if (ch == '(' || ch == '[' || ch == '{') {
			st.push(ch);
		}
		else {
			if (
				!st.size() ||
				(ch == ')' && st.top() != '(') ||
				(ch == ']' && st.top() != '[') ||
				(ch == '}' && st.top() != '{')
			) {
				return false;
			}
			st.pop();
		}
	}
	return st.size() == 0;
}

int main() {
	cout << isValid("((()))") << "\n"; // true
	cout << isValid("[()]{}") << "\n"; // true
	cout << isValid("({[)]") << "\n"; // false
	cout << isValid("()(){(())") << "\n"; // false
	cout << isValid("") << "\n"; // true
	cout << isValid("([{}])()") << "\n"; // true
	cout << isValid("))(())") << "\n"; // false

	return 0;
}
