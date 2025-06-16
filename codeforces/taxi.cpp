// Taxi 1100
#include<bits/stdc++.h>
using namespace std; 
int s[4] {0, 0, 0, 0}, c = 0; 


int main(){
  int n, aux;
  cin >> n; 
  while (n--){
    cin >> aux; s[aux-1]++; 
  }
  c += s[3]; 
  c += s[2]; 
  if (s[2] <= s[0]) s[0] -= s[2];
  else s[0] = 0; 
  c += ceil((float) s[1] / 2); 
  if (s[1] % 2 != 0){
    if (2 <= s[0]) s[0] -= 2; 
    else s[0] = 0; 
  }
  c += ceil((float) s[0] / 4); 
  cout << c << "\n"; 
}
