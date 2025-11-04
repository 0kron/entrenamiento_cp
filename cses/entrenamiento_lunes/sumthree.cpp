#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int N, x, current;
    cin>>N>>x;
    vector<vector<long long int>> vec(N, vector<long long int>(2));
    for(int i=0; i<N; i++){
        vec[i][1]=i+1;
        cin>>vec[i][0];
    }
    sort(vec.begin(), vec.end());
    int point2, point3;
    for(int i=0; i<N-2; i++){
        point2 = i+1;
        point3 = N-1;
        while(point2<point3){
            current = vec[i][0]+vec[point2][0]+vec[point3][0];
            if(current==x){
                cout<<vec[i][1]<<" "<<vec[point2][1]<<" "<<vec[point3][1];
                return 0;
            }
            else if(current>x){
                point3--;
            }
            else{
                point2++;
            }
        }
    }
    cout<<"IMPOSSIBLE";
}