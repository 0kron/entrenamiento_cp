#include <bits/stdc++.h>

using namespace std; 
using ll = long long int; 

int main(){
  ll n, aux, m, sum = 0; 
  cin >> n; 
  m = ((n+1)*n) / 2; 
  for (int i = 0; i < n-1; i++){
    cin >> aux; 
    sum += aux; 
  }
  cout << m - sum << endl; 

  return 0; 
}