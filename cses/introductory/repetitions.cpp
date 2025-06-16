#include <bits/stdc++.h>

using namespace std; 

int main(){
  string adn; 
  cin >> adn; 
  int max = 0, count = 0; 
  char prev = ' '; 
  for (auto i : adn){
    if (i != prev){
      count = 0; 
    }
    prev = i;
    count++;
    if (count > max) max = count; 
  }
  cout << max << "\n"; 

}