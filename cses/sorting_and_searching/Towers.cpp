#include<bits/stdc++.h>

using namespace std; 
using ll = long long int; 
using paiir = pair<int, int>; 

int main(){
    int n, aux; cin >> n; 
    int t[n], r = 0; 
    for (int i = 0; i < n; i++){
        cin >> aux; 
        auto pos = upper_bound(t, t+r, aux); 
        t[pos - t] = aux; 
        if (pos == t + r){
            r++; 
        }
    }
    cout << r << endl; 
}