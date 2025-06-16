// Football - 900
#include<bits/stdc++.h>
using namespace std; 
int main(){
  int n; string s; 
  int ad = 0; 
  cin >> s; 
  n = s.length();
  int flag = -1;
  while (n--){
    if ((int)s[n] == flag) ad++; 
    else{
      ad = 1;
      flag = (int)s[n];
    }
    if (ad >= 7){
      cout << "YES\n"; 
      return 0; 
    }
  }
  cout << "NO\n"; 
  return 0;
}
