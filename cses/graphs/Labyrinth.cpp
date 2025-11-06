#include<bits/stdc++.h>
#define endl '\n'

using namespace std; 
using ll = long long int; 
using paiir  = pair<int, int>; 

const int MAXN = 1001; 

vector<bool> visitables(MAXN*MAXN, 0); 
vector<char> visitados(MAXN*MAXN, ' ');
map<char, int> dir = {{'L', -1}, {'R', 1}, {'U', -MAXN}, {'D', MAXN}}; 
char direcciones[4] {'L', 'R', 'U', 'D'}; 
queue<int> q;
int a, b; 

void bfs(){
    bool found = 0;
    while (!q.empty() && !found){
        int pos = q.front(); q.pop();
        for (char move : direcciones){
            int pos_new = pos + dir[move]; 
            if ((0 <= pos_new) && (pos_new < MAXN*MAXN) && 
                visitables[pos_new] && (visitados[pos_new] == ' ')){
                visitados[pos_new] = move; 
                q.push(pos_new); 
                if (pos_new == b){
                    found = 1; break; 
                }
            }
        }
    }
}; 

int main(){
    int n, m; cin >> n >> m; 
    char aux; 
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> aux; 
            int index = j + i * MAXN;
            
            if (aux == '.' || aux == 'A' || aux == 'B') {
                visitables[index] = 1;
                if (aux == 'A') {
                    a = index;
                } else if (aux == 'B') {
                    b = index;
                }
            }
        }
    }
    q.push(a); 
    visitados[a] = 'S'; 
    bfs(); 
    if (visitados[b] != ' '){
        cout << "YES\n";
        int pos = b; 
        vector<char> ruta; 
        while (pos != a){
            ruta.push_back(visitados[pos]); 
            pos -= dir[visitados[pos]]; 
        }
        reverse(ruta.begin(), ruta.end()); 
        cout << ruta.size() << "\n"; 
        for (char c : ruta) cout << c; 
        cout << "\n"; 
    }
    else cout << "NO\n"; 
}