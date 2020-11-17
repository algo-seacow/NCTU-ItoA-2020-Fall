#include <stdio.h>
#include <stdlib.h>

int n, m, k, l, a, i, d[100001];

int main() {
  scanf("%d%d%d", &n, &m, &k);
  k *= n;
  if (k >= m) {
    printf("%d", k - m);
    return 0;
  }
  for (; i <= m; ++i)
    d[i] = abs(i - k);
  for (; n; --n) {
    scanf("%d", &a);
    a *= n;
    for (i = m; i >= a; --i)
      if (d[i] > d[i - a])
        d[i] = d[i - a];
    for (; i > k + a / 2; --i)
      if (d[i] > k - i + a)
        d[i] = k - i + a;
  }
  printf("%d", d[m]);
  return 0;
}
