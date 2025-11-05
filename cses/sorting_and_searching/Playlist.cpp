#include<bits/stdc++.h>

using namespace std; 
using ll = long long int; 
using paiir = pair<int, int>; 

/*
Basicamente, cuál es el tamaño máximo 
de números adyacentes sin repeticiones en la lista.
*/

int main(){
    int n, aux; cin >> n; 
    int k[n];  
    for (int i = 0; i < n; i++){
        cin >> k[i]; 
    }
    set<int> escuchadas; 
    int i = 0, j = 0, maxVal = 0; 
    while (i < n && j < n){
        while (j < n && !escuchadas.count(k[j])){
            escuchadas.insert(k[j]); 
            maxVal = max(maxVal, j-i+1); 
            j++; 
        }
        while (j < n && escuchadas.count(k[j])){
            escuchadas.erase(k[i]); 
            i++; 
        }
    }
    cout << maxVal << endl; 
} 