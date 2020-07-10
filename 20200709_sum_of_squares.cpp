#include <iostream>
#include <cmath>
using namespace std;

/*

This problem was recently asked by Facebook:

Given a number n, find the least number of squares needed to sum up to the number.

Here's an example and some starting code:

def square_sum(n):
  # Fill this in.

print(square_sum(13))
# Min sum is 32 + 22
# 2

*/

int sumOfSquares(int n) {
	int dp[n] = {1,2,3};
	for (int i=4; i<=n; i++) {
		dp[i] = i;
		for (int j=1; j<=ceil(sqrt(i)); j++) {
			int tmp = j*j;
			if (tmp > i) break;
			dp[i] = min(dp[i], 1+dp[i-tmp]);
		}
	}
	return dp[n];
}

int main(){
	cout << sumOfSquares(13) << "\n"; // 2
	return 0;
}