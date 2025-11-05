#include<bits/stdc++.h>

using namespace std; 
using ll = long long int; 
using paiir = pair<int, int>; 

/*
Este es un problema bastante famoso, su complejidad viene de que se pueden tener
enteros negativos, con esto, el algoritmo que lo resuelve se llama "Kadane's Algorithm", 
se resume en "dejar atrás el pasado cuando se vuelve una carga", es decir, llevamos una 
variable de la suma pasada con la que obtenemos la suma presente, y la comparamos con
la variable actual sola, en el momento en que "cargar" el pasado sea menor que el actual solo 
lo borramos, siempre comparando con el valor maximo almacenado hasta ese momento. 
*/

int main(){
    ll n, aux; cin >> n; 
    ll maxVal = INT_MIN, past = 0; // NT_MIN es el valor mínimo del int32
    while(n--){
        cin >> aux; 
        past = max(past+aux, aux); 
        maxVal = max(maxVal, past); 
    }
    cout << maxVal << endl; 
}