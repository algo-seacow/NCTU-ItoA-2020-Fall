#include <stdio.h>
#include <stdlib.h>

typedef struct P {
  int x, y, z, i;
  struct P *n;
} P;

int n, i, j, s[1000000], a[1000000], c;
P p[1000000];
P *b[1000000], *t;

void add(int i, P p) {
  t = malloc(sizeof(P));
  *t = p;
  t->n = b[i];
  b[i] = t;
  s[i]++;
}

int main() {
  scanf("%d", &n);
  for (i = 0; i != n; ++i) {
    scanf("%d%d%d", &p[i].x, &p[i].y, &p[i].z);
    p[i].i = i;
    a[i] = n - 1;
    add(p[i].x, p[i]);
  }

  for (i = 0, j = 0; i != n; ++i) {
    for (t = b[i]; t; t = b[i]) {
      a[t->i] -= s[i] - 1;
      p[j++] = *t;
      b[i] = t->n;
      free(t);
    }
    s[i] = 0;
  }

  for (i = 0; i != n; ++i)
    add(p[i].y, p[i]);

  for (i = 0, j = 0; i != n; ++i) {
    for (t = b[i]; t; t = b[i]) {
      a[t->i] -= s[i] - 1;
      p[j++] = *t;
      b[i] = t->n;
      free(t);
    }
    s[i] = 0;
  }

  for (i = 0; i != n;) {
    for (j = i + 1; j != n && p[i].x == p[j].x && p[i].y == p[j].y; ++j);
    c = j - i - 1;
    for (; i < j; ++i) {
      a[p[i].i] += c;
      add(p[i].z, p[i]);
    }
  }

  for (i = 0, j = 0; i != n; ++i) {
    for (t = b[i]; t; t = b[i]) {
      a[t->i] -= s[i] - 1;
      p[j++] = *t;
      b[i] = t->n;
      free(t);
    }
    s[i] = 0;
  }

  for (i = 0; i != n;) {
    for (j = i + 1; j != n && p[i].y == p[j].y && p[i].z == p[j].z; ++j);
    c = j - i - 1;
    for (; i < j; ++i)
      a[p[i].i] += c;
  }

  for (i = 0; i != n;) {
    for (j = i + 1; j != n && p[i].x == p[j].x && p[i].y == p[j].y && p[i].z == p[j].z; ++j);
    c = j - i - 1;
    for (; i < j; ++i) {
      a[p[i].i] -= c;
      add(p[i].x, p[i]);
    }
  }

  for (i = 0, j = 0; i != n; ++i)
    for (t = b[i]; t; t = b[i]) {
      p[j++] = *t;
      b[i] = t->n;
      free(t);
    }

  for (i = 0; i != n;) {
    for (j = i + 1; j != n && p[i].x == p[j].x && p[i].z == p[j].z; ++j);
    c = j - i - 1;
    for (; i < j; ++i)
      a[p[i].i] += c;
  }

  printf("%d", a[0]);
  for (i = 1; i != n; ++i)
    printf(" %d", a[i]);

  return 0;
}

