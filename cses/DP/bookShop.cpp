// You are in a book shop which sells n different books. You know the price and number of pages of each book.
// You have decided that the total price of your purchases will be at most x.
// What is the maximum number of pages you can buy?
// You can buy each book at most once.
#include <bits/stdc++.h>

using namespace std;

int main() {
	// read input
	int n, maxPrice;
	cin >> n >> maxPrice;
	vector<int> prices(n);
	vector<int> pages(n);
	for(int i = 0; i < n; i++) cin >> prices[i];
	for(int i = 0; i < n; i++) cin >> pages[i];

	// build dp table (You only need one row)
	vector<int> dp(maxPrice + 1); // at index price you store the max pages you can buy for that price
	for (int i = 0; i < n; i++){
		int bookPrice = prices[i];
		int bookPages = pages[i];
		// Trick to avoid using two or more rows:
		// read from the right(end) to the left(start)
		// The reason for this is that once you buy a book, you always move to the left in the table:  money - price = money left (<-)
		for (int price = maxPrice; price >= bookPrice; price--){
			dp[price] = max(dp[price], bookPages + dp[price - bookPrice]);
		}
	}
	cout << dp[maxPrice];
	return 0;
}
