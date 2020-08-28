#include <iostream>
#include <string>
using namespace std;

/*

This problem was recently asked by Facebook:

Given two binary numbers represented as strings, return the sum of the two binary numbers as a new binary represented as a string. Do this without converting the whole binary string into an integer.

Here's an example and some starter code.

def sum_binary(bin1, bin2):
  # Fill this in.
  
print(sum_binary("11101", "1011"))
# 101000

*/

// n = length of binary1, m = length of binary2
// TC - o(max(n, m))
// SC - o(max(n, m)+1)
string sumBinary(string bin1, string bin2) {
	string ans;
	int i=bin1.size(), j=bin2.size(), carry=0;
	while(i>0 || j>0) {
		int tmp=carry;
		if (--i>=0) tmp += bin1[i]-'0';
		if (--j>=0) tmp += bin2[j]-'0';
		carry=tmp/2;
		ans = (char)(tmp%2+'0') + ans;
	}
	if (carry) ans = (char)(carry+'0') + ans;
	return ans;
}

int main() {
	cout << sumBinary("11101", "1011") << "\n"; // 101000
	cout << sumBinary("11", "1") << "\n"; // 100
	cout << sumBinary("10", "1") << "\n"; // 11
	cout << sumBinary("100", "1") << "\n"; // 101
	cout << sumBinary("10001", "1") << "\n"; // 10010
	cout << sumBinary("10111", "1") << "\n"; // 11000
	return 0;
}
