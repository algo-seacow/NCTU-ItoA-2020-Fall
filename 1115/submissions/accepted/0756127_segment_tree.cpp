#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
using std::max;
using std::copy;

int n, m, i, j, k, st[1000000][4], l[4], r[4], t[4];

void merge(int p[], int l[], int r[]) {
  p[0] = max(l[1] + r[0], l[0] + r[2]);
  p[1] = max(l[1] + r[1], l[0] + r[3]);
  p[2] = max(l[2] + r[2], l[3] + r[0]);
  p[3] = max(l[3] + r[1], l[2] + r[3]);
}

void update(int x) {
  merge(st[x], st[x << 1], st[(x << 1) + 1]);
}

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (i = n; i != n << 1; ++i)
    cin >> st[i][3];
  for (i = n - 1; i != 0; --i)
    update(i);
  while (m--) {
    cin >> i >> j >> k;
    j += n;
    if (i == 0) {
      st[j][3] = k;
      while (j >>= 1)
        update(j);
    } else {
      k += n + 1;
      for (i = 0; i != 4; ++i) {
        l[i] = 0;
        r[i] = 0;
      }
      while (j < k) {
        if (j & 1) {
          copy(l, l + 4, t);
          merge(l, t, st[j]);
          j++;
        }
        if (k & 1) {
          k--;
          copy(r, r + 4, t);
          merge(r, st[k], t);
        }
        j >>= 1;
        k >>= 1;
      }
      copy(l, l + 4, t);
      merge(l, t, r);
      cout << l[3] << '\n';
    }
  }
  return 0;
}

