#include <iostream>
using namespace std;

/*

This problem was recently asked by Facebook:

A Perfect Number is a positive integer that is equal to the sum of all its positive divisors except itself.

For instance,
28 = 1 + 2 + 4 + 7 + 14

Write a function to determine if a number is a perfect number.

class Solution(object):
  def checkPerfectNumber(self, num):
    # Fill this in.

print(Solution().checkPerfectNumber(28))
# True
# 28 = 1 + 2 + 4 + 7 + 14

*/

bool checkPerfectNumber(int n) {
	int sum=1;
	for (int i=2; i<=n/2; i++)
		if (!(n%i)) sum += i;

	return n == sum;
}

int main(){
	cout << checkPerfectNumber(28) << "\n"; // true
	cout << checkPerfectNumber(15) << "\n"; // false
	cout << checkPerfectNumber(496) << "\n"; // true
	cout << checkPerfectNumber(8128) << "\n"; // true
	return 0;
}