// You are given an array containing n integers
// Your task is to determine the longest increasing subsequence in the array
// i.e., the longest subsequence where every element is larger than the previous one
// A subsequence is a sequence that can be derived from the array by deleting some
// elements without changing the order of the remaining element

#include <bits/stdc++.h>
using namespace std;

int main(){
	// read input
	int n;
	cin >> n;
	vector<int> sequence(n);
	for(int i = 0; i < n; i++) cin >> sequence[i];

	// build our LIS array
	vector<int> longestSub;
	for(auto i: sequence){
		// binary search to find the first number that is gt or eq to i
		auto lower = lower_bound(longestSub.begin(), longestSub.end(), i);
		if (lower == longestSub.end())
			longestSub.push_back(i);
		else
			*lower = i;
	}
	cout << longestSub.size() << endl;
	return 0;
}


