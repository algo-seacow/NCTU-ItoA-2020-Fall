#include <stdio.h>

int n, m, i, j, k, a[500001], b[500001], s;

int main() {
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n; ++i) {
    scanf("%d", a + i);
    b[i] += a[i];
    if ((j = i + (i & -i)) <= n)
      b[j] += b[i];
  }

  while (m--) {
    scanf("%d%d%d", &i, &j, &k);
    if (i) {
      s = 0;
      if (j > k)
        for (i = n; i > 0; i &= i - 1)
          s += b[i];
      for (; j > 0; j &= j - 1)
        s -= b[j];
      for (k++; k > 0; k &= k - 1)
        s += b[k];
      printf("%d\n", s);
    } else {
      k -= a[++j];
      a[j] += k;
      for (; j <= n; j += j & -j)
        b[j] += k;
    }
  }

  return 0;
}

