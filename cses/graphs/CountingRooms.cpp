#include<bits/stdc++.h>
#define endl '\n'

using namespace std; 
using ll = long long int; 
using paiir  = pair<int, int>; 

const int MAXN = 1001; 

vector<bool> visitables(MAXN*MAXN, 0); 
vector<int> visitados(MAXN*MAXN, 0);
vector<int> dir {1, -1, MAXN, -MAXN};


void dfs(int pos, int mark){
    visitados[pos] = mark; 
    int pos_new; 
    for (int movimiento : dir){
        pos_new = pos + movimiento; 
        if (0<= pos_new && pos_new <MAXN*MAXN && visitables[pos_new] && !(visitados[pos_new])){
            dfs(pos_new, mark); 
        }
    }
}

int main(){
    int n, m; cin >> n >> m; 
    char aux; 
    int cuarto = 0; 
    for (int i = 0; i < n; i++){
        for(int j = 0; j<m; j++){
            cin >> aux; 
            if (aux == '.') visitables[j+i*MAXN] = 1; 
        }
    }
    for (int i = 0; i < n; i++){
        for(int j = 0; j<m; j++){
            if (visitables[j+i*MAXN] && !(visitados[j+i*MAXN])){
                cuarto++;
                dfs(j+i*MAXN, cuarto);
            }
        }
    }
    cout << cuarto << endl; 
}