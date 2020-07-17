#include <iostream>
#include <string>
using namespace std;

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

string longestPalindrome(string s) {
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
				end = r+1;
			}
			l--;
			r++;
		}

	}
	return s.substr(start, end);
}

int main(){
	cout << longestPalindrome("banana") << "\n"; // anana
	cout << longestPalindrome("million") << "\n"; // racecar
	cout << longestPalindrome("tracecars") << "\n"; // racecar
	return 0;
}