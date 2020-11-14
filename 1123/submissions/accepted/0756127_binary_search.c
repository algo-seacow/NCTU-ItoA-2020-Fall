#include <stdio.h>
#include <math.h>

int t;
double y, b, l, r, m;

int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%lf%lf", &y, &b);
    b = log2(b);
    l = 1;
    r = 2147483647;
    while (r - l >= m / 10e+10) {
      m = (l + r) / 2;
      if (y < m * log2(m) / b)
        r = m;
      else
        l = m;
    }
    printf("%.10lf\n", l);
  }
  return 0;
}
