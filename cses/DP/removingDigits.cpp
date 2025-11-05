// You are given an integer n. On each step, you may subtract one of the digits from the number.
// How many steps are required to make the number equal to 0

#include <iostream>
#include <vector>
using namespace std;

int fun(vector<int>& memo, int j){
	if (memo[j] == -1){
		// We get the minimum from i - d for all the digits
		int current_j = j;
		int min_steps = 1000000; // A large value, similar to 'inf'
		while (current_j > 0) {
    			int d = current_j % 10; // Get the last digit
    			if (d != 0) {
        			// Here we make the recursive call for the next state: j - d
        			int steps_from_next = fun(memo, j - d);
        
        			// Update the minimum
        			if (steps_from_next < min_steps){
					min_steps = steps_from_next;
				}
    			}

    			current_j = current_j / 10; // Move to the next digit
		}

		memo[j] = 1 + min_steps;
	}
	return memo[j];
}

int main() {
	int n;
	cin >> n; // Integer given

	vector<int> memo(n+1, -1); // memo stores the minimum steps required to get to 0 for memo[i]
	memo[0] = 0;
	
	cout << fun(memo, n) << endl;

	return 0;
}

