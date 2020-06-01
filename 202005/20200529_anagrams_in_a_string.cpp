#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*

This problem was recently asked by Twitter:

Given 2 strings s and t, find and return all indexes in string s where t is an anagram.

Here's an example and some starter code:

def find_anagrams(s, t):
  # Fill this in.

print(find_anagrams('acdbacdacb', 'abc'))
# [3, 7]

*/

#define ALPHABETS 26

bool compare(int* v1, int* v2) {
	for (int i=0; i<ALPHABETS; i++) {
		if (v1[i] != v2[i]) return false;
	}
	return true;
}

vector<int> findAnagrams(string s1, string s2) {
	if (s2.size() > s1.size()) swap(s1, s2);

	int v1[ALPHABETS]={0}, v2[ALPHABETS]={0};
	for (int i=0; i<s2.size(); i++) {
		v1[s1[i]-'a']++;
		v2[s2[i]-'a']++;
	}

	vector<int> ans;
	if (compare(v1, v2)) ans.emplace_back(0);

	for (int i=s2.size(); i<s1.size(); i++) {
		v1[s1[i]-'a']++;
		v1[s1[i-s2.size()]-'a']--;
		if (compare(v1, v2)) ans.emplace_back(i-s2.size()+1);
	}
	return ans;
}

void print(vector<int> ans) {
	cout << "[";
	for (int i=0; i<ans.size(); i++) {
		cout << ans[i];
		if (i != ans.size()-1) cout << ", ";
	}
	cout << "]\n";
}

int main(){
	print(findAnagrams("acdbacdacb", "abc")); // [3, 7]
	print(findAnagrams("abc", "acdbacdacb")); // [3, 7]
	print(findAnagrams("abab", "ab")); // [0, 1, 2]
	print(findAnagrams("cbaebabacd", "abc")); // [0, 6]

	return 0;
}