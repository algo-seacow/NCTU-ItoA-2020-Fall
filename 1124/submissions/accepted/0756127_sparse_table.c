#include <stdio.h>
#include <limits.h>
#define max(a,b) a>b?a:b

int n, m, i, j, k, st[20][1000000];

int main() {
  scanf("%d%d", &n, &m);
  for (; i != n; ++i)
    scanf("%d", st[0] + i);
  for (i = 0; 1 << (i + 1) <= n ; ++i)
    for (j = 0; j + (1 << (i + 1)) <= n; ++j)
      st[i + 1][j] = max(st[i][j], st[i][j + (1 << i)]);
  while (m--) {
    scanf("%d%d", &i, &j);
    j++;
    k = 31 - __builtin_clz(j - i);
    printf("%d\n", max(st[k][i], st[k][j - (1 << k)]));
  }
  return 0;
}
