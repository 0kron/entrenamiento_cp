// Consider a money system consisting of n coins. Each coin has a positive integer value. 
// Your task is to produce a sum of money x using the available coins in such a way that the number of coins is minimal.
#include <bits/stdc++.h>
using namespace std;

int main(){
	// Read data
	int n, x;
	cin >> n >> x;
	vector <int> coins(n);
	for (int i = 0; i < n; i++){
		cin >> coins[i];
	}

	// Build the dp table
	vector<int> dp(x + 1, -1);
	dp[0] = 0;
	for (int i = 1; i <= x; i++){
		for (auto coin: coins){
			// can you sum to i with the coin? 
			bool possible = (i >= coin) && (dp[i-coin] != -1);
			// if not, go to the next coin
			if (!possible){
				continue;
			}

			int coinsNeeded = 1 + dp[i - coin];
			// If you previously couldn't sum or you needed more coins update the table
			if (dp[i] == -1 || coinsNeeded < dp[i]){
				dp[i] = coinsNeeded;
			}
		}
	}
	cout << dp[x];
	return 0;
}

