#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

/*

This problem was recently asked by Apple:

Given a list of words in a string, reverse the words in-place (ie don't create a new string and reverse the words). Since python strings are not mutable, you can assume the input will be a mutable sequence (like list).

Here's an example and some starting code:

def reverse_words(words):
  # Fill this in.

s = list("can you read this")
reverse_words(s)
print(''.join(s))
# this read you can

*/

string reverseWords(string s) {
	// reverse the string
	reverse(s.begin(), s.end());

	// find words by spaces and mirror each word
	int curr=0, space=0;;
	for (int i=0; i<s.size(); i++) {
		if (s[i] == ' ') space = i;
		if (curr < space) {
			for (int j=curr; j<(space+curr)/2; j++) {
				swap(s[j], s[space-1-j+curr]);
			}	
			curr = space+1;
		}
	}

	// mirror the last word from the last space
	for (int i=curr; i<(s.size()+curr)/2; i++) {
		swap(s[curr], s[s.size()-1-i+curr]);
	}

	return s;
}

int main(){
	cout << reverseWords("can you read this") << "\n"; // this read you can
	cout << reverseWords("i did it") << "\n"; // it did i

	return 0;
}

/* complexity analysis
	runtime o(n)
		reverse string - o(n)
		find space - o(n)
		mirror from start of word to space o(n)
		mirror from last space to end of string o(n)
	o(n+n+n+n) = o(4n) = o(n)

	space complexity o(1)
		track curr index = o(1)
		track space index = o(1)
	o(1+1) = o(2) = o(1)
*/