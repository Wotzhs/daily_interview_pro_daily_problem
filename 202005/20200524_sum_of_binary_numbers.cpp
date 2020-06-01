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
	int i=bin1.size()-1, j=bin2.size()-1, bal=0;

	stringstream ss;
	while(i>=0 || j>=0) {
		int sum=0;
		sum += i >= 0 ? bin1[i]-'0' : 0;
		sum += j >= 0 ? bin2[j]-'0' : 0;
		sum += bal;
		bal = sum / 2;
		ss << sum % 2;
		i--;
		j--;
	}

	if (bal) ss << bal;

	string ans = ss.str();
	reverse(ans.begin(), ans.end());

	return ans;
}

int main(){
	cout << sumBinary("11101", "1011") << "\n"; // 101000
	cout << sumBinary("11", "1") << "\n"; // 100
	cout << sumBinary("10", "1") << "\n"; // 11
	cout << sumBinary("100", "1") << "\n"; // 101
	cout << sumBinary("10001", "1") << "\n"; // 10010
	cout << sumBinary("10111", "1") << "\n"; // 11000
	return 0;
}