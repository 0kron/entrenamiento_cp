#include<bits/stdc++.h>

using namespace std; 
using ll = long long int; 
using paiir = pair<int, int>; 

int main(){
    int n, a, b, mx = 0; 
    cin >> n; 
    vector<paiir> eventos; 
    for (int i = 0; i < n; i++){
        cin >> a >> b; 
        eventos.push_back({a, 1}); 
        eventos.push_back({b, -1}); 
    }
    sort(eventos.begin(), eventos.end()); 
    int act = 0; 
    for (int i = 0; i < 2*n; i++){
        act += eventos[i].second; 
        mx = max(mx, act); 
    }
    cout << mx; 
}