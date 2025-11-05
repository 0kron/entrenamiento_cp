#include<bits/stdc++.h>
using namespace std; 
using ll = long long int; 

#define endl "\n"

const int MAXN = 1e6+1, md = 1e9 + 7;
ll dp[MAXN][2]; 

int main(){
    dp[0][0] = dp[0][1] = 1; 

    for (int i = 1; i < MAXN; i++){
        dp[i][0] = ((dp[i-1][0]*4)%md + dp[i-1][1])%md; 
        dp[i][1] = (dp[i-1][0] + (dp[i-1][1]*2)%md)%md; 
    }

    int t, n; cin >> t; 
    while (t--){
        cin>>n; 
        cout << (dp[n-1][0] + dp[n-1][1])%md << endl; 
    }
}