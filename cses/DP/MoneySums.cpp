#include<bits/stdc++.h>

using namespace std; 
using ll = long long int; 

int x[101]; 
const int MAXSUM = 1e5+1; 

int main(){
    int n, i, max = 0; cin >> n; 
    for (i = 0; i < n; i++){
        cin >> x[i]; 
        max += x[i]; 
    }
    vector<vector<int>> suma(101, vector<int>(max+1,0)); 
    suma[0][0] = 1; 
    for (i = 0; i < n; i++){
        for (int j = 0; j<=max-x[i]; j++){
            suma[i+1][j] |= suma[i][j]; 
            suma[i+1][j+x[i]] |= suma[i][j];
        }
    }
    int count = 0; 
    for (i = 1; i <= max; i++){
        if (suma[n][i]) count++; 
    } 
    cout << count << endl; 
    for (i = 1; i <= max; i++){
        if (suma[n][i]) cout << i << " ";
    } 
    cout << endl; 
}