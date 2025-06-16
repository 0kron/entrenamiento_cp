#include <bits/stdc++.h>
using namespace std; 
using ll = long long int; 

int main(){
  int n, prev = 0, act; 
  ll count = 0; 
  cin >> n; 
  for (int i = 0; i < n; i++){
    cin >> act; 
    if (prev - act > 0){
      count += prev - act; 
    }
    else prev = act; 
  }
  cout << count << endl; 
  return 0; 
}