#include<bits/stdc++.h>

using namespace std; 
using ll = long long int; 
using paiir = pair<int, int>; 

/* 
Este problema tiene una solución en DP, similar al Money Sums, 
sin embargo, aquí se presenta la solución con sorting and searching, 
dado que la escala de este problema hace a la solución de DP inviable. 

Esto funciona por inducción, es decir, dado que podemos generar 
todas las sumas entre 1 y k, llegados a la posición i-1, entonces, 
es posible generar las sumas desde 1 hasta k+1 usando el número en
la posición i? Si el número es mayor a k+1, no, por el contrario sí.  
*/

int main(){
    int n; cin >> n; 
    int x[n]; 
    for (int i = 0; i<n; i++) cin >> x[i]; 
    sort(x, x+n); 
    ll k = 1; 
    for (int i = 0; i < n && k >= x[i]; i++){
        k+=x[i]; 
    }
    cout << k << endl; 
}