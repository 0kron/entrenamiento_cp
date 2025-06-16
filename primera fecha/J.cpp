#include <bits/stdc++.h>

using namespace std;
int L[30];

int main()
{
  int N, m, lon;
  string s;
  cin >> N;
  cin >> s;
  lon = s.length();

  for (auto i : s){
    L[((int)i) - 97]++;
  }

  for (int i = 0; i < 26; i++)
  {
    if (L[i] % 2 != 0)
      m++;
  }

  while (m > 1)
  {
    if (L[(int)s[lon - 1] - 97] % 2 == 1)
    {
      L[(int)s[lon - 1] - 97]--;
      s = s.substr(0, lon - 1);
    }
    else if (L[(int)s[0] - 97] % 2 == 1)
    {
      L[(int)s[0] - 97]--;
      s = s.substr(1, lon - 1);
    }
    else
    {
      if (L[(int)s[0] - 97] > L[(int)s[lon - 1] - 97])
      {
        L[(int)s[0] - 97]--;
        s = s.substr(1, lon - 1);
      }
      else
      {
        L[(int)s[lon - 1] - 97]--;
        s = s.substr(0, lon - 1);
      }
    }
    m = 1;
    for (int i = 1; i < 26; i++)
    {
      if (L[i] % 2 != 0)
        m++;
    }
    cout << s << " " << m << endl;
    lon--;
  }
  cout << s.length() << endl;
  return 1;
}