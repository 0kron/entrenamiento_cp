// Team 
#include <bits/stdc++.h>
using namespace std; 
int main(){
  int n, a, b, c, total; 
  cin >> n; 
  while (n--){
    cin >> a >> b >> c; 
    if (a+b+c > 1) total++;
  }
  cout << total << "\n"; 
}
