// Your task is to count the number of integers between a and b where no two adjacent digits are the same
#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll solve(ll num, vector<ll> &dp) {
    // Base Case: If the number is < 1. Returns 1 for the empty number (num=0), 0 otherwise.
    if (num < 1)
        return num == 0 ? 1: 0; 
        
    string numString = to_string(num);
    ll res = 0;
    
    // --- 1. Count all valid numbers with fewer digits than 'num' ---
    for (int i = 0; i < numString.size(); i++){
        res += dp[i]; // dp[i] stores the total count of valid numbers with exactly i digits.
    }

    // --- 2. Count numbers with the same number of digits using prefix logic ---
    int prev = 0; // Tracks the previously placed digit; initialized to 0 for the first position check.
    for (int i = 0; i < numString.size(); i++){
        int digit = numString[i] - '0';
        // 'diff' is the count of remaining digit positions to fill.
        int diff = numString.size() - i - 1; 
        
        // 'below' determines the number of valid choices (d < digit) that are not equal to 'prev'.
        // If prev < digit: the invalid choice is 'prev', so (digit - 1) choices remain.
        // If prev >= digit: 'prev' is outside the range [0, digit-1], so 'digit' choices remain.
        int below = prev < digit ? digit - 1: digit; 
        
        // Add the result: (Valid choices 'below' * Ways to fill the remainder (dp[diff])).
        // The ternary check avoids counting numbers starting with 0 (since dp[diff] includes all 9 options).
        res += (digit == 0) ? 0 : below * dp[diff];

        // --- BREAK CONDITION ---
        // If the current digit violates the constraint (digit == prev), stop counting and return 'res'.
        if (digit == prev)
            return res; 
            
        // Set the current digit as the previous digit for the next iteration.
        prev = digit;
    }
    
    // If the loop completes, the target number 'num' itself is valid; add 1 for 'num'.
    return res + 1; 
}




int main(){
    // read the input range [a, b]
    ll a, b;
    cin >> a >> b;

    // --- PRE-CALCULATE DP TABLE ---
    // dp[i] stores the total count of valid numbers with EXACTLY 'i' digits.
    vector<ll> dp(19); 
    dp[0] = 1; // Base case: one way to have zero digits (the empty number).
    ll res = 1;
    // Calculation: 9 * 9 * 9 * ... 
    for(int i = 1; i < 19; i++){
        // For i-digits: The count is the previous count times 9 (10 choices - 1 excluded choice).
        res *= 9;
        dp[i] = res; 
    }

    // --- COMPUTE FINAL RESULT ---
    // Use Inclusion-Exclusion Principle: solve(b) - solve(a-1) for the inclusive range [a, b].
    cout << solve(b, dp) - solve(a-1, dp) << endl;

    return 0;
}
