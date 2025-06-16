#include <bits/stdc++.h>

using namespace std;
using ll = long long int; 

const int MAXN = 1e5 + 1;
const int MAXQ = 1e5 +1;
int rel[MAXN];
ll top[MAXN];
vector<int> ind[MAXN];

int main()
{
  ind[0].push_back(1);
  int N, Q, padre, idx, nxt, topic;
  cin >> N;
  cin >> Q;
  for (int i = 0; i < N; i++)
  {
    cin >> top[i]; 
    rel[i] = 0;
  }
  for (int i = 0; i < N - 1; i++)
  {
    cin >> padre;
    cin >> idx;
    rel[idx - 1] = padre;
    ind[idx - 1].push_back(idx);

    nxt = rel[idx - 1];
    bool flag = true;
    while (nxt != 0)
    {

      for (auto i : ind[idx-1])
      {
        if(i==idx)flag=false;
      }
      if (!flag) break;
      for (auto j : ind[idx - 1])
      {
        ind[nxt - 1].push_back(j);
      }
      nxt = rel[nxt - 1];
    }
  }

  

  int cont;
  for(int q=0;q<Q;q++){
    cin>>idx;
    cin>>topic; 
    cont=0;
    for (auto i : ind[idx-1])
    {
      if(top[i-1]==topic) cont++;
    }
    cout << cont << endl;
  }

  return 0;
}