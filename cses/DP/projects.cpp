// There are n projects you can attend. 
// For each project, you know its starting and
// ending days and the amount of money you would get as reward.
// You can only attend one project during a day.
// What is the maximum amount of money you can earn?
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	ll n;
	cin >> n;
	ll best;
	vector <tuple <ll, ll, ll>> projects(n);
	map <ll, ll> dp; // Key: end date, Value: max reward

	// Read data
	for (int i = 0; i < n; i++){
		ll start,  end, reward;
		cin >> start >> end >> reward;
		projects[i] = {end, start, reward};
	}

	// Sort the data by deadline
	sort(projects.begin(), projects.end());

	dp[0] = 0;
	best = 0;
	for (auto project : projects){
		ll start, end, reward;
		start = get<1>(project);
		end = get<0>(project);
		reward = get<2>(project);
		// use binary search to look for last project that doesn't collide
		// points to the first key that is >= start
		auto it = dp.lower_bound(start);
		it --;	// This would be the first key that ends before our project starts
		// The total reward if we were to take on the project
		ll total = it->second + reward;
		best = max(best, total);
		dp[end] = best; // As of the last date our max reward is best
	}
	cout << best << endl;
	return 0;
}




