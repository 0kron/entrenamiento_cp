#include<bits/stdc++.h>

using namespace std; 
using ll = long long int; 

int const MAXN = 2e5 + 1; 
pair<int, int> movie[MAXN]; 

int main(){
    int n, a, b; 
    cin >> n; 
    for (int i = 0; i < n; i++){
        cin >> a >> b; 
        movie[i] = {a, b}; 
    }
    sort(movie, movie+n); 
    pair<int, int> actual = movie[0]; 
    int i = 1, count = 1; 
    while (i < n){
        if (actual.second <= movie[i].first){
            count++; actual = movie[i]; 
        }
        else if (actual.second > movie[i].second) actual = movie[i]; // Como que te regresas una peli, dado que es más eficiente para verla en vez.  
        i++; 
    
    }
    cout << count << endl; 
}