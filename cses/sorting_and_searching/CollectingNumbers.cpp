#include<bits/stdc++.h>

using namespace std; 
using ll = long long int; 
using paiir = pair<int, int>; 

int main(){
    int n, aux; 
    cin >> n;
    vector<paiir> x;
    for (int i = 0; i < n; i++){
        cin >> aux; 
        x.push_back({aux, i});
    }
    sort(x.begin(), x.end()); 
     // for (auto val : x) cout << val.first << " " << val.second << endl; 
    int ind_act = -1, count = 1; 
    for (int i = 0; i < n; i++){
        if (ind_act > x[i].second) count++; 
        ind_act = x[i].second; 
    }
    cout << count << endl; 
}