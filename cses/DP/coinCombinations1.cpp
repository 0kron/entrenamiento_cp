// Your task is to calculate the number of distinct ways you can produce a money sum x using the available coins. 

#include <iostream>
#include <vector>
using namespace std;
const long long MOD = 1000000007;

long long fun(vector<long long>& f, long long coins[], long long n, long long x) {
    if (f[x] == -1) {
        f[x] = 0;
        for (int k = 0; k < n; k++) {
            if (x - coins[k] >= 0) {
		f[x] = (f[x] + fun(f, coins, n, x - coins[k])) % MOD;
            }
        }
    }
    return f[x];
}

int main() {
    long long n, x;
    cin >> n; // Numero de monedas
    cin >> x; // Suma deseada
    long long coins[n];

    for (int i=0; i < n; i++){
        cin >> coins[i];

    }

    vector<long long> f(x + 1, -1);
    f[0] = 1;

    cout << fun(f, coins, n, x) << endl;
    return 0;
}

