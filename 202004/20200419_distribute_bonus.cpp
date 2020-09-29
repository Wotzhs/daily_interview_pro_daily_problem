#include <iostream>
#include <vector>
using namespace std;

/*

This problem was recently asked by Twitter:

You are the manager of a number of employees who all sit in a row. The CEO would like to give bonuses to all of your employees, but since the company did not perform so well this year the CEO would like to keep the bonuses to a minimum.

The rules of giving bonuses is that:
- Each employee begins with a bonus factor of 1x.
- For each employee, if they perform better than the person sitting next to them, the employee is given +1 higher bonus (and up to +2 if they perform better than both people to their sides).

Given a list of employee's performance, find the bonuses each employee should get.

Example:
Input: [1, 2, 3, 2, 3, 5, 1]
Output: [1, 2, 3, 1, 2, 3, 1]
Here's your starting point:

def getBonuses(performance):
  # Fill this in.

print getBonuses([1, 2, 3, 2, 3, 5, 1])
# [1, 2, 3, 1, 2, 3, 1]

*/

// TC - o(n)
// SC - o(n)
vector<int> getBonuses(vector<int> performance) {
	if (!performance.size()) {
		return performance;
	}
	vector<int> ans(performance.size(), 1);
	for (int i=1; i<performance.size()-1; i++) {
		if (performance[i-1] < performance[i]) {
			ans[i]++;
		}
		
		if (performance[i+1] < performance[i]) {
			ans[i]++;
		}
	}
	return ans;
}

void print(vector<int> v) {
	cout << "[";
	for (int i=0; i<v.size(); i++) {
		cout << v[i];
		if (i<v.size()-1) {
			cout << ", ";
		}
	}
	cout << "]\n";
}

int main() {
	print(getBonuses({1,2,3,2,3,5,1})); // [1, 2, 3, 1, 2, 3, 1]
	return 0;
}
