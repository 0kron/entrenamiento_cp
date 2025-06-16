// Even Odds 
#include <bits/stdc++.h>
using namespace std; 
using ll = long long int; 

int main(){
  ll n, k, r; 
  cin >> n >> k; 
  if (n%2==1) n++;
  if (k <= n/2) r = 2*(k-1) + 1; 
  else r = 2*(k-n/2); 
  cout << r << "\n";
}
