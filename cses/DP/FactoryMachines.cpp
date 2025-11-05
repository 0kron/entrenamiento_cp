#include<bits/stdc++.h>

using namespace std; 
using ll = long long int; 

int main(){
    int n; ll t; 
    cin >> n >> t; 
    vector<int> k(n); 
    int min_n = INT_MAX; 
    for (int &x : k){
        cin >> x; 
        min_n = min(min_n, x);
    }
    ll lo = 0, hi = min_n * t, res = 0;
    while (lo <= hi){
        ll mid = (lo + hi)/2, sum = 0;
        for (int i = 0; i < n; i++){
            sum += (mid / k[i]); 
            if (sum >= t) break; 
        } 

        if (sum >= t) {
            res = mid; 
            hi = mid - 1; 
        }
        else {
            lo = mid + 1; 
        }
    }
    cout << res << endl; 
}