#include<bits/stdc++.h>

using namespace std; 
using ll = long long int; 

const int MAXN = 2e5; 
pair<ll, ll> t[MAXN]; // rangos de deptos
int T[MAXN]; // deptos disponibles

int main(){
    int n, m;
    ll k, aux; 
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++){
        cin >> aux; 
        t[i].first = aux - k; 
        t[i].second = aux + k; 
    } 
    for (int i = 0; i < m; i++){
        cin >> T[i]; 
    }
    sort(t, t+n); 
    sort(T, T+m); 
    int i = 0, j = 0, count = 0; 
    while (i < n && j < m){
        if (T[j] < t[i].first) j++; 
        else if (T[j] > t[i].second) i++; 
        else {
            count++; i++; j++; 
        }
    }
    cout << count << endl; 

}