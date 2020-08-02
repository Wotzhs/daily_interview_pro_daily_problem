#include <iostream>
#include <vector>
using namespace std;

/*

Hi, here's your problem today. This problem was recently asked by Twitter:

Given an integer, check if that integer is a palindrome. For this problem do not convert the integer to a string to check if it is a palindrome.

import math

def is_palindrome(n):
  # Fill this in.

print is_palindrome(1234321)
# True
print is_palindrome(1234322)
# False

*/

// l - number of digits in n
// TC - o(l)
// SC - o(l)
bool isPalindrome(int n) {
	vector<int> v;
	while (n>0) {
		v.emplace_back(n%10);
		n/=10;
	}
	for (int l=0, r=v.size()-1; l<r; l++, r--)
		if (v[l]!=v[r]) return false;
	return true;
}

int main() {
	cout << isPalindrome(1234321) << "\n"; // true
	cout << isPalindrome(1234322) << "\n"; // false
	cout << isPalindrome(1221) << "\n"; // true
	cout << isPalindrome(1122) << "\n"; // false
	return 0;
}
