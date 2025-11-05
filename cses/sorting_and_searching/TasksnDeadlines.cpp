#include <bits/stdc++.h>

using namespace std;

int main(){
    long long int n, sum = 0, t;
    cin >> n;
    long long int d[n];
    
    for(int i = 0; i < n; i++){
        cin >> d[i] >> t;
        sum += t;
    }
    
    sort(d, d + n);
    
    for(int j = 0; j < n; j++){
        sum -= (j + 1) * d[n - j - 1];
    }
    
    cout << sum;
    
    return 0;
}