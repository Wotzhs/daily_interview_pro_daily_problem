#include <iostream>
using namespace std;

/*

This problem was recently asked by Amazon:

Given a number like 159, add the digits repeatedly until you get a single number.

For instance, 1 + 5 + 9 = 15.
1 + 5 = 6.

So the answer is 6.

class Solution(object):
  # Fill this in.

print(Solution().addDigits(159))
# 1 + 5 + 9 = 15
# 1 + 5 = 6
# 6

*/

int addDigits(int n) {
	int sum=0;
	
	while(n>10) {
		sum += n%10;
		n /= 10;
	}

	sum += n;
	
	if (sum>10) sum = addDigits(sum);
	
	return sum;
}

int main(){
	cout << addDigits(159) << "\n"; // 6
	cout << addDigits(111) << "\n"; // 3
	cout << addDigits(999) << "\n"; // 9
	return 0;
}