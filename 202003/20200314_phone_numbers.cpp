#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

/*

This problem was recently asked by AirBNB:

Given a phone number, return all valid words that can be created using that phone number.

For instance, given the phone number 364
we can construct the words ['dog', 'fog'].

Here's a starting point:

lettersMaps = {
    1: [],
    2: ['a', 'b', 'c'],
    3: ['d', 'e', 'f'],
    4: ['g', 'h', 'i'],
    5: ['j', 'k', 'l'],
    6: ['m', 'n', 'o'],
    7: ['p', 'q', 'r', 's'],
    8: ['t', 'u', 'v'],
    9: ['w', 'x', 'y', 'z'],
    0: []
}

validWords = ['dog', 'fish', 'cat', 'fog']

def makeWords(phone):
  #Fill this in

print(makeWords('364'))
# ['dog', 'fog']

*/

// TC - o(length of validWords) + o(length of all words)
// SC - o(length of validWords)
const unordered_map<int, vector<char>> letterMaps = {
	{1, {}},
	{2, {'a', 'b', 'c'}},
	{3, {'d', 'e', 'f'}},
	{4, {'g', 'h', 'i'}},
	{5, {'j', 'k', 'l'}},
	{6, {'m', 'n', 'o'}},
	{7, {'p', 'q', 'r', 's'}},
	{8, {'t', 'u', 'v'}},
	{9, {'w', 'x', 'y', 'z'}},
	{0, {}},
};

const vector<string> validWords = {"dog", "fish", "cat", "fog"};

vector<string> makeWords(string phone) {
	vector<string> ans;

	unordered_map<char, int> reverseLetterMaps;
	for (auto it=letterMaps.begin(); it!=letterMaps.end(); it++) {
		for (char ch: it->second) {
			reverseLetterMaps[ch] = it->first;
		}
	}

	vector<string> wordsNumber;
	for (string word: validWords) {
		string tmpS;
		for (char ch: word) {
			tmpS += to_string(reverseLetterMaps[ch]);
		}
		wordsNumber.emplace_back(tmpS);
	}

	for (int i=0; i<wordsNumber.size(); i++) {
		if (wordsNumber[i] == phone) {
			ans.emplace_back(validWords[i]);
		}
	}
	
	return ans;
}

void print(vector<string> ans) {
	cout << "[";
	for (int i=0; i<ans.size(); i++) {
		cout << "'" << ans[i] << "'";
		if (i<ans.size()-1) {
			cout << ", ";
		}
	}
	cout << "]\n";
}

int main() {
	print(makeWords("364")); // ['dog', 'fog']
	return 0;
}
