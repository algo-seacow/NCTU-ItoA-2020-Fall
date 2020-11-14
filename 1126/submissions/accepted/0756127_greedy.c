#include <stdio.h>
#define swap(x,y) t=x;x=y;y=t

typedef struct {
  int s, f;
} A;

int cmp(void *x, void *y) {
  if (((A*) x)->f < ((A*) y)->f)
    return -1;
  if (((A*) x)->f == ((A*) y)->f)
    return 0;
  return 1;
}

int n, i, q, w, c, t;
A a[500000];

int main() {
  scanf("%d", &n);
  for (; i != n; ++i)
    scanf("%d%d", &a[i].s, &a[i].f);

  qsort(a, n, sizeof(A), cmp);

  for (i = 0; i != n; ++i) {
    if (a[i].s >= w) {
      if (a[i].s >= q)
        q = a[i].f;
      else {
        w = a[i].f;
        if (q < w)
          swap(q, w);
      }
      c++;
    }
  }

  printf("%d", c);
  return 0;
}
