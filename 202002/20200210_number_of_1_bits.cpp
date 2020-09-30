#include <iostream>
using namespace std;

/*

This problem was recently asked by Google:

Given an integer, find the number of 1 bits it has.

Here's an example and some starting code.

def one_bits(num):
  # Fill this in.

print(one_bits(23))
# 4
# 23 = 0b1011

*/

// TC - o(n/2)
// SC - o(1)
int oneBits(int n) {
	int ans=0;
	while(n>0) {
		if (n&1) {
			ans++;
		}
		n>>=1;
	}
	return ans;
}

int main() {
	cout << oneBits(23) << "\n"; // 4
	cout << oneBits(3) << "\n"; // 2
	cout << oneBits(4) << "\n"; // 1
	return 0;
}
