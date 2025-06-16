#include<bits/stdc++.h>
using namespace std; 

int main(){
  int count[26], im, ind_im, j; 
  string s; 
  cin >> s; 
  for (int i = 0; i<26; i++) count[i] = 0; 
  for (auto c:s) count[((int)c)-65]++; 
  
  for (int i = 0; i < 26; i++){
    if (count[i] % 2 != 0){
      im++;
      ind_im = i; 
    }
  }
  if (im > 1) cout << "NO SOLUTION\n"; 
  else{
    for (int i = 0; i < 26; i++){
      if (i != ind_im){
        j = 0; 
        while (j < count[i]/2){
         cout << (char)(i+65); j++; 
        }
      }
    }
    for (int i = 0; i < count[ind_im]; i++) cout << (char)(ind_im+65); 
    for (int i = 25; i >= 0; i--){
      if (i != ind_im){
        j = 0; 
        while (j < count[i]/2){
          cout << (char)(i+65); j++; 
         }
      }
    }
    cout << "\n"; 
  }
  

  return 0; 
}
