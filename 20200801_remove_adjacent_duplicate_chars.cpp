#include <iostream>
#include <string>
#include <queue>
using namespace std;

/*

This problem was recently asked by Apple:

Given a string, we want to remove 2 adjacent characters that are the same, and repeat the process with the new string until we can no longer perform the operation.

Here's an example and some starter code:

def remove_adjacent_dup(s):
  # Fill this in.

print(remove_adjacent_dup("cabba"))
# Start with cabba
# After remove bb: caa
# After remove aa: c
# print c

*/

string removeAdjacentDup(string s) {
	deque<char> dq;
	for (char ch: s)
		if (dq.size() && dq.back() == ch) dq.pop_back();
		else dq.emplace_back(ch);
	
	string ans;
	while(dq.size()) {
		ans+=dq.front();
		dq.pop_front();
	}

	return ans;
}

int main() {
	cout << removeAdjacentDup("cabba") << "\n"; // c
	cout << removeAdjacentDup("ca") << "\n"; // ca
	cout << removeAdjacentDup("caabbcbba") << "\n"; // a
	cout << removeAdjacentDup("abccba") << "\n"; // 
	cout << removeAdjacentDup("axabcaya") << "\n"; // axabcaya
	return 0;
}
