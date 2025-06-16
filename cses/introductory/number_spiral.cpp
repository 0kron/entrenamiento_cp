#include <bits/stdc++.h>
using namespace std; 
using ll = long long int; 

int main(){
  int t ;
  ll res, x, y, max, min;
  cin >> t; 
  for (int i = 0; i < t; i++){
    cin >> y >> x; 
    if (x > y){max = x; min = y;}
    else{max = y; min = x;}
    res = max * max - (max - 1); 
    if (max % 2 == 0){
      if (min == y) res -= max - min; 
      else res += max - min; 
    }
    else{
      if (min == y) res += max - min; 
      else res -= max - min;
    }
    cout << res << endl; 
  }
  
  return 0; 
}
