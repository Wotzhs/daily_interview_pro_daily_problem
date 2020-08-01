#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

/*

This problem was recently asked by Uber:

Given a string s and a character c, find the distance for all characters in the string to the character c in the string s. You can assume that the character c will appear at least once in the string.

Here's an example and some starter code:

def shortest_dist(s, c):
  # Fill this in.

print(shortest_dist('helloworld', 'l'))
# [2, 1, 0, 0, 1, 2, 2, 1, 0, 1]

*/

typedef pair<int, int> pii;

vector<int> shortestDist(string s, char c) {
	int n=s.size();
	bool visited[n];
	vector<int> ans(n ,0);
	queue<pii> q;
	for (int i=0; i<n; i++) {
		if (s[i] == c) {
			q.emplace(make_pair(i, 0));
			visited[i] = true;
		}
	}

	while(q.size()) {
		pii p = q.front();
		q.pop();
		ans[p.first] = p.second;
		if (p.first-1>=0 && !visited[p.first-1]) {
			q.emplace(make_pair(p.first-1, p.second+1));
			visited[p.first-1] = true;
		}
		if (p.first+1<n && !visited[p.first+1]) {
			q.emplace(make_pair(p.first+1, p.second+1));
			visited[p.first+1] = true;
		}
	}

	return ans;
}

void print(vector<int> ans) {
	cout << "[";
	for (int i=0; i<ans.size(); i++) {
		cout << ans[i];
		if (i<ans.size()-1) cout << ", ";
	}
	cout << "]\n";
}

int main(){
	print(shortestDist("helloworld", 'l')); // [2, 1, 0, 0, 1, 2, 2, 1, 0, 1]
	print(shortestDist("aaaaabaaaaa", 'b')); // [5, 4, 3, 2, 1, 0, 1, 2, 3, 4, 5]
	print(shortestDist("baaaaaaaaab", 'b')); // [0, 1, 2, 3, 4, 5, 4, 3, 2, 1, 0]
	return 0;
}