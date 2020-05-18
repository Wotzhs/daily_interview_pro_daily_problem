#include <iostream>
#include <vector>
#include <string>

/*

This problem was recently asked by Apple:

Given a number n, generate all possible combinations of n well-formed brackets.

Here are some examples and some starting code.

def generate_brackets(n):
  #Fill this in.
  
print(generate_brackets(1))
# ['()']

print(generate_brackets(3))
# ['((()))', '(()())', '()(())', '()()()', '(())()']

*/

// credit: https://leetcode.com/articles/generate-parentheses/
void backtrack(std::vector<std::string>* ans, std::string cur, int open, int close, int max) {
	if (cur.size() == max*2) ans->emplace_back(cur);
	if (open < max) backtrack(ans, cur+"(", open+1, close, max);
	if (close < open) backtrack(ans, cur+")", open, close+1, max);
}

std::vector<std::string> generateBrackets(int i) {
	std::vector<std::string> ans;
	backtrack(&ans, "", 0, 0, i);
	return ans;
}

int main() {
	auto ans = generateBrackets(1);
	std::cout << "[";
	for (int i=0; i < ans.size(); i++) {
		std::cout << "'" << ans[i] << "'";
		if (i != ans.size()-1) std::cout << ", ";
	}
	std::cout << "]\n"; // ['()']

	ans = generateBrackets(3);
	std::cout << "[";
	for (int i=0; i < ans.size(); i++) {
		std::cout << "'" << ans[i] << "'";
		if (i != ans.size()-1) std::cout << ", ";
	}
	std::cout << "]\n"; // ['((()))', '(()())', '(())()', '()(())', '()()()']
	
	return 0;
}