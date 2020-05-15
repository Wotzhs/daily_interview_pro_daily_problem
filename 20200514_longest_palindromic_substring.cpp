#include <iostream>
#include <string>

/*

This problem was recently asked by Twitter:

A palindrome is a sequence of characters that reads the same backwards and forwards. Given a string, s, find the longest palindromic substring in s.

Example:

Input: "banana"
Output: "anana"

Input: "million"
Output: "illi"

class Solution: 
    def longestPalindrome(self, s):
      # Fill this in.
        
# Test program
s = "tracecars"
print(str(Solution().longestPalindrome(s)))
# racecar

*/

std::string longestPalindromicSubString(std::string s) {
	if (s.size() == 0) return s;
	int len=0, start=0, end=0;
	for (int i=0; i<s.size(); i++) {
		int l=i-1, r=i+1;
		while(l>=0 && r<s.size()) {
			if (s[l] == s[r] && r-l+1 > len) {
				len = r-l+1;
				start = l;
				end = r;
			} 
			if (s[l] == s[r+1] && r-l+2 > len) {
				len = r-l+2;
				start = l;
				end = r;
			}
			l--;
			r++;
		}

	}
	return s.substr(start, end+1);
}

int main() {
	std::string a = longestPalindromicSubString("banana");
	std::cout << a << "\n"; // anana
	
	std::string b = longestPalindromicSubString("million");
	std::cout << b << "\n"; // illi

	std::string c = longestPalindromicSubString("racecar");
	std::cout << c << "\n"; // racecar

	return 0;
}