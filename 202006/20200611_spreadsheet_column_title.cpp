#include <iostream>
#include <string>
using namespace std;

/*

This problem was recently asked by Amazon:

MS Excel column titles have the following pattern: A, B, C, ..., Z, AA, AB, ..., AZ, BA, BB, ..., ZZ, AAA, AAB, ... etc. In other words, column 1 is named "A", column 2 is "B", column 26 is "Z", column 27 is "AA" and so forth. Given a positive integer, find its corresponding column name.
Examples:
Input: 26
Output: Z

Input: 51
Output: AY

Input: 52
Output: AZ

Input: 676
Output: YZ

Input: 702
Output: ZZ

Input: 704
Output: AAB
Here is a starting point:

class Solution:
  def convertToTitle(self, n):
    # Fill this in.

input1 = 1
input2 = 456976
input3 = 28
print(Solution().convertToTitle(input1))
# A
print(Solution().convertToTitle(input2))
# YYYZ
print(Solution().convertToTitle(input3))
# AB

*/

string convertToTitle(int n) {
	string s="";
	while (n >= 1) {
		s = (char)('A' + --n%26) + s;
		n /= 26;
	}
	return s;
}

int main(){
	cout << convertToTitle(1) << "\n"; // A
	cout << convertToTitle(456976) << "\n"; // YYYZ
	cout << convertToTitle(28) << "\n"; // AB
	cout << convertToTitle(26) << "\n"; // Z
	cout << convertToTitle(51) << "\n"; // AY
	cout << convertToTitle(52) << "\n"; // AZ
	cout << convertToTitle(676) << "\n"; // YZ
	cout << convertToTitle(702) << "\n"; // ZZ
	cout << convertToTitle(704) << "\n"; // AAB
	return 0;
}