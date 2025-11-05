#include<bits/stdc++.h>

using namespace std; 
using ll = long long int; 
using paiir = pair<int, int>; 

/*
La idea es almacenar los tickets en un Set, que, para que pueda tener repeticiones lo hicimos de pares, 
donde se almacena el ticket y la posición en la que lo dí, con esto, se garantiza que se almacenen todas 
las repeticiones de los tickets, 
*/

int main(){
    int n, m; // n - número de tickets, m - número de clientes
    cin >> n >> m; 
    int aux, t[m], res[n]; 
    set<paiir> tickets; // Estructura de Datos donde se almacenarán los tickets sin usar. 
    for (int i = 0; i < n; i++){
        cin >> aux; 
        tickets.insert({aux, i}); 
    }
    for (int i = 0; i < m; i++) cin >> t[i]; 
    for (int i = 0; i < m; i++){
        auto match = tickets.lower_bound({t[i]+1, 0}); // nos encuentra el primer empate que es estrictamente mayor
        if (match == tickets.begin()) cout << -1 << endl; // si este empate está al inicio entonces no hay match
        else{ // si este empate está después del inicio, entonces hay algo menor o igual al máximo del cliente en match--
            match--; 
            cout << (*match).first << endl; 
            tickets.erase(match); 
        }
    }

}