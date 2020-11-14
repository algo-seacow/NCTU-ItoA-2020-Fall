#include <stdio.h>

int n, m, k, l, a, i, d[200001];

int main() {
  scanf("%d%d%d", &n, &m, &k);
  k *= n;
  if (k >= m) {
    printf("%d", k - m);
    return 0;
  }
  l = 2 * m - k - 1;
  d[k] = 1;
  for (; n; --n) {
    scanf("%d", &a);
    a *= n;
    for (i = l; i >= k + a; --i)
      d[i] |= d[i - a];
  }
  for (i = 0; i <= m - k; ++i)
    if (d[m - i] || d[m + i]) {
      printf("%d", i);
      break;
    }
  return 0;
}
