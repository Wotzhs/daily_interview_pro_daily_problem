#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

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