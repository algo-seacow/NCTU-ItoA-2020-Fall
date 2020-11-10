#include <stdio.h>
#include <stdlib.h>
#define HT_SIZE 10010101
#define SIZE 2500
#define h(x) ((x) % HT_SIZE + HT_SIZE) % HT_SIZE

typedef struct E {
  int i, j, s;
  struct E *n;
} E;

int n, s, i, a[SIZE], j, q = -1, w, e, r;
E *ht[HT_SIZE], *t;

int main() {
  scanf("%d%d", &n, &s);
  for (; i != n; ++i)
    scanf("%d", a + i);

  for (j = 1; j < n - 2; ++j) {
    for (i = 0; i != j; ++i) {
      t = ht[h(s - a[i] - a[j])];
      while (t) {
        if (t->s == s - a[i] - a[j])
          break;
        t = t->n;
      }

      if (t) {
        if (i < t->i || i == t->i && j < t->j) {
          t->i = i;
          t->j = j;
        }
      } else {
        t = malloc(sizeof(E));
        t->i = i;
        t->j = j;
        t->s = a[i] + a[j];
        t->n = ht[h(t->s)];
        ht[h(t->s)] = t;
      }
    }
    for (i = j + 2; i != n; ++i) {
      t = ht[h(s - a[j + 1] - a[i])];
      while (t) {
        if (t->s == s - a[j + 1] - a[i] && (q == -1 || t->i < q || t->i == q && (t->j < w || t->j == w && (j + 1 < e || j + 1 == e && i < r)))) {
          q = t->i;
          w = t->j;
          e = j + 1;
          r = i;
        }
        t = t->n;
      }
    }
  }

  if (q == -1)
    puts("-1");
  else
    printf("%d %d %d %d", q, w, e, r);

  return 0;
}

