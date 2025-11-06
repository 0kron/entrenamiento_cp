// Consider a money system consisting of n coins. Each coin has a positive integer value.
// Your task is to calculate the number of distinct ordered ways you can produce a money sum x using the available coins.

#include <bits/stdc++.h>

using namespace std;

int main(){
	int MOD = 1e9 + 7;
        // Read data
        int n, x;
        cin >> n >> x;
        vector <int> coins(n);
        for (int i = 0; i < n; i++){
                cin >> coins[i];
        }

        // Build the dp table
	vector<int> dp(x+1);
	dp[0] = 1;

	for (auto coin : coins){
		for (int i = coin; i <=x; i++){
			dp[i] = (dp[i] + dp[i - coin]) % MOD;
		}

	}
	cout << dp[x];
	return 0;
}

