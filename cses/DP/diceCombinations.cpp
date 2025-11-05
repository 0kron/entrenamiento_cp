// Your task is to count the number of ways to construct sum n 
// by throwing a dice one or more times. Each throw produces an outcome between 1 and  6.

// Input: The only input line has an integer n.
// Output: Print the number of ways modulo (10^9) + 7

#include <iostream>
#include <vector>
using namespace std;

const long long MOD = 1000000007;

long long fun(vector<long long>& f, long long n) {
    if (f[n] == -1) {
        f[n] = 0;
        for (int k = 1; k <= 6; k++) {
            if (n - k >= 0) {
                f[n] = (f[n] + fun(f, n - k)) % MOD;
            }
        }
    }
    return f[n];
}

int main() {
    long long n;
    cin >> n;
    vector<long long> f(n + 1, -1);
    f[0] = 1;

    cout << fun(f, n) << endl;
    return 0;
}

