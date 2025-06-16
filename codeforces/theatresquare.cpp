// Theatre Square
#include<bits/stdc++.h>

using namespace std; 
using ll = long long int;


int main(){
  int n, m, a; 
  cin >> n >> m >> a; 
  ll r = 1;
  if (n%a != 0) r*=(n/a)+1; 
  else r*= n/a; 
  if (m%a != 0) r*= (m/a)+1; 
  else r*= m/a; 
  cout << r << "\n";
}
