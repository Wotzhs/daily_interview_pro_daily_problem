#include <iostream>
#include <cmath>

/*

This problem was recently asked by Microsoft:

Return the longest run of 1s for a given integer n's binary representation.

Example:

Input: 242
Output: 4

242 in binary is 0b11110010, so the longest run of 1 is 4.

def longest_run(n):
  # Fill this in.

print longest_run(242)
# 4

*/

int longestRunOfOne(int n) {
	int maxRun=0;
	int sum=0;
	while(n) {
		n&1 ? sum++ : sum=0;
		n >>= 1;
		maxRun = std::max(maxRun, sum);
	}
	return maxRun;
}

int main() {
	std::cout << longestRunOfOne(242) << "\n";
	return 0;
}