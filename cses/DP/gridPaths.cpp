// Consider an n \times n grid whose squares may have traps. It is not allowed to move to a square with a trap

//  calculate the number of paths from the upper-left square to the lower-right square. You can only move right or down.

#include <bits/stdc++.h>
using namespace std;

int main() {
	// Read input
	int n;
	cin >> n;
	vector<string> grid(n);
	for (int i = 0; i <n; i++){
		cin >> grid[i];
	}

	int MOD = 1e9 + 7;
	// Build the dp table
	// In this implementation we are only using a single row in the dp table
	vector<int> dp(n);
	dp[0] = 1;
	for (int row = 0; row < n; row++){
		for (int col = 0; col < n; col++){
			if (grid[row][col] == '*') {
				dp[col] = 0;
				continue;
			}
			if (col > 0){
				// # of ways to get to a given point is # of ways to get to the point to the left + # of ways to get to the point above
				// As we are only using a single row, the point above is just the un-updated dp[col]
				dp[col] = (dp[col] + dp[col - 1]) % MOD;
			}

		}
	}

	cout << dp[n-1];
	return 0;
}
