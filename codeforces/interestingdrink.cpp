// Interesting Drink
#include <bits/stdc++.h>
using namespace std; 
const int MAXN = 1e5 + 1; 
int X[MAXN];  

int main(){
  int n, i, q, m; cin >> n; i = n;  
  while (i--) cin >> X[i]; 
  sort(X, X+n); 
  cin >> q; 
  while (q--){
    cin >> m; 
    cout << upper_bound(X, X+n, m)-X << endl; 
  }

}
