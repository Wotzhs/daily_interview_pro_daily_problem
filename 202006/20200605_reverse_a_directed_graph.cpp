#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

/*

This problem was recently asked by Facebook:

Given a directed graph, reverse the directed graph so all directed edges are reversed.

Example:
Input:
A -> B, B -> C, A ->C

Output:
B->A, C -> B, C -> A
Here's a starting point:

from collections import defaultdict

class Node:
  def __init__(self, value):
    self.adjacent = []
    self.value = value

def reverse_graph(graph):
  # Fill this in.

a = Node('a')
b = Node('b')
c = Node('c')

a.adjacent += [b, c]
b.adjacent += [c]

graph = {
    a.value: a,
    b.value: b,
    c.value: c,
}

for _, val in reverse_graph(graph).items():
  print(val.adjacent)
# []
# ['a', 'b']
# ['a']

*/

typedef unordered_map<char, vector<char>> graph;

class Node {
public:
	vector<char> adjacent;
	char value;
	Node(char val): value(val) {};
};

graph reverseGraph(graph g) {
	graph ans;
	for (auto it=g.begin(); it != g.end(); it++)
		ans[it->first] = vector<char>();

	for (auto it = g.begin(); it != g.end(); it++)
		for (char ch: it->second)
			ans[ch].emplace_back(it->first);

	return ans;
}

void print(graph g) {
	for (auto it = g.begin(); it != g.end(); it++) {
		cout << it->first << ": [";
		for (int i=0; i<it->second.size(); i++) {
			cout << "'" << it->second[i] << "'";
			if (i < it->second.size()-1) cout << ", ";
		}
		cout << "]\n";
	}
}

int main(){
	Node a('a');
	Node b('b');
	Node c('c');

	a.adjacent.emplace_back('b');
	a.adjacent.emplace_back('c');
	b.adjacent.emplace_back('c');

	graph g;
	g[a.value] = a.adjacent;
	g[b.value] = b.adjacent;
	g[c.value] = c.adjacent;

	print(reverseGraph(g));
	// a = []
	// b = ['a']
	// c = ['a', 'b']

	return 0;
}