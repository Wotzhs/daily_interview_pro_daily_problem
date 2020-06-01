#include <iostream>
#include <string>
using namespace std;

/*

This problem was recently asked by Google:

A look-and-say sequence is defined as the integer sequence beginning with a single digit in which the next term is obtained by describing the previous term. An example is easier to understand:

Each consecutive value describes the prior value.

1      #
11     # one 1's
21     # two 1's
1211   # one 2, and one 1.
111221 # #one 1, one 2, and two 1's.

Your task is, return the nth term of this sequence.

*/

// Note: I felt today's question is somewhat vaguely defined, so I came up with the solution
// assuming only a pair of string is expected given a nth sequence

string words [10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

string lookAndSaySequence(int n, int k) {
	if (n<10) return "";

	string strN = to_string(n);
	if ((k-0)*2 > strN.size()) return "";

	int sequence = (strN[k]-'0'-0) *2;
	
	return words[strN[sequence]-'0'] + " " + strN[sequence+1];
}

int main(){
	cout << lookAndSaySequence(111221, 1) << "\n"; // one 1
	cout << lookAndSaySequence(111221, 2) << "\n"; // one 2
	cout << lookAndSaySequence(111221, 3) << "\n"; // two 1

	return 0;
}