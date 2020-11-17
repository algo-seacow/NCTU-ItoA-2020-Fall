#include <stdio.h>
#include <stdlib.h>

int n, k, i, p[1000000], l, m, r, f, j, c;

int cmp(const void *x, const void *y) {
  if (*(int*)x < *(int*)y)
    return -1;
  if (*(int*)x == *(int*)y)
    return 0;
  return 1;
}

int main() {
  scanf("%d%d", &n, &k);
  for (; i != n; ++i)
    scanf("%d", p + i);
  qsort(p, n, sizeof(int), cmp);

  l = -1;
  r = (p[n - 1] - p[0]) / k;
  while (l + 1 < r) {
    m = l + (r - l) / 2;
    f = 1;
    j = p[0] + m;
    c = k;
    for (i = 1; i != n; ++i)
      if (p[i] > j) {
        c--;
        if (!c) {
          f = 0;
          break;
        }
        j = p[i] + m;
      }
    if (f)
      r = m;
    else
      l = m;
  }

  printf("%d", r);
  return 0;
}
