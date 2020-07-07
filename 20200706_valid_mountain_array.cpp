#include <iostream>
#include <vector>
using namespace std;

/*

This problem was recently asked by Microsoft:

Given an array of heights, determine whether the array forms a "mountain" pattern. A mountain pattern goes up and then down.

Like
  /\
 /  \
/    \
class Solution(object):
  def validMountainArray(self, arr):
    # Fill this in.

print(Solution().validMountainArray([1, 2, 3, 2, 1]))
# True

print(Solution().validMountainArray([1, 2, 3]))
# False

*/

bool validMountainArray(vector<int> arr) {
	if (arr.size()<1) return false;
	int peak=-1;
	bool dec=false;
	for (int i=0; i<arr.size(); i++){
		if (i+1 < arr.size()-1 && arr[i] == arr[i+1]) return false;
		peak = max(peak, arr[i]);
		if (arr[i] < peak) dec = true;
		if (dec && arr[i] > arr[i-1]) return false;
	}

	return peak != arr[0] && peak != arr[arr.size()-1] && dec;
}

int main(){
	cout << validMountainArray({1,2,3,2,1}) << "\n"; // true
	cout << validMountainArray({1,2,3}) << "\n"; // false
	return 0;
}