// There are n people who want to get to the top of a building which has only one elevator. 
// You know the weight of each person and the maximum allowed weight in the elevator. 
// What is the minimum number of elevator rides?

// --- SOLUTION DESCRIPTION ---
// State Definition: We use Bitmask DP, where the index represents a subset of people
// already moved, and DP[mask] stores the best outcome: the minimum total rides and the current weight of the final ride

// Subproblem Iteration: To find the optimal result for a given subset, we iterate over every person
// as the last person to board, using the best known result from the set without that person

// Optimal Transition: The transition determines if the last person can squeeze onto the previous ride
// (joining it) or if they must start a new ride, selecting the option that minimizes the total ride count

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	// read the input
	int n;
	ll maxWeight;
	cin >> n >> maxWeight;
	vector<ll> people(n);
	for(int i = 0; i < n; i++) cin >> people[i];

	// use bit-masking to compute the dp table
	int limit = 1 << n; //  left bit-shift op to get 2^n fast
	vector<pair<ll, ll>> dp(limit); // (numRides, weightLastRide)
	dp[0] = {1, 0};

	for(int mask = 1; mask < limit; mask++) {
		pair<ll, ll> best = {INT_MAX, INT_MAX};
		for (int i = 0; i < n; i++) {
			// 1 << i: creates an int where only the i-th bit is 1
			// If item i is NOT included in the current subset represented by mask, skip the current loop iteration
			if(((1 << i) & mask) == 0) continue;
			// Bitwise XOR operator (^) to flip the state of the i-th bit in the mask
			pair<ll, ll> res = dp[(1 << i) ^ mask];
			if (res.second + people[i] <= maxWeight)
				res.second += people[i]; //.second represents weightLastRide
			else {
				res.first += 1;
				res.second = people[i];
			}
			best = min(best, res);
		}
		dp[mask] = best;
	}
	cout << dp[limit - 1].first << endl;
	return 0;
}


