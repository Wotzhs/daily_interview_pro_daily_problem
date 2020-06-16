#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

/*

This problem was recently asked by AirBNB:

Given two strings, determine the edit distance between them. The edit distance is defined as the minimum number of edits (insertion, deletion, or substitution) needed to change one string to the other.

For example, "biting" and "sitting" have an edit distance of 2 (substitute b for s, and insert a t).

Here's the signature:

def distance(s1, s2):
  # Fill this in.
         
print distance('biting', 'sitting')
# 2

*/

// credit: https://www.youtube.com/watch?v=We3YDTzNXEk
int minEditDistance(string s1, string s2) {
	int n=s1.size(), m=s2.size();
	int dp[n+1][m+1];

	for (int i=0; i<=n; i++) dp[i][0] = i;
	for (int i=0; i<=m; i++) dp[0][i] = i;

	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			if (s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1];
			else dp[i][j] = min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]}) + 1;
		}
	}

	return dp[n][m];
}

int main(){
	cout << minEditDistance("biting", "sitting") << "\n"; // 2
	cout << minEditDistance("abcde", "abcefg") << "\n"; // 3

	return 0;
}