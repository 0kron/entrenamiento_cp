// Your task is to count the number of ways numbers 1,2,...,n can be divided into two sets of equal sum
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	// read input
	int n;
	cin >> n;	
	int total = (n * (1 + n)) / 2; // Sum of 1 to n. 
	if (total % 2 != 0){
		cout << 0 << endl;
		return 0;
	}

	ll MOD = 1e9 + 7;
	// build the dp table
	int half = total / 2;
	vector<ll> dp(half + 1);
	dp[0] = 1;
	for (int coin = 1; coin <= n; coin++){
		for(int i = half; i >= coin; i--){
			dp[i] = (dp[i] + dp[i - coin]) % MOD;

		}
	}
	// We only cout half as they are reapeated (symetrical)
	// division must be done using the Modular Multiplicative Inverse (MMI), not standard division
	ll MOD_INV_2 = 500000004;
	cout << (dp[half] * MOD_INV_2) % MOD << endl;
	return 0;
}

