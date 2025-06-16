// HQ9+
#include<bits/stdc++.h>

using namespace std; 

int main(){
  string s;
  cin >> s; 
  int n = s.length(); 
  while(n--){
    if (s[n] == 'H' || s[n] == 'Q' || s[n] == '9') {
    cout << "YES\n";
    return 0; 
    }}
  cout << "NO\n"; 
}
