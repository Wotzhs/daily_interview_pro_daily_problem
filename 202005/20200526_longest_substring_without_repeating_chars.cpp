#include <iostream>
using namespace std;

/*

This problem was recently asked by Microsoft:

Given a string, find the length of the longest substring without repeating characters.

Here is an example solution in Python language. (Any language is OK to use in an interview, though we'd recommend Python as a generalist language utilized by companies like Google, Facebook, Netflix, Dropbox, Pinterest, Uber, etc.,)

class Solution:
  def lengthOfLongestSubstring(self, s):
    # Fill this in.

print Solution().lengthOfLongestSubstring('abrkaabcdefghijjxxx')
# 10

Can you find a solution in linear time?

*/

#define TOTAL_ALPHABETS 26
int lengthOfLongestSubstring(string s) {
	int chars[TOTAL_ALPHABETS]={0}, ans=0, last=0;

	for (int i=0; i<s.size(); i++) {
		last = max(chars[s[i]-'a']+1, last);
		chars[s[i]-'a'] = i;
		ans = max(ans, i-last+1);
	}

	return ans;
}

int main(){
	cout << lengthOfLongestSubstring("abrkaabcdefghijjxxx") << "\n"; // 10
	cout << lengthOfLongestSubstring("aaaaaab") << "\n"; // 2
	return 0;
}