#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

/*

This problem was recently asked by Apple:

Given a list of points, an interger k, and a point p, find the k closest points to p.

Here's an example and some starter code:

class Point:
  def __init__(self, x=0, y=0):
    self.x = x
    self.y = y

  def __repr__(self):
    return f"({self.x}, {self.y})"

def closest_points(points, k, p):
  # Fill this in.

points = [
    Point(0, 0),
    Point(1, 1),
    Point(2, 2),
    Point(3, 3),
]
print(closest_points(points, 2, Point(0, 2)))
# [(0, 0), (1, 1)]

*/

class Point {
public:
	int x, y;
	Point(int X, int Y): x(X), y(Y) {};
};

vector<Point> nearestPoints(vector<Point> &points, int k, Point p) {
	vector<pair<float, Point>> distances;

	for (int i=0; i < points.size(); i++) {
		float dist = sqrt(pow(abs(points[i].x-p.x), 2) + pow(abs(points[i].y-p.y), 2));
		distances.emplace_back(make_pair(dist, points[i]));
	}

	struct {
		bool operator() (pair<float, Point> a, pair<float, Point>b) const {
			return a.first < b.first;
		}
	} distancesLess;

	sort(distances.begin(), distances.end(), distancesLess);

	vector<Point> ans;
	for (int i=0; i < k; i++) 
		ans.emplace_back(distances[i].second);
	
	return ans;
}

int main() {
	vector<Point> points = { Point(0,0), Point(1,1), Point(2,2), Point(3,3) };

	cout << "[";
	for (auto p: nearestPoints(points, 2, Point(0,2)))
		cout << "[" << p.x << "," << p.y << "]";
	cout << "]\n"; // [[1,1][0,0]]

	return 0;
}