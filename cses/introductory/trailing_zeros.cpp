#include <bits/stdc++.h>
using namespace std; 

int main(){
  int n, res = 0, act = 1, i = 1; 
  cin >> n; 
  while (act != 0){
    act = n / pow(5, i);
    res += act; 
    i++; 
  }
  cout << res << endl; 
  return 0; 
}