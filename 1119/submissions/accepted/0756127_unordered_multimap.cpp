#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <utility>

using std::cin;
using std::copy;
using std::cout;
using std::pair;
using std::sort;
using std::unordered_multimap;

int n, s, a[2500], i, j, q[4] = {-1}, t[4];
unordered_multimap<int, pair<int, int> > h;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> s;
  h.reserve(n * (n - 1) / 2);
  for (i = 0; i != n; ++i)
    cin >> a[i];

  for (i = 0; i != n; ++i)
    for (j = i + 1; j < n; ++j) {
      auto r = h.equal_range(s - a[i] - a[j]);
      for (auto k = r.first; k != r.second; ++k)
        if (!(k->second.first == i || k->second.second == i || k->second.second == j)) {
          t[0] = k->second.first;
          t[1] = k->second.second;
          t[2] = i;
          t[3] = j;
          sort(t, t + 4);
          if (q[0] == -1 || t[0] < q[0] || t[0] == q[0] && (t[1] < q[1] || t[1] == q[1] && (t[2] < q[2] || t[2] == q[2] && t[3] < q[3])))
            copy(t, t + 4, q);
        }
      h.insert({a[i] + a[j], {i, j}});
    }

  if (q[0] == -1)
    cout << "-1";
  else
    cout << q[0] << ' ' << q[1] << ' ' << q[2] << ' ' << q[3];

  return 0;
}

