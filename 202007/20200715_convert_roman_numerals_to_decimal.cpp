#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

/*

This problem was recently asked by Twitter:

Given a Roman numeral, find the corresponding decimal value. Inputs will be between 1 and 3999.

Example:
Input: IX
Output: 9

Input: VII
Output: 7

Input: MCMIV
Output: 1904
Roman numerals are based on the following symbols:
I     1
IV    4
V     5
IX    9 
X     10
XL    40
L     50
XC    90
C     100
CD    400
D     500
CM    900
M     1000
Numbers are strings of these symbols in descending order. In some cases, subtractive notation is used to avoid repeated characters. The rules are as follows:
1.) I placed before V or X is one less, so 4 = IV (one less than 5), and 9 is IX (one less than 10)
2.) X placed before L or C indicates ten less, so 40 is XL (10 less than 50) and 90 is XC (10 less than 100).
3.) C placed before D or M indicates 100 less, so 400 is CD (100 less than 500), and 900 is CM (100 less than 1000).

class Solution():
  def romanToInt(self, s):
    # Fill this in.
    
n = 'MCMX'
print(Solution().romanToInt(n))
# 1910

*/

unordered_map<char, int> dict({
	{'I', 1},
	{'V', 5},
	{'X', 10},
	{'L', 50},
	{'C', 100},
	{'D', 500},
	{'M', 1000},
});

int romanToInt(string s) {
	int n=s.size()-1, sum=dict[s[n]];
	for (int i=n-1; i>=0; i--) {
		if (
			(s[i] == 'I' && (s[i+1] == 'V' || s[i+1] == 'X')) ||
			(s[i] == 'X' && (s[i+1] == 'L' || s[i+1] == 'C')) ||
			(s[i] == 'C' && (s[i+1] == 'D' || s[i+1] == 'M'))
		) sum -= dict[s[i]];
		else sum += dict[s[i]];
	}
	return sum;
}

int main(){
	cout << romanToInt("MCMX") << "\n"; // 1910
	cout << romanToInt("MMMDCCXXIV") << "\n"; // 3724
	return 0;
}