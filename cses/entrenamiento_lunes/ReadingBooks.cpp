#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int n, t, sum=0, maximo=0;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>t;
        sum+=t;
        if(t>=maximo){
            maximo = t;
        }
    }
    cout<<max(sum, 2*maximo);
    return 0;
}