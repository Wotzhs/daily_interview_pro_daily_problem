#include <iostream>

/*

This problem was recently asked by Apple:

The Fibonacci sequence is the integer sequence defined by the recurrence relation: F(n) = F(n-1) + F(n-2), where F(0) = 0 and F(1) = 1. In other words, the nth Fibonacci number is the sum of the prior two Fibonacci numbers. Below are the first few values of the sequence:

0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144...

Given a number n, print the n-th Fibonacci Number.
Examples:

Input: n = 3
Output: 2

Input: n = 7
Output: 13

Here's a starting point:

class Solution():
  def fibonacci(self, n):
    # fill this in.

n = 9
print(Solution().fibonacci(n))
# 34

*/

long nthFibonacci(int n) {
	if (n<2) return 0;
	long first=0, second=1, fib=1;
	for (int i=2; i < n; i++) {
		first=second;
		second=fib;
		fib=first+second;
	}
	return fib;
}

int main() {
	std::cout << nthFibonacci(3) << "\n"; // 2
	std::cout << nthFibonacci(7) << "\n"; // 13
	std::cout << nthFibonacci(9) << "\n"; // 34
	std::cout << nthFibonacci(50) << "\n"; // 12586269025
	return 0;
}