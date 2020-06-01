#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*

This problem was recently asked by Microsoft:

Given a list of strings, find the longest common prefix between all strings.

Here's some examples and some starter code.

def longest_common_prefix(strs):
  # Fill this in.
  
print(longest_common_prefix(['helloworld', 'hellokitty', 'hell']))
# hell

print(longest_common_prefix(['daily', 'interview', 'pro']))
# ''

*/

string longestCommonPrefix(vector<string> v) {
	if (v.size()<2) return "";

	string prefix;
	int i=0;
	while(i < v[0].size() && i < v[1].size()) {
		if (v[0][i] == v[1][i]) prefix += v[0][i];
		else break;
		i++;
	}

	if (!prefix.size()) return prefix;

	for (int i=2; i<v.size(); i++) {
		while(prefix != v[i]) prefix.pop_back();
		if (!prefix.size()) break;
	}

	return prefix;
}

void print(string s) {
	if (s == "") cout << "''" << "\n";
	else cout << s << "\n";
}

int main(){
	print(longestCommonPrefix({"helloworld", "hellokitty", "hell"})); // hell
	print(longestCommonPrefix({"daily", "interview", "pro"})); // ''

	return 0;
}