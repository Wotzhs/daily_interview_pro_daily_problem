#include <iostream>
#include <string>
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

string reverseWords(string words) {
	for (int i=0, j=words.size()-1; i<j; i++, j--)
		swap(words[i], words[j]);

	int tail=0;
	for (int i=0; i<words.size(); i++) {
		if (words[i] == ' ') {
			for (int j=tail, k=i-1; j<k; j++, k--)
				swap(words[j], words[k]);
			tail = i+1;
		}
	}

	for (int i=tail, j=words.size()-1; i<j; i++, j--)
		swap(words[i], words[j]);

	return words;
}

int main(){
	cout << reverseWords("can you read this") << "\n"; // this read you can
	cout << reverseWords("I did it again") << "\n"; // again it did i
	return 0;
}