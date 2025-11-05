#include<bits/stdc++.h>

using namespace std; 
using ll = long long int; 
using paiir = pair<int, int>; 

/*
La idea es usar un MAP para almacenar el valor como key y su posición en la lista como value, 
con esto, se revisa si se ha encontrado el complemento del valor actual de manera previa, 
en dado caso se regresan las posiciones actuales y la previa encontrada, en caso contrario 
se almacena el nuevo valor a la espera de encontrar su complemento, finalmente si no se encontró 
ninguna pareja se imprime el imposible. 
*/

int main(){
    int n, x, aux; 
    cin >> n >> x;
    map<int, int> valores;  
    for (int i = 0; i < n; i++){
        cin >> aux; 
        if (valores.count(x-aux) > 0){ // entonces su complemento ya fue añadido al map
            cout << valores[x-aux] << " " << i+1 << endl; 
            return 0; // Terminamos el programa una vez encontrada una respuesta. 
        }
        valores[aux] = i + 1; 
    }
    cout << "IMPOSSIBLE\n"; // no encontramos ningun par y terminamos de leer todos los valores 
}