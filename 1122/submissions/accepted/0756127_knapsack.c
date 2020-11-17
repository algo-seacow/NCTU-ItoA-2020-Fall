#include <stdio.h>

int n, w, v, wi[500], vi[500], p[500], i, d[501][501], j, k;

int main() {
  scanf("%d%d%d", &n, &w, &v);
  for (; i != n; ++i)
    scanf("%d%d%d", wi + i, vi + i, p + i);

  for (i = 0; i != n; ++i)
    for (j = w; j >= wi[i]; --j)
      for (k = v; k >= vi[i]; --k)
        if (d[j][k] < d[j - wi[i]][k - vi[i]] + p[i])
          d[j][k] = d[j - wi[i]][k - vi[i]] + p[i];

  printf("%d", d[w][v]);
  return 0;
}
