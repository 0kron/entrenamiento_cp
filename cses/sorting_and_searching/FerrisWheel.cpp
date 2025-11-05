#include <bits/stdc++.h>
using namespace std;
using ll = long long int;


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