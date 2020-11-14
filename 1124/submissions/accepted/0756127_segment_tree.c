#include <stdio.h>
#include <limits.h>
#define max(a,b) a>b?a:b

int n, m, i, j, st[2000000], a;

int main() {
  scanf("%d%d", &n, &m);
  for (i = n; i != n << 1; ++i)
    scanf("%d", st + i);
  for (i = n - 1; i != 0; --i)
    st[i] = max(st[i << 1], st[(i << 1) + 1]);
  while (m--) {
    scanf("%d%d", &i, &j);
    a = INT_MIN;
    for (i += n, j += n + 1; i < j; i >>= 1, j >>= 1) {
      if (i & 1) {
        if (a < st[i])
          a = st[i];
        i++;
      }
      if (j & 1) {
        j--;
        if (a < st[j])
          a = st[j];
      }
    }
    printf("%d\n", a);
  }
  return 0;
}
