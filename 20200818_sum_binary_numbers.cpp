#include <iostream>
#include <string>
#include <algorithm>
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

// n - length of bin1, m - length of bin2
// TC - o(n+m)
// SC - o(n+m)
string sumBinary(string bin1, string bin2) {
	string ans;
	char carry='0';
	int i=0;

	reverse(bin1.begin(), bin1.end());
	reverse(bin2.begin(), bin2.end());
	
	while (1) {
		if (i>=bin1.size()||i>=bin2.size()) break;
		ans += bin1[i]^bin2[i]^carry;
		if (bin1[i] == bin2[i] && bin1[i] == carry) carry = '1';
		else carry = char(bin1[i]^bin2[i]&carry)+'0';
		i++;
	}

	while (i<bin1.size()) {
		ans += to_string(bin1[i]^carry);
		carry = bin1[i]&carry;
		i++;
	}

	while (i<bin2.size()) {
		ans += to_string(bin2[i]^carry);
		carry = bin2[i]&carry;
		i++;
	}

	if (carry == '1') ans += carry;

	reverse(ans.begin(), ans.end());

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
