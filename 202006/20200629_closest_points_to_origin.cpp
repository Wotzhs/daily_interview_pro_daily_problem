#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*

This problem was recently asked by Google:

Given a list of points and a number k, find the k closest points to the origin.

def findClosestPointsOrigin(points, k):
  # Fill this in.

print (findClosestPointsOrigin([[1, 1], [3, 3], [2, 2], [4, 4], [-1, -1]], 3))
# [[-1, -1], [1, 1], [2, 2]]

*/

vector<pair<int, int>> findClosestPointsOrigin(vector<pair<int, int>> points, int k) {
	if (k == 0) return vector<pair<int, int>>();

	sort(points.begin(), points.end(), [&](auto const &p1, auto const &p2){
		int p1Dist = p1.first*p1.first + p1.second*p1.second;
		int p2Dist = p2.first*p2.first + p2.second*p2.second;
		if (p1Dist == p2Dist) return (p1.first+p1.second < p2.first+p2.second);
		else return p1Dist < p2Dist;
	});

	for (int i=points.size(); i>k; i--)
		points.pop_back();

	return points;
}

void print(vector<pair<int, int>> points) {
	cout << "[";
	for (int i=0; i<points.size(); i++) {
		auto p = points[i];
		cout << "[" << p.first << ", " << p.second <<"]";
		if (i<points.size()-1) cout << ", ";
	}
	cout << "]\n";
}

int main(){
	print(findClosestPointsOrigin({{1, 1}, {3, 3}, {2, 2}, {4, 4}, {-1, -1}}, 3)); // [[-1, -1], [1, 1], [2, 2]]
	print(findClosestPointsOrigin({{1, 1}, {3, 3}, {2, 2}, {4, 4}, {-1, -1}}, 0)); // []
	print(findClosestPointsOrigin({{1, 1}, {3, 3}, {2, 2}, {4, 4}, {-1, -1}}, 5)); // [[-1, -1], [1, 1], [2, 2], [3, 3], [4, 4]]
	print(findClosestPointsOrigin({{1, 1}, {3, 3}, {2, 2}, {4, 4}, {-1, -1}}, 6)); // [[-1, -1], [1, 1], [2, 2], [3, 3], [4, 4]]
	return 0;
}