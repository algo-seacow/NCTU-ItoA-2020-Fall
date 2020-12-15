#include <stdio.h>

int n, i = 1, a[1000001] = {-1}, j;

int main() {
  scanf("%d", &n);
  while (n--) {
    scanf("%d", a + i);
    j = i - 1;
    while (j && a[j] <= a[i])
      j--;
    printf("%d ", a[j]);
    j++;
    a[j] = a[i];
    i = j + 1;
  }
  return 0;
}
