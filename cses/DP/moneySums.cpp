// You have n coins with certain values.
// Your task is to find all money sums you can create using these coins.
#include <bits/stdc++.h>
using namespace std;

int main(){
	// Read input
	int n;
	cin >> n;
	vector <int> coins(n);
	for(int i = 0; i < n; i++) cin >> coins[i];

	// Build dp table
	vector<bool> dp(100000); // The maximum sum we can have is 100 coins of 1000 each, so 100,000
	set<int> distinctSums; // sets automatically keep it's elements sorted (in ascending order by default) as you insert them
	dp[0] = true; // You can always sum zero, so this is your base case
	int total = 0;
	for(auto coin: coins){
		total += coin; // this is so that you start looking at your upper bound, the most you can sum
		// reading from left to righ allows you to only keep track of one row and you can avoid using a prev vector
		for(int i = total; i >= coin; i--){ // When you get to your coin, there is no way to sum things smaller with that coin
			if(dp[i - coin] && !dp[i]) { // if you can sum i - coin and you have a coin, then you can sum to i
				dp[i] = true;
				distinctSums.insert(i);
			}
		}

	}
	cout << distinctSums.size() << endl;
	for(auto i: distinctSums){
		cout << i << " ";
	}

	return 0;
}


