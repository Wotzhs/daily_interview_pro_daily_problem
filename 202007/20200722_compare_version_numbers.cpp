#include <iostream>
#include <string>
#include <sstream>
using namespace std;

/*

This problem was recently asked by Amazon:

Version numbers are strings that are used to identify unique states of software products. A version number is in the format a.b.c.d. and so on where a, b, etc. are numeric strings separated by dots. These generally represent a hierarchy from major to minor changes. Given two version numbers version1 and version2, conclude which is the latest version number. Your code should do the following:
If version1 > version2 return 1.
If version1 < version2 return -1.
Otherwise return 0.

Note that the numeric strings such as a, b, c, d, etc. may have leading zeroes, and that the version strings do not start or end with dots. Unspecified level revision numbers default to 0.

Example:
Input: 
version1 = "1.0.33"
version2 = "1.0.27"
Output: 1 
#version1 > version2

Input:
version1 = "0.1"
version2 = "1.1"
Output: -1
#version1 < version2

Input: 
version1 = "1.01"
version2 = "1.001"
Output: 0
#ignore leading zeroes, 01 and 001 represent the same number. 

Input:
version1 = "1.0"
version2 = "1.0.0"
Output: 0
#version1 does not have a 3rd level revision number, which
defaults to "0"
Here's a starting point

class Solution:
  def compareVersion(self, version1, version2):
    # Fill this in.

version1 = "1.0.1"
version2 = "1"
print(Solution().compareVersion(version1, version2))
# 1

*/

int compareVersion(string v1, string v2) {
	stringstream ss;
	bool major;
	float i1, i2;
	for (char ch: v1) {
		if (!major && ch == '.') {
			ss << ch;
			major=true;
		}
		else if (!major && ch-'0'>=0 && ch-'0'<=9) ss << ch;
		else if (ch-'1'>=0 && ch-'1'<=9) ss << ch;
	}
	ss >> i1;
	
	stringstream().swap(ss);
	major=false;

	for (char ch: v2) {
		if (!major && ch == '.') {
			ss << ch;
			major=true;
		}
		else if (!major && ch-'0'>=0 && ch-'0'<=9) ss << ch;
		else if (ch-'1'>=0 && ch-'1'<=9) ss << ch;
	}
	ss >> i2;

	if (i1 == i2) return 0;
	return i1>i2 ? 1: -1;
}

int main(){
	cout << compareVersion("1.0.1", "1") << "\n";      // 1     
	cout << compareVersion("1", "1") << "\n";          // 0         
	cout << compareVersion("0.99", "1") << "\n";       // -1     
	cout << compareVersion("0.0.9", "0.0.09") << "\n"; // 0
	cout << compareVersion("1.0.33", "1.0.27") << "\n"; // 1
	cout << compareVersion("0.1", "1.1") << "\n";       // -1     
	cout << compareVersion("1.01", "1.001") << "\n";    // 0   
	cout << compareVersion("1.0", "1.0.0") << "\n";     // 0    

	return 0;
}