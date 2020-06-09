#include <iostream>
#include <vector>
using namespace std;

/*

This problem was recently asked by Twitter:

Given an integer, check if that integer is a palindrome. For this problem do not convert the integer to a string to check if it is a palindrome.

import math

def is_palindrome(n):
  # Fill this in.

print is_palindrome(1234321)
# True
print is_palindrome(1234322)
# False

*/

bool isPalindrome(int n) {
	vector<int> numbers;
	
	while(n > 0) {
		numbers.emplace_back(n%10);
		n /= 10;
	}

	for (int left=0, right=numbers.size()-1; left<right; left++, right--)
		if (numbers[left] != numbers[right]) return false;

	return true;
}

int main(){
	cout << isPalindrome(1234321) << "\n"; // true
	cout << isPalindrome(1234322) << "\n"; // false
	cout << isPalindrome(1111111) << "\n"; // true
	return 0;
}