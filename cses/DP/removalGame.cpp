// There is a list of n numbers and two players who move alternately
// On each move, a player removes either the first or last number from the list, 
// and their score increases by that number. Both players try to maximize their scores.
// What is the maximum possible score for the first player when both players play optimally?
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	// Read input
	int n;
	cin >> n;
	vector<ll> list(n);
	for (int i = 0; i < n; i++) cin >> list[i];

	// initialize dp and prefixSum
	// dp[i][j] will store the best score from index i to j
	vector<ll> prefixSums(n); // What does the prefix of the array sum?
	vector<vector<ll>> dp(n, vector<ll>(n)); // n X n dp table
	for (int i = 0; i < n; i++){
		dp[i][i] = list[i];
		prefixSums[i] = list[i];
		if(i > 0)
			prefixSums[i] += prefixSums[i-1];
	}

	// Build the dp table
	for(int size = 2; size <= n; size++){
		for(int i = size - 1; i < n; i++){
			ll total;
			// Calculate the starting index j for the current window [j, i]
        		int j = i - size + 1; // (e.g., if size=2, i=1, j=0)
			// Calculate total sum for the range [j, i]
			total = prefixSums[i];
			if (j > 0)
             			total -= prefixSums[j - 1];

			ll selectLast = total - dp[j][i - 1];
			ll selectFirst = total - dp[j + 1][i];
			dp[j][i] = max(selectLast, selectFirst);
		}
	}
	cout << dp[0][n-1] << endl;
	return 0;
}

