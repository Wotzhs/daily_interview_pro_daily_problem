#include <iostream>
#include <climits>
#include <string>
#include <cmath>
#include <sstream>
using namespace std;

/*

This problem was recently asked by LinkedIn:

Write a function that reverses the digits a 32-bit signed integer, x. Assume that the environment can only store integers within the 32-bit signed integer range, [-2^31, 2^31 - 1]. The function returns 0 when the reversed integer overflows.

Example:
Input: 123
Output: 321
class Solution:
  def reverse(self, x):
    # Fill this in.

print(Solution().reverse(123))
# 321
print(Solution().reverse(2**31))
# 0

*/

// n = length of digits
// TC - o(n)
// SC - o(n)
int reverse(long x) {
	if (x > INT_MAX || x < INT_MIN) {
		return 0;
	}
	
	string s;
	int i=0, xc=abs(x), ans;
	while(xc > 0) {
		s += char(xc%10 +'0');
		xc /= 10;
	}
	
	for (; i<s.size(); i++) {
		if (s[i] != '0') break;
	}
	
	if (i == s.size()) i = 0;

	stringstream ss;

	for (; i<s.size(); i++) ss << s[i];
	ss >> ans;
	return x < 0 ? -ans : ans;
}

int main() {
	cout << reverse(123) << "\n"; // 321
	cout << reverse(-123) << "\n"; // 321
	cout << reverse(123000) << "\n"; // 321
	cout << reverse(900009) << "\n"; // 900009
	cout << reverse(pow(2,31)) << "\n";// 0
	return 0;
}
