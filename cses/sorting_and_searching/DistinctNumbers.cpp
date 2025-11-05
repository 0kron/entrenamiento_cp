#include <bits/stdc++.h>
using namespace std; 

/*
Este problema tiene dos vías obvias: 
1. Abusar el funcionamiento de una estructura como Map o Set, O(nlog n). (agregar valores toma log (n)). 
2. Sortear los números dados y devolver los cambios al leerlo lineal, O(nlog n). 
*/

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