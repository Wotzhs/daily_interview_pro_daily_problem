#include <iostream>
#include <vector>
using namespace std;

/*

This problem was recently asked by Amazon:

Given a positive integer n, find all primes less than n.

Here's an example and some starter code:

def find_primes(n):
  # Fill this in.

print(find_primes(14))
# [2, 3, 5, 7, 11, 13]

*/

vector<int> findPrimes(int n) {
	vector<int> ans;
	if (n<1) return ans;

	vector<int> soe(n+1, 0);
	for (int i=2; i<=n; i++) {
		if (soe[i]==0) soe[i]++;
		for (int j=i+i; j<=n; j+=i) {
			soe[j] = -1;
		}
	}

	for (int i=2; i<=n; i++)
		if (soe[i]>0) ans.emplace_back(i);

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
	print(findPrimes(14)); // [2, 3, 5, 7, 11, 13]
	print(findPrimes(50)); // [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47]
	print(findPrimes(3)); // [2, 3]
	print(findPrimes(0)); // []
	print(findPrimes(1)); // []
	return 0;
}