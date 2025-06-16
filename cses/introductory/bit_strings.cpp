#include <bits/stdc++.h>
using namespace std; 
using ll = long long int; 

const int m = 1e9 + 7; 

int main(){
  int n; ll res = 1;  
  cin >> n; 
  for (int i = 1; i<=n; i++){
    res = res<<1; 
    res %= m; 
  }
  cout << res<< endl; 
  return 0; 
}