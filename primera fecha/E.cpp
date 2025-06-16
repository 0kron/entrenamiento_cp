#include<bits/stdc++.h>

using namespace std; 

int main(){
  int n, m, aux; 
  scanf("%d %d", &n, &m); 
  for (int i = 0; i < n; i++){
    cin >> aux; 
    if (aux >= m) {
      cout << i+1 << endl; 
      return 0; 
    }

  }

  cout << -1 << endl; 
  return 0; 
}