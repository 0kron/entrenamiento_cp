// Twins
#include <bits/stdc++.h>
using namespace std; 
int main(){
  int n, aux=0;
  float t; 
  int arr[100];
  cin >> n; int i = 0; 
  while (i<n){
    cin >> arr[i]; 
    t += arr[i];
    i++; 
  }
  i = 0; 
  t = t/2; 
  sort(arr, arr+n); 
  while (aux <= t){
    aux += arr[n-(i+1)]; 
    i++; 
  } 
  cout << i << "\n";
}
