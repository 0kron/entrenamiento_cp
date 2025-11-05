#include<bits/stdc++.h>

using namespace std; 
using ll = long long int; 
using paiir = pair<int, int>;

/*
Este de hecho es un problema famoso es el "Interval Scheduling" Problem, la idea es generar un greedy, 
con esto, debemos ordenar los intervalos por su término, y si el intervalo empieza después del último
que tomamos, entonces ese es el que tomamos, de lo contrario pasamos al siguiente.
*/

bool comp(paiir a, paiir b){
    return a.second < b.second; // ordenar por el tiempo de término
}

int main(){
    int n, a, b; 
    cin >> n; 
    vector<paiir> intervalos(n); 
    for (int i = 0; i < n; i++) cin >> intervalos[i].first >> intervalos[i].second; 
    sort(intervalos.begin(), intervalos.end(), comp); 
    int i = 0, finAct = -1, count = 0; 
    while (i < n){
        if (finAct <= intervalos[i].first){
            count++; 
            finAct = intervalos[i].second; 
        }
        i++; 
    }
    cout << count << endl; 
}