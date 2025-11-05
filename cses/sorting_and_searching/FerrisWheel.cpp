#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

/*
Como el número de niños en la góndola está limitado a 2, tenemos garantizado 
que al menos un niño siempre cabe en la góndola, con esto, entonces, por lo bajo, el más 
pesado siempre va a entrar, entonces, revisamos si el más grande y el más ligero entran a la vez, 
en caso de que sí, nos movemos en los ligeros a la derecha, en caso en que no, nos movemos
en los pesados a la izquierda, y siempre aumentamos la cantidad de góndolas por iteración. 
*/

int main(){
    ll  n, x;
    cin >> n >> x;
    
    ll  children[n];
    for (int i=0; i<n; i++ ){
        cin >> children[i];
    }
    sort(children, children+n);
    
    ll  pesado = n-1, ligero = 0, gondolas = 0;
    while (ligero <= pesado){
        if (children[ligero] + children[pesado] <= x){
        ligero++;
        
        }
        pesado--;
        gondolas++;
    }
    cout << gondolas;
    return 0; 
}