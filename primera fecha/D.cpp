#include<bits/stdc++.h>

using namespace std; 
using ll = long long int; 
const int MAXK = 100; 
ll A[MAXK]; 
ll O[MAXK][10000+1]; 
ll R[MAXK][2]; 

int main(){
  int k, aux, N;  
  cin >> k;
  for (int i = 0; i < k; i++){
    cin >> A[i];  
    // if (&A[i] == 0) 
  }; 

  cin >> N; 
  for(int i = 0; i<N+1; i++){
    for (int j = 0; j < k; j++){
      if (i == 0) O[j][i] = 0; 
      else{
        cin >> aux;
        O[j][i] = aux + O[j][i-1]; 
      }; 
    }; 
  };  

  ll min = 1e12 +1;

  for (int i = 0; i<k; i++){
    if (O[i][N] == 0) R[i][0] = 1e12 +1; 
    else{
      R[i][0] = A[i] / O[i][N]; 
    }
    if (R[i][0] < min){
      min = R[i][0]; 
    }
  }
  cout << min+1 << " "; 
  for (int i = 0; i<k; i++){
    R[i][1] = A[i] - O[i][N]*min;  
  }
  for (int i = 1; i<N+1; i++){
    for (int j = 0; j<k; j++){
      if (R[j][1] - O[j][i] < 0){
        cout << i; return 0; 
      }
    }
  }
}