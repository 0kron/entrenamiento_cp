#include<bits/stdc++.h>

using namespace std; 
using ll = long long int; 
using paiir = pair<int, int>; 

/*
La primera intuición es encontrar el máximo local, es decir, si nos paramos 
en el valor más grande y vamos decreciendo el valor objetivo, debemos encontrar 
el momento en que el costo deje de bajar y comience a subir, así encontraremos el 
costo mínimo local para todos los cambios de costos. 

Más aún, esto se encontrará en el momento en que parados en el arreglo sorteado, 
tendremos la misma cantidad de elementos de un lado y del otro. 
*/

int main(){
    int n; 
    ll cost = 0; // se puede exceder
    cin >> n; 
    int p[n]; 
    for (int i = 0; i < n; i++) cin >> p[i]; 
    sort(p, p+n); 
    for (int i = 0; i < n; i++){
        cost += abs(p[i]-p[n/2]);  
    }
    cout << cost << endl; 
}