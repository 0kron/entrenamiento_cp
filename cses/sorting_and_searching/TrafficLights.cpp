#include<bits/stdc++.h>

using namespace std; 
using ll = long long int; 
using paiir = pair<int, int>; 
#define endl "\n"; 

/*
Solo nos interesan como cambia el intervalo en el que entra
el nuevo valor que estamos agregando, set, como está ordenado 
nos puede dar el prev y el next, perfectos para encontrar el intervalom
lo que queda, es almacenar el intervalo máximo, en caso de ser modificado, 
modificaremos el máximo intervalo. 
*/

int main(){
    int x, n; cin >> x >> n; 
    set<int> cotas{0, x};
    multiset<int> longs{x}; 
    while (n--){
        cin >> x; 
        cotas.insert(x);
        // find en los set regresa el puntero asociado a la aparición de la key
        auto iter = cotas.find(x); 
        int p = *prev(iter); // valor previo en el set, prev es solo el puntero pasado
        int n = *next(iter); // valor siguiente en el set, next es el puntero siguiente
        longs.erase(longs.find(n-p)); // es necesario usar el find para que elimine solo la primera aparición de las que encuentra, no todas
        longs.insert(x-p); 
        longs.insert(n-x);
        cout << *longs.rbegin() << " "; // .rbegin es el puntero que toca el último valor, * es su valor asociado
    }
    // cout << endl; 
}