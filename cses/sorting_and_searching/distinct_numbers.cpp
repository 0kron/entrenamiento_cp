#include <bits/stdc++.h>
using namespace std; 

const int MAXN = 1e9 +1; 
map<int, int> mapa; 

int main(){
  int n, aux; 
  cin >> n; 
  while(n--){
    cin >> aux;
    if (mapa[aux] == 0) mapa.insert({aux, 1}); 
  }
  cout << mapa.size() << endl; 
  return 0; 
}