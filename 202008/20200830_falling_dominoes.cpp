#include <iostream>
#include <string>
#include <queue>
using namespace std;

/*

This problem was recently asked by Twitter:

Given a string with the initial condition of dominoes, where:

. represents that the domino is standing still
L represents that the domino is falling to the left side
R represents that the domino is falling to the right side

Figure out the final position of the dominoes. If there are dominoes that get pushed on both ends, the force cancels out and that domino remains upright.

Example:
Input:  ..R...L..R.
Output: ..RR.LL..RR
Here is your starting point:

class Solution(object):
  def pushDominoes(self, dominoes):
    # Fill this in.

print Solution().pushDominoes('..R...L..R.')
# ..RR.LL..RR

*/

// n = length of dominoes
// TC o(n)
// SC o(n)
string pushDominoes(string dominoes) {
	queue<pair<char, int>> q;
	for (int i=0; i<dominoes.size(); i++)
		if (dominoes[i] != '.') q.push({dominoes[i], i});

	while(q.size()) {
		pair<char, int> curr = q.front(); q.pop();
		if (curr.first == 'R') {
			if (curr.second+1 < dominoes.size()) {
				if (dominoes[curr.second+1] == '.' && dominoes[curr.second+2] != 'L') {
					dominoes[curr.second+1] = curr.first;
					q.push({curr.first, curr.second+1});
				}
				else if (dominoes[curr.second+1] == 'L') dominoes[curr.second+1] = '.';
			}
		}
		if (curr.first == 'L') {
			if (curr.second-1 >= 0) {
				if (dominoes[curr.second-1] == '.' && dominoes[curr.second-2] != 'R') {
					dominoes[curr.second-1] = curr.first;
					q.push({curr.first, curr.second-1});
				}
				else if (dominoes[curr.second-1] == 'R') dominoes[curr.second-1] = '.';
			}
		}
	}
	return dominoes;
}

int main() {
	cout << pushDominoes("..R...L..R.") << "\n"; // ..RR.LL..RR
	cout << pushDominoes("R.........L") << "\n"; // RRRRR.LLLLL
	cout << pushDominoes("...........") << "\n"; // ...........
	cout << pushDominoes("L.........R") << "\n"; // L.........R
	cout << pushDominoes("RLRLRLRLRLR") << "\n"; // ..........R
	cout << pushDominoes("LRLRLRLRLRL") << "\n"; // L..........

	return 0;
}
