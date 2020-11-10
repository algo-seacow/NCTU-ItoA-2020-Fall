#include <stdio.h>
#define swap(x, y) x^=y^=x^=y

int n, i, j, a[500001], b;
long long c;

void heapify(int i) {
  j = (i << 1) + 1;
  while (j < n) {
    if (j + 1 < n && a[j] < a[j + 1])
      j++;
    if (a[i] >= a[j])
      break;
    swap(a[i], a[j]);
    i = j;
    j = (i << 1) + 1;
  }
}

int main() {
  scanf("%d", &n);
  for (i = 0; i != n; ++i)
    scanf("%d", a + i);
  n++;

  for (i = (n - 1) >> 1; i >= 0; --i)
    heapify(i);

  while (n > 1) {
    b = a[0];
    n--;
    swap(a[0], a[n]);
    heapify(0);
    b -= a[0];
    if (b) {
      c += b;
      a[0] = b;
    } else {
      n--;
      swap(a[0], a[n]);
    }
    heapify(0);
  }

  printf("%lld", c);

  return 0;
}

