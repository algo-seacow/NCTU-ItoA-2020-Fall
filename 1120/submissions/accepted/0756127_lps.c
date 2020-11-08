#include <stdio.h>
#define max(a, b) ((a) > (b) ? (a) : (b))

int n, i, d[7000][7000], j;
char s[7001];

int main() {
  scanf("%d%s", &n, s);
  for (; i < n - 1; ++i) {
    d[i][i] = 1;
    d[i][i + 1] = 1;
  }
  d[n - 1][n - 1] = 1;
  for (i = 2; i < n; ++i)
    for (j = 0; j < n - i; ++j)
      if (s[j] == s[j + i])
        d[j][j + i] = d[j + 2][j + i - 2] + 2;
      else
        d[j][j + i] = max(d[j + 1][j + i], d[j][j + i - 1]);
  printf("%d", d[0][n - 1]);
  return 0;
}
