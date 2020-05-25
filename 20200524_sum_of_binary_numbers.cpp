#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;
typedef basic_stringstream<char> stringstream;

/*

This problem was recently asked by Facebook:

Given two binary numbers represented as strings, return the sum of the two binary numbers as a new binary represented as a string. Do this without converting the whole binary string into an integer.

Here's an example and some starter code.

def sum_binary(bin1, bin2):
  # Fill this in.
  
print(sum_binary("11101", "1011"))
# 101000

*/

string sumBinary(string bin1, string bin2) {
	stringstream ss;

	if (bin1.size() < bin2.size()) swap(bin1, bin2);
	reverse(bin1.begin(), bin1.end());
	reverse(bin2.begin(), bin2.end());

	bool carryOver = false;
	for (int i=0; i < bin2.size(); i++) {
		int curr = bin1[i]-'0' ^ bin2[i]-'0';
		if (carryOver) curr ^= 1;
		if (curr == 0) carryOver = true;
		ss << curr;
	}

	for (int i=bin2.size(); i < bin1.size(); i++) {
		int curr = bin1[i]-'0';
		if (carryOver) curr ^= 1;
		if (curr == 0) carryOver = true;
		ss << curr;
	}

	if (carryOver) ss << 1;

	string ans = ss.str();
	reverse(ans.begin(), ans.end());

	return ans;
}

int main(){
	cout << sumBinary("11101", "1011") << "\n"; // 101000
	cout << sumBinary("11", "1") << "\n"; // 100
	return 0;
}