#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

/*

This problem was recently asked by Google:

Given a positive integer, find the square root of the integer without using any built in square root or power functions (math.sqrt or the ** operator). Give accuracy up to 3 decimal points.

Here's an example and some starter code:

def sqrt(x):
  # Fill this in.
    
print(sqrt(5))
# 2.236

*/

// TC - o(log n)
// SC - o(1)
double binarySearch(double lo, double hi, int target) {
	double mid=lo+(hi-lo)/2, square=mid*mid;
	if (square == target || abs(target-square) <= 0.001) return  mid;
	else if (square>target) return binarySearch(lo, mid, target);
	else return binarySearch(mid, hi, target);
}

double sqrt(int n) {
	return n == 1 ? 1 : binarySearch(0, n, n);
}

int main() {
	cout << setprecision(3) << fixed << sqrt(5) << "\n"; // 2.236
	cout << sqrt(4) << "\n"; // 2
	cout << sqrt(18) << "\n"; // 4.243

	return 0;
}
