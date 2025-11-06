// You know that an array has n integers between 1 and  m, and the absolute difference between two adjacent values is at most 1.
// Given a description of the array where some values may be unknown, your task is to count the number of arrays that match the description.

// --- SOLUTION DESCRIPTION ---
// MENTAL MODEL: We use 1D Dynamic Programming with space optimization. 
// dp[val] stores the total number of valid ways to fill the array up to the *current* index (i), 
// where the array element at position (i) is exactly the *value* (val).
// i.e. we are filling the array at (i) with (val) and keeping track of how many ways that is valid

// To calculate dp[val] for the current index i, we sum up the valid counts from the 
// *previous* index (i-1), which are stored in the 'prev' array:
// dp[val] = prev[val-1] + prev[val] + prev[val+1].
 
// OPTIMIZATION: We swap 'dp' and 'prev' arrays in each iteration to reuse space (O(M)).
// CONSTRAINTS: The inner loop uses 'lowerBound' and 'upperBound' to enforce two checks:
// 1. The problem's constraint (1 <= val <= M).
// 2. The input array's constraints (if arr[i] is known, the loop runs only for that one value).



#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	int n, m;
	ll MOD = 1e9  + 7;
	// Read input
	cin >> n >> m;
	vector<int> arr(n);
	for (int i = 0; i <n; i++) cin >> arr[i];

	// Initialize dp tables, one for the previous and one for the current
	vector<ll> prev(m + 1); // Think of this in vertical (i.e. rows)
	vector<ll> dp(m + 1);
	// This will initialize the first column of the dp table prev
	if (arr[0] == 0) // This means the first value is unknown, so you could have anything
		// therefore we fill it with 1s
		fill(prev.begin() + 1, prev.end(), 1);
	else
		// Else we only fill the corresponding value of prev to 1
		prev[arr[0]] = 1;


	// Build the dp tables
	// We use upper and lower bounds to only add the values that are within range (abs value diff of 1)
	// For a given number x there are always three candidates, x-1, x and x+1
	for (int i = 1; i < n; i++) { // Iterate over the array
		int lowerBound;
		int upperBound;
		if (arr[i] == 0) {
    			lowerBound = 1; // If our value is unknown (0) we assign the lower bound 1
			upperBound = m; // If our value is unknown (0) we assign the upper bound m
		}
		else {
    			lowerBound = arr[i]; // If our value is known we assign the lower bound the value itself
			upperBound = arr[i]; // If our value is known, the upper and the lower bounds will be equal
		}
		for (int val = lowerBound; val <= upperBound; val++){
			// Think of prev and dp as vertical towers, prev to the left and dp to the right
			// You add the value directly to the left always
			dp[val] += prev[val];

			// This conditions ensure we only add what is within the bounds:
			if (val > 1) dp[val] += prev[val - 1];
			if (val < m) dp[val] += prev[val + 1];
			dp[val] = dp[val] % MOD;
		}
		swap(dp, prev); // prev becomes dp
		fill(dp.begin(), dp.end(), 0l); // Fills with zero as a long
	}

	ll ans = accumulate(prev.begin(), prev.end(), 0l); // Sum all the column, initial value is zero long

	cout << ans % MOD; 

	return 0;
}


