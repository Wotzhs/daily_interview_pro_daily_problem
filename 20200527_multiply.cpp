#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <climits>
using namespace std;
typedef basic_stringstream<char> stringstream;

/*

This problem was recently asked by Microsoft:

Given two strings which represent non-negative integers, multiply the two numbers and return the product as a string as well. You should assume that the numbers may be sufficiently large such that the built-in integer type will not be able to store the input (Python does have BigNum, but assume it does not exist).

Here's an example and some starter code.

def multiply(str1, str2):
  # Fill this in.

print(multiply("11", "13"))
# 143


*/

// credit: https://www.geeksforgeeks.org/multiply-large-numbers-represented-as-strings/
string multiply(string a, string b) {
	vector<int> v(a.size()+b.size());

    for (int i=a.size()-1; i>=0; i--) { 
        int carryOver = 0; 
        for (int j=b.size()-1; j>=0; j--) {
        	int currIdx = a.size()-1-i+b.size()-1-j;
            int tmp = (a[i]-'0') * (b[j]-'0') + v[currIdx] + carryOver; 
            carryOver = tmp/10;
            v[currIdx] = tmp%10; 
        } 

        v[a.size()-1-i+b.size()] += carryOver;
    } 

	while(v.back() == 0) v.pop_back();

	stringstream ss;
	for (int i=v.size()-1; i>=0;i--)
		ss << v[i];

	return ss.str();
}

int main(){
	cout << multiply("11", "13") << "\n"; // 143
	cout << multiply("99", "99") << "\n"; // 9801
	cout << multiply(to_string(INT_MAX), to_string(INT_MAX)) << "\n"; // 4611686014132420609

	return 0;
}