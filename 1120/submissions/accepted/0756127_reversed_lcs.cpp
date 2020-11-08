#include <algorithm>
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::max;
using std::reverse;
using std::string;

int n, i, j, d[7002][7002];
string s, r;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> s;
  r = s;
  reverse(r.begin(), r.end());
  for (; i != n; ++i)
    for (j = 0; j != n; ++j) {
      if (s[i] == r[j])
        d[i + 2][j + 2] = d[i][j] + 1;
      else
        d[i + 2][j + 2] = max(d[i + 2][j + 1], d[i + 1][j + 2]);
    }
  cout << d[n + 1][n + 1];
  return 0;
}
