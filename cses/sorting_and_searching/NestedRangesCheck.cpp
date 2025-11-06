#include<bits/stdc++.h>
#define endl '\n'

using namespace std; 
using ll = long long int; 
using paiir  = pair<int, int>; 

struct rango{
    int l, r, ind; 
    bool operator< (const rango &other) const{
        if (l == other.l) return r > other.r; // si el inicio coincide regresa si el primero abarca al segundo
        return l < other.l; // si no coincide el inicio, regresa la relación de los inicios
    }
}; 

int main(){
    int n; cin >> n; 
    vector<rango> rangos(n); 
    vector<bool> contenidos(n); 
    vector<bool> contiene(n); 
    for (int i = 0; i < n; i++){
        cin >> rangos[i].l >> rangos[i].r; 
        rangos[i].ind = i; 
    }
    sort(rangos.begin(), rangos.end()); 
    int maxEnd = 0; // el fin más a la derecha de los rangos hasta ahora
    for (int i = 0; i < n; i++){
        if (rangos[i].r <= maxEnd) contenidos[rangos[i].ind] = true; // prendemos que está contenido
        maxEnd = max(maxEnd, rangos[i].r); // como ordenamos de menor a mayor las "l"s, entonces siempre garantizamos que cuando pasamos al siguiente rango, este pueda estar dentro del de maxEnd.
    }
    int minEnd = INT_MAX; 
    for (int i = n-1; i>= 0; i--){
        if (rangos[i].r >= minEnd) contiene[rangos[i].ind] = true;
        minEnd = min(minEnd, rangos[i].r); 
    }
    for(int i = 0; i < n; i++) cout << contiene[i] << " "; 
    cout << endl; 
    for(int i = 0; i < n; i++) cout << contenidos[i] << " "; 
    cout << endl; 

}