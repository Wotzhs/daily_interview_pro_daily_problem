#include <iostream>

/*

This problem was recently asked by LinkedIn:

You are given a positive integer N which represents the number of steps in a staircase. You can either climb 1 or 2 steps at a time. Write a function that returns the number of unique ways to climb the stairs.

def staircase(n):
  # Fill this in.
  
print staircase(4)
# 5
print staircase(5)
# 8

Can you find a solution in O(n) time?

*/

int staircase(int n) {
	int dp[n] = {1,1};
	for (int i=2; i<=n; i++)
		dp[i] = dp[i-1] + dp[i-2];

	return dp[n];
}

int main(){
	std::cout << staircase(4) << "\n"; // 5
	std::cout << staircase(5) << "\n"; // 8
	return 0;
}