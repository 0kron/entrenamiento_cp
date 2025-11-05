#include<bits/stdc++.h>

using namespace std; 
using ll = long long int; 
using paiir = pair<int, int>; 

/*
Todo 
*/

int main(){
    int n, m; 
    cin >> n >> m; 
    vector<int> valores(n+1);
    vector<int> posiciones(n+1);  
    for (int i = 1; i <= n; i++){
        cin >> valores[i]; 
        posiciones[valores[i]] = i; 
    }
    int res = 1; // siempre se necesita al menos una ronda
    for (int i = 0; i < n; i++){
        res += (posiciones[i] > posiciones[i+1]); 
    }
    int l, r; 
    set<paiir> parejas; 
    while(m--){
        cin >> l >> r; 
        if (valores[l] + 1 <= n) parejas.insert({valores[l], valores[l] + 1}); 
        if (valores[l] - 1 >= 1) parejas.insert({valores[l]-1, valores[l]}); 
        if (valores[r] + 1 <= n) parejas.insert({valores[r], valores[r] + 1}); 
        if (valores[r] - 1 >= 1) parejas.insert({valores[r]-1, valores[r]}); // guardamos las parejas afectadas
        for (paiir inversiones : parejas) res -= (posiciones[inversiones.first] > posiciones[inversiones.second]); 
        swap(valores[l], valores[r]); 
        posiciones[valores[l]] = l; 
        posiciones[valores[r]] = r; 
        for (paiir inversiones : parejas) res += (posiciones[inversiones.first] > posiciones[inversiones.second]); 
        cout << res << endl; 
        parejas.clear(); 
    }
}